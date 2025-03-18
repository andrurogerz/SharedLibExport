#pragma once

//
// We define four import/export visibility macros to use when building shared
// libraries:
//
// SDK_ABI
// The symbol will be exported from the shared library. Can be applied to type,
// function, and variable declarations.
//
// SDK_TYPE
// The struct or class will export its type information, but not necessarily its
// members, from the shared library. Intended only to annotate class and struct
// declarations. Compiles out on Windows.
//
// SDK_EXTERN
// Primarily intended for annotating extern template instance declarations in
// header files. For Windows targets, it resolves to __declspec(dllimport) when
// building clients but compiles-out when building the implementation. For
// non-Windows targets, it is equivalent to SDK_ABI.
//
// SDK_EXPORT
// Primarily intended for annotating explcit template instantiations in source
// files. For Windows targets, it resolves to __declspec(dllexport) when
// building the implementation but compiles-out when building clients. For
// non-Windows targets, it compiles-out.

// Windows
#ifdef _WIN32
  #ifdef COMPILING_SDK
    #define SDK_ABI __declspec(dllexport)
    #define SDK_EXPORT SDK_ABI
    #define SDK_EXTERN
  #else
    #define SDK_ABI __declspec(dllimport)
    #define SDK_EXPORT
    #define SDK_EXTERN SDK_ABI
  #endif
  // On Windows, the type itself does not need to be exported as long as all
  // externally referenced members of the type are exported.
  #define SDK_TYPE
#elif defined(__has_attribute) && __has_attribute(visibility)
  #define SDK_ABI __attribute__((visibility("default")))
  #define SDK_EXPORT
  #define SDK_EXTERN SDK_ABI
  #if __has_attribute(__type_visibility__)
    // Use the __type_visibility__ attribute to on classes where type info or
    // vtable need to be visible externally. This is only supported on clang.
    #define SDK_TYPE __attribute__((__type_visibility__("default")))
  #else
    // The __type_visibility__ attribute is not supported on gcc, so resort to
    // the visibility attribute. This attribute will export all members of the
    // type, not just type info and vtable.
    //#warning("__type_visibility__ not supported; all members will be exported!")
    #define SDK_TYPE SDK_ABI
  #endif
#else
  #error "Required visibility attribute are not supported by compiler!"
#endif

#pragma once

// Windows
#ifdef _WIN32
  #ifdef COMPILING_SDK
    #define SDK_ABI __declspec(dllexport)
  #else
    #define SDK_ABI __declspec(dllimport)
  #endif
  // On Windows, the type itself does not need to be exported as long as all
  // externally referenced members of the type are exported.
  #define SDK_TYPE_ABI
#elif defined(__has_attribute) && __has_attribute(visibility)
  #define SDK_ABI __attribute__((visibility("default")))
  #if __has_attribute(__type_visibility__)
    // Use the __type_visibility__ attribute to on classes where type info or
    // vtable need to be visible externally. This is only supported on clang.
    #define SDK_TYPE_ABI __attribute__((__type_visibility__("default")))
  #else
    // The __type_visibility__ attribute is not supported on gcc, so resort to
    // the visibility attribute. This attribute will export all members of the
    // type, not just type info and vtable.
    #warning("__type_visibility__ not supported; all members will be exported!")
    #define SDK_TYPE_ABI SDK_ABI
  #endif
#else
  #error "Required visibility attribute are not supported by compiler!"
#endif

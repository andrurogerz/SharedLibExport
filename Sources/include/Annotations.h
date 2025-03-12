#pragma once

// Windows
#ifdef _WIN32
  #ifdef COMPILING_SDK
    #define SDK_ABI __declspec(dllexport)
  #else
    #define SDK_ABI __declspec(dllimport)
  #endif
  #define SDK_TYPE_ABI
#elif __has_attribute(visibility)
  #define SDK_ABI __attribute__((visibility("default")))
  #if __has_attribute(__type_visibility__)
    // Use the __type_visibility__ attribute to on classes where type info or
    // vtable need to be visible externally.
    #define SDK_TYPE_ABI __attribute__((__type_visibility__("default")))
  #else
    // gcc does not support the __type_visibility__ attribute so resort to using
    // the visibility attribute. This will export all members of the type, not
    // just type info and vtable.
    #warning("__type_visibility__ not supported; all members will be exported!")
    #define SDK_TYPE_ABI SDK_ABI
  #endif
#else
  #error "Required visibility attribute are not supported by compiler!"
#endif

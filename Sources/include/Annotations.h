#ifdef _WIN32
  #ifdef COMPILING_SDK
    #define SDK_EXPORT_ABI __declspec(dllexport)
    #define SDK_ABI __declspec(dllexport)
  #else
    #define SDK_EXPORT_ABI
    #define SDK_ABI __declspec(dllimport)
  #endif
#elif __has_attribute(visibility)
  #define SDK_ABI __attribute__((visibility("default")))
#else
  #define SDK_ABI
#endif


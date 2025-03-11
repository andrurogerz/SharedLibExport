add_library(SharedLibExport SHARED
  ExportedSimpleClass.cxx
)

set_target_properties(SharedLibExport PROPERTIES
  OUTPUT_NAME "SharedLibExport"
  VERSION 1.0
  SOVERSION 1
)

if(NOT WIN32)
  target_compile_options(SharedLibExport PRIVATE "-fvisibility=hidden")
endif()

target_compile_definitions(SharedLibExport PRIVATE COMPILING_SDK)
target_include_directories(SharedLibExport PUBLIC include)

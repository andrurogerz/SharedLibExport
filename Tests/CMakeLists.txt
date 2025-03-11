add_executable(SharedLibExportTest
  main.cxx
)
target_link_libraries(SharedLibExportTest PRIVATE SharedLibExport)

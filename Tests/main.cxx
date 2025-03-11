#include <ExportedSimpleClass.hxx>

#include <stdio.h>

int main(int argc, const char* argv[]) {
  ExportedSimpleClass obj;
  auto x = exportedSimpleClassGetAndSet(obj, 10);
  return 0;
}

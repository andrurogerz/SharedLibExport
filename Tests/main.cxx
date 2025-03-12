#include <ExportedSimpleClass.hxx>
#include <ExportedDerivedClass.hxx>

#include <assert.h>
#include <string.h>
#include <iostream>

int main(int argc, const char* argv[]) {
  {
    ExportedSimpleClass obj;
    const int x = exportedSimpleClassGetAndSet(obj, 10);
    obj.set(obj.get() + x);
    assert(::strcmp(ExportedSimpleClass::ID, obj.identify()) == 0);
  }

  {
    ExportedDerivedClass obj;
    const int x = exportedSimpleClassGetAndSet(obj, 10);
    obj.set(obj.get() + x);
    assert(::strcmp(ExportedDerivedClass::ID, obj.identify()) == 0);
  }

  std::cout << "test passed\n";
  return 0;
}

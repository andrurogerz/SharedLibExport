#include <ContainerTemplate.hxx>
#include <ExportedDerivedClass.hxx>
#include <ExportedSimpleClass.hxx>
#include <ExternVariables.hxx>

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

  {
    ContainerTemplate<std::string> obj("string");
    obj.doSomething();
  }

  {
    ContainerTemplate<std::size_t> obj(147);
    obj.doSomething();
  }

  {
    const char *str = ExternVariables::const_string;
  }

  {
    std::size_t size = ExternVariables::mutable_size;
    ExternVariables::mutable_size = size + 10;
  }

  std::cout << "test passed\n";
  return 0;
}

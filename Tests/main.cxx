#include <ContainerTemplate.hxx>
#include <ExportedDerivedClass.hxx>
#include <ExportedSimpleClass.hxx>
#include <ExternVariables.hxx>
#include <FriendClass.hxx>

#include <assert.h>
#include <string.h>
#include <iostream>

int main(int argc, const char* argv[]) {
  {
    ExportedSimpleClass obj;
    obj.set(obj.get() + 10);
    assert(::strcmp(ExportedSimpleClass::ID, obj.identify()) == 0);
  }

  {
    ExportedDerivedClass obj;
    obj.set(obj.get() + 10);
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
    FriendlyClass friendlyClass;
    FriendClass friendClass;
    auto result = friendClass.doSomethingFriendly(friendlyClass);
    assert(result == 18);
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

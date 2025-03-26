#include <ContainerTemplate.hxx>
#include <ExportedDerivedClass.hxx>
#include <ExportedSimpleClass.hxx>
#include <ExternVariables.hxx>
#include <FriendClass.hxx>
#include <InstantiatedTemplateClass.hxx>
#include <SpecializedTemplateFunction.hxx>
#include <TemplateWithExternMethod.hxx>
#include <TemplateWithSpecializedMethod.hxx>

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
    // T=long specialization will resolve to the method in the class definition
    // that returns (a + b)
    TemplateSpecialization::TemplateStruct<long> obj;
    auto result = obj.method(1, 2);
    assert(result == 1 + 2);
  }

  {
    // T=unsigned will resolve to a specialized method that returns (a + b + 1)
    TemplateSpecialization::TemplateStruct<unsigned> obj;
    auto result = obj.method(1, 2);
    assert(result == 1 + 2 + 1);
  }

  {
    // T=int will resolve to a specialized method that returns (a + b + 2)
    TemplateSpecialization::TemplateStruct<int> obj;
    auto result = obj.method(1, 2);
    assert(result == 1 + 2 + 2);
  }

  {
    auto result = TemplateSpecialization::method<unsigned>(3, 5);
    assert(result == 9);
  }

  {
    TemplateClass<unsigned> obj;
    auto result = obj.method(6, 8);
    assert(result == 6 + 8);
  }

  {
    const char *str = ExternVariables::const_string;
  }

  {
    std::size_t size = ExternVariables::mutable_size;
    ExternVariables::mutable_size = size + 10;
  }

  {
    doSomething('c');
    doSomething((long)-1);
    doSomething((unsigned)6);
  }

  std::cout << "test passed\n";
  return 0;
}

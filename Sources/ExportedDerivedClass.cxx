#include "ExportedDerivedClass.hxx"

int ExportedDerivedClass::get() const {
  return ExportedSimpleClass::get();
}

char ExportedDerivedClass::ID[] = "ExportedDerivedClass";

const char* ExportedDerivedClass::identify() const {
  return ID;
}

#include "ExportedSimpleClass.hxx"

ExportedSimpleClass::ExportedSimpleClass() {
  value_ = 0;
}

ExportedSimpleClass::~ExportedSimpleClass() {
  value_ = 0;
}

void ExportedSimpleClass::set(int value) {
  setInternal(value);
}

void ExportedSimpleClass::setInternal(int value) {
  value_ = value;
}

char ExportedSimpleClass::ID[] = "ExportedSimpleClass";

const char* ExportedSimpleClass::identify() const {
  return ID;
}

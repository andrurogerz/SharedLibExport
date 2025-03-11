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

int exportedSimpleClassGetAndSet(ExportedSimpleClass &obj, int value) {
  const auto result = obj.get();
  obj.setInternal(value);
  return result;
}

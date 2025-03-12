#pragma once

#include "Annotations.h"
#include "ExportedSimpleClass.hxx"

class SDK_TYPE_ABI ExportedDerivedClass : public ExportedSimpleClass {
public:
  ExportedDerivedClass() : ExportedSimpleClass() {}
  ~ExportedDerivedClass() {}

  SDK_ABI int get() const;
  SDK_ABI const char* identify() const;

  void set(int value) {
    ExportedSimpleClass::set(value);
  }

  SDK_ABI static char ID[];
};

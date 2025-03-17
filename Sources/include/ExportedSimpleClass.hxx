#pragma once

#include "Annotations.h"

class ExportedSimpleClass {
public:
  SDK_ABI ExportedSimpleClass();
  SDK_ABI virtual ~ExportedSimpleClass();

  virtual int get() const {
    return value_;
  }

  SDK_ABI virtual void set(int);
  SDK_ABI virtual const char* identify() const;

  SDK_ABI static char ID[];

private:
  void setInternal(int);

private:
  int value_;
};

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

  // For Windows DLLs, friend function declarations must have the same dllexport
  // or dllimport as the actual function declaration or a compiler warning is
  // generated.
  SDK_ABI friend int
  exportedSimpleClassGetAndSet(ExportedSimpleClass &obj, int value);

private:
  void setInternal(int);

private:
  int value_;
};

SDK_ABI int exportedSimpleClassGetAndSet(ExportedSimpleClass &obj, int value);

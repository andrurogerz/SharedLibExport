#pragma once

#include "Annotations.h"

class FriendlyClass;

class FriendClass {
public:
  SDK_ABI int doSomethingFriendly(FriendlyClass &obj);
};

SDK_ABI int veryFriendlyFunction(FriendlyClass &obj);

class FriendlyClass {
  friend class FriendClass;

  // For Windows DLLs, friend function declarations must have the same dllexport
  // or dllimport as the actual function declaration or a compiler warning is
  // generated.
  SDK_ABI friend int veryFriendlyFunction(FriendlyClass &obj);

private:
  SDK_ABI int privateMethod();
};

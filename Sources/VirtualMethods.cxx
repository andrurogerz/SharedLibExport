#include "VirtualMethods.hxx"

namespace VirtualMethods {

ExternVirtualMethods::~ExternVirtualMethods() {}

unsigned ExternVirtualMethods::virtualMethod(unsigned value) {
  return value;
}

ExternOverrideInlineVirtualMethod::~ExternOverrideInlineVirtualMethod() {}

unsigned ExternOverrideInlineVirtualMethod::virtualMethod(unsigned value) {
  return value + 1;
}

ExternOverridePureVirtualMethod::~ExternOverridePureVirtualMethod() {}

unsigned ExternOverridePureVirtualMethod::virtualMethod(unsigned value) {
  return value + 2;
}

PureVirtualDestructor::~PureVirtualDestructor() {}

void ChildOfPureVirtualDestructor::virtualMethod() {}

};

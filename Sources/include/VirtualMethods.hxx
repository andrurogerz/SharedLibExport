#pragma once

#include "Annotations.h"

namespace VirtualMethods {

class InlineVirtualMethods {
public:
  InlineVirtualMethods() = default;
  virtual ~InlineVirtualMethods() {}
  virtual unsigned virtualMethod(unsigned value) {
    return value;
  }
};

class SDK_ABI ExternVirtualMethods {
public:
  ExternVirtualMethods() = default;
  virtual ~ExternVirtualMethods();
  virtual unsigned virtualMethod(unsigned value);
};

class PureVirtualMethods {
public:
  PureVirtualMethods() = default;
  virtual ~PureVirtualMethods() {};
  virtual unsigned virtualMethod(unsigned value) = 0;
};

class SDK_ABI ExternOverrideInlineVirtualMethod: public InlineVirtualMethods {
public:
  ExternOverrideInlineVirtualMethod() = default;
  ~ExternOverrideInlineVirtualMethod() override;
  unsigned virtualMethod(unsigned value) override;
};

class InlineOverrideInlineVirtualMethod: public InlineVirtualMethods {
public:
  InlineOverrideInlineVirtualMethod() = default;
  ~InlineOverrideInlineVirtualMethod() {};
  unsigned virtualMethod(unsigned value) override {
    return value + 1;
  }
};

class InlineOverrideExternVirtualMethod: public ExternVirtualMethods {
public:
  InlineOverrideExternVirtualMethod() = default;
  ~InlineOverrideExternVirtualMethod() {};
  unsigned virtualMethod(unsigned value) override {
    return value + 2;
  }
};

class InlineOverridePureVirtualMethod: public PureVirtualMethods {
public:
  InlineOverridePureVirtualMethod() = default;
  ~InlineOverridePureVirtualMethod() {}
  unsigned virtualMethod(unsigned value) override {
    return value + 3;
  }
};

class SDK_ABI ExternOverridePureVirtualMethod: public PureVirtualMethods {
public:
  ExternOverridePureVirtualMethod() = default;
  ~ExternOverridePureVirtualMethod();
  unsigned virtualMethod(unsigned value) override;
};

class PureVirtualDestructor {
public:
  SDK_ABI virtual ~PureVirtualDestructor() = 0;
  virtual void virtualMethod() = 0;
};

class SDK_ABI ChildOfPureVirtualDestructor : public PureVirtualDestructor {
public:
  ~ChildOfPureVirtualDestructor() {}
  void virtualMethod() override;
};

};

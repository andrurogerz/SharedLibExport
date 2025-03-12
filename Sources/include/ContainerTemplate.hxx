#include "Annotations.h"

#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
class ContainerTemplate {
public:
  ContainerTemplate(T v) : v_(v) {}

  T get() { return v_; }

  void doSomething();

private:
  const T v_;
};

extern template class SDK_ABI ContainerTemplate<std::size_t>;
extern template class SDK_ABI ContainerTemplate<std::string>;

#pragma once

#include "Annotations.h"

namespace TemplateSpecialization {

template <typename T> T method(T a, T b) {
  return a + b;
}

template <> SDK_ABI unsigned method(unsigned a, unsigned b);

}; // namespace TemplateSpecialization

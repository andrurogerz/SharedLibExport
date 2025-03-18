#pragma once

#include "Annotations.h"

namespace TemplateSpecialization {

template <typename T>
struct TemplateStruct {
  T method(T a, T b) {
    return a + b;
  }
};

template <> SDK_ABI
unsigned TemplateStruct<unsigned>::method(unsigned a, unsigned b);

template <> SDK_ABI
int TemplateStruct<int>::method(int a, int b);

}; // namespace TemplateSpecialization

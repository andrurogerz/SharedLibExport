#pragma once

#include "Annotations.h"

namespace TemplateSpecialization {

template <typename t>
struct TemplateStruct {
  int method(int a, int b) {
    return a + b;
  }
};

template <> SDK_ABI
int TemplateStruct<unsigned>::method(int a, int b);

}; // namespace TemplateSpecialization

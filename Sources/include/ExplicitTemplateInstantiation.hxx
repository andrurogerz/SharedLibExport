#pragma once

#include "Annotations.h"

namespace ExplicitTemplateInstantiation {

template <typename T>
struct SDK_EXTERN TemplateStruct {
  int method();

  static int staticMethod();

  static int key;
};

template <> SDK_ABI int TemplateStruct<int>::method();
template <> SDK_ABI int TemplateStruct<int>::staticMethod();
template <> SDK_ABI int TemplateStruct<int>::key;

extern template struct TemplateStruct<int>;
extern template struct TemplateStruct<float>;

} // namespace ExplicitTemplateInstantation

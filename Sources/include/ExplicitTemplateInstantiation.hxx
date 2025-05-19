#pragma once

#include "Annotations.h"

namespace ExplicitTemplateInstantiation {

struct Key {};

template <typename T>
struct SDK_EXTERN TemplateStruct {
  int method();

  static int staticMethod();

  static Key key;
  static int value;
};

template <> SDK_ABI int TemplateStruct<int>::method();
template <> SDK_ABI int TemplateStruct<int>::staticMethod();
template <> SDK_ABI int TemplateStruct<int>::value;

template <typename T> Key TemplateStruct<T>::key;

// explicit instantiations
extern template struct TemplateStruct<int>;
extern template struct TemplateStruct<float>;

} // namespace ExplicitTemplateInstantation

#pragma once

#include "Annotations.h"

namespace ExplicitTemplateInstantiation {

template <typename T>
struct SDK_ABI TemplateStruct {
  int method();
};

template <> int TemplateStruct<int>::method();
extern template struct TemplateStruct<int>;
extern template struct TemplateStruct<float>;

} // namespace ExplicitTemplateInstantation

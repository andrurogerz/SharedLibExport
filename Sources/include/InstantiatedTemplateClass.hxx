#pragma once

#include "Annotations.h"

template <typename T>
class TemplateClass {
public:
  T method(T a, T b);
};

// TemplateClass<unsigned> is explicitly instantiated in the source file
extern template class SDK_EXTERN TemplateClass<unsigned>;

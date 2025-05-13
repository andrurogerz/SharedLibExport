#include "ExplicitTemplateInstantiation.hxx"

namespace ExplicitTemplateInstantiation {

  template <typename T>
  int TemplateStruct<T>::method() {
    return 7;
  }

  template <>
  int TemplateStruct<int>::method() {
    return 9;
  }

  template struct SDK_EXPORT TemplateStruct<int>;
  template struct SDK_EXPORT TemplateStruct<float>;
}

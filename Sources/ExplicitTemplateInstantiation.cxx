#include "ExplicitTemplateInstantiation.hxx"

namespace ExplicitTemplateInstantiation {

  template <typename T>
  int TemplateStruct<T>::method() {
    return 2;
  }

  template <typename T>
  int TemplateStruct<T>::staticMethod() {
    return 3;
  }

  // specialized method
  template <>
  int TemplateStruct<int>::method() {
    return 9;
  }

  // specialized static method
  template <>
  int TemplateStruct<int>::staticMethod() {
    return 10;
  }

  // explicit instantiations
  template struct SDK_EXPORT TemplateStruct<int>;
  template struct SDK_EXPORT TemplateStruct<float>;
}

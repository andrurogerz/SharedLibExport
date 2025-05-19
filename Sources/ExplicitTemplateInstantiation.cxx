#include "ExplicitTemplateInstantiation.hxx"

namespace ExplicitTemplateInstantiation {

  template <typename T>
  int TemplateStruct<T>::method() {
    return value;
  }

  template <typename T>
  int TemplateStruct<T>::staticMethod() {
    return value;
  }

  template <typename T> int TemplateStruct<T>::value = 7;

  // specialized method
  template <>
  int TemplateStruct<int>::method() {
    return value;
  }

  // specialized static method
  template <>
  int TemplateStruct<int>::staticMethod() {
    return value;
  }

  // specialized static field
  template <> SDK_EXPORT int TemplateStruct<int>::value = 9;

  // explicit instantiations
  template struct SDK_EXPORT TemplateStruct<int>;
  template struct SDK_EXPORT TemplateStruct<float>;
}

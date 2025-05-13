#include "ExplicitTemplateInstantiation.hxx"

namespace ExplicitTemplateInstantiation {

  template <typename T>
  int TemplateStruct<T>::method() {
    return key;
  }

  template <typename T>
  int TemplateStruct<T>::staticMethod() {
    return key;
  }

  template <typename T> int TemplateStruct<T>::key = 7;

  // specialized method
  template <>
  int TemplateStruct<int>::method() {
    return key;
  }

  // specialized static method
  template <>
  int TemplateStruct<int>::staticMethod() {
    return key;
  }

  // specialized static field
  template <> SDK_EXPORT int TemplateStruct<int>::key = 9;

  template struct SDK_EXPORT TemplateStruct<int>;
  template struct SDK_EXPORT TemplateStruct<float>;
}

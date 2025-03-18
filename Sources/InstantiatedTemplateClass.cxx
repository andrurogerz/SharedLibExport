#include "InstantiatedTemplateClass.hxx"

template <typename T>
T TemplateClass<T>::method(T a, T b) {
  return a + b;
}

// Explicitly instantiate TemplateClass<unsigned>
template class SDK_EXPORT TemplateClass<unsigned>;

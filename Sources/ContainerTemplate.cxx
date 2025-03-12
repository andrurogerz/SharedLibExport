#include "ContainerTemplate.hxx"

template <typename T>
void ContainerTemplate<T>::doSomething() {}

template class SDK_EXPORT ContainerTemplate<std::size_t>;
template class SDK_EXPORT ContainerTemplate<std::string>;

#include "ContainerTemplate.hxx"

template <typename T>
void ContainerTemplate<T>::doSomething() {}

template class ContainerTemplate<std::size_t>;
template class ContainerTemplate<std::string>;

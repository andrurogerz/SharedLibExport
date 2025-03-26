#include "TemplateWithExternMethod.hxx"

template <typename T>
void doSomething(T arg) {
  return;
}

template SDK_ABI void doSomething(char);
template SDK_ABI void doSomething(long);
template SDK_ABI void doSomething(unsigned);

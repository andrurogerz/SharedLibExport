#include "TemplateWithSpecializedMethod.hxx"

namespace TemplateSpecialization {

template<>
unsigned TemplateStruct<unsigned>::method(unsigned a, unsigned b) {
  return a + b + 1;
}

template<>
int TemplateStruct<int>::method(int a, int b) {
  return a + b + 2;
}

}; // namespace TemplateSpecialization

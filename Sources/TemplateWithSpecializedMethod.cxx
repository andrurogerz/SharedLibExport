#include "TemplateWithSpecializedMethod.hxx"

namespace TemplateSpecialization {

template<>
int TemplateStruct<unsigned>::method(int a, int b) {
  return a + b + 1;
}

}; // namespace TemplateSpecialization

#include "SpecializedTemplateFunction.hxx"

namespace TemplateSpecialization {

template <> unsigned method(unsigned a, unsigned b) {
  return a + b + 1;
}

}; // namespace TemplateSpecialization

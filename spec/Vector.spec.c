#include "Vector.spec.h"

spec_suite({
  T_vector_base();
  T_vector_dup();
  T_vector_functional_functions();
});

int main(void) {
  run_spec_suite("all");
};

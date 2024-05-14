#include "vector_base/vector_base.module.h"
#include "vector_dup/vector_dup.module.h"
#include "vector_functional_functions/vector_functional_functions.module.h"
#include "vector_push_pop_peek/vector_push_pop_peek.module.h"

spec_suite({
  T_vector_base();
  T_vector_dup();
  T_vector_functional_functions();
  T_vector_push_pop_peek();
});

int main(void) { run_spec_suite("all"); }

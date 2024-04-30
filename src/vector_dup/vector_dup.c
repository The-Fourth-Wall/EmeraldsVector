#include "vector_dup.h"

#include "../vector_base/vector_base.h"

vector *vector_dup(vector *self) {
  vector *dup = NULL;
  size_t i;
  size_t vlen;

  if(self == NULL) {
    return NULL;
  }

  dup = vector_new();

  /* Iteratively copy the vector items from one memory location to another */
  vlen = vector_length(self);
  for(i = 0; i < vlen; i++) {
    vector_add(dup, vector_get(self, i));
  }

  return dup;
}

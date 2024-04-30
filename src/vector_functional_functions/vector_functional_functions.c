#include "vector_functional_functions.h"

#include "../vector_base/vector_base.h"

vector *vector_map(vector *self, vector_lambda1 modifier) {
  vector *dup = NULL;
  size_t i;
  size_t vlen;

  if(self == NULL || modifier == NULL) {
    return NULL;
  }

  dup = vector_new();

  vlen = vector_length(self);
  for(i = 0; i < vlen; i++) {
    /* Pass each element through the modifier and add it to the new vector */
    vector_add(dup, modifier(vector_get(self, i)));
  }

  vector_free(self);

  return dup;
}

vector *vector_filter(vector *self, vector_lambda1 filter) {
  vector *dup = NULL;
  size_t i;

  if(self == NULL || filter == NULL) {
    return NULL;
  }

  dup = vector_new();

  for(i = 0; i < vector_length(self); i++) {
    void *item = vector_get(self, i);
    /* If the item passes the filter it gets added to the dup vector */
    if(!filter(item)) {
      vector_add(dup, item);
    }
  }

  vector_free(self);

  return dup;
}

vector *vector_select(vector *self, vector_lambda1 selector) {
  vector *dup = NULL;
  size_t i;

  if(self == NULL || selector == NULL) {
    return NULL;
  }

  dup = vector_new();

  for(i = 0; i < vector_length(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup vector */
    if(selector(item)) {
      vector_add(dup, item);
    }
  }

  vector_free(self);

  return dup;
}

void *vector_reduce(vector *self, vector_lambda2 fold) {
  void *accumulator = NULL;
  size_t i;
  size_t vlen;

  if(self == NULL || fold == NULL) {
    return NULL;
  }

  /* Get the initial value that gets returned
      with the accumulation of the vector elements */
  accumulator = vector_get(self, 0);

  vlen = vector_length(self);
  for(i = 1; i < vlen; i++) {
    /* Accumulate the current item */
    void *current = vector_get(self, i);
    accumulator   = fold(accumulator, current);
  }

  return accumulator;
}

bool vector_all(vector *self, vector_lambda1 checker) {
  size_t i;

  if(self == NULL || checker == NULL || vector_length(self) == 0) {
    return false;
  }

  for(i = 0; i < vector_length(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup vector */
    if(!checker(item)) {
      return false;
    }
  }

  return true;
}

bool vector_any(vector *self, vector_lambda1 checker) {
  size_t i;

  if(self == NULL || checker == NULL) {
    return false;
  }

  for(i = 0; i < vector_length(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup vector */
    if(checker(item)) {
      return true;
    }
  }

  return false;
}

bool vector_none(vector *self, vector_lambda1 checker) {
  size_t i;

  if(self == NULL || checker == NULL) {
    return false;
  }

  for(i = 0; i < vector_length(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup vector */
    if(checker(item)) {
      return false;
    }
  }

  return true;
}

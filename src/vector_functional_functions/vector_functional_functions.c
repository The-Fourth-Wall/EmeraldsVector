#include "vector_functional_functions.h"

#include "../vector_base/vector_base.h"

EmeraldsVector *
vector_map(EmeraldsVector *self, EmeraldsVectorLambda1 modifier) {
  EmeraldsVector *dup = NULL;
  size_t i;
  size_t vlen;

  if(self == NULL || modifier == NULL) {
    return NULL;
  }

  dup = vector_new_empty();

  vlen = vector_size(self);
  for(i = 0; i < vlen; i++) {
    /* Pass each element through the modifier and add it to the new
     * EmeraldsVector */
    vector_add(dup, modifier(vector_get(self, i)));
  }

  vector_free(self);

  return dup;
}

EmeraldsVector *
vector_filter(EmeraldsVector *self, EmeraldsVectorLambda1 filter) {
  EmeraldsVector *dup = NULL;
  size_t i;

  if(self == NULL || filter == NULL) {
    return NULL;
  }

  dup = vector_new_empty();

  for(i = 0; i < vector_size(self); i++) {
    void *item = vector_get(self, i);
    /* If the item passes the filter it gets added to the dup EmeraldsVector */
    if(!filter(item)) {
      vector_add(dup, item);
    }
  }

  vector_free(self);

  return dup;
}

EmeraldsVector *
vector_select(EmeraldsVector *self, EmeraldsVectorLambda1 selector) {
  EmeraldsVector *dup = NULL;
  size_t i;

  if(self == NULL || selector == NULL) {
    return NULL;
  }

  dup = vector_new_empty();

  for(i = 0; i < vector_size(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup EmeraldsVector */
    if(selector(item)) {
      vector_add(dup, item);
    }
  }

  vector_free(self);

  return dup;
}

void *vector_reduce(EmeraldsVector *self, EmeraldsVectorLambda2 fold) {
  void *accumulator = NULL;
  size_t i;
  size_t vlen;

  if(self == NULL || fold == NULL) {
    return NULL;
  }

  /* Get the initial value that gets returned
      with the accumulation of the vector elements */
  accumulator = vector_get(self, 0);

  vlen = vector_size(self);
  for(i = 1; i < vlen; i++) {
    /* Accumulate the current item */
    void *current = vector_get(self, i);
    accumulator   = fold(accumulator, current);
  }

  return accumulator;
}

bool vector_all(EmeraldsVector *self, EmeraldsVectorLambda1 checker) {
  size_t i;

  if(self == NULL || checker == NULL || vector_size(self) == 0) {
    return false;
  }

  for(i = 0; i < vector_size(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup EmeraldsVector */
    if(!checker(item)) {
      return false;
    }
  }

  return true;
}

bool vector_any(EmeraldsVector *self, EmeraldsVectorLambda1 checker) {
  size_t i;

  if(self == NULL || checker == NULL) {
    return false;
  }

  for(i = 0; i < vector_size(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup EmeraldsVector */
    if(checker(item)) {
      return true;
    }
  }

  return false;
}

bool vector_none(EmeraldsVector *self, EmeraldsVectorLambda1 checker) {
  size_t i;

  if(self == NULL || checker == NULL) {
    return false;
  }

  for(i = 0; i < vector_size(self); i++) {
    void *item = vector_get(self, i);
    /* If the item gets selected it gets added to the dup EmeraldsVector */
    if(checker(item)) {
      return false;
    }
  }

  return true;
}

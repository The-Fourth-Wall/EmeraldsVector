#include "vector_base.h"

#define GOLDEN_MEAN 1.618

/**
 * @func: vector_ensure_space
 * @desc: Ensure there is enough space for our values in the vector
 * @param self -> The vector to use
 * @param capacity -> The new capacity to set
 **/
static void vector_ensure_space(vector *self, size_t capacity) {
  void **items = NULL;

  if(self == NULL || capacity == 0) {
    return;
  }

  /* Attempt to reallocate new memory in the items list */
  items = realloc(self->items, sizeof(void *) * capacity);

  if(items) {
    /* Reset the items in the new memory space */
    self->items   = items;
    self->alloced = capacity;
  }
}

vector *vector_new(void) {
  vector *self  = (vector *)malloc(sizeof(vector));
  self->alloced = vector_init_capacity;
  self->size    = 0;
  self->items   = (void **)malloc(sizeof(void *) * self->alloced);
  return self;
}

vector *vector_add(vector *self, void *item) {
  /* TODO We allow NULL elements (NOT TESTED) */
  if(self == NULL) {
    return self;
  }
  if(self->alloced == self->size) {
    vector_ensure_space(self, self->alloced * GOLDEN_MEAN);
  }
  self->items[self->size++] = item;

  return self;
}

vector *vector_set(vector *self, size_t index, void *item) {
  if(self == NULL) {
    return self;
  }
  if(index < self->size) {
    self->items[index] = item;
  }

  return self;
}

void *vector_get(vector *self, size_t index) {
  if(self == NULL) {
    return NULL;
  }
  if(index < self->size) {
    return self->items[index];
  }

  /* TODO -> FIX NULLITY */
  return NULL;
}

vector *vector_delete(vector *self, size_t index) {
  size_t i;
  size_t vlen;

  if(self == NULL) {
    return self;
  }
  if(index >= self->size) {
    return self;
  }

  self->items[index] = NULL;

  /* Reset the rest of the elements forwards */
  vlen = vector_length(self);
  for(i = index; i < vlen - 1; i++) {
    self->items[i]     = self->items[i + 1];
    self->items[i + 1] = NULL;
  }

  self->size--;

  if(self->size > 0 && self->size == self->alloced / 4) {
    vector_ensure_space(self, self->alloced / GOLDEN_MEAN);
  }

  return self;
}

size_t vector_length(vector *self) {
  if(self == NULL) {
    return 0;
  }
  return self->size;
}

void vector_free(vector *self) {
  /* TODO -> IMPLEMENT A CUSTOM FREE METHOD FOR ARRAY ELEMENTS */
  if(self != NULL && self->items != NULL) {
    free(self->items);
  }
  if(self != NULL) {
    free(self);
  }
}

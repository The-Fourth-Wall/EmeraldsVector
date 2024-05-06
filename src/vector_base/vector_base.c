#include "vector_base.h"

#define GOLDEN_MEAN 1.618

/**
 * @brief Ensure there is enough space for our values in the vector
 * @param self -> The vector to use
 * @param capacity -> The new capacity to set
 **/
static void vector_ensure_space(EmeraldsVector *self, size_t capacity) {
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

EmeraldsVector *vector_new(void) {
  EmeraldsVector *self = (EmeraldsVector *)malloc(sizeof(EmeraldsVector));
  self->alloced        = vector_init_capacity;
  self->size           = 0;
  self->items          = (void **)malloc(sizeof(void *) * self->alloced);
  return self;
}

EmeraldsVector *vector_add(EmeraldsVector *self, void *item) {
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

EmeraldsVector *vector_set(EmeraldsVector *self, size_t index, void *item) {
  if(self == NULL) {
    return self;
  }
  if(index < self->size) {
    self->items[index] = item;
  }

  return self;
}

void *vector_get(EmeraldsVector *self, size_t index) {
  if(self == NULL) {
    return NULL;
  }
  if(index < self->size) {
    return self->items[index];
  }

  /* TODO -> FIX NULLITY */
  return NULL;
}

EmeraldsVector *vector_delete(EmeraldsVector *self, size_t index) {
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

size_t vector_length(EmeraldsVector *self) {
  if(self == NULL) {
    return 0;
  }
  return self->size;
}

void vector_free(EmeraldsVector *self) {
  /* TODO -> IMPLEMENT A CUSTOM FREE METHOD FOR ARRAY ELEMENTS */
  if(self != NULL && self->items != NULL) {
    free(self->items);
  }
  if(self != NULL) {
    free(self);
  }
}

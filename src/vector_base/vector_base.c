#include "vector_base.h"

#include "../../libs/EmeraldsPreprocessor/export/EmeraldsPreprocessor.h"

#include <stdio.h>

#if PREPROCESSOR_C_VERSION >= 1999
  /**
   * @brief: Initializes a vector data structure
   * @param type -> The type for the initialization of the vector
   * @param name -> The name of the function to create
   * @return: The newly created vector
   */
  #define _vector_new(self, type, cast_type, argc)         \
    do {                                                   \
      va_list vars;                                        \
      va_start(vars, argc)                                 \
        ;                                                  \
        for(size_t i = 0; i < argc; i++) {                 \
          vector_add(self, (type)va_arg(vars, cast_type)); \
        }                                                  \
      va_end(vars);                                        \
    } while(0)

char *_vector_char_new(size_t argc, ...) {
  char *self = NULL;
  _vector_new(self, char, int, argc);
  return self;
}
void **_vector_voidptr_new(size_t argc, ...) {
  void **self = NULL;
  _vector_new(self, void *, void *, argc);
  return self;
}
char **_vector_charptr_new(size_t argc, ...) {
  char **self = NULL;
  _vector_new(self, char *, char *, argc);
  return self;
}
int *_vector_int_new(size_t argc, ...) {
  int *self = NULL;
  _vector_new(self, int, int, argc);
  return self;
}
long *_vector_long_new(size_t argc, ...) {
  long *self = NULL;
  _vector_new(self, long, long, argc);
  return self;
}

#endif

void *
_vector_growf(void *self, size_t elemsize, size_t addlen, size_t min_cap) {
  void *b;
  size_t min_len = vector_size(self) + addlen;

  if(min_len > min_cap) {
    min_cap = min_len;
  }

  if(min_cap <= vector_capacity(self)) {
    return self;
  }

  if(min_cap < 2 * vector_capacity(self)) {
    min_cap = 2 * vector_capacity(self);
  } else if(min_cap < 4) {
    min_cap = 4;
  }

  b = vector_allocator(
    (self) ? _vector_get_header(self) : 0,
    elemsize * min_cap + sizeof(_vector_header)
  );
  b = (char *)b + sizeof(_vector_header);

  if(self == NULL) {
    _vector_get_header(b)->size = 0;
  }

  _vector_get_header(b)->capacity = min_cap;

  return b;
}

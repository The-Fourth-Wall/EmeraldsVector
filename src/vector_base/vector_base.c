#include "vector_base.h"

/**
 * @brief: Initializes a vector data structure
 * @param type -> The type for the initialization of the vector
 * @param name -> The name of the function to create
 * @return: The newly created vector
 */
#define _vector_new(self, type, cast_type)               \
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
  _vector_new(self, char, int);
  return self;
}
void **_vector_voidptr_new(size_t argc, ...) {
  void **self = NULL;
  _vector_new(self, void *, void *);
  return self;
}
char **_vector_charptr_new(size_t argc, ...) {
  char **self = NULL;
  _vector_new(self, char *, char *);
  return self;
}
int *_vector_int_new(size_t argc, ...) {
  int *self = NULL;
  _vector_new(self, int, int);
  return self;
}
long *_vector_long_new(size_t argc, ...) {
  long *self = NULL;
  _vector_new(self, long, long);
  return self;
}

#ifndef __EMERALDS_VECTOR_BASE_H_
#define __EMERALDS_VECTOR_BASE_H_

#include "../../libs/EmeraldsPreprocessor/export/EmeraldsPreprocessor.h"

#include <stdarg.h> /* va_list, va_arg, va_start, va_end */
#include <stddef.h> /* ptrdiff_t */
#include <stdlib.h> /* NULL, realloc */
#include <string.h> /* memmove, memset */

/**
 * @brief Metadata for a vector.  Stores the size and capacity
 * of the vector one byte before the vector data
 * @param size -> The number of elements in the vector
 * @param capacity -> The current capacity in bytes (number of elements *
 * sizeof(type))
 */
typedef struct {
  size_t size;
  size_t capacity;
} _vector_header;

/**
 * @brief Calculates the header of a vector
 * @param self -> The vector pointer
 * @return The header of the vector
 */
#define _vector_get_header(self) ((_vector_header *)(self) - 1)

/**
 * @brief Grabs the sizeof the vector element by dereferencing the pointer
 * @param self -> The vector pointer
 * @return The sizeof the vector element
 */
#define _vector_selfptr_size(self) sizeof(*(self)) // NOLINT

/**
 * @brief A grow function that grows the vector by a given number of elements.
 * Is using the address of self and casting it to a void** and then
 * dereferencing it, a trick to treat all types as raw memory in a type-safe
 * manner.
 * @param self -> The vector pointer
 * @param n -> The number of elements to grow the vector by
 * @return The new pointer to the vector
 */
#define _vector_grow(self, n) \
  (*(void **)&(self) =        \
     _vector_growf((self), _vector_selfptr_size(self), (n), 0))

/**
 * @brief Decides whether to grow the vector or not based on the current
 * capacity
 * @param self -> The vector pointer
 * @param n -> The number of elements to grow the vector by
 * @return The new pointer to the vector
 */
#define _vector_maybegrow(self, n)                                             \
  ((!(self) ||                                                                 \
    _vector_get_header(self)->size + (n) > _vector_get_header(self)->capacity) \
     ? (_vector_grow(self, n), 0)                                              \
     : 0)

// TODO - Add an allocator struct that can be generic for use
// TODO - Potentially adding a GC in the custom allocator
/** @brief Custom allocator.  Can be overridden by user before including */
#ifndef vector_allocator
  #define vector_allocator realloc
#endif

#define vector_initialize(self) \
  do {                          \
    (self) = NULL;              \
    _vector_maybegrow(self, 1); \
  } while(0)

/**
 * @brief Initializes a vector with a given size
 * @param v -> The vector to initialize
 * @param n -> The size of the vector
 */
#define vector_initialize_n(v, n)         \
  do {                                    \
    (v) = NULL;                           \
    _vector_maybegrow(v, n);              \
    _vector_get_header(v)->size = (n);    \
    memset((v), 0, (n) * sizeof((v)[0])); \
  } while(0)

/**
 * @brief Creates a new vector and initializes it with the given arguments.
 * Using generic to have type-safe interaction for defined types of vectors.
 * We add a void* value as an extra argument to the variadics to allow for a
 * potential of a vector with 1 element.  In any case vector_new should be typed
 * and initialized properly by recognizing the first argument for the generic
 * choice.  Since its all macros it is possible to have any type even if
 * __VA_ARGS__ do not contain void*.
 * @param ... -> Initialization arguments
 * @return: The newly created vector
 */
#define _vector_get_first_arg(first, ...) (first)
#define vector_new(...)                                                                                                                                                                                                                                     \
  _Generic(_vector_get_first_arg(__VA_ARGS__, (void *)0), void *: _vector_voidptr_new, char *: _vector_charptr_new, const char *: _vector_charptr_new, int: _vector_int_new, char: _vector_char_new, long: _vector_long_new, default: _vector_voidptr_new)( \
    PREPROCESSOR_EXPANSIONS_NUMBER_OF_ELEMENTS(__VA_ARGS__), __VA_ARGS__                                                                                                                                                                                    \
  )

/**
 * @brief Adds a new element in the vector
 * @param self -> The vector to use
 * @param item -> The item to add
 **/
#define vector_add(self, item) \
  (_vector_maybegrow(self, 1), \
   (self)[_vector_get_header(self)->size++] = (item))

/**
 * @brief Adds a larger element in the vector
 * @param self -> The vector to use
 * @param item -> The item to add (usually byte sized like char*)
 * @param n -> The number with which to extend size
 */
#define vector_add_n(self, item, n)                 \
  ((item) != NULL ? _vector_maybegrow(self, n),     \
   memmove(                                         \
     (self) + vector_size(self),                    \
     (item),                                        \
     (n) * ((item) != NULL ? sizeof((self)[0]) : 0) \
   ),                                               \
   _vector_get_header(self)->size += (n)            \
                  : 0)

/**
 * @brief Adds a vector to the end of the vector
 * @param self -> The vector to use
 * @param item -> The vector to add
 */
#define vector_add_vector(self, item) \
  vector_add_n(self, item, vector_size(item))

/**
 * @brief Delete a multiple values from the vector
 * @param self -> The vector to use
 * @param index -> The index to start
 * @param n -> The number of elements to delete
 **/
#define vector_remove_n(self, index, number_of_elements)                 \
  (memmove(                                                              \
     &(self)[(index)],                                                   \
     &(self)[(index) + (number_of_elements)],                            \
     _vector_selfptr_size(self) *                                        \
       (_vector_get_header(self)->size - (number_of_elements) - (index)) \
   ),                                                                    \
   _vector_get_header(self)->size -= (number_of_elements))

/**
 * @brief Delete a specific vector value by index
 * @param self -> The vector to use
 * @param index -> The index to delete
 **/
#define vector_remove(self, index) vector_remove_n(self, index, 1)

/**
 * @brief Deletes the last element of the vector
 * @param self -> The vector to use
 **/
#define vector_remove_last(self) vector_remove((self), vector_size(self) - 1)

/**
 * @brief Finds the last element of the vector
 * @param self -> The vector to use
 */
#define vector_last(self) ((self)[_vector_get_header(self)->size - 1])

/**
 * @brief Checks if the vector is empty
 * @param self -> The vector to check
 * @return: true if the vector is empty, false otherwise
 */
#define vector_is_empty(self) (vector_size(self) == 0)

/**
 * @brief Get the total number of values inserted in the vector
 * @param self -> The vector to use
 * @return: The number of items in the vector
 **/
#define vector_size(self) ((self) ? (size_t)_vector_get_header(self)->size : 0)

/**
 * @brief Same as vector_size but returns a signed value
 * @param self -> The vector to use
 * @return: The number of items in the vector
 */
#define vector_size_signed(self) \
  ((self) ? (ptrdiff_t)_vector_get_header(self)->size : 0)

/**
 * @brief Gets the current total capacity of the vector
 * @param self -> The vector pointer
 * @return The capacity of the vector or 0 if the vector is NULL
 */
#define vector_capacity(self) \
  ((self) ? (size_t)_vector_get_header(self)->capacity : 0)

/**
 * @brief Same as vector_capacity but returns a signed value
 * @param self -> The vector pointer
 * @return The capacity of the vector or 0 if the vector is NULL
 */
#define vector_capacity_signed(self) \
  ((self) ? (ptrdiff_t)_vector_get_header(self)->capacity : 0)

/**
 * @brief Frees the memory of the vector
 * @param self -> The vector to free
 */
#define vector_free(self)                                              \
  ((void)((self) ? vector_allocator(_vector_get_header(self), 0) : 0), \
   (self) = NULL)

static void *
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

char *_vector_char_new(size_t argc, ...);
void **_vector_voidptr_new(size_t argc, ...);
char **_vector_charptr_new(size_t argc, ...);
int *_vector_int_new(size_t argc, ...);
long *_vector_long_new(size_t argc, ...);

#endif

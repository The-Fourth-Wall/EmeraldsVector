#ifndef __EMERALDS_VECTOR_FUNCTIONAL_FUNCTIONS_H_
#define __EMERALDS_VECTOR_FUNCTIONAL_FUNCTIONS_H_

#include "../vector_base/vector_base.h"

/**
 * @brief Maps all vector elements in iteration using a modifier function
 *pointer
 * @param self -> The vector to map
 * @param dup -> The new vector to map to
 * @param modifier -> The modifier function
 **/
#define vector_map(self, dup, modifier)                      \
  do {                                                       \
    size_t vlen = vector_size(self);                         \
    if((void *)(self) == (void *)(dup)) {                    \
      for(size_t i = 0; i < vlen; i++) {                     \
        vector_set((dup), i, modifier(vector_get(self, i))); \
      }                                                      \
    } else {                                                 \
      for(size_t i = 0; i < vlen; i++) {                     \
        vector_add((dup), modifier(vector_get(self, i)));    \
      }                                                      \
    }                                                        \
  } while(0)

/**
 * @brief Filters all vector elements in iteration using a filter function
 * @param self -> The vector to filter
 * @param dup -> The new vector to store results
 * @param filter -> The filter function
 **/
#define vector_filter(self, dup, filter)              \
  do {                                                \
    size_t vlen = vector_size(self);                  \
    if((void *)(self) == (void *)(dup)) {             \
      for(size_t i = 0; i < vector_size(self); i++) { \
        if(filter(vector_get(self, i))) {             \
          vector_remove((dup), i);                    \
          i--;                                        \
        }                                             \
      }                                               \
    } else {                                          \
      for(size_t i = 0; i < vlen; i++) {              \
        if(!filter(vector_get(self, i))) {            \
          vector_add((dup), vector_get(self, i));     \
        }                                             \
      }                                               \
    }                                                 \
  } while(0)

/**
 * @brief Selects vector elements according to a selector lambda
 * @param self -> The vector to select from
 * @param dup -> The new vector to store results
 * @param selector -> The selector function
 */
#define vector_select(self, dup, selector) vector_filter(self, dup, !selector)

/**
 * @brief Recudes all vector elements into a void* result using a foldl function
 * @param self -> The vector to reduce
 * @param fold -> The folding function to use
 * @param res -> The result pointer
 **/
#define vector_reduce(self, fold, res)        \
  do {                                        \
    *res        = vector_get(self, 0);        \
    size_t vlen = vector_size(self);          \
    for(size_t i = 1; i < vlen; i++) {        \
      *res = fold(*res, vector_get(self, i)); \
    }                                         \
  } while(0)

#endif

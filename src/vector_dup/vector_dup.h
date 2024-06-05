#ifndef __EMERALDS_VECTOR_DUP_H_
#define __EMERALDS_VECTOR_DUP_H_

#include "../vector_base/vector_base.h"

/**
 * @brief Get a memory duplicate of the passed vector
 * @param self -> The vector to use
 * @param dup -> The vector to duplicate to
 **/
#define vector_dup(self, dup)                 \
  do {                                        \
    size_t vlen = vector_size(self);          \
    for(size_t i = 0; i < vlen; i++) {        \
      vector_add((dup), vector_get(self, i)); \
    }                                         \
  } while(0)

#endif

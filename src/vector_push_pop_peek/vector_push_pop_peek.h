#ifndef __EMERALDS_VECTOR_PUSH_POP_PEEK_H_
#define __EMERALDS_VECTOR_PUSH_POP_PEEK_H_

#include "../vector_base/vector_base.h"

/** @brief Pushes an element to the end of the vector (alias for vector_add) */
#define vector_push vector_add

/**
 * @brief Pops from the end of the vector
 * @param self -> vector
 * @return The last element of the vector
 */
#define vector_pop(self) \
  (_vector_get_header(self)->size--, (self)[_vector_get_header(self)->size])

/**
 * @brief Peeks at the last element of the vector without removing it
 * @param self -> vector
 * @return The last element of the vector
 */
#define vector_peek(self) (self)[_vector_get_header(self)->size - 1]

#endif

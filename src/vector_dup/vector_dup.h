#ifndef __EMERALDS_VECTOR_DUP_H_
#define __EMERALDS_VECTOR_DUP_H_

#include "../vector_base/vector_base.h"

/**
 * @brief Get a memory duplicate of the passed vector
 * @param self -> The vector to use
 * @return The duplicate vector
 **/
EmeraldsVector *vector_dup(EmeraldsVector *self);

#endif

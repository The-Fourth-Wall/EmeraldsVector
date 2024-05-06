#ifndef __EMERALDS_VECTOR_BASE_H_
#define __EMERALDS_VECTOR_BASE_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */

/* Initial capacity of a vector */
static const size_t vector_init_capacity = 32;

/**
 * @brief Defines a vector data structure
 * @param items -> A void pointer array that contains the heterogenous elements
 *of the vector
 * @param alloced -> The total capacity of the vector
 * @param size -> The total number of values
 **/
typedef struct EmeraldsVector {
  /* TODO -> USE A TYPED UNION INSTEAD OF VOID POINTERS */
  void **items;
  size_t alloced;
  size_t size;
} EmeraldsVector;

/**
 * @brief Initializes a vector data structure
 * @return: The newly created vector
 **/
EmeraldsVector *vector_new(void);

/**
 * @brief Adds a new element in the vector
 * @param v -> The vector to use
 * @param item -> The item to add
 * @return The modified vector
 **/
EmeraldsVector *vector_add(EmeraldsVector *self, void *item);

/**
 * @brief Set the value of a specific vector index to a new one
 * @param self-> The vector
 * @param index -> The index to set the value of
 * @param item -> The item to set the value as
 * @return The modified vector
 **/
EmeraldsVector *vector_set(EmeraldsVector *self, size_t index, void *item);

/**
 * @brief Get the value of a specific vector index
 * @param self -> The vector to use
 * @param index -> The index to get the value of
 * @return The value
 **/
void *vector_get(EmeraldsVector *self, size_t index);

/**
 * @brief Delete a specific vector value by index
 * @param self -> The vector to use
 * @param index -> The index to delete
 * @return The modified vector
 **/
EmeraldsVector *vector_delete(EmeraldsVector *self, size_t index);

/**
 * @brief Get the total number of values inserted in the vector
 * @param self -> The vector to use
 * @return: The number of items in the vector
 **/
size_t vector_length(EmeraldsVector *self);

/**
 * @brief Frees the memory of the vector
 * @param self -> The vector to free
 */
void vector_free(EmeraldsVector *self);

#endif

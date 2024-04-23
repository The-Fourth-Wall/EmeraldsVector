#ifndef __VECTOR_FUNCTIONAL_FUNCTIONS_H_
#define __VECTOR_FUNCTIONAL_FUNCTIONS_H_

#include "../../../libs/Bool/Bool.h"
#include "vector_base.h"

/**
 * @func: vector_lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void* (*vector_lambda0)(void);
typedef void* (*vector_lambda1)(void*);
typedef void* (*vector_lambda2)(void*, void*);

/**
 * @func: vector_map
 * @desc: Maps all vector elements in iteration using a modifier function pointer
 * @param v -> The vector to map
 * @param modifier -> The modifier function
 * @return The mapped vector duplicate
 **/
vector *vector_map(vector *self, vector_lambda1 modifier);

/**
 * @func: vector_filter
 * @desc: Filters all vector elements in iteration using a filter function
 * @param v -> The vector to filter
 * @param filter -> The filter function
 * @return The filtered vector duplicate
 **/
vector *vector_filter(vector *self, vector_lambda1 filter);

/**
 * @func: vector_select
 * @brief Selects vector elements according to a selector lambda
 * @param v -> The vector to select from
 * @param selector -> The selector function
 * @return vector* -> The filtered vector duplicate
 */
vector *vector_select(vector *self, vector_lambda1 selector);

/**
 * @func: vector_reduce
 * @desc: Recudes all vector elements into a void* result using a foldl function
 * @param v -> The vector to reduce
 * @param fold -> The folding function to use
 * @return The folder void* result
 **/
void *vector_reduce(vector *self, vector_lambda2 fold);

/**
 * @func: vector_all
 * @brief Checks if all elements pass through a checker function conditional
 * @param v -> The vector to check
 * @param checker -> The checker function
 * @return bool -> true if all elements pass, else false
 */
bool vector_all(vector *self, vector_lambda1 checker);

/**
 * @func: vector_any
 * @brief Checks if any of the elements pass through a checker function
 * @param v -> The vector to check
 * @param checker -> The checker function
 * @return bool -> true if at least one of the elements pass, else false
 */
bool vector_any(vector *self, vector_lambda1 checker);

/**
 * @func: vector_none
 * @brief Checks if none of the elementrs pass through a checker function
 * @param v -> The vector to check
 * @param checker -> The checker function
 * @return bool -> true if none of the elements pass, else false
 */
bool vector_none(vector *self, vector_lambda1 checker);

#endif

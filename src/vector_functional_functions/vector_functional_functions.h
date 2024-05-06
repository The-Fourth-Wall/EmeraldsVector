#ifndef __EMERALDS_VECTOR_FUNCTIONAL_FUNCTIONS_H_
#define __EMERALDS_VECTOR_FUNCTIONAL_FUNCTIONS_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"
#include "../vector_base/vector_base.h"

/**
 * @brief A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort
 */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void *(*EmeraldsVectorLambda0)(void);
typedef void *(*EmeraldsVectorLambda1)(void *);
typedef void *(*EmeraldsVectorLambda2)(void *, void *);

/**
 * @brief Maps all vector elements in iteration using a modifier function
 *pointer
 * @param v -> The vector to map
 * @param modifier -> The modifier function
 * @return The mapped vector duplicate
 **/
EmeraldsVector *
vector_map(EmeraldsVector *self, EmeraldsVectorLambda1 modifier);

/**
 * @brief Filters all vector elements in iteration using a filter function
 * @param v -> The vector to filter
 * @param filter -> The filter function
 * @return The filtered vector duplicate
 **/
EmeraldsVector *
vector_filter(EmeraldsVector *self, EmeraldsVectorLambda1 filter);

/**
 * @brief Selects vector elements according to a selector lambda
 * @param v -> The vector to select from
 * @param selector -> The selector function
 * @return vector* -> The filtered vector duplicate
 */
EmeraldsVector *
vector_select(EmeraldsVector *self, EmeraldsVectorLambda1 selector);

/**
 * @brief Recudes all vector elements into a void* result using a foldl function
 * @param v -> The vector to reduce
 * @param fold -> The folding function to use
 * @return The folder void* result
 **/
void *vector_reduce(EmeraldsVector *self, EmeraldsVectorLambda2 fold);

/**
 * @brief Checks if all elements pass through a checker function conditional
 * @param v -> The vector to check
 * @param checker -> The checker function
 * @return bool -> true if all elements pass, else false
 */
bool vector_all(EmeraldsVector *self, EmeraldsVectorLambda1 checker);

/**
 * @brief Checks if any of the elements pass through a checker function
 * @param v -> The vector to check
 * @param checker -> The checker function
 * @return bool -> true if at least one of the elements pass, else false
 */
bool vector_any(EmeraldsVector *self, EmeraldsVectorLambda1 checker);

/**
 * @brief Checks if none of the elementrs pass through a checker function
 * @param v -> The vector to check
 * @param checker -> The checker function
 * @return bool -> true if none of the elements pass, else false
 */
bool vector_none(EmeraldsVector *self, EmeraldsVectorLambda1 checker);

#endif

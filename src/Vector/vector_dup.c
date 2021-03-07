#include "headers/vector_dup.h"

vector *vector_dup(vector *v) {
    vector *dup = NULL;
    size_t i;
    
    if(v == NULL) return NULL;

    dup = vector_new();
    
    /* Iteratively copy the vector items from one memory location to another */
    for(i = 0; i < vector_length(v); i++)
        vector_add(dup, vector_get(v, i));

    return dup;
}

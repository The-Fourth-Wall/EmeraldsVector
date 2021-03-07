#include "headers/vector_dup.h"
#include "headers/vector_base.h"

vector *vector_dup(vector *v) {
    vector *dup = NULL;
    size_t i;
    size_t vlen;
    
    if(v == NULL) return NULL;

    dup = vector_new();
    
    /* Iteratively copy the vector items from one memory location to another */
    vlen = vector_length(v);
    for(i = 0; i < vlen; i++)
        vector_add(dup, vector_get(v, i));

    return dup;
}

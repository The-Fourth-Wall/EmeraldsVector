#include "headers/vector_functional_functions.h"

vector *vector_map(vector *v, vector_lambda modifier) {
    vector *dup = NULL;
    size_t i;

    if(v == NULL || modifier == NULL) return NULL;

    dup = vector_new();

    for(i = 0; i < vector_length(v); i++) {
        /* Pass each element through the modifier and add it to the new vector */
        vector_add(dup, modifier(vector_get(v, i)));
    }

    return dup;
}

vector *vector_filter(vector *v, vector_lambda filter) {
    vector *dup = NULL;
    size_t i;
    
    if(v == NULL || filter == NULL) return NULL;

    dup = vector_new();

    for(i = 0; i < vector_length(v); i++) {
        void *item = vector_get(v, i);
        /* If the item passes the filter it gets added to the dup vector */
        if(filter(item))
            vector_add(dup, item);
    }

    return dup;
}

void *vector_reduce(vector *v, vector_lambda fold) {
    void *accumulator = NULL;
    size_t i;
    if(v == NULL || fold == NULL) return NULL;

    /* Get the initial value that gets returned
        with the accumulation of the vector elements */
    accumulator = vector_get(v, 0);

    for(i = 1; i < vector_length(v); i++) {
        /* Accumulate the current item */
        void *current = vector_get(v, i);
        accumulator = fold(accumulator, current);
    }
    
    return accumulator;
}

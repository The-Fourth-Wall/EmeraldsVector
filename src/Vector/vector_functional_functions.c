#include "headers/vector_functional_functions.h"
#include "headers/vector_base.h"

vector *vector_map(vector *v, vector_lambda modifier) {
    vector *dup = NULL;
    size_t i;
    size_t vlen;

    if(v == NULL || modifier == NULL) return NULL;

    dup = vector_new();

    vlen = vector_length(v);
    for(i = 0; i < vlen; i++) {
        /* Pass each element through the modifier and add it to the new vector */
        vector_add(dup, modifier(vector_get(v, i)));
    }

    vector_free(v);

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
        if(!filter(item))
            vector_add(dup, item);
    }

    vector_free(v);

    return dup;
}

vector *vector_select(vector *v, vector_lambda selector) {
    vector *dup = NULL;
    size_t i;

    if(v == NULL || selector == NULL) return NULL;

    dup = vector_new();

    for(i = 0; i < vector_length(v); i++) {
        void *item = vector_get(v, i);
        /* If the item gets selected it gets added to the dup vector */
        if(selector(item))
            vector_add(dup, item);
    }

    vector_free(v);

    return dup;
}

void *vector_reduce(vector *v, vector_lambda fold) {
    void *accumulator = NULL;
    size_t i;
    size_t vlen;

    if(v == NULL || fold == NULL) return NULL;

    /* Get the initial value that gets returned
        with the accumulation of the vector elements */
    accumulator = vector_get(v, 0);

    vlen = vector_length(v);
    for(i = 1; i < vlen; i++) {
        /* Accumulate the current item */
        void *current = vector_get(v, i);
        accumulator = fold(accumulator, current);
    }

    return accumulator;
}

bool vector_all(vector *v, vector_lambda checker) {
    size_t i;

    if(v == NULL || checker == NULL || vector_length(v) == 0)
        return false;

    for(i = 0; i < vector_length(v); i++) {
        void *item = vector_get(v, i);
        /* If the item gets selected it gets added to the dup vector */
        if(!checker(item))
            return false;
    }

    return true;
}

bool vector_any(vector *v, vector_lambda checker) {
    size_t i;

    if(v == NULL || checker == NULL) return false;

    for(i = 0; i < vector_length(v); i++) {
        void *item = vector_get(v, i);
        /* If the item gets selected it gets added to the dup vector */
        if(checker(item))
            return true;
    }

    return false;
}

bool vector_none(vector *v, vector_lambda checker) {
    size_t i;

    if(v == NULL || checker == NULL) return false;

    for(i = 0; i < vector_length(v); i++) {
        void *item = vector_get(v, i);
        /* If the item gets selected it gets added to the dup vector */
        if(checker(item))
            return false;
    }

    return true;
}

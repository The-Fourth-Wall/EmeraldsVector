vector *v = NULL;
vector *dup = NULL;

static void initialize_vectors(void) {
    v = vector_new();
    vector_add(v, 1);
    vector_add(v, 2);
    vector_add(v, 4);
    dup = vector_dup(v);
}

module(T_vector_dup, {
    describe("#vector_dup", {
        before_each(&initialize_vectors);

        it("copies an empty vector", {
            vector *empty = vector_new();
            vector *empty_dup = vector_dup(empty);
            assert_that_int(vector_length(empty) equals to 0);
            assert_that_int(vector_length(empty_dup) equals to 0);
            assert_that_int(vector_length(empty) equals to vector_length(empty_dup));
        });

        it("copies a vector with 3 elements", {
            assert_that_int(vector_length(dup) equals to 3);
            assert_that_int(vector_length(dup) equals to vector_length(v));
            assert_that_int(vector_get(dup, 0) equals to 1);
            assert_that_int(vector_get(dup, 2) equals to 4);
            assert_that_int(vector_get(dup, 1) equals to 2);
        });

        it("ensures the memory duplicate is a deep copy", {
            vector_delete(v, 1);
            vector_delete(v, 2);
            vector_delete(dup, 0);

            assert_that_int(vector_get(v, 0) equals to 1);
            assert_that_int(vector_length(dup) equals to 2);
            assert_that_int(vector_get(dup, 0) equals to 2);
            assert_that_int(vector_get(dup, 1) equals to 4);
        });
    });
});

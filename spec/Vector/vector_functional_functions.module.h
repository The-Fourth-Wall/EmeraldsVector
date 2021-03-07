vector *vec;
static void setup_vector(void) {
    vec = vector_new();
    vector_add(vec, 1);
    vector_add(vec, 2);
    vector_add(vec, 3);
    vector_add(vec, 4);
    vector_add(vec, 5);
}

static int double_item(int item) {
    return item * 2;
}

static int positive_filter(int item) {
    return item > 0;
}

static int greater_than_three(int item) {
    return item > 3;
}

static int adder(int acc, int curr) {
    return acc + curr;
}

module(T_vector_functional_functions, {
    describe("#vector_map", {
        before_each(&setup_vector);

        it("tries to map an empty vector", {
            vector *empty = vector_new();
            vector *empty_m = vector_map(empty, (vector_lambda)double_item);
            assert_that_int(vector_length(empty_m) equals to 0);
        });

        it("maps an vector of integers its double values", {
            vector *mapped_v = vector_map(vec, (vector_lambda)double_item);
            assert_that_int(vector_length(mapped_v) equals to 5);
            assert_that_int(vector_get(mapped_v, 0) equals to 2);
            assert_that_int(vector_get(mapped_v, 1) equals to 4);
            assert_that_int(vector_get(mapped_v, 2) equals to 6);
            assert_that_int(vector_get(mapped_v, 3) equals to 8);
            assert_that_int(vector_get(mapped_v, 4) equals to 10);
        });

        it("tries to filter out an empty vector", {
            vector *empty = vector_new();
            vector *empty_f = vector_filter(empty, (vector_lambda)greater_than_three);
            assert_that_int(vector_length(empty_f) equals to 0);
        });

        it("filters out numbers greater than 3", {
            vector *filtered_v = vector_filter(vec, (vector_lambda)greater_than_three);
            assert_that_int(vector_length(filtered_v) equals to 3);
            assert_that_int(vector_get(filtered_v, 0) equals to 1);
            assert_that_int(vector_get(filtered_v, 1) equals to 2);
            assert_that_int(vector_get(filtered_v, 2) equals to 3);
        });

        it("tries to select from an empty vector", {
            vector *empty = vector_new();
            vector *empty_f = vector_select(empty, (vector_lambda)greater_than_three);
            assert_that_int(vector_length(empty_f) equals to 0);
        });

        it("selects numbers greater than 3", {
            vector *filtered_v = vector_select(vec, (vector_lambda)greater_than_three);
            assert_that_int(vector_length(filtered_v) equals to 2);
            assert_that_int(vector_get(filtered_v, 0) equals to 4);
            assert_that_int(vector_get(filtered_v, 1) equals to 5);
        });

        it("tries to reduce an empty vector", {
            vector *empty = vector_new();
            void *empty_r = vector_reduce(empty, (vector_lambda)adder);
            assert_that(empty_r is NULL);
        });

        it("reduces a vector to the addition of its elements", {
            int reduced = vector_reduce(vec, (vector_lambda)adder);
            assert_that_int(reduced equals to 15);
        });

        it("maps to the double, filters positives and reduces to the sum of elements", {
            vector *testv = vector_new();
            vector_add(testv, 1);
            vector_add(testv, 2);
            vector_add(testv, -3);
            vector_add(testv, -4);
            vector_add(testv, 5);
            vector_add(testv, -1);
            vector_add(testv, -2);
            vector_add(testv, 3);
            vector_add(testv, 4);
            vector_add(testv, -5);

            vector *double_testv = vector_map(testv, (vector_lambda)double_item);
            vector *positive_double_testv = vector_select(double_testv, (vector_lambda)positive_filter);
            int sum = vector_reduce(positive_double_testv, (vector_lambda)adder);
            assert_that_int(sum equals to 30);
        });

        it("tries to check for all elements on an empty vector", {
            vector *empty = vector_new();
            bool res = vector_all(empty, (vector_lambda)adder);
            assert_that(res is false);
        });

        it("checks that all elements are greater than 3", {
            vector *testv = vector_new();
            vector_add(testv, 5);
            vector_add(testv, 7);
            vector_add(testv, 12);
            vector_add(testv, 6);

            bool res = vector_all(testv, (vector_lambda)greater_than_three);
            assert_that(res is true);
        });

        it("fails on the check that all elements are greater than 3", {
            vector *testv = vector_new();
            vector_add(testv, 5);
            vector_add(testv, 3);
            vector_add(testv, 12);
            vector_add(testv, 6);

            bool res = vector_all(testv, (vector_lambda)greater_than_three);
            assert_that(res is false);
        });

        it("tries to check for any elements on an empty vector", {
            vector *empty = vector_new();
            bool res = vector_any(empty, (vector_lambda)adder);
            assert_that(res is false);
        });

        it("checks if any element is greater than 3", {
            vector *testv = vector_new();
            vector_add(testv, 5);
            vector_add(testv, 7);
            vector_add(testv, 12);
            vector_add(testv, 6);

            bool res = vector_any(testv, (vector_lambda)greater_than_three);
            assert_that(res is true);
        });

        it("fails on the check if any element is greater than 3", {
            vector *testv = vector_new();
            vector_add(testv, 1);
            vector_add(testv, 3);
            vector_add(testv, 2);
            vector_add(testv, 0);

            bool res = vector_any(testv, (vector_lambda)greater_than_three);
            assert_that(res is false);
        });

        it("tries to check for none of the elements on an empty vector", {
            vector *empty = vector_new();
            bool res = vector_none(empty, (vector_lambda)adder);

            /* Should be true */
            assert_that(res is true);
        });

        it("checks that none of the elements are greater than 3", {
            vector *testv = vector_new();
            vector_add(testv, 5);
            vector_add(testv, 7);
            vector_add(testv, 12);
            vector_add(testv, 6);

            bool res = vector_none(testv, (vector_lambda)greater_than_three);
            assert_that(res is false);
        });

        it("fails on the check that all elements are greater than 3", {
            vector *testv = vector_new();
            vector_add(testv, 1);
            vector_add(testv, 3);
            vector_add(testv, 2);
            vector_add(testv, 0);

            bool res = vector_none(testv, (vector_lambda)greater_than_three);
            assert_that(res is true);
        });
    });
});

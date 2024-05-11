#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_functional_functions/vector_functional_functions.h"

EmeraldsVector *vec;
static void setup_vector(void) { vec = vector_new(1, 2, 3, 4, 5); }

static int double_item(int item) { return item * 2; }

static int positive_filter(int item) { return item > 0; }

static int greater_than_three(int item) { return item > 3; }

static int adder(int acc, int curr) { return acc + curr; }

module(T_vector_functional_functions, {
  describe("#vector_map", {
    before_each(&setup_vector);

    it("tries to map an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      EmeraldsVector *empty_m =
        vector_map(empty, (EmeraldsVectorLambda1)double_item);
      assert_that_int(vector_size(empty_m) equals to 0);
    });

    it("maps an vector of integers its double values", {
      EmeraldsVector *mapped_v =
        vector_map(vec, (EmeraldsVectorLambda1)double_item);
      assert_that_int(vector_size(mapped_v) equals to 5);
      assert_that_int(vector_get(mapped_v, 0) equals to 2);
      assert_that_int(vector_get(mapped_v, 1) equals to 4);
      assert_that_int(vector_get(mapped_v, 2) equals to 6);
      assert_that_int(vector_get(mapped_v, 3) equals to 8);
      assert_that_int(vector_get(mapped_v, 4) equals to 10);
    });

    it("tries to filter out an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      EmeraldsVector *empty_f =
        vector_filter(empty, (EmeraldsVectorLambda1)greater_than_three);
      assert_that_int(vector_size(empty_f) equals to 0);
    });

    it("filters out numbers greater than 3", {
      EmeraldsVector *filtered_v =
        vector_filter(vec, (EmeraldsVectorLambda1)greater_than_three);
      assert_that_int(vector_size(filtered_v) equals to 3);
      assert_that_int(vector_get(filtered_v, 0) equals to 1);
      assert_that_int(vector_get(filtered_v, 1) equals to 2);
      assert_that_int(vector_get(filtered_v, 2) equals to 3);
    });

    it("tries to select from an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      EmeraldsVector *empty_f =
        vector_select(empty, (EmeraldsVectorLambda1)greater_than_three);
      assert_that_int(vector_size(empty_f) equals to 0);
    });

    it("selects numbers greater than 3", {
      EmeraldsVector *filtered_v =
        vector_select(vec, (EmeraldsVectorLambda1)greater_than_three);
      assert_that_int(vector_size(filtered_v) equals to 2);
      assert_that_int(vector_get(filtered_v, 0) equals to 4);
      assert_that_int(vector_get(filtered_v, 1) equals to 5);
    });

    it("tries to reduce an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      void *empty_r = vector_reduce(empty, (EmeraldsVectorLambda2)adder);
      assert_that(empty_r is NULL);
    });

    it("reduces a vector to the addition of its elements", {
      int reduced = vector_reduce(vec, (EmeraldsVectorLambda2)adder);
      assert_that_int(reduced equals to 15);
    });

    it(
      "maps to the double, filters positives and reduces to the sum of "
      "elements",
      {
        EmeraldsVector *testv = vector_new(1, 2, -3, -4, 5, -1, -2, 3, 4, -5);

        EmeraldsVector *double_testv =
          vector_map(testv, (EmeraldsVectorLambda1)double_item);
        EmeraldsVector *positive_double_testv =
          vector_select(double_testv, (EmeraldsVectorLambda1)positive_filter);
        int sum =
          vector_reduce(positive_double_testv, (EmeraldsVectorLambda2)adder);
        assert_that_int(sum equals to 30);
      }
    );

    it("tries to check for all elements on an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      bool res              = vector_all(empty, (EmeraldsVectorLambda2)adder);
      assert_that(res is false);
    });

    it("checks that all elements are greater than 3", {
      EmeraldsVector *testv = vector_new(5, 7, 12, 6);
      bool res = vector_all(testv, (EmeraldsVectorLambda1)greater_than_three);
      assert_that(res is true);
    });

    it("fails on the check that all elements are greater than 3", {
      EmeraldsVector *testv = vector_new(5, 3, 12, 6);
      bool res = vector_all(testv, (EmeraldsVectorLambda1)greater_than_three);
      assert_that(res is false);
    });

    it("tries to check for any elements on an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      bool res              = vector_any(empty, (EmeraldsVectorLambda2)adder);
      assert_that(res is false);
    });

    it("checks if any element is greater than 3", {
      EmeraldsVector *testv = vector_new(5, 7, 12, 6);
      bool res = vector_any(testv, (EmeraldsVectorLambda1)greater_than_three);
      assert_that(res is true);
    });

    it("fails on the check if any element is greater than 3", {
      EmeraldsVector *testv = vector_new(1, 3, 2, 0);
      bool res = vector_any(testv, (EmeraldsVectorLambda1)greater_than_three);
      assert_that(res is false);
    });

    it("tries to check for none of the elements on an empty vector", {
      EmeraldsVector *empty = vector_new_empty();
      bool res              = vector_none(empty, (EmeraldsVectorLambda2)adder);

      /* Should be true */
      assert_that(res is true);
    });

    it("checks that none of the elements are greater than 3", {
      EmeraldsVector *testv = vector_new(5, 7, 12, 6);
      bool res = vector_none(testv, (EmeraldsVectorLambda1)greater_than_three);
      assert_that(res is false);
    });

    it("fails on the check that all elements are greater than 3", {
      EmeraldsVector *testv = vector_new(1, 3, 2, 0);
      bool res = vector_none(testv, (EmeraldsVectorLambda1)greater_than_three);
      assert_that(res is true);
    });
  });
})

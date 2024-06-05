#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_functional_functions/vector_functional_functions.h"

static int *vec = NULL;
static void setup_vector(void) {
  vector_free(vec);
  vector_add(vec, 1);
  vector_add(vec, 2);
  vector_add(vec, 3);
  vector_add(vec, 4);
  vector_add(vec, 5);
}

static int double_item(int item) { return item * 2; }

static int positive_filter(int item) { return item > 0; }

static int greater_than_three(int item) { return item > 3; }

static int adder(int acc, int curr) { return acc + curr; }

module(T_vector_functional_functions, {
  before_each(&setup_vector);

  it("tries to map an empty vector", {
    int *empty   = NULL;
    int *empty_m = NULL;
    vector_map(empty, empty_m, double_item);
    assert_that_int(vector_size(empty_m) equals to 0);
  });

  it("maps an vector of integers its double values", {
    int *mapped_v = NULL;
    vector_map(vec, mapped_v, double_item);
    assert_that_int(vector_size(mapped_v) equals to 5);
    assert_that_int(vector_get(mapped_v, 0) equals to 2);
    assert_that_int(vector_get(mapped_v, 1) equals to 4);
    assert_that_int(vector_get(mapped_v, 2) equals to 6);
    assert_that_int(vector_get(mapped_v, 3) equals to 8);
    assert_that_int(vector_get(mapped_v, 4) equals to 10);
  });

  it("tries to filter out an empty vector", {
    int *empty   = NULL;
    int *empty_f = NULL;
    vector_filter(empty, empty_f, greater_than_three);
    assert_that_int(vector_size(empty_f) equals to 0);
  });

  it("filters out numbers greater than 3", {
    int *filtered_v = NULL;
    vector_filter(vec, filtered_v, greater_than_three);
    assert_that_int(vector_size(filtered_v) equals to 3);
    assert_that_int(vector_get(filtered_v, 0) equals to 1);
    assert_that_int(vector_get(filtered_v, 1) equals to 2);
    assert_that_int(vector_get(filtered_v, 2) equals to 3);
  });

  it("tries to select from an empty vector", {
    int *empty   = NULL;
    int *empty_f = NULL;
    vector_select(empty, empty_f, greater_than_three);
    assert_that_int(vector_size(empty_f) equals to 0);
  });

  it("selects numbers greater than 3", {
    int *filtered_v = NULL;
    vector_select(vec, filtered_v, greater_than_three);
    assert_that_int(vector_size(filtered_v) equals to 2);
    assert_that_int(vector_get(filtered_v, 0) equals to 4);
    assert_that_int(vector_get(filtered_v, 1) equals to 5);
  });

  it("tries to reduce an empty vector", {
    int *empty  = NULL;
    int empty_r = 0;
    vector_reduce(empty, adder, &empty_r);
    assert_that(empty_r is 0);
  });

  it("reduces a vector to the addition of its elements", {
    int reduced;
    vector_reduce(vec, adder, &reduced);
    assert_that_int(reduced equals to 15);
  });

  it(
    "maps to the double, filters positives and reduces to the sum of "
    "elements",
    {
      int *testv = NULL;
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

      int *double_testv = NULL;
      vector_map(testv, double_testv, double_item);

      int *positive_double_testv = NULL;
      vector_select(double_testv, positive_double_testv, positive_filter);

      int sum;
      vector_reduce(positive_double_testv, adder, &sum);
      assert_that_int(sum equals to 30);
    }
  );
})

#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_dup/vector_dup.h"

static int *v   = NULL;
static int *dup = NULL;

static void initialize_vectors(void) {
  vector_free(v);
  vector_free(dup);
  vector_add(v, 1);
  vector_add(v, 2);
  vector_add(v, 4);
  vector_dup(v, dup);
}

module(T_vector_dup, {
  describe("#vector_dup", {
    before_each(&initialize_vectors);

    it("copies an empty vector", {
      int *empty     = NULL;
      int *empty_dup = NULL;
      vector_dup(empty, empty_dup);
      assert_that_int(vector_size(empty) equals to 0);
      assert_that_int(vector_size(empty_dup) equals to 0);
      assert_that_int(vector_size(empty) equals to vector_size(empty_dup));
    });

    it("copies a vector with 3 elements", {
      assert_that_int(vector_size(dup) equals to 3);
      assert_that_int(vector_size(dup) equals to vector_size(v));
      assert_that_int(vector_get(dup, 0) equals to 1);
      assert_that_int(vector_get(dup, 2) equals to 4);
      assert_that_int(vector_get(dup, 1) equals to 2);
    });

    it("ensures the memory duplicate is a deep copy", {
      vector_remove(v, 2);
      vector_remove(v, 1);
      vector_remove(dup, 0);

      assert_that_int(vector_size(v) equals to 1);
      assert_that_int(vector_get(v, 0) equals to 1);
      assert_that_int(vector_size(dup) equals to 2);
      assert_that_int(vector_get(dup, 0) equals to 2);
      assert_that_int(vector_get(dup, 1) equals to 4);
    });
  });
})

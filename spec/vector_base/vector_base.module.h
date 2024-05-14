#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_base/vector_base.h"

module(T_vector_base, {
  describe("vector", {
    int *v = NULL;
    int a, b, c;

    before({
      v = NULL;
      a = 1;
      b = 2;
      c = 4;
    });

    it("creates a new vector", {
      assert_that(v is NULL);
      assert_that(vector_size(v) is 0);
    });

    it("adds exactly three elements to the vector", {
      vector_add(v, a);
      vector_add(v, b);
      vector_add(v, c);
      assert_that_int(vector_size(v) equals to 3);
    });

    it("creates a new vector with initial elements", {
      void *v = vector_new(a, b, c);
      assert_that_int(vector_size(v) equals to 3);
    });

    it("peeks the second element of the vector", {
      assert_that_int(vector_get(v, 1) equals to b);
    });

    it("sets the third element to the double of the previous value", {
      vector_set(v, 2, (long)vector_get(v, 2) * 2);
      assert_that_int(vector_get(v, 2) equals to c * 2);
    });

    it("deletes the second element on the vector", {
      vector_remove(v, 1);
      assert_that_int(vector_size(v) equals to 2);
      assert_that_int(vector_get(v, 0) equals to a);
      assert_that_int(vector_get(v, 1) equals to c * 2);
    });

    it("counts the length correctly on additions and deletions", {
      int *vv = NULL;

      assert_that_int(vector_size(vv) equals to 0);
      vector_add(vv, 42);
      vector_add(vv, 43);
      assert_that_int(vector_size(vv) equals to 2);
      vector_add(vv, 1);
      vector_remove(vv, 1);
      assert_that_int(vector_size(vv) equals to 2);
      vector_remove(vv, 0);
      vector_remove(vv, 0);
      assert_that_int(vector_size(vv) equals to 0);
    });

    it("frees vector items without error", {
      vector_free(v);
      assert_that(true is true);
    });
  });
})

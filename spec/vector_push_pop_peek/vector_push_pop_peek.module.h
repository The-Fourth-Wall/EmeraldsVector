#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_base/vector_base.h"

module(T_vector_push_pop_peek, {
  describe("#push", {
    it("pushes 3 elements to the end of the vector", {
      int *v = NULL;
      vector_push(v, 1);
      vector_push(v, 2);
      vector_push(v, 4);
      assert_that_int(v[0] equals to 1);
      assert_that_int(v[1] equals to 2);
      assert_that_int(v[2] equals to 4);
      assert_that(vector_size(v) is 3);
    });
  });

  describe("#pop", {
    it("pushes 3 elements and pops the 2 last", {
      int *v = NULL;
      vector_push(v, 1);
      vector_push(v, 2);
      vector_push(v, 4);
      int res1 = vector_pop(v);
      int res2 = vector_pop(v);
      assert_that_int(res1 equals to 4);
      assert_that_int(res2 equals to 2);
      assert_that(vector_size(v) is 1);
    });
  });

  describe("#peek", {
    it("pushes elements and correctly peeks the top (last element)", {
      int *v = NULL;
      vector_push(v, 1);
      int res1 = vector_peek(v);
      vector_push(v, 2);
      int res2 = vector_peek(v);
      vector_push(v, 4);
      int res3 = vector_peek(v);
      assert_that_int(res1 equals to 1);
      assert_that_int(res2 equals to 2);
      assert_that_int(res3 equals to 4);
      assert_that(vector_size(v) is 3);
    });
  });
})

#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_base/vector_base.h"

void _external_vector_add(int **self, int value) { vector_add(*self, value); }

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

    it("initializes an empty vector", {
      vector_initialize(v);
      assert_that_int(vector_size(v) equals to 0);
      assert_that(v isnot NULL);
    });

    it("initializes an empty vector and adds elements", {
      int *vv = NULL;
      vector_initialize(vv);
      assert_that_int(vector_size(vv) equals to 0);
      assert_that(vv isnot NULL);

      vector_add(vv, 123);
      vector_add(vv, 456);
      vector_add(vv, 789);
      assert_that_int(vector_size(vv) equals to 3);
      assert_that_int(vector_get(vv, 0) equals to 123);
      assert_that_int(vector_get(vv, 1) equals to 456);
      assert_that_int(vector_get(vv, 2) equals to 789);
    });

    context("on external vector add", {
      it("adds an element to an uninitialized vector", {
        int *vv = NULL;
        vector_initialize(vv);
        _external_vector_add(&vv, 42);
        _external_vector_add(&vv, 43);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vector_get(vv, 0) equals to 42);
        assert_that_int(vector_get(vv, 1) equals to 43);
      });

      it("adds an element to an initialized vector", {
        int *vv = NULL;
        _external_vector_add(&vv, 42);
        _external_vector_add(&vv, 43);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vector_get(vv, 0) equals to 42);
        assert_that_int(vector_get(vv, 1) equals to 43);
      });
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

    it("tries to set an element out of bounds but gets vibe checked", {
      vector_set(v, 9999, 123);
      assert_that_int(vector_get(v, 9999) equals to 0);
      assert_that_int(vector_size(v) equals to 3);
    });

    it("deletes the second element on the vector", {
      vector_remove(v, 1);
      assert_that_int(vector_size(v) equals to 2);
      assert_that_int(vector_get(v, 0) equals to a);
      assert_that_int(vector_get(v, 1) equals to c * 2);
    });

    it("deletes multiple elements starting from an index", {
      long *vv = (long *)vector_new(1, 2, 3, 4, 5, 6, 7);
      vector_remove_n(vv, 2, 4);
      assert_that_int(vector_size(vv) equals to 3);
      assert_that_int(vector_get(vv, 0) equals to 1);
      assert_that_int(vector_get(vv, 1) equals to 2);
      assert_that_int(vector_get(vv, 2) equals to 7);
    });

    it("deletes the last element on the vector", {
      int *vv = NULL;
      vector_add(vv, 1);
      vector_add(vv, 2);
      vector_add(vv, 4);

      vector_remove_last(vv);
      assert_that_int(vector_size(vv) equals to 2);
      assert_that_int(vector_get(vv, 0) equals to 1);
      assert_that_int(vector_get(vv, 1) equals to 2);

      vector_remove_last(vv);
      assert_that_int(vector_size(vv) equals to 1);
      assert_that_int(vector_get(vv, 0) equals to 1);
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

    it("grabs the last element on the vector and returns it", {
      long *vv = (long *)vector_new(1, 2, 3);
      assert_that_int(vector_last(vv) equals to 3);
    });

    it("creates a char* vector with `new`", {
      char **cv = vector_string_new("a", "b", "c");
      assert_that_int(vector_size(cv) equals to 3);
      assert_that_charptr(vector_get(cv, 0) equals to "a");
      assert_that_charptr(vector_get(cv, 1) equals to "b");
      assert_that_charptr(vector_get(cv, 2) equals to "c");
    });

    it("frees vector items without error", {
      vector_free(v);
      assert_that(true is true);
    });
  });
})

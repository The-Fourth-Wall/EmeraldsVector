#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/vector_base/vector_base.h"
#include "../../src/vector_dup/vector_dup.h"

static void _external_vector_add(int **self, int value) {
  vector_add(*self, value);
}

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

    it("creates a new empty vector", {
      assert_that(v is NULL);
      assert_that(vector_size(v) is 0);
    });

    it("initializes an empty vector", {
      vector_initialize(v);
      assert_that_int(vector_size(v) equals to 0);
      assert_that(v isnot NULL);
    });

    context("#vector_new", {
      it("initializes a new vector with 1 element", {
        int *vv = vector_new(1);
        assert_that_int(vector_size(vv) equals to 1);
        assert_that_int(vv[0] equals to 1);
      });

      it("initializes a new vector with 3 elements", {
        char **vv = vector_new("A", "B", "C");
        assert_that_int(vector_size(vv) equals to 3);
        assert_that_charptr(vv[0] equals to "A");
        assert_that_charptr(vv[1] equals to "B");
        assert_that_charptr(vv[2] equals to "C");
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
        assert_that_int(vv[0] equals to 123);
        assert_that_int(vv[1] equals to 456);
        assert_that_int(vv[2] equals to 789);
      });

      it("creates a char* vector with `new`", {
        char **cv = vector_new("a", "b", "c");
        assert_that_int(vector_size(cv) equals to 3);
        assert_that_charptr(cv[0] equals to "a");
        assert_that_charptr(cv[1] equals to "b");
        assert_that_charptr(cv[2] equals to "c");
      });

      it("creates a new vector with 1 element", {
        int *vv = vector_new(1);
        assert_that_int(vector_size(vv) equals to 1);
        assert_that_int(vv[0] equals to 1);
      });

      it("creates new vectors but using variables instead of literals", {
        int a   = 1;
        int b   = 2;
        int c   = 3;
        int *vv = vector_new(a, b, c);
        assert_that_int(vector_size(vv) equals to 3);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);
        assert_that_int(vv[2] equals to 3);

        const char *aa = "a";
        const char *bb = "b";
        const char *cc = "c";
        char **cv      = vector_new(aa, bb, cc);
        assert_that_int(vector_size(cv) equals to 3);
        assert_that_charptr(cv[0] equals to "a");
        assert_that_charptr(cv[1] equals to "b");
        assert_that_charptr(cv[2] equals to "c");
      });
    });

    context("#vector_add", {
      it("adds exactly three elements to the vector", {
        vector_add(v, a);
        vector_add(v, b);
        vector_add(v, c);
        assert_that_int(vector_size(v) equals to 3);
      });

      it("adds to a NULL vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        assert_that_int(vv[0] equals to 1);
      });
    });

    context("#vector_initialize_n", {
      it("initializes a vector with a given size", {
        int *vv = NULL;
        vector_initialize_n(vv, 3);
        assert_that_int(vector_size(vv) equals to 3);
        assert_that_int(vector_capacity(vv) equals to 4);
        assert_that_int(vv[0] equals to 0);
        assert_that_int(vv[1] equals to 0);
        assert_that_int(vv[2] equals to 0);
      });

      it("initializes a vector of 16 elements", {
        int *vv = NULL;
        vector_initialize_n(vv, 16);
        assert_that_int(vector_size(vv) equals to 16);
        assert_that_int(vector_capacity(vv) equals to 16);
        vector_add(vv, 1);
        assert_that_int(vector_size(vv) equals to 17);
        assert_that_int(vector_capacity(vv) equals to 32);
        assert_that_int(vv[0] equals to 0);
        assert_that_int(vv[15] equals to 0);
        assert_that_int(vv[16] equals to 1);
      });
    });

    context("on external vector add", {
      it("adds an element to an uninitialized vector", {
        int *vv = NULL;
        vector_initialize(vv);
        _external_vector_add(&vv, 42);
        _external_vector_add(&vv, 43);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vv[0] equals to 42);
        assert_that_int(vv[1] equals to 43);
      });

      it("adds an element to an initialized vector", {
        int *vv = NULL;
        _external_vector_add(&vv, 42);
        _external_vector_add(&vv, 43);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vv[0] equals to 42);
        assert_that_int(vv[1] equals to 43);
      });

      it("creates a new vector with initial elements", {
        void *v = vector_new(a, b, c);
        assert_that_int(vector_size(v) equals to 3);
      });
    });

    context("#vector_add_n", {
      it("tries to add a NULL pointer to a vector", {
        int *vv = NULL;
        vector_add_n(vv, NULL, 1);
        assert_that(vv is NULL);
      });

      it("adds multiple elements to a vector", {
        char *vv       = NULL;
        const char *s1 = "1234";
        vector_add_n(vv, s1, 4);
        assert_that_charptr(vv equals to "1234");
        vector_add_n(vv, s1, 4);
        assert_that_charptr(vv equals to "12341234");
      });

      it("adds multiple integers to a vector", {
        int *vv    = NULL;
        int arr[5] = {1, 2, 3, 4, 5};
        vector_add_n(vv, arr, 5);
        assert_that_int(vector_size(vv) equals to 5);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);
        assert_that_int(vv[2] equals to 3);
        assert_that_int(vv[3] equals to 4);
        assert_that_int(vv[4] equals to 5);
      });

      it("adds multiple strings to a vector of strings", {
        char **vv = NULL;
        vector_add(vv, (char *)"a");
        vector_add(vv, (char *)"b");
        vector_add(vv, (char *)"c");
        assert_that_charptr(vv[0] equals to "a");
        assert_that_charptr(vv[1] equals to "b");
        assert_that_charptr(vv[2] equals to "c");

        char **vv2 = NULL;
        vector_dup(vv, vv2);
        assert_that_charptr(vv2[0] equals to "a");
        assert_that_charptr(vv2[1] equals to "b");
        assert_that_charptr(vv2[2] equals to "c");

        vector_add_n(vv2, vv, vector_size(vv));
        assert_that_int(vector_size(vv2) equals to 6);
        assert_that_charptr(vv2[0] equals to "a");
        assert_that_charptr(vv2[1] equals to "b");
        assert_that_charptr(vv2[2] equals to "c");
        assert_that_charptr(vv2[3] equals to "a");
        assert_that_charptr(vv2[4] equals to "b");
        assert_that_charptr(vv2[5] equals to "c");
      });
    });

    context("#vector_add_vector", {
      it("adds a vector to the end of the vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 2);
        vector_add_vector(vv, vv);
        assert_that_int(vector_size(vv) equals to 4);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);
        assert_that_int(vv[2] equals to 1);
        assert_that_int(vv[3] equals to 2);
      });

      it("adds a vector and its duplicate to the end of the vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 2);
        int *vv2 = NULL;
        vector_dup(vv, vv2);
        vector_add_vector(vv, vv2);
        assert_that_int(vector_size(vv) equals to 4);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);
        assert_that_int(vv[2] equals to 1);
        assert_that_int(vv[3] equals to 2);
      });

      it("adds two different vectors to the end of the vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 2);
        int *vv2 = NULL;
        vector_add(vv2, 3);
        vector_add(vv2, 4);
        vector_add(vv2, 5);
        vector_add_vector(vv, vv2);
        assert_that_int(vector_size(vv) equals to 5);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);
        assert_that_int(vv[2] equals to 3);
        assert_that_int(vv[3] equals to 4);
        assert_that_int(vv[4] equals to 5);
      });
    });

    context("on setting elements in a vector", {
      it("sets the third element to the double of the previous value", {
        v[2] = v[2] * 2;
        assert_that_int(v[2] equals to c * 2);
      });

      it("tries to set an element out of bounds without increasing the size", {
        v[9999] = 123;
        assert_that_int(v[9999] equals to 123);
        assert_that_int(vector_size(v) equals to 3);

        v[-42] = 456;
        assert_that_int(v[-42] equals to 456);
        assert_that_int(vector_size(v) equals to 3);
      });
    });

    context("on removing elements from a vector", {
      it("removes characters from a string", {
        char *vv = NULL;
        vector_add_n(vv, "abcde", 5);
        vector_remove_n(vv, 1, 3);
        assert_that_charptr(vv equals to "ae");
      });

      it("removes multiple elements from a vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 2);
        vector_add(vv, 3);
        vector_add(vv, 4);
        vector_add(vv, 5);
        vector_remove_n(vv, 1, 3);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 5);
      });

      it("removes an element from a vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 2);
        vector_add(vv, 3);
        vector_add(vv, 4);
        vector_add(vv, 5);
        vector_remove(vv, 1);
        assert_that_int(vector_size(vv) equals to 4);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 3);
        assert_that_int(vv[2] equals to 4);
        assert_that_int(vv[3] equals to 5);
      });

      it("removes the last element from a vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 5);
        vector_add(vv, 2);
        vector_remove_last(vv);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 5);
      });

      it("deletes the second element on the vector", {
        vector_remove(v, 1);
        assert_that_int(vector_size(v) equals to 2);
        assert_that_int(v[0] equals to a);
        assert_that_int(v[1] equals to c * 2);
      });

      it("deletes multiple elements starting from an index", {
        int *vv = vector_new(1, 2, 3, 4, 5, 6, 7);
        vector_remove_n(vv, 2, 4);
        assert_that_int(vector_size(vv) equals to 3);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);
        assert_that_int(vv[2] equals to 7);
      });

      it("deletes the last element on the vector", {
        int *vv = NULL;
        vector_add(vv, 1);
        vector_add(vv, 2);
        vector_add(vv, 4);

        vector_remove_last(vv);
        assert_that_int(vector_size(vv) equals to 2);
        assert_that_int(vv[0] equals to 1);
        assert_that_int(vv[1] equals to 2);

        vector_remove_last(vv);
        assert_that_int(vector_size(vv) equals to 1);
        assert_that_int(vv[0] equals to 1);
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
    });

    it("grabs the last element on the vector and returns it", {
      int *vv = vector_new(1, 2, 3);
      assert_that_int(vector_last(vv) equals to 3);
    });

    it("checks if the vector is empty", {
      int *vv = NULL;
      assert_that(vector_is_empty(vv));
      vector_add(vv, 1);
      nassert_that(vector_is_empty(vv));
    });

    context("on getting header elements: capacity and size", {
      it("gets the current total capacity of the vector", {
        int *vv = vector_new(1, 2, 3);
        assert_that_int(vector_capacity(vv) equals to 4);
        vector_add(vv, 42);
        vector_add(vv, 43);
        assert_that_int(vector_capacity(vv) equals to 8);
      });

      it("gets the current total capacity of the vector (signed)", {
        int *vv = vector_new(1, 2, 3);
        assert_that_int(vector_capacity_signed(vv) equals to 4);
      });

      it("gets the current total size of the vector", {
        int *vv = vector_new(1, 2, 3);
        assert_that_int(vector_size(vv) equals to 3);
      });

      it("gets the current total size of the vector (signed)", {
        int *vv = vector_new(1, 2, 3);
        assert_that_int(vector_size_signed(vv) equals to 3);
      });
    });

    context("#vector_free", {
      it("frees a null vector", {
        int *vv = NULL;
        vector_free(vv);
        assert_that(true is true);
      });

      it("frees vector items without error", {
        vector_free(v);
        assert_that(true is true);
      });
    });
  });
})

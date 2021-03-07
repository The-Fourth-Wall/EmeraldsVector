#include "Vector.spec.h"

module(T_Vector, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr("Hello, World!" equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_Vector();
});

spec({
    run_spec_suite("all");
});

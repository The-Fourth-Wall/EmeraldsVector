#include "../export/Vector.h"

int double_item(int item) {
    return item * 2;
}

int positive_filter(int item) {
    return item > 0;
}

int adder(int accumulator, int current) {
    return accumulator + current;
}

int main(void) {
    vector *testv = NULL;
    long sum;

    printf("TESTING VECTOR MAP FILTER REDUCE\n");
    testv = vector_new();

    vector_add(testv, (void*)1);
    vector_add(testv, (void*)2);
    vector_add(testv, (void*)-3);
    vector_add(testv, (void*)-4);
    vector_add(testv, (void*)5);
    vector_add(testv, (void*)-1);
    vector_add(testv, (void*)-2);
    vector_add(testv, (void*)3);
    vector_add(testv, (void*)4);
    vector_add(testv, (void*)-5);

    testv = vector_map(testv, (vector_lambda1)double_item);
    testv = vector_select(testv, (vector_lambda1)positive_filter);
    sum = (long)vector_reduce(testv, (vector_lambda2)adder);
    printf("SUM: `%ld` should be `30`\n\n", sum);

    vector_free(testv);

    return 0;
}

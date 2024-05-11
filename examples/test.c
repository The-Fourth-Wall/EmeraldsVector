#include "../export/EmeraldsVector.h" /* IWYU pragma: keep */

int double_item(int item) { return item * 2; }

int positive_filter(int item) { return item > 0; }

int adder(int accumulator, int current) { return accumulator + current; }

int main(void) {
  EmeraldsVector *testv = NULL;
  long sum;

  printf("TESTING VECTOR MAP FILTER REDUCE\n");
  testv = vector_new(1, 2, -3, -4, 5, -1, -2, 3, 4, -5);
  testv = vector_map(testv, (EmeraldsVectorLambda1)double_item);
  testv = vector_select(testv, (EmeraldsVectorLambda1)positive_filter);
  sum   = (long)vector_reduce(testv, (EmeraldsVectorLambda2)adder);
  printf("SUM: `%ld` should be `30`\n\n", sum);

  vector_free(testv);

  return 0;
}

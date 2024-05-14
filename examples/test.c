#include "../export/EmeraldsVector.h" /* IWYU pragma: keep */

#include <stdio.h>

int double_item(int item) { return item * 2; }

int positive_filter(int item) { return item > 0; }

int adder(int accumulator, int current) { return accumulator + current; }

int main(void) {
  printf("TESTING VECTOR MAP FILTER REDUCE\n");
  void **testv = vector_new(1, 2, -3, -4, 5, -1, -2, 3, 4, -5);
  int sum      = 0;

  vector_map(testv, testv, double_item);
  vector_select(testv, testv, positive_filter);
  vector_reduce(testv, adder, &sum);
  printf("SUM: `%d` should be `30`\n\n", sum);

  vector_free(testv);

  return 0;
}

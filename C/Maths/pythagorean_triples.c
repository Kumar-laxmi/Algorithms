#include <stdlib.h>

int **generatePythagoreanTriples(int n) {
  int **triples = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    triples[i] = (int *)malloc(3 * sizeof(int));
  }
  int count = 0;

  for (int a = 1; a <= n; a++) {
    for (int b = a; b <= n; b++) {
      for (int c = b; c <= n; c++) {
        if (a * a + b * b == c * c) {
          triples[count][0] = a;
          triples[count][1] = b;
          triples[count][2] = c;
          count++;
        }
      }
    }
  }

  return triples;
}

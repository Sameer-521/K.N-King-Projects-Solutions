#include <stdio.h>
#define N 40

int main(void) {
  int i;
  int fibs[N] = {0, 1};
  for (i = 2; i < N; i++)
    fibs[i] = fibs[i - 2] + fibs[i - 1];

  for (i = 0; i < N; i++)
    printf("%d ", fibs[i]);

  printf("\n");

  return 0;
}

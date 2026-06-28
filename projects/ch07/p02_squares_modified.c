#include <stdio.h>

int main(void) {
  int i, n, ch;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    if (i % 24 == 0) {
      printf("Press Enter to continue...");
      while ((ch = getchar()) != EOF && ch != '\n')
        ;
      getchar();
    }
    printf("%10d%10d\n", i, i * i);
  }
  return 0;
}

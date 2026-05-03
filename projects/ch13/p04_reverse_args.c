#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, end;

  end = argc - 1;

  printf("Reversed: ");
  for (i = end; i >= 1; i--)
    printf("%s ", argv[i]);

  printf("\n");

  return 0;
}

#include <stdio.h>

int main(void) {
  int a, b, c, d;
  int e, f, g, h;
  int i, j, k, l;
  int m, n, o, p;
  int row_1, row_2, row_3, row_4;
  int col_1, col_2, col_3, col_4;
  int diagonal_1, diagonal_2;

  printf("Enter the numbers from 1 to 16 in any order: \n");
  scanf("%d %d %d %d ", &a, &b, &c, &d);
  scanf("%d %d %d %d ", &e, &f, &g, &h);
  scanf("%d %d %d %d ", &i, &j, &k, &l);
  scanf("%d %d %d %d", &m, &n, &o, &p);

  printf("\n");

  // print 4 elements per row
  printf("%2d %2d %2d %2d\n", a, b, c, d);
  printf("%2d %2d %2d %2d\n", e, f, g, h);
  printf("%2d %2d %2d %2d\n", i, j, k, l);
  printf("%2d %2d %2d %2d\n", m, n, o, p);

  printf("\n");

  // row sums
  row_1 = a + b + c + d;
  row_2 = e + f + g + h;
  row_3 = i + j + k + l;
  row_4 = m + n + o + p;
  printf("Row sums: %d %d %d %d\n", row_1, row_2, row_3, row_4);

  // column sums
  col_1 = a + e + i + m;
  col_2 = b + f + j + n;
  col_3 = c + g + k + o;
  col_4 = d + h + l + p;
  printf("Column sums: %d %d %d %d\n", col_1, col_2, col_3, col_4);

  // diagonal sums
  diagonal_1 = a + f + k + p;
  diagonal_2 = d + g + j + m;
  printf("Diagonal sums: %d %d\n", diagonal_1, diagonal_2);

  return 0;
}

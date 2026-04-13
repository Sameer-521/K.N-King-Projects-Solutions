#include <stdio.h>
#define N 5

int main(void) {
  int row, col, element, i;
  /* This array is now redundant
  int arr[N][N] = {[0][0] = 0}; */
  int row_totals[N] = {0}, col_totals[N] = {0};

  for (row = 0; row < N; row++) {
    printf("Enter row %d: ", row + 1);
    for (col = 0; col < N; col++) {
      scanf("%d", &element);
      // arr[row][col] = element;
      row_totals[row] += element; // sum total for each row per pass
      col_totals[col] += element; // sequentially add up for each column
    }
  }

  printf("\nRow totals: ");
  for (i = 0; i < N; i++)
    printf("%d ", row_totals[i]);

  printf("\nCol totals: ");
  for (i = 0; i < N; i++)
    printf("%d ", col_totals[i]);

  printf("\n");

  return 0;
}

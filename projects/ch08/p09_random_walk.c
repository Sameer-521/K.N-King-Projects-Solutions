#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void display_map(char map[][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%c ", map[i][j]);
    printf("\n");
  }
}

int main(void) {
  int move, i, j, current_letter;
  char map[N][N];
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  // fill map
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      map[i][j] = '.';

  srand((unsigned)time(NULL));

  i = 0;
  j = 0;
  current_letter = 0;

  // first move
  map[i][j] = letters[current_letter];
  current_letter++;

  while (current_letter < 26) {
    move = rand() % 4;
    switch (move) {
    case 0: // move up
      if ((i - 1) >= 0 && map[i - 1][j] == '.') {
        map[i - 1][j] = letters[current_letter];
        i--;
        current_letter++;
      } else if ((j + 1) < N && map[i][j + 1] == '.') { // try right
        map[i][j + 1] = letters[current_letter];
        j++;
        current_letter++;
      } else if ((i + 1) < N && map[i + 1][j] == '.') { // try down
        map[i + 1][j] = letters[current_letter];
        i++;
        current_letter++;
      } else if ((j - 1) >= 0 && map[i][j - 1] == '.') { // try left
        map[i][j - 1] = letters[current_letter];
        j--;
        current_letter++;
      } else {
        printf("Stuck at: [%d][%d]\n", i, j);
        display_map(map);
        return 0;
      }
      break;

    case 1: // move right
      if ((j + 1) < N && (map[i][j + 1] == '.')) {
        map[i][j + 1] = letters[current_letter];
        j++;
        current_letter++;
      } else if ((i + 1) < N && map[i + 1][j] == '.') { // try down
        map[i + 1][j] = letters[current_letter];
        i++;
        current_letter++;
      } else if ((j - 1) >= 0 && map[i][j - 1] == '.') { // try left
        map[i][j - 1] = letters[current_letter];
        j--;
        current_letter++;
      } else if ((i - 1) >= 0 && map[i - 1][j] == '.') { // try up
        map[i - 1][j] = letters[current_letter];
        i--;
        current_letter++;
      } else {
        printf("Stuck at: [%d][%d]\n", i, j);
        display_map(map);
        return 0;
      }
      break;

    case 2: // move down
      if ((i + 1) >= 0 && map[i + 1][j] == '.') {
        map[i + 1][j] = letters[current_letter];
        i++;
        current_letter++;
      } else if ((j - 1) >= 0 && map[i][j - 1] == '.') { // try left
        map[i][j - 1] = letters[current_letter];
        j--;
        current_letter++;
      } else if ((i - 1) < N && map[i - 1][j] == '.') { // try up
        map[i - 1][j] = letters[current_letter];
        i--;
        current_letter++;
      } else if ((j + 1) < N && map[i][j + 1] == '.') { // try right
        map[i][j + 1] = letters[current_letter];
        j++;
        current_letter++;
      } else {
        printf("Stuck at: [%d][%d]\n", i, j);
        display_map(map);
        return 0;
      }
      break;

    case 3: // move left
      if ((j - 1) >= 0 && map[i][j - 1] == '.') {
        map[i][j - 1] = letters[current_letter];
        current_letter++;
        j--;
      } else if ((i - 1) >= 0 && map[i - 1][j] == '.') { // try up
        map[i - 1][j] = letters[current_letter];
        i--;
        current_letter++;
      } else if ((j + 1) < N && map[i][j + 1] == '.') { // try right
        map[i][j + 1] = letters[current_letter];
        j++;
        current_letter++;
      } else {
        printf("Stuck at: [%d][%d]\n", i, j);
        display_map(map);
        return 0;
      }
      break;

    default:
      break;
    }
  }

  display_map(map);
  return 0;
}

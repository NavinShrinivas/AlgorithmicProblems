#include "1_1.h"

int main() {
  struct head *graph[graphsize] = {NULL}; // easy to tell when empty
  int st_row, st_col, dt_row, dt_col;
  scanf("%d %d", &st_row, &st_col);
  scanf("%d %d", &dt_row, &dt_col);
  dt_row++;
  dt_col++;
  int arr[dt_row][dt_col];
  for (int i = 0; i < dt_row; i++) {
    for (int j = 0; j < dt_col; j++) {
      scanf("%d", (*(arr + i) + j));
    }
  }
  printf("halo");
  fflush(stdout);
  GenerateAdjList(dt_row, dt_col, graph, arr);
}

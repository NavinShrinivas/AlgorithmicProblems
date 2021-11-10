#include "1_1.h"

int main() {
  int st_row, st_col, dt_row, dt_col;
  // dt are going to be used as array size as the input does
  // not mention it!!! Im very certain it has to be given.

  scanf("%d %d", &st_row, &st_col);
  scanf("%d %d", &dt_row, &dt_col);
  int map[dt_row + 1][dt_col + 1];

  for (int i = 0; i <= dt_row; i++)
    for (int j = 0; j <= dt_col; j++)
      scanf("%d", (*(map + i) + j));
  struct sp_mat *metadata = GenerateSparceMatrix(dt_row + 1, dt_col + 1, map);

  // testing sparce generator :,(
  metadata = metadata->down->down;
  while (metadata != NULL) {
    printf("%d", metadata->col);
    metadata = metadata->right;
  }
}

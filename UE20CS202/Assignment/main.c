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
  metadata = metadata->right->right->down;
  while (metadata != NULL) {
    printf("%d", metadata->row);
    metadata = metadata->down;
  }
  /*
   *
   *  struct head *stack = (struct head *)malloc(sizeof(struct head));
   *  stack->top = -1;
   *  pushe(stack, metadata->right->down);
   *  int flag = 0;
   *  struct sp_mat *work = peek(stack);
   *  if (work->right != NULL)
   *    printf("right exists");
   *  if (work->visited_right != true)
   *    printf("hmm hm");
   *  while (stack->top >= 0) {
   *    struct sp_mat *work = peek(stack);
   *    if (work->right == NULL && work->down == NULL) {
   *      pope(stack);
   *      printf("1");
   *    } else if (work->visited_right == true && work->visited_down == true) {
   *      pope(stack);
   *      printf("2");
   *    } else if (work->col == dt_col && work->row == dt_row) {
   *      flag = 1;
   *      printf("3");
   *      break;
   *    } else if (work->right != NULL && work->visited_right != true) {
   *      pushe(stack, work->right);
   *      work->visited_right = true;
   *      printf("4");
   *    } else if (work->down != NULL && work->visited_down != true) {
   *      pushe(stack, work->down);
   *      work->visited_down = true;
   *      printf("5");
   *    } else {
   *      pope(stack);
   *      if (work->down != NULL)
   *        printf("yay");
   *      if (work->visited_down != true)
   *        printf("hmm hm");
   *
   *      printf("6");
   *    }
   *  }
   *  printf("flag : %d", flag);
   */
}

#include "PES2UG20CS237_H.h"
#include <stdio.h>

int main() {
  // input is read from file using file redirection in terminal
  // written to file in the end
  printf(
      "Please give input file using redirection operator (<) if not given! \n");
  fflush(stdout);
  int st_row, st_col, dt_row, dt_col;
  // dt are going to be used as array size as the input does
  // not mention it!!! Im very certain it has to be given.
  FILE *fp = fopen("./output.txt", "w+");
  scanf("%d %d", &st_row, &st_col);
  scanf("%d %d", &dt_row, &dt_col);
  int map[dt_row + 1][dt_col + 1];

  for (int i = 0; i <= dt_row; i++)
    for (int j = 0; j <= dt_col; j++)
      scanf("%d", (*(map + i) + j));
  struct sp_mat *metadata = GenerateSparceMatrix(dt_row + 1, dt_col + 1, map);

  // below is testing my sparce matrix
  /*
   *struct sp_mat *curr = metadata->right->right;
   *while (curr != NULL) {
   *  printf("%d", curr->col);
   *  curr = curr->down;
   *}
   */

  struct head *stack = (struct head *)malloc(sizeof(struct head));
  stack->top = -1;
  pushe(stack, metadata->right->down);
  int flag = 0;

  while (stack->top >= 0) {
    struct sp_mat *work = peek(stack);
    if (work->row == dt_row && work->col == dt_col) {
      flag = 1;
      break;
    } else if (work->right == NULL && work->down == NULL) {
      pope(stack);
    } else if (work->visited_right == true && work->visited_down == true) {
      pope(stack);
    } else if (work->right != NULL && work->visited_right == false) {
      fflush(stdout);
      pushe(stack, work->right);
      work->visited_right = true;
    } else if (work->down != NULL && work->visited_down == false) {
      pushe(stack, work->down);
      work->visited_down = true;
    }
    if (work->down == NULL)
      work->visited_down = true;
    if (work->right == NULL)
      work->visited_right = true;
  }
  FlushStack(stack, fp);
  printf("Output successfully written to output.txt");
}

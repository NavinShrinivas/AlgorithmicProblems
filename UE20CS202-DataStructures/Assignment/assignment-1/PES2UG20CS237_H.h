#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// to build sparse matrix
// unlike most implmentations on the internet , both my head and body
// nodes are the same
struct sp_mat {
  int row;
  int col;
  struct sp_mat *right;
  struct sp_mat *down;
  bool visited_right;
  bool visited_down;
  bool hit;
};

struct sp_mat *GenerateSparceMatrix(int row, int col, int arr[][col]);

// below are stuff to handle the stack for path finding
struct node {
  struct sp_mat *data;
  struct node *link;
};
struct head {
  struct node *link;
  int top;
};

void pushe(struct head *head, struct sp_mat *d);
void pope(struct head *head);
void displaystack(struct head *head);
struct sp_mat *peek(struct head *head);
void FlushStack(struct head *head, FILE *fp);

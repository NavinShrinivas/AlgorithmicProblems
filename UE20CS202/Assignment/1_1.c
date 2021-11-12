
#include "1_1.h"

void pushe(struct head *head, struct sp_mat *d) {
  if (head->top == -1) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    head->link = temp;
    (head->top)++;
    return;
  } else {
    struct node *curr = head->link;
    while (curr->link != NULL)
      curr = curr->link;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    curr->link = temp;
    (head->top)++;
    return;
  }
}

void pope(struct head *head) {
  if (head->top == -1)
    return;
  else if (head->top == 0) {
    head->link = NULL;
    (head->top)--;
    return;
  } else {
    struct node *curr = head->link;
    struct node *del = curr->link;
    while (del->link != NULL) {
      curr = del;
      del = del->link;
    }
    curr->link = NULL;
    (head->top)--;
    return;
  }
}

struct sp_mat *peek(struct head *head) {
  if (head->top == -1)
    return NULL;
  else
    return head->link->data;
}

struct sp_mat *GenerateSparceMatrix(int row, int col, int arr[][col]) {
  struct sp_mat *meta = (struct sp_mat *)malloc(sizeof(struct sp_mat));
  meta->row = -1;
  meta->col = -1;
  struct sp_mat *curr = meta;
  // build head cols
  for (int i = 0; i < col; i++) {
    struct sp_mat *temp = (struct sp_mat *)malloc(sizeof(struct sp_mat));
    temp->row = -1;
    temp->col = -1;
    temp->visited_down = false;
    temp->visited_right = false;
    curr->right = temp;
    curr = curr->right;
  }

  curr = meta;
  // build head row
  for (int i = 0; i < row; i++) {
    struct sp_mat *temp = (struct sp_mat *)malloc(sizeof(struct sp_mat));
    temp->row = -1;
    temp->col = -1;
    temp->visited_down = false;
    temp->visited_right = false;
    curr->down = temp;
    curr = curr->down;
  }
  // now handling the actual data!
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] == 0) {
        struct sp_mat *datanode =
            (struct sp_mat *)malloc(sizeof(struct sp_mat));
        datanode->row = i;
        datanode->col = j;
        datanode->visited_down = false;
        datanode->visited_right = false;
        datanode->right = NULL;
        datanode->down = NULL;
        if (i == 0 && j == 0) {
          meta->down->right = datanode;
          meta->right->down = datanode;
        } else {
          // check if anything from top need to refrence this node :
          if (i != 0 && arr[i - 1][j] != 1) {
            // going down first , then right
            curr = meta;
            int rowi = 0, coli = 0;
            while (rowi != i && curr->down != NULL) {
              curr = curr->down;
              rowi++;
            }
            if (j == 0)
              curr->down->right = datanode;
            while (coli != j + 1 && curr->right != NULL) {
              curr = curr->right;
              coli++;
            }
            // if curr ends up as NULL meaning this 0 will never be part of the
            // path
            curr->down = datanode;
          }
          // check if anything from left need to refrence this node :
          if (j != 0 && arr[i][j - 1] != 1) {
            // going right first , then down
            curr = meta;
            int rowi = 0, coli = 0;
            while (coli != j && curr->right != NULL) {
              curr = curr->right;
              coli++;
            }
            if (i == 0)
              curr->right->down = datanode;
            while (rowi != i + 1 && curr->down != NULL) {
              curr = curr->down;
              rowi++;
            }
            curr->right = datanode;
          }
        }
      }
    }
  }
  return meta;
}

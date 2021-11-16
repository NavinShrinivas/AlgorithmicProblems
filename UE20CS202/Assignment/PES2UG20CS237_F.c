
#include "PES2UG20CS237_H.h"

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
  else {
    struct node *curr = head->link;
    while (curr->link != NULL)
      curr = curr->link;
    return curr->data;
  }
}

void FlushStack(struct head *head, FILE *fp) {
  struct node *curr = head->link;
  while (curr != NULL) {
    fprintf(fp, "%d %d \n", curr->data->row, curr->data->col);
    curr = curr->link;
  }
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
        }
        if (i == 0 && j != 0) {
          int fakej = 0;
          curr = meta;
          while (fakej != j + 1 && curr != NULL) {
            curr = curr->right;
            fakej++;
          }
          curr->down = datanode;
        }
        if (j == 0 && i != 0) {
          int fakei = 0;
          curr = meta;
          while (fakei != i + 1 && curr != NULL) {
            curr = curr->down;
            fakei++;
          }
          curr->right = datanode;
        }
        // link from left
        if (j != 0) {
          int link = 0;
          int fakej = 0, fakei = 0;
          curr = meta;
          while (fakei != i + 1 && curr->down != NULL) {
            curr = curr->down;
            fakei++;
          }
          while (fakej != j && curr->right != NULL) {
            curr = curr->right;
            fakej++;
          }
          if (arr[i][j - 1] == 1 && fakej == 0)
            curr->right = datanode;
          else if (curr != NULL && curr->row == i) {
            curr->right = datanode;
            link = 1;
          }
          fakej = 0;
          fakei = 0;
          curr = meta;
          while (fakej != j && curr->right != NULL) {
            curr = curr->right;
            fakej++;
          }
          while (fakei != i + 1 && curr->down != NULL) {
            curr = curr->down;
            fakei++;
          }
          if (arr[i][j - 1] == 1 && fakej == 0)
            curr->right = datanode;
          else if (curr != NULL && curr->row == i)
            curr->right = datanode;
        }
        // link from top
        if (i != 0) {
          int fakej = 0, fakei = 0;
          int link = 0;
          curr = meta;
          while (fakej != j + 1 && curr->right != NULL) {
            curr = curr->right;
            fakej++;
          }

          while (fakei != i && curr->down != NULL) {
            curr = curr->down;
            fakei++;
          }
          if (arr[i - 1][j] == 1 && fakei == 0)
            curr->down = datanode;
          else if (curr != NULL && curr->col == j) {
            curr->down = datanode;
            link = 1;
          }

          fakej = 0;
          fakei = 0;
          curr = meta;
          while (fakei != i && curr->down != NULL) {
            curr = curr->down;
            fakei++;
          }
          while (fakej != j + 1 && curr->right != NULL) {
            curr = curr->right;
            fakej++;
          }
          if (arr[i - 1][j] == 1 && fakei == 0)
            curr->down = datanode;
          else if (curr != NULL && curr->col == j) {
            curr->down = datanode;
            link = 1;
          }
        }
      }
    }
  }

  return meta;
}

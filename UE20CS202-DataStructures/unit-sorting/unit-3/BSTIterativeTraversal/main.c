#include "1_1.h"
#include <stdio.h>

int main() {
  struct stack *st = (struct stack *)malloc(sizeof(struct stack));
  st->top = -1;
  struct node *root;
  root = (struct node *)malloc(sizeof(struct node));
  root->data = -1;

  while (true) {
    printf("1.BST Insertion \n");
    printf("2.Iterative Postorder Traversal \n");
    printf("3.Interative Preorder Traversal \n");
    printf("4.Interative Inorder Traversal \n");
    printf("Enter choice : ");
    int choice = 0;
    scanf("%d", &choice);
    if (choice == 1) {
      int d;
      printf("Enter data to be inserted : ");
      scanf("%d", &d);
      BSTInsertion(root, d);
    } else if (choice == 2) {
      printf("BST in Postorder : \n");
      printf("Start of traversal ->");
      BSTIterativePostorder(root, st);
      printf("End of traversal \n");
    } else if (choice == 3) {
      printf("BST in Preorder : \n");
      printf("Start of traversal ->");
      BSTIterativePreorder(root, st);
      printf("End of traversal \n");
    } else if (choice == 4) {
      printf("BST in Inorder : \n");
      printf("Start of traversal ->");
      BSTIterativeInorder(root, st);
      printf("End of traversal\n");
    }
  }
}

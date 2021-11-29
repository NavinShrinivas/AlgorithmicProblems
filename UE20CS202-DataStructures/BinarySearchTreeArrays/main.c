#include "1_1.h"
#include <stdio.h>

int main() {
  int tree[treesize] = {0}; // initialising with 0
  tree[0] = -1;             // start of array should aways be -1
  while (true) {
    printf("1.Insert Element \n");
    printf("2.Inorder Traversal \n");
    printf("3.Preorder Traversal \n");
    printf("4.Postorder Traversal \n");
    printf("5.Delete from tree \n");
    int choice;
    printf("Enter choice : ");
    scanf("%d", &choice);
    if (choice == 1) {
      int d;
      printf("Enter element to insert to tree : ");
      scanf("%d", &d);
      BSTInsertion(tree, d, 1);
    } else if (choice == 2) {
      printf(" \nStart of tree ->");
      BSTInorderTraversal(tree, 1);
      printf("->End of tree \n \n");
    } else if (choice == 3) {
      printf(" \nStart of tree ->");
      BSTPreorderTraversal(tree, 1);
      printf("->End of tree \n \n");
    } else if (choice == 4) {
      printf(" \nStart of tree ->");
      BSTPostorderTraversal(tree, 1);
      printf("->End of tree \n \n");
    } else if (choice == 5) {
      int d;
      printf("Enter number to delete : ");
      scanf("%d", &d);
      BSTDelete(tree, d, 1);
    }
  }
}

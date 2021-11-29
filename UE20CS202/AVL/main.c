#include "1_1.h"

int main() {
  struct node *root = NULL;
  while (true) {
    int choice;
    printf("1.Insert to AVL \n");
    printf("Enter choice : ");
    scanf("%d", &choice);

    if (choice == 1) {
      int d;
      printf("\n Enter element to insert : ");
      scanf("%d", &d);
      AVLInsert(root, d);
    }
  }
}

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

// NOTES : WIP , as for this course UE20CS202 this AVL code is never gonna be
// asked, but ill get to it when i have the time , seem like a challenge

#include "1_1.h"
#include <stdio.h>

// n/2 will be the posistion for the node for the last child!!!!!
// log : n is the last child , n/2 is ofc its nide

int main() {
  int tree[100] = {0};
  while (true) {
    printf("1.Insert \n");
    int choice;
    printf("Enter choice :");
    scanf("%d", &choice);
    if (choice == 1) {
      int d;
      printf("Enter element to insert : ");
      scanf("%d", &d);
      HeapInsert(tree, d);
    }
  }
}

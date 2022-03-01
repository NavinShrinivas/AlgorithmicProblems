#include "1_1.h"
#include <stdio.h>

// This code is no where near complete, In fact it is wrong :()

int main() {
  printf("Enter size of graph within 1000 : ");
  int size;
  scanf("%d", &size);
  int a[1000][1000] = {0};

  while (true) {
    printf("1.Create edge \n");
    printf("2.Source removal traversal \n");
    printf("Enter choice : ");

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      printf("Enter values of 2 nodes : ");
      int n, m;
      scanf("%d %d", &n, &m);
      insert_edge(a, n, m);
    } else if (choice == 2) {
      source_removal(a, size);
      printf("\n");
    }
  }
}

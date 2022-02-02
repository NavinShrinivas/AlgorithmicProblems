#include "1_1.h"
#include <stdio.h>

int main() {
  list_t list;
  init_list(&list);

  while (true) {
    printf("1.Enter a element as a first node to a list \n");
    printf("2.Display all elements of a list [RECURSION]\n");
    printf("3.Numbers of nodes in the list [RECUSION]\n");
    printf("4.Copy the list to a new list[RECURSION] \n");
    printf("5.Reverse the list [RECURSION] \n");
    printf("Enter choice : ");
    int choice;
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {

      printf("Enter element to enter to list : ");
      int n;
      scanf("%d", &n);
      prepend_list(&list, n);
      printf("Inserted to list \n \n");

    } else if (choice == 2) {

      printf("The list : \n");
      printf("Start of list -> ");
      display_list(&list);
      printf("End of list \n \n");

    } else if (choice == 3) {

      printf("Number of node in the list : %d \n \n", no_node(&list));

    } else if (choice == 4) {

      printf("Copying to new list ...\n");
      list_t newlist;
      init_list(&newlist);
      copy_list(&list, &newlist);
      printf("Done copying \n");
      printf("New list : \n");
      printf("Start of list -> ");
      display_list(&newlist);
      printf("End of list \n \n");

    } else if (choice == 5) {

      printf("Reversing list ...");
      reverse_list(&list);
      printf("Done revresing list \n \n");

    } else {
      break;
    }
  }
}

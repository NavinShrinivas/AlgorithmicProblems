#include "1_1.h"
#include <stdio.h>

int main() {
  int n;
  printf("Enter number of elements to sort : ");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elemnts : \n");
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    a[i] = c;
  }
  int once = 0;
  while (!once) {
    printf("How to want to sort the above numbers ?\n");
    printf("1.Selection sort \n");
    printf("2.Bubble sort \n");
    printf("3.Better Bubble sort \n");
    printf("Enter choice : ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
      selection_sort(a, a + n);
      once = 1;
    } else if (choice == 2) {
      bubble_sort(a, a + n);
      once = 1;
    } else if (choice == 3) {
      better_bubble_sort(a, a + n);
      once = 1;
    } else {
      once = 1;
    }
  }
  printf("After sorting using above chosen sort : \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

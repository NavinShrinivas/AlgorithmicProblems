#include "1_1.h"
#include <stdio.h>

int main() {
  int (*fn_ptr)(int, int); // a callback
  fn_ptr = add;
  int n;
  printf("Enter number of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  int a[n];
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    a[i] = c;
  }
  while (1) {
    printf("1.Find sum off elements in the array \n");
    printf("2.Find product of elements in the array \n");
    printf("3.Are all elements odd? \n");
    printf("4.Is any one element odd? \n");
    printf("Enter chice : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      printf("\t Sum of elements : %d \n", arr_collect(a, n, 0, add));
    } else if (choice == 2) {
      printf("\t Product of elements : %d \n", arr_collect(a, n, 1, mul));
    } else if (choice == 3) {
      if (is_all(a, n, odd)) {
        printf("\t All elements are odd! \n");
      } else {
        printf("\t Not all elements are odd :( \n)");
      }
    } else if (choice == 4) {
      if (is_any(a, n, odd)) {
        printf("\t One elements is odd! \n");
      } else {
        printf("\t None of the elements are odd :( \n)");
      }
    }
  }
}

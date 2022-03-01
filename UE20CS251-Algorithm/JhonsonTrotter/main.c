#include "1_1.h"

int main() {
  int n;
  printf("Enter number of elements : ");
  scanf("%d", &n);
  node_t *arr[n + 1];
  printf("Enter all the elements : \n ");
  init_and_input(n + 1, arr);
  johnson_trotter(n + 1, arr);
}

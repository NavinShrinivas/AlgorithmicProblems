#include "RandomMatrixH.h"

int main() {
  int n;
  printf("enter the dimention of matrix: ");
  scanf("%d", &n);
  print_rand(n);
  srand(time(0));
  return 0;
}

#include "MatrixAddH.h"
int main() {
  int n;
  printf("enter the dimention of matrix: ");
  scanf("%d", &n);
  srand(time(0));
  struct timespec start;
  struct timespec end;
  int a[n][n], b[n][n];
  gen_matrix(n, a);
  gen_matrix(n, b);
  printf("matrix a:\n");
  print_matrix(n, a);
  printf("matrix b:\n");
  print_matrix(n, b);
  printf("addition of a and b:\n");
  clock_gettime(CLOCK_REALTIME, &start);
  print_sum(n, a, b);
  clock_gettime(CLOCK_REALTIME, &end);
  printf("time %lf \n", time_elapsed(start, end));
  return 0;
}

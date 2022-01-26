#include "MatrixMulH.h"

int main() {
  int n;
  printf("enter the dimention of matrix: ");
  scanf("%d", &n);
  srand(time(0));
  struct timespec start;
  struct timespec end;
  int a[n][n], b[n][n], c[n][n];

  gen_matrix(n, a);
  gen_matrix(n, b);

  printf("matrix a:\n");
  print_matrix(n, a);
  printf("matrix b:\n");
  print_matrix(n, b);

  clock_gettime(CLOCK_REALTIME, &start);
  mul_matrix(n, a, b, c);
  clock_gettime(CLOCK_REALTIME, &end);
  printf("multiplication of a and b:\n");

  print_matrix(n, c);
  printf("time %lf \n", time_elapsed(start, end));
  return 0;
}

#include "IdentityMatrixH.h"

int main() {
  struct timespec start;
  struct timespec end;
  clock_gettime(CLOCK_REALTIME, &start);
  int n;
  printf("enter the matirx size: ");
  scanf("%d", &n);
  print_identity(n);
  clock_gettime(CLOCK_REALTIME, &end);
  printf("time %lf \n", time_elapsed(start, end));
  return 0;
}

#include "IdentityMatrixH.h"

double time_elapsed(struct timespec start, struct timespec end) {
  double t;
  t = (end.tv_sec - start.tv_sec);
  t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}

void print_identity(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        printf("%d	", 1);
      } else {
        printf("%d	", 0);
      }
    }
    printf("\n");
  }
}

#include "MatrixAddH.h"

double time_elapsed(struct timespec start, struct timespec end) {
  double t;
  t = (end.tv_sec - start.tv_sec);
  t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}

void gen_matrix(int n, int a[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 100;
    }
  }
}

void print_matrix(int n, int a[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d	", a[i][j]);
    }
    printf("\n");
  }
}

void print_sum(int n, int a[][n], int b[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d	", a[i][j] + b[i][j]);
    }
    printf("\n");
  }
}

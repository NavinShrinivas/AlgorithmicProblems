
#include "RandomMatrixH.h"

void print_rand(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d	", rand() % 100);
    }
    printf("\n");
  }
}

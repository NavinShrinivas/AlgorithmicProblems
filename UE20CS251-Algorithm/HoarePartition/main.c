#include "1_1.h"
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  quick_sort(a, 0, n);
  disp(a, n);
}

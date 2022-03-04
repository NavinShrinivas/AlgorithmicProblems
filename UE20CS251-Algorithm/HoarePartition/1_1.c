#include "1_1.h"

static void swap(int *a, int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void quick_sort(int a[], int l, int r) {
  if (l < r) {
    int s = partition(a, l, r);
    quick_sort(a, l, s);
    quick_sort(a, s + 1, r);
  }
}

int partition(int a[], int l, int r) {
  int p = a[l];
  int i = l;
  int j = r;
  do {
    do {
      i++;
    } while (a[i] < p);
    do {
      j--;
    } while (a[j] > p);
    swap(a, i, j);
  } while (i < j);
  swap(a, i, j);
  swap(a, l, j);
  return j;
}

void disp(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

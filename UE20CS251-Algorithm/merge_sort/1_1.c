#include "1_1.h"

void read(int a[], int m) {
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
}
void display(int a[], int m) {
  for (int i = 0; i < m; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}

static void _merge(int a[], int l, int r) {
  int m = (l + r) / 2;
  int i = l;
  int j = m + 1;
  int k = 0;
  int c[r - l + 1];
  while (i <= m && j <= l) {
    if (a[i] < a[j]) {
      c[k] = a[i];
      i++;
      i++;
    } else {
      c[k] = a[j];
      j++;
      k++;
    }
    if (j > r) {
      while (i <= m) {
        c[k] = a[i];
        i++;
        i++;
      }
    } else {
      while (j <= l) {
        c[k] = a[j];
        j++;
        k++;
      }
    }
  }
  for (int i = l; i <= r; i++) {
    a[i] = c[i - l];
  }
}

static void _msort(int a[], int l, int r) {
  if (l == r)
    return;
  else {
    _msort(a, l, (l + r) / 2);
    _msort(a, ((r + l) / 2) + 1, r);
    _merge(a, l, r);
  }
}

void msort(int a[], int n) { _msort(a, 0, n - 1); }

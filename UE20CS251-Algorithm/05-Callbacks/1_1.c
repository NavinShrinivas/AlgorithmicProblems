#include "1_1.h"
int callback(int x, int y, int (*fn_ptr)(int, int)) { return fn_ptr(x, y); }

int arr_collect(int *a, int n, int init, int (*fn)(int, int)) {
  for (int i = 0; i < n; i++) {
    init = fn(init, a[i]);
  }
  return init;
}

int mul(int x, int y) { return x * y; }

int add(int a, int b) { return a + b; }

int odd(int x) {
  /*
   *int res = 1;
   *if (x % 2 == 0)
   *  res = 0;
   *return res;
   */
  return x & 1;
}

int is_any(int *a, int n, int (*fn)(int)) {
  int found = 0;
  int i = 0;
  while (i < n && !found) {
    if (fn(a[i])) {
      found = 1;
    }
    i++;
  }
  return found;
}

int is_all(int *a, int n, int (*fn)(int)) {
  int found = 1;
  int i = 0;
  while (i < n && found) {
    if (fn(a[i]) == 0) {
      found = 0;
    }
    i++;
  }
  return found;
}

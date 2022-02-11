#include "1_1.h"

void selection_sort(int *a, int *b) {
  int n = b - a;
  for (int i = 0; i < n - 1; i++) {
    int pos = i;
    for (int j = n - 1; j >= i; j--) {
      if (a[j] < a[pos])
        pos = j;
    }
    int temp = a[i];
    a[i] = a[pos];
    a[pos] = temp;
  }
}
void bubble_sort(int *a, int *b) {
  int n = b - a;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}
void better_bubble_sort(int *a, int *b) {
  int n = b - a;
  int i = 0;
  bool is_swapped = true;
  while (is_swapped && i < n - 1) {
    is_swapped = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        is_swapped = true;
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
    i++;
  }
}

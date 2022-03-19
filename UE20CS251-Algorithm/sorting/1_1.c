#include "1_1.h"
// Sorting algorithms the intutive way!

//-----Selection Sort-----
// Find smallest in an array

int find_min(int a[], int n) {
  int min = a[0];
  // If you the number of times a loop is going to be executed, use for loops
  for (int i = 1; i < n; i++) {
    if (a[i] < min)
      min = a[i];
  }
  return min;
}

int find_min_pos(int a[], int n) {
  int min = 0;
  // If you the number of times a loop is going to be executed, use for loops
  for (int i = 1; i < n; i++) {
    if (a[i] < a[min])
      min = i;
  }
  return min;
}

// replace the elements in the array starting from 0 to n-2
// with the smallest element from replacing index to end
// n-1th element will be sorted anyway.
void selection_sort(int *a, int *b) {
  int n = b - a;
  for (int i = 0; i < n - 1; i++) { // note only till n-2
    int pos = i;
    for (int j = n - 1; j >= i; j--) { // does not have to be reverse
      if (a[j] < a[pos])
        pos = j;
    }
    int temp = a[i];
    a[i] = a[pos];
    a[pos] = temp;
  }
}

//-----Bubble Sort-----
// Push the largest to end
// reduce hypotehical end down by 1
// again only have to find and push n-2 biggest elements to sort n-1 elements
void bubble_sort(int *a, int *b) {
  int n = b - a;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i;
         j++) { // only till n-2, why? See the if condition in the loop
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

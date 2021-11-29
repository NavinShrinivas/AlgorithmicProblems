#include "1_1.h"
#include <stdio.h>

void HeapifyMax(int *tree, int i, int n) {
  int left = 2 * i;
  int right = (i * 2) + 1;
  int largest = i;
  if (left <= n && tree[left] > tree[largest])
    largest = left;

  if (right <= n && tree[right] > tree[largest])
    largest = right;

  if (largest != i) {
    int temp = tree[largest];
    tree[largest] = tree[i];
    tree[i] = temp;
    HeapifyMax(tree, largest, n);
  }
}

void HeapInsert(int *tree, int d) {
  int n = 0;
  for (int i = 1; i < ARRSIZE; i++) {
    if (tree[i] == 0) {
      n = i;
      tree[n] = d;
    } else
      continue;
  }
  for (int i = n / 2; i >= 1; i--) {
    HeapifyMax(tree, i, n);
  }
  printf("\nInserted Element to Heap! \n");
}

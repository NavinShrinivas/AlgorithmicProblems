#include "1_1.h"

heap_t *create_heap(int n) {
  heap_t *heap_ptr = malloc(sizeof(heap_t) + (n) * sizeof(int));
  // first element is within the struct
  // n elements
  heap_ptr->key_[0] = n;
  return heap_ptr;
}
void read_heap(heap_t *heap_ptr) {
  int n = heap_ptr->key_[0];
  int *p = &heap_ptr->key_[0];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
}

static void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

static void heapify_(int *p, int n, int i) {
  int node = i;           // parent
  int biggest = node * 2; // left
  int is_heap = 0;
  while (!is_heap &&
         biggest <= n) { // <= cus the left node has ti be within the array
    if (biggest < n && p[biggest + 1] > p[biggest]) {
      // biggest + 1 can be right node if exists
      biggest++; // right node
    }
    if (p[i] > p[biggest])
      is_heap = 1;
    else {
      swap(&p[node], &p[biggest]);
      node = biggest; // we also make sure everything below is heapified, we
                      // still do bottom up
      // in the caller function
      biggest = i * 2;
    }
  }
}

void heapsort(heap_t *heap_ptr) {
  int n = heap_ptr->key_[0];
  int *p = &heap_ptr->key_[0];
  // heapify
  heapify(heap_ptr);
  for (int i = 1; i < n; i++) { // bottom up approach here
    swap(&p[1], &p[n - i + 1]);
    heapify_(p, n - i, 1); // this is why we wrote heapify seperately
  }
}

void heapify(heap_t *heap_ptr) {
  int n = heap_ptr->key_[0];
  int *p = &heap_ptr->key_[0];
  for (int i = n / 2; i >= 1; i--) {
    heapify_(p, n, i);
  }
}
void display(const heap_t *heap_ptr) {
  int n = heap_ptr->key_[0];
  const int *p = &heap_ptr->key_[0];
  for (int i = 1; i <= n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}

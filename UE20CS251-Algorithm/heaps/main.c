#include "1_1.h"

int main() {
  int n;
  heap_t *h;
  scanf("%d", &n);
  h = create_heap(n);
  read_heap(h);
  heapsort(h);
  display(h);
}

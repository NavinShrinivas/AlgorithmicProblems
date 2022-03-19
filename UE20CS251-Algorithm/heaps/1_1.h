#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
// Using struct hack
// 1 based index
// 0th can be size of heap
// Structure has to be created dynmicallcay, see theoruy
struct heap {
  int key_[1];
};

typedef struct heap heap_t;
heap_t *create_heap(int n);
void read_heap(heap_t *heap_ptr);
void heapify(heap_t *heap_ptr);
void display(const heap_t *heap_ptr);
void heapsort(heap_t *heap_ptr);
#endif

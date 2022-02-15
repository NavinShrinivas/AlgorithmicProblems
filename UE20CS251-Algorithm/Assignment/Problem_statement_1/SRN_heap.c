// Name:
// SRN:
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) {
  heap->size = 0;
  heap->max_size = max_size;
  heap->arr = (int *)calloc(max_size, sizeof(int));
  // sizeof int as its sometimes compiler and system dependant
  // default value 0 cus of calloc
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) {
  // the last free space is pointed to by size varaible
  // hence insert there first
  heap->size += 1;
  heap->arr[heap->size] = key;
  int i = heap->size;
  int is_maxheap = 0;
  while (i > 1 && !is_maxheap) {
    if (key <= heap->arr[i / 2]) {
      is_maxheap = 1; // found right place for key value
      *(count_ptr) += 1;
    } else {
      // carries key value to root node
      heap->arr[i] = heap->arr[i / 2];
      // instead ot carrying the key value through out the tree, we just try and
      // find its right place
      *(count_ptr) += 1;
      i /= 2; // not outside else cus need to update i only if not found
    }
  }
  heap->arr[i] = key;
}

/*// *Removes and Returns* the maximum element in the heap*/
/*// and store the number of key comparisons made in the*/
/*// location pointed to by count_ptr.*/
/*int extract_max(heap_t *heap, int *count_ptr) {}*/

/*// Searches for the element key in the heap*/
/*// Returns the element if found, else -1*/
/*int search(const heap_t *heap, int key, int *count_ptr) {}*/

/*// Returns the maximum value of the element in the heap*/
/*// and store the number of key comparisons made in the*/
/*// location pointed to by count_ptr.*/
/*int find_max(const heap_t *heap, int *count_ptr) {}*/

/*// Returns the minimum value in the heap*/
/*int find_min(const heap_t *heap, int *count_ptr) {}*/

/*// Clears the heap for reuse*/
/*void clear_heap(heap_t *heap) {}*/

/*// Frees all resources acquired to initialize heap*/
/*void free_heap(heap_t *heap) {}*/

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
  // as observed in test in client file, 0 is a posible value, hence -1 is
  // indicating empty :
  for (int i = 0; i < heap->max_size; i++)
    heap->arr[i] = -1;
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) {
  // the last free space is pointed to by size varaible
  // hence insert there first
  heap->size += 1; // Doesn't allow values to occupy 0th index
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
int extract_max(heap_t *heap, int *count_ptr) {
  // the deleting node (root) msut be replaced with rightmost element
  int right_farthest = 0;
  for (int i = 0; i < heap->max_size; i++) {
    if (heap->arr[i] != -1) // not key comparisons
      right_farthest = i;
  }
  int largest_value = heap->arr[1];
  heap->size -= 1;
  heap->arr[1] = heap->arr[right_farthest]; // replacing
  heap->arr[right_farthest] = -1;           // deleting

  int is_maxheap = 0;
  int i = 1;
  int largest_pos = i;
  while (!is_maxheap) {
    largest_pos = i;
    int r = (largest_pos * 2) + 1;
    int l = largest_pos * 2;

    if (l < heap->max_size &&
        heap->arr[l] > heap->arr[largest_pos]) { // key comparison
      largest_pos = l;
      *(count_ptr) += 1;
    }
    if (r < heap->max_size &&
        heap->arr[r] > heap->arr[largest_pos]) { // key comparison
      largest_pos = r;
      *(count_ptr) += 1;
    }
    if (largest_pos != i) { // not key comparison
      int temp_ = heap->arr[i];
      heap->arr[i] = heap->arr[largest_pos];
      heap->arr[largest_pos] = temp_;
      i = largest_pos;
    } else {
      is_maxheap = 1;
    }
  }
  return largest_value;
}

/*// Searches for the element key in the heap*/
/*// Returns the element if found, else -1*/
int search(const heap_t *heap, int key, int *count_ptr) {
  // instead of searchign through tree, making use of the array structure
  // We are doing linear search
  int i = 1;
  while (i < heap->max_size && heap->arr[i] != key) {
    *(count_ptr) += 1;
    i++;
  }
  if (i == heap->max_size)
    return -1;
  else
    return heap->arr[i];
}

/*// Returns the maximum value of the element in the heap*/
/*// and store the number of key comparisons made in the*/
/*// location pointed to by count_ptr.*/
int find_max(const heap_t *heap, int *count_ptr) {
  // max heap, thus no need of any comparisons we already know the posistion of
  // max element
  *(count_ptr) = 0;
  return heap->arr[1];
}

/*// Returns the minimum value in the heap*/
int find_min(const heap_t *heap, int *count_ptr) {
  // Again, no need to follow tree paths, just linear search in the array :
  int smallest = heap->arr[1];
  int i = 2;
  while (i < heap->max_size && heap->arr[i] != -1) {
    // the key comparison takes place every time this loop iterates
    *(count_ptr) += 1;
    if (smallest > heap->arr[i]) { // key comparison
      smallest = heap->arr[i];
    }
    i++;
  }
  return smallest;
}

void clear_heap(heap_t *heap) {
  heap->size = 0;
  for (int i = 0; i < heap->max_size; i++)
    heap->arr[i] = -1;
}

/*// Frees all resources acquired to initialize heap*/
void free_heap(heap_t *heap) { free(heap); }

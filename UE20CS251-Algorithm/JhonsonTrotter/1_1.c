#include "1_1.h"
#include <stdio.h>

void init_and_input(int n, node_t *arr[]) {
  for (int i = 0; i < n - 1; i++) {
    int c;
    scanf("%d", &c);
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->value = c;
    temp->direction = 1; // 1 for left
    arr[i] = temp;
  }
  node_t *temp = (node_t *)malloc(sizeof(node_t)); // sentinel
  temp->value = -1;
  temp->direction = 1; // left
  arr[n - 1] = temp;
}

int find_highest_mobile(int n, node_t *arr[]) {
  int ret_index = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (i != 0 && arr[i]->direction == 1) {
      if (arr[i - 1]->value < arr[i]->value) {       // possible mobile
        if (arr[i]->value > arr[ret_index]->value) { // highest mobile
          ret_index = i;
        }
      }
    } else if (i != n - 2 && arr[i]->direction == 0) { // same for rights
      if (arr[i + 1]->value < arr[i]->value) {         // possible mobile
        if (arr[i]->value > arr[ret_index]->value) {   // highest mobile
          ret_index = i;
        }
      }
    }
  }
  return ret_index;
}

static void _swap_node(int s1, node_t *arr[], int n) {
  if (arr[s1]->direction == 1) { // left
    node_t *t = arr[s1];
    arr[s1] = arr[s1 - 1];
    arr[s1 - 1] = t;
  } else {
    node_t *t = arr[s1];
    arr[s1] = arr[s1 + 1];
    arr[s1 + 1] = t;
  }
}

static void _print_array(int n, node_t *arr[]) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]->value);
  }
  printf("\n");
}

static void _change_direction(int n, int mobile, node_t *arr[]) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i]->value > arr[mobile]->value) {
      if (arr[i]->value == 0)
        arr[i]->value = 1;
      else
        arr[i]->value = 0;
    }
  }
}

void johnson_trotter(int n, node_t *arr[]) {

  while (find_highest_mobile(n, arr) != n - 1) {
    int swap1 = find_highest_mobile(n, arr);
    _print_array(n, arr);
    _swap_node(swap1, arr, n);
    _change_direction(n, swap1, arr);
  }
}

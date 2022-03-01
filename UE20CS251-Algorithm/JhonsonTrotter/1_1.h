#ifndef JHONTROT_H
#define JHONTROT_H
#include <stdio.h>
#include <stdlib.h>
struct node {
  int value;
  int direction;
};
typedef struct node node_t;
void init_and_input(int n, node_t *arr[]);
int find_highest_mobile(int n, node_t *arr[]);
void johnson_trotter(int n, node_t *arr[]);
#endif

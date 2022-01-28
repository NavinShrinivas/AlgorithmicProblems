#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  int key_;
  struct node *next_;
};
typedef struct node node_t;
struct list {
  node_t *head_;
};
typedef struct list list_t;
void init_list(list_t *list);
void prepend_list(list_t *list, int n);
void display_list(list_t *list);
int no_node(list_t *list);
void copy_list(list_t *src, list_t *dst);
void reverse_list(list_t *list);
#endif

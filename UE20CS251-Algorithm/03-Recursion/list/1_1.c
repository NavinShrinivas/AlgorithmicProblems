#include "1_1.h"
#include <stdio.h>

void init_list(list_t *list) { list->head_ = NULL; }
void prepend_list(list_t *list, int n) {
  node_t *new = (node_t *)malloc(sizeof(node_t));
  new->key_ = n;
  new->next_ = list->head_;
  list->head_ = new;
  return;
}

void _disp(node_t *node) {
  if (node) {
    printf("%d ->", node->key_);
    _disp(node->next_);
  }
}

void display_list(list_t *list) {
  _disp(list->head_);
  return;
}

int _count(node_t *node) {
  if (node) {
    return 1 + _count(node->next_);
  } else {
    return 0;
  }
}

int no_node(list_t *list) { return _count(list->head_); }

void *_copy(node_t *src_) {
  if (src_) {
    node_t *dst_ = (node_t *)malloc(sizeof(node_t));
    dst_->key_ = src_->key_;
    dst_->next_ = _copy(src_->next_);
    return dst_;
  } else {
    return NULL;
  }
}

void copy_list(list_t *src, list_t *dst) { dst->head_ = _copy(src->head_); }
/*void reverse_list(list_t *list);*/

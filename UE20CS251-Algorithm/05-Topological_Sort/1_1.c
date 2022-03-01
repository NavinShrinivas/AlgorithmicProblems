#include "1_1.h"
#include <stdio.h>

void insert_edge(int (*a)[1000], int key1, int key2) { a[key1][key2] = 1; }

static int indegree(int (*a)[1000], int key_check) {
  int n = 0;
  for (int i = 0; i < 1000; i++) {
    if (a[i][key_check] == 1)
      n++;
  }
  return n;
}

static int outdegree(int (*a)[1000], int key_check) {
  int n = 0;
  for (int i = 0; i < 1000; i++) {
    if (a[key_check][i] == 1)
      n++;
  }
  return n;
}

static void clear_outdegree(int (*a)[1000], int key1) {
  for (int i = 0; i < 1000; i++) {
    if (a[key1][i] == 1)
      a[key1][i] = 0;
  }
}
static int total_indegree(int a[][1000], int size) {
  int tot = 0;
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++)
      if (a[i][j] == 1)
        tot++;
  }
  return tot;
}
void source_removal(int (*a)[1000], int size) {
  int b[1000][1000];
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++)
      b[i][j] = a[i][j];
  }
  int i = 1;
  int complete = 0;
  int tot = total_indegree(a, size);
  while (complete <= tot) {
    if (indegree(a, i) == 0) {
      printf("%d ", i);
      clear_outdegree(a, i);
      complete++;
    }

    if (i == size)
      i = 0;

    i++;
  }
}

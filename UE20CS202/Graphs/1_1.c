#include "1_1.h"

void queuepush(int *queue, int *top, int *front, int e) {
  if (*top == QUEUESIZE - 1) {
    return;
  } else if (*top == -1 && *front == -1) {
    *top = 0;
    *front = 0;
    *(queue + *top) = e;
    return;
  } else {
    *top = *top + 1;
    *(queue + *top) = e;
    return;
  }
}

void queuepop(int *queue, int *top, int *front) {
  if (*top == -1 && *front == -1) {
    return;
  } else if (*front == *top) {
    printf("%d", *(queue + *front));
    *top = -1;
    *front = -1;
    return;
  } else {
    printf("%d", *(queue + *front));
    *front = *front + 1;
  }
}

int QueuePeek(int *queue, int *top, int *front) {
  if (*top == -1 && *front == -1)
    return -1;
  else
    return *(queue + *front);
}
void GraphInsertEdge(int a[][graphvertices], int n, int m) {
  if (a[n][m] == 1 || a[m][n] == 1) {
    printf("\n This edge already exists! \n \n");
    return;
  } else {
    a[n][m] = 1;
    a[m][n] = 1;
    printf("\n Edge inserted to graph \n \n");
    return;
  }
}

void GraphDFS(int a[][graphvertices], bool visited[graphvertices], int j) {
  if (visited[j] == true) {
    return;
  } else {
    printf("%d ->", j);
    visited[j] = true;
    for (int i = 0; i < graphvertices; i++) {
      if (a[j][i] == 1) {
        GraphDFS(a, visited, i);
      }
    }
  }
}

void GraphBFS(int a[][graphvertices], int j, int *queue, int *top, int *front,
              bool visited[graphvertices]) {
  while (*top != -1 && *front != -1) {
    int s = QueuePeek(queue, top, front);
    queuepop(queue, top, front);
    printf(" ->");
    for (int i = 0; i < graphvertices; i++) {
      if (a[s][i] == 1) {
        if (visited[i] == true)
          continue;
        else {
          queuepush(queue, top, front, i);
          visited[i] = true;
        }
      }
    }
  }
}

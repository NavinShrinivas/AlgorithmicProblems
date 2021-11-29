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

void GraphAllPath(int a[][graphvertices], bool visited[graphvertices],
                  int *path, int s, int d) {
  if (visited[s] == true) {
    return;
  } else if (s == d) {
    for (int i = 0; i < graphvertices; i++) {
      if (path[i] != 0)
        printf(" %d->", path[i]);
    }
    printf("%d\n", d);
  } else {
    visited[s] = true;
    for (int j = 0; j < graphvertices; j++) {
      if (path[j] == 0) {
        path[j] = s;
        break;
      }
    }
    for (int i = 0; i < graphvertices; i++) {
      if (a[s][i] == 1) {
        GraphAllPath(a, visited, path, i, d);
      }
    }
  }

  // after done with this vertex , i.e after finding one path , remove from path
  // and prepare for second path big brain smortness
  visited[s] = false;
  int j;
  for (int j = 0; j < graphvertices; j++) {
    if (path[j] == s) {
      path[j] = 0;
      break;
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

int GraphIndegree(int a[][graphvertices], int v) {
  // every edge that point to the vertex, I know this is undirected graph so
  // both In and Out degree will be the same , but eh!
  int count = 0;
  for (int i = 0; i < graphvertices; i++) {
    if (a[i][v] == 1)
      count++;
  }
  return count;
}

int GraphOutdegree(int a[][graphvertices], int v) {
  // every edge that point to the vertex, I know this is undirected graph so
  // both In and Out degree will be the same , but eh!
  int count = 0;
  for (int i = 0; i < graphvertices; i++) {
    if (a[v][i] == 1)
      count++;
  }
  return count;
}

void IsConnected(int a[][graphvertices], int c, int d) {
  bool flag = false;
  // First using BFS :
  bool visited[graphvertices] = {false};
  int queue[QUEUESIZE];
  int top = -1, front = -1;
  queuepush(queue, &top, &front, c);
  while (top != -1 && front != -1) {
    int s = QueuePeek(queue, &top, &front);
    queuepop(queue, &top, &front);
    if (s == d) {
      flag = true;
      printf("\n Yup!The node are connected :) \n \n");
    }
    for (int i = 0; i < graphvertices; i++) {
      if (a[s][i] == 1) {
        if (visited[i] == true)
          continue;
        else {
          queuepush(queue, &top, &front, i);
          visited[i] = true;
        }
      }
    }
  }
  if (!flag) {
    printf("\n No , they are not connected :( \n \n");
    return;
  }
  return;

  // Using BFs : ahhh you get the idea , imma implement , lator
}

#include "PES2UG20CS237_H.h"
void queuepush(int *queue, int *top, int *front, int e) {
  if (*top == QUEUESIZE - 1) {
    printf("Queue Overflow!!\n");
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
    printf("Queue Underflow!!!\n");
    return;
  } else if (*front == *top) {
    *top = -1;
    *front = -1;
    return;
  } else {
    *front = *front + 1;
  }
}

int queuepeek(int *queue, int *top, int *front) { return *(queue + *front); }

void queuedisplay(int *queue, int *top, int *front) {
  int end = *top;
  printf("Start of queue ->");
  for (int i = *front; i <= end; i++)
    printf("%d ->", *(queue + i));
  printf("End of queue\n");
}
//----------End of Queue stuff-----------//
bool found = false;
void CreateGraphEdge(struct head **graph, int row, int col, int id) {
  struct head *temp = NULL;
  for (int i = 0; i < graphsize; i++) {
    if (graph[i] != NULL) {
      if (graph[i]->row == row && graph[i]->col == col) {
        temp = graph[i];
        break;
      }
    }
  }
  if (temp != NULL) {
    if (temp->link == NULL) {
      struct node *temp_node = (struct node *)malloc(sizeof(struct node));
      temp_node->id = id;
      temp_node->link = NULL;
      temp->link = temp_node;
    } else {
      struct node *curr = temp->link;
      while (curr->link != NULL)
        curr = curr->link;
      struct node *temp_node = (struct node *)malloc(sizeof(struct node));
      temp_node->id = id;
      temp_node->link = NULL;
      curr->link = temp_node;
    }
  } else {
    printf("\nError: Node not found on link to id : %d \n", id);
  }
}

void GenerateAdjList(int dt_row, int dt_col, struct head **graph,
                     int arr[][dt_col]) {
  int id = 1;
  for (int i = 0; i < dt_row; i++) {
    for (int j = 0; j < dt_col; j++) {
      if (arr[i][j] == 0) {
        struct head *new_vertice = (struct head *)malloc(sizeof(struct head));
        new_vertice->id = id;
        new_vertice->row = i;
        new_vertice->col = j;
        new_vertice->link = NULL;
        if (graph[id] == NULL) {
          graph[id] = new_vertice;
        } else {
          printf("Oh oh!!Somthing went wrong :(\n");
        }
        id++;
      }
    }
  }

  // dealing all edges after vertices are created
  id = 1;
  for (int i = 0; i < dt_row; i++) {
    for (int j = 0; j < dt_col; j++) {
      if (arr[i][j] == 0) {
        if (i == 0 && j != 0) {
          if (arr[i][j - 1] == 0) {
            CreateGraphEdge(graph, i, j - 1, id);
          }
        } else if (i != 0 && j == 0) {
          if (arr[i - 1][j] == 0) {
            CreateGraphEdge(graph, i - 1, j, id);
          }
        } else if (i != 0 && j != 0) {
          if (arr[i - 1][j] == 0)
            CreateGraphEdge(graph, i - 1, j, id);
          if (arr[i][j - 1] == 0)
            CreateGraphEdge(graph, i, j - 1, id);
        }
        id++;
      }
    }
  }
}

void pathAdd(int *path, int id) {
  for (int i = 0; i < graphsize; i++) {
    if (path[i] == 0) {
      path[i] = id;
      break;
    }
  }
}

void pathDelete(int *path) {
  for (int i = 0; i < graphsize; i++) {
    if (path[i] == 0 && i != 0) { // bruh mem checks killing me :,(
      path[i - 1] = 0;
    }
  }
}

void DFSPathFinder(struct head **graph, int dt_row, int dt_col, int st_row,
                   int st_col, bool *visited, int *path) {
  for (int i = 0; i < graphsize; i++) {
    if (graph[i] != NULL) {
      if (graph[i]->row == dt_row && graph[i]->col == dt_col &&
          found == false) {
        // magic moment :cri:
        found = true; // this is because this s recurse function , we could
                      // reach dest from multiple path , to stop that
        FILE *fp = fopen("./dfsout.txt", "w+");
        fprintf(fp, "1\n");
        for (int i = 0; i < graphsize; i++) {
          if (path[i] == 0)
            break;
          else {
            fprintf(fp, "%d\n", path[i]);
          }
        }
        printf("DFS path successfully written to ./dfspath.txt \n");
        return;
      }
      if (graph[i]->row == st_row && graph[i]->col == st_col) {
        struct node *temp = graph[i]->link;
        while (temp != NULL) {
          if (visited[temp->id] == false) {
            visited[temp->id] = true;
            pathAdd(path, temp->id);
            for (int i = 0; i < graphsize; i++) {
              if (graph[i] != NULL) {
                if (graph[i]->id == temp->id) {
                  DFSPathFinder(graph, dt_row, dt_col, graph[i]->row,
                                graph[i]->col, visited, path);
                }
              }
            }
          }
          // If it has come back means it is a dead end OR path has been found ,
          // hence need to pop from path array i could have used a stack but
          // this function is already large enuf xD
          pathDelete(path);
          temp = temp->link;
        }
      }
    }
  }
  return;
}

int IDReturn(struct head **graph, int row, int col) {
  for (int i = 0; i < graphsize; i++) {
    if (graph[i] != NULL) {
      if (graph[i]->col == col && graph[i]->row == row)
        return graph[i]->id;
    }
  }
  return -1; // does not exist
}

void BFSPathFinder(struct head **graph, int dt_row, int dt_col, int st_row,
                   int st_col, bool *visited) {
  int queue[QUEUESIZE];
  int top = -1;
  int front = -1;
  if (IDReturn(graph, st_row, st_col) != -1) {
    queuepush(queue, &top, &front, IDReturn(graph, st_row, st_col));
    visited[IDReturn(graph, st_row, st_col)] = true;
  }

  int path[graphsize] = {0};
  while (top != -1 && front != -1) {
    int s = queuepeek(queue, &top, &front);
    queuepop(queue, &top, &front);
    pathAdd(path, s);
    if (s == IDReturn(graph, dt_row, dt_col)) {
      FILE *fp = fopen("./bfsout.txt", "w+");
      for (int i = 0; i < graphsize; i++) {
        if (path[i] == 0)
          break;
        else {
          fprintf(fp, "%d\n", path[i]);
        }
      }
      printf("BFS path successfully written to ./bfsout.txt \n");
      return;
    }
    if (graph[s]->link != NULL) {
      struct node *temp = graph[s]->link;
      while (temp != NULL) {
        if (visited[temp->id] == false) {
          visited[temp->id] = true;
          queuepush(queue, &top, &front, temp->id);
        }
        temp = temp->link;
      }
      // There is not concept of going back in BFS hence if founf foudn , else
      // no
    }
  }
}

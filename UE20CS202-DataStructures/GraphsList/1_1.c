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

int queuepeek(int *queue, int *top, int *front) {
  if (*top == -1 && *front == -1)
    return -1;
  else
    return *(queue + *front);
}

//----------End of queue stuff----------

void GraphInsertEdge(struct root **graph, int n, int m) {
  if (graph[n] == NULL) {
    // we also need to create a root node is NULL
    // i could have easily avoided this , but im staying true to the data
    // structure
    struct root *newroot = (struct root *)malloc(sizeof(struct root));
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = m;
    newnode->link = NULL;
    newroot->link = newnode;
    graph[n] = newroot;
    printf("\n Edge created in graph! \n \n");
    return;
  } else {
    // meaning root has been created , meaning a vertices already exists
    struct node *prev = graph[n]->link;
    struct node *curr = prev->link;
    while (curr != NULL) {
      if (prev->data == m) { // this is acitng littul weird , would be nice if
                             // someone can figure out why
        printf("\n This edge already exists , Stop breaking me \n \n");
        return;
      }
      prev = curr;
      curr = prev->link;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = m;
    newnode->link = NULL;
    prev->link = newnode;
    printf("\n Edge create in graph \n \n");
    return;
  }
}

// recursive function
void GraphDFS(struct root **graph, bool *visited, int j) {
  if (visited[j] == true) {
    return;
  } else {
    printf("%d ->", j);
    visited[j] = true;
    if (graph[j] != NULL) { // i.e if there are any edges from this new root
      struct node *curr = graph[j]->link;
      while (curr != NULL) {
        GraphDFS(graph, visited, curr->data);
        curr = curr->link;
      }
    }
  }
  return;
}

// iterative with queue
void GraphBFS(struct root **graph, int j) {
  // little diff from matrix rep
  // ill be creating visited array and queue here
  int queue[QUEUESIZE];
  int top = -1, front = -1;
  bool visited[graphsize] = {false};
  visited[j] = true;
  queuepush(queue, &top, &front, j);
  printf("\n Start of traversal ->");
  while (top != -1 && front != -1) {
    int s = queuepeek(queue, &top, &front);
    queuepop(queue, &top, &front); // pop is printing
    printf(" ->");
    if (graph[s] != NULL) {
      struct node *curr = graph[s]->link;
      while (curr != NULL) {
        if (visited[curr->data] != true) {
          queuepush(queue, &top, &front, curr->data);
          visited[curr->data] = true;
          curr = curr->link;
        } else {
          curr = curr->link;
        }
      }
    }
  }
  printf("End of traversal \n \n");
}

// for an undirected graph both indegree and outdegree are same
// implmenting indegree is harder for lists, this is what ive done
void GraphIndegree(struct root **graph, int v) {
  int ans = 0;
  for (int i = 0; i < graphsize; i++) {
    if (graph[i] != NULL) {
      struct node *curr = graph[i]->link;
      while (curr != NULL) {
        if (curr->data == v)
          ans += 1;
        curr = curr->link;
      }
    }
  }
  printf(" \n Indegree/Outdegree of the above node : %d \n \n", ans);
}

void GraphConnected(struct root **graph, int n, int m) {
  if (graph[n] != NULL) {
    struct node *curr = graph[n]->link;
    while (curr != NULL) {
      if (curr->data == m) {
        printf("\n Yup the two nodes are connected. \n \n");
        return;
      }
      curr = curr->link;
    }
  } else if (graph[m] != NULL) {
    // this else if case not needed for undirect,but eh
    struct node *curr = graph[m]->link;
    while (curr != NULL) {
      if (curr->data == n) {
        printf("\n Yup the two nodes are connected. \n \n");
        return;
      }
      curr = curr->link;
    }
  } else {
    printf("\n Nope The two nodes are not connected! \n \n");
    return;
  }
  printf("\n Nope the two nodes are not connected! \n \n");
}

#include "1_1.h"

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
    if (temp->link != NULL) {
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
      temp->link = temp_node;
      curr->link = temp_node;
    }
  } else {
    printf("Oh noooo!! Something went wrong :( \n");
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
        } else {
          if (arr[i - 1][j] == 0)
            CreateGraphEdge(graph, i - 1, j, id);
          if (arr[i][j - 1])
            CreateGraphEdge(graph, i, j - 1, id);
        }
        id++;
      }
    }
  }
}

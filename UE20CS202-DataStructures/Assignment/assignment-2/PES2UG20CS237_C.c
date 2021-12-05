#include "PES2UG20CS237_H.h"
#include <stdio.h>

int main() {
  struct head *graph[graphsize] = {NULL}; // easy to tell when empty
  int st_row, st_col, dt_row, dt_col;
  scanf("%d %d", &st_row, &st_col);
  scanf("%d %d", &dt_row, &dt_col);
  int arr[dt_row + 1][dt_col + 1];
  for (int i = 0; i < dt_row + 1; i++) {
    for (int j = 0; j < dt_col + 1; j++) {
      scanf("%d", (*(arr + i) + j));
    }
  }
  fflush(stdout);
  GenerateAdjList(dt_row + 1, dt_col + 1, graph, arr);
  // below was for debugging purposes
  /*
   *printf("%d->%d->%d", graph[2]->id, graph[2]->link->id,
   *       graph[2]->link->link->id);
   */
  // DFS first :
  bool visited[graphsize] = {false};
  int path[graphsize] = {0};
  found = false;
  DFSPathFinder(graph, dt_row, dt_col, st_row, st_col, visited, path);
  bool visited1[graphsize] = {false};
  BFSPathFinder(graph, dt_row, dt_col, st_row, st_col, visited1);
}

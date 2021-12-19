#include "1_1.h"
#include <stdio.h>

int main() {
  // little queue stuff
  int queue[QUEUESIZE];
  int top = -1, front = -1;
  //------------------
  int a[graphvertices][graphvertices] = {0}; // initializing with 0's
  printf(" This program considers all edges undirected\n \n");
  while (true) {
    printf("1.Inserted edge to graph \n");
    printf("2.DFS using Recursion \n");
    printf("3.BFS using Queue \n");
    printf("4.Indegree of a vertice \n");
    printf("5.Out degree of a vertice \n");
    printf("6.Find all paths between two vertices \n");
    printf("7.Are two vertices connected? \n");
    printf("Enter choice : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      int m, n;
      printf(" \n Enter two vertices the edge connects : ");
      scanf("%d %d", &m, &n);
      GraphInsertEdge(a, n, m);
    } else if (choice == 2) {
      int j;
      printf("Enter node to start traversal : ");
      scanf("%d", &j);
      printf("\n ");
      bool visited[graphvertices] = {false};
      GraphDFS(a, visited, j);
      printf("End of graph traversal \n \n");
    } else if (choice == 3) {
      int j;
      printf("Enter node to start traversal : ");
      scanf("%d", &j);
      printf("\n ");
      bool visited[graphvertices] = {false};
      visited[j] = true;
      queuepush(queue, &top, &front, j);
      GraphBFS(a, j, queue, &top, &front, visited);
      printf(" End of graph traversal\n \n");
    } else if (choice == 4) {
      int v;
      printf("Enter vertice to find Indegree :  ");
      scanf("%d", &v);
      printf(" \n Indegree of %d : %d \n \n", v, GraphIndegree(a, v));
    } else if (choice == 5) {
      int v;
      printf("Enter vertice to find Outdegree :  ");
      scanf("%d", &v);
      printf(" \n Outdegree of %d : %d \n \n", v, GraphOutdegree(a, v));
    } else if (choice == 6) {
      int s, d;
      printf("Enter source and destination with space : ");
      scanf("%d %d", &s, &d);
      printf("\n All paths between the two vertices : \n\n");
      bool visited[graphvertices] = {false};
      int path[graphvertices] = {0};
      GraphAllPath(a, visited, path, s, d);
    } else if (choice == 7) {
      int c, d;
      printf("Enter two vertices : ");
      scanf("%d %d", &c, &d);
      IsConnected(a, c, d);
    } else {
      printf("Buh Byeee :) \n");
      return 0;
    }
  }
}

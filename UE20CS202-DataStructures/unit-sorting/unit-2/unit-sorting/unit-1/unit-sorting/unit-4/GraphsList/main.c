#include "1_1.h"
#include <stdio.h>

int main() {
  struct root *graph[graphsize] = {NULL}; // if NULL the empty,no vertices
  printf(" This program considers all edges undirected\n \n");
  while (true) {
    printf("1.Inserted edge to graph \n");
    printf("2.DFS using Recursion \n");
    printf("3.BFS using Queue \n");
    printf("4.Indegree of a vertice \n");
    printf("5.Out degree of a vertice \n");
    printf("6.Are two vertices connected? \n");
    printf("Enter choice : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      int n, m;
      printf("Enter two number to created edge : ");
      scanf("%d %d", &n, &m);
      GraphInsertEdge(graph, n, m);
      GraphInsertEdge(graph, m, n);
      // above is only cus we are doing a undirected graph
    } else if (choice == 2) {
      printf("Enter node to start traversal from : ");
      int m;
      scanf("%d", &m);
      bool visited[graphsize] = {false};
      printf("\n Start of traversal ->");
      GraphDFS(graph, visited, m);
      printf("End of traversal \n \n");
    } else if (choice == 3) {
      printf("Enter node to start traversal from : ");
      int m;
      scanf("%d", &m);
      GraphBFS(graph, m);
    } else if (choice == 4) {
      printf("Enter node to find Indegree :");
      int v;
      scanf("%d", &v);
      GraphIndegree(graph, v);
    } else if (choice == 5) {
      printf("Enter node to find Outdegree : ");
      int v;
      scanf("%d", &v);
      GraphIndegree(graph, v);
      // indegree and outdegree are same for undirected graph
    } else if (choice == 6) {
      printf("Enter two number to check if connected :");
      int n, m;
      scanf("%d %d", &n, &m);
      GraphConnected(graph, n, m);
    } else {
      printf("Buh Byeee :) \n");
      return 0;
    }
  }
}

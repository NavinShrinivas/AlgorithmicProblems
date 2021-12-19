#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define graphsize 1000 //no more than node 999

struct root{
    struct node* link;
};


struct node{
    int data;
    struct node *link;
}; //for adjacenncy list

void GraphInsertEdge(struct root **graph, int n, int m);
void GraphDFS(struct root **graph, bool *visited, int j); 
void GraphBFS(struct root **graph, int j); 
void GraphIndegree(struct root **graph, int v);
void GraphConnected(struct root **graph, int n, int m);


//Queue stuff  for BFS: 
#define QUEUESIZE 1000

void queuepush(int* queue , int* top , int* front,int e);
void queuepop(int* queue,int* top , int* front);
int queuepeek(int* queue , int* top , int* front);


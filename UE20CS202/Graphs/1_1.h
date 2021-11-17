#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define graphvertices 1000

void GraphInsertEdge(int a[][graphvertices], int n, int m); 
void GraphDFS(int a[][graphvertices], bool visited[graphvertices], int j);
void GraphBFS(int a[][graphvertices], int j, int *queue, int *top, int *front,bool visited[graphvertices]);

//queue stuff
#define QUEUESIZE 100

void queuepush(int* queue , int* top , int* front,int e);
void queuepop(int* queue,int* top , int* front);
void queuepeek(int* queue , int* top , int* front);
void queuedisplay(int* queue , int* top, int* front);

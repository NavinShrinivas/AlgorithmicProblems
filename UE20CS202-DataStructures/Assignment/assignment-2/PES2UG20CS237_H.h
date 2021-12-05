#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



#define graphsize 1000 //1000 should be sufficient for all given problems

extern bool found;
struct head{
    int id;
    int row,col;
    struct node* link;
};


struct node{
    int id;
    struct node* link; //we dont need left right crap , cus graph :)) , directed also.
};

//A little smortness is induced here.Instead of storing row and col in every node.
//the the two digit number stored in the array along with the link to start of list
//will always be refrenced for getting row and col.(head struct)
//space complexity go stonks
//If you are reffering my code , please be sane and dont do this space complexity thing
//It killed me , literally , this is the reason the functions are so hige



void GenerateAdjList(int dt_row, int dt_col, struct head **graph,int arr[][dt_col]);
void DFSPathFinder(struct head **graph, int dt_row, int dt_col, int st_row,int st_col, bool *visited, int *path) ;
void BFSPathFinder(struct head **graph, int dt_row, int dt_col, int st_row,int st_col, bool *visited);

//Queue stuff for BFS : 
#define QUEUESIZE 100

void queuepush(int* queue , int* top , int* front,int e);
void queuepop(int* queue,int* top , int* front);
int queuepeek(int* queue , int* top , int* front);
void queuedisplay(int* queue , int* top, int* front);


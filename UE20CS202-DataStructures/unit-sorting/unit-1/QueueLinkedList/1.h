#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>


struct node{
    int data;
    struct node* link;
};
struct head{
    struct node* link;
    int size;
};
void queuepush(struct head* queue,int e);
void queuepop(struct head* queue);
void queuedisplay(struct head* queue);
void queuepeek(struct head* queue);

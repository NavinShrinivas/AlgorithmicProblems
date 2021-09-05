#include<stdio.h>
#include<stdlib.h>


struct head{
    struct node* link;
    int nodes;
};

struct node{
    int data;
    struct node* link;
};

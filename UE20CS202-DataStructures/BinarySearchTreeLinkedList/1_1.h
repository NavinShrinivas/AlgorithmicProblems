#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
    int data;
    struct node* l;
    struct node* r;
};


void BSTInsertion(struct node* root , int d);
void BSTInorderTraversal(struct node* root);

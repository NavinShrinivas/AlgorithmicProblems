#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
 
 
struct node{ 
    int data; 
    struct node* l; 
    struct node* r; 
}; 
 
#define STACKSIZE 100 
 
struct vnode{ 
    struct node* n; 
    int vleft; 
    int vright; 
}; 
 
struct stack{ 
    int top; 
    struct vnode* data[STACKSIZE]; 
}; 
 
void pushe(struct stack* st , struct vnode* d); 
void pope(struct stack* st); 
void BSTInsertion(struct node* root , int d); 
void BSTIterativePostorder(struct node* root , struct stack* st); 
void BSTIterativePreorder(struct node* root , struct stack* st); 
void BSTIterativeInorder(struct node* root , struct stack* st);

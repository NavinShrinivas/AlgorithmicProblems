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
    int top;
};

void pushe(struct head* head , int d);
void pope(struct head* head);
void displaystack(struct head* head);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct node{
    char data;
    struct node* link;
};

struct head{
    struct node* link;
    int top;
};

void pushe(struct head* head , char d);
void pope(struct head* head);
void displaystack(struct head* head);
char stacktop(struct head* head);

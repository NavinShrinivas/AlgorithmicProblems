#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define STACKSIZE 10

struct stack{
    int top;
    int data[STACKSIZE];
};

void pushe(struct stack* st , int d);
void pope(struct stack* st);
void displaystack(struct stack* st);

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
    int height; //very imp to easily calc BF
};





#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



#define graphsize 1000 //1000 should be sufficient for all given problems

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



void GenerateAdjList(int dt_row, int dt_col, struct head **graph,int arr[][dt_col]); 


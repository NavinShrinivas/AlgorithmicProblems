#include "1_1.h"
#include <stdio.h>


void BSTInsertion(struct node *root , int d)
{
    if(root->data < 0){
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        root->data = d;
        root->l = NULL;
        root->r = NULL;
        printf("\n--------------------------\n");
        printf("Data %d inserted to BST! :))", root->data);
        printf("\n----------------------------\n");
        return;
    }
    else if(root->data > d){
        if(root->l == NULL){
            struct node* temp = (struct node*) malloc(sizeof(struct node));
            temp->data = d;
            temp->l = NULL;
            temp->r =NULL;
            root->l = temp;
            printf("\n--------------------------\n");
            printf("Data inserted to BST! :))");
            printf("\n----------------------------\n");
            return;
        }
        else{
            BSTInsertion(root->l,d);
        }
    }
    else{
        if(root->r == NULL){
            struct node* temp = (struct node*) malloc(sizeof(struct node));
            temp->data = d;
            temp->l = NULL;
            temp->r =NULL;
            root->r = temp;
            printf("\n--------------------------\n");
            printf("Data inserted to BST! :))");
            printf("\n----------------------------\n");
            return;
        }
        else{
            BSTInsertion(root->r,d);
        }
    }
}

void BSTInorderTraversal(struct node* root){
    if(root == NULL){
        return;
    }

    //LNR
    BSTInorderTraversal(root->l);
    printf("%d-> ",root->data);
    BSTInorderTraversal(root->r);
}

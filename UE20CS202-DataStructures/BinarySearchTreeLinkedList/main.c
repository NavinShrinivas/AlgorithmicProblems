#include "1_1.h"
#include <stdio.h>

int main(){

    struct node* root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data = -1;

    while(true){
        printf("1.BST Insertion \n");
        printf("2.BST deletion\n");
        printf("3.Inorder traversing \n");
        printf("4.Preorder Traversal \n"); 
        printf("5.Post order traversal \n");
        printf("6.Searching  for an element \n");
        printf("Enter choice : ");
        int choice=0;
        scanf("%d",&choice);
        if(choice == 1)
        {
            int d;
            printf("Enter data to be inserted : ");
            scanf("%d",&d);
            BSTInsertion(root , d);
        }
        else if(choice == 3){
            printf("%d",root->data);
            printf("\n--------------------------------\n");
            printf("If the Traversal was succesfull you should see all the elements in sorted order!\n");
            BSTInorderTraversal(root);printf("End of BST");
            printf("\n------------------------------------\n");
        }
    }
}

#include "1_1.h"

void insertnode(struct head* top , int pos , int value)
{
    if(pos==0)//inseting at beginning
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->link = top->link;
        top->link = temp;
        top->nodes=top->nodes+1;
        printf("\n-------------------------------------------------\n");
        printf("Node inserted :)");
        printf("\n-------------------------------------------------\n");
    }
    else if(pos == top->nodes)
    {
        struct node* curr = top->link;
        while(curr->link!=NULL)
            curr=curr->link;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->link=NULL;
        curr->link=temp;
        top->nodes=top->nodes+1;
        printf("\n-------------------------------------------------\n");
        printf("Node inserted :)");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else if(pos > top->nodes || pos<0)
    {
        printf("\n-------------------------------------------------\n");
        printf("Stawwp trying to break me with wrong index :(");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else{
        struct node* curr = top->link;
        struct node* next = curr->link;
        int i=0;
        while(i!=pos-1)
        {
            curr=next;
            next=next->link;
            i++;
        }
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        curr->link=temp;
        temp->link=next;
        top->nodes=top->nodes+1;
        printf("\n-------------------------------------------------\n");
        printf("Node inserted :)");
        printf("\n-------------------------------------------------\n");
        return;
    }
}

void displaylist(struct head* top)
{
    if(top->nodes == 0)
    {
        printf("\n-------------------------------------------------\n");
        printf("The list has been empty all this time you doofus!");
        printf("\n-------------------------------------------------\n");
        return;
    }
    struct node* temp = top->link;
    printf("\n----------------------------------------------------\n");
    while(temp->link!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("%d ->NULL",temp->data);
    printf("\n-----------------------------------------------------\n");
    return;
}

void deletenode(struct head* top , int pos)
{
    if(pos > top->nodes)
    {
        printf("\n-------------------------------------------------\n");
        printf("Stawwp trying to break me with wrong index :(");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else if(top->nodes == 0)
    {
        printf("\n-------------------------------------------------\n");
        printf("There exists no nodes to be delete you good sir!");
        printf("\n-------------------------------------------------\n");
    }
    else if(pos == 0)
    {
        struct node* delnode = top->link;
        top->link = delnode->link;
        free(delnode);
        top->nodes=top->nodes-1;
        printf("\n-------------------------------------------------\n");
        printf("Node deleted!");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else if(pos == top->nodes)
    {
        struct node* prev = top->link;
        struct node* delnode = prev->link;
        while(delnode->link!=NULL)
        {
            prev=delnode;
            delnode=delnode->link;
        }
        prev->link=NULL;
        free(delnode);
        top->nodes=top->nodes-1;
        printf("\n-------------------------------------------------\n");
        printf("Node deleted!");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else{
        struct node* prev = top->link;
        struct node* delnode = prev->link;
        struct node* next = delnode->link;
        int i=1;//0 is handled by other cases luckily
        while(i!=pos)
        {
            prev=delnode;
            delnode=next;
            next=next->link;
            i++;
        }
        prev->link=next;
        free(delnode);
        top->nodes=top->nodes-1;
        printf("\n-------------------------------------------------\n");
        printf("Node deleted!");
        printf("\n-------------------------------------------------\n");
        return;

    }
}

void revlist(struct head* top)
{
    if(top->link->link == NULL)
        return; //only one node , nothing to reverse
    else{
        struct node* curr = top->link;
        struct node* next = curr->link;
        curr->link = NULL;//the first node is becoming last
        while(next->link!=NULL){
            struct node* nextcurr = next;
            struct node* nextnext = next->link;
            next->link=curr;
            next=nextnext;
            curr=nextcurr;
        }
        next->link = curr;
        top->link=next;//the last node becoming first
        printf("\n-------------------------------------------------\n");
        printf("Linked list reversed :))!");
        printf("\n-------------------------------------------------\n");

    }
}

/*
 *void catlist(struct head* list1 , struct head* list 2){
 *struct node* temp = list1->link;
 *while(temp->link!=NULL){
 *temp=temp->link;
 *}
 *temp->link=list2->link;
 *printf(“Two lists have be concatnated”);
 *return;
 *} 
 */

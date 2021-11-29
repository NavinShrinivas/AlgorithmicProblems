#include"1_1.h"

void pushe(struct head* head , char d)
{
    if(head->top == -1)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->link=NULL;
        head->link=temp;
        (head->top)++;
        return;
    }
    else{
        struct node* curr = head->link;
        while(curr->link!=NULL)
            curr=curr->link;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->link=NULL;
        curr->link=temp;
        (head->top)++;
        return;

    }
}

void pope(struct head* head){
    if(head->top == 0)
    {
        head->link=NULL;
        (head->top)--;
        return;
    }
    else{
        struct node* curr = head->link;
        struct node* del = curr->link;
        while(del->link!=NULL)
        {
            curr=del;
            del=del->link;
        }
        curr->link=NULL;
        (head->top)--;
        return;
    }
}

void displaystack(struct head* head)
{
    if(head->top==-1)
    {
        return;
    } 
    printf("Start of stack ->");
    struct node* curr = head->link;
    while(curr->link!=NULL)
    {
        printf("%c ->",curr->data);
        curr=curr->link;
    }
    printf("%c ->",curr->data);
    printf("End of stack\n");
}

char stacktop(struct head* head)
{
    struct node* curr = head->link;
    while(curr->link!=NULL)
        curr=curr->link;
    return curr->data;

}

#include"1.h"


void queuepush(struct head* queue,int e)
{
    if(queue->size==-1)
    {
        struct node* temp =(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=NULL;
        queue->link=temp;
        printf("Element with value %d pushed to queue\n",queue->link->data);
        (queue->size)++;
    }
    else{
        struct node* curr = queue->link;
        while(curr->link!=NULL)
            curr=curr->link;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=e;
        temp->link=NULL;
        curr->link=temp;
        printf("Element with value %d pushed onto stack.\n",e);
        (queue->size)++;
    }
}

void queuepop(struct head* queue)
{
    if(queue->size==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    else if(queue->size == 0)
    {
        printf("Element with value %d popped from queue\n",queue->link->data);
        queue->link=NULL;
        (queue->size)--;
    }
    else{
        printf("Element with value %d popped from queue\n",queue->link->data);
        queue->link=queue->link->link;
        (queue->size)--;
    }
}
void queuedisplay(struct head* queue)
{
    printf("Start of queue->");
    struct node* temp = queue->link;
    while(temp->link!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->link;
    }
    printf("%d ->",temp->data);
    printf("End of queue\n");
}
void queuepeek(struct head* queue)
{
    printf("Front of queue : %d\n",queue->link->data);
    struct node* curr = queue->link;
    while(curr->link!=NULL)
        curr=curr->link;
    printf("Top/Back of queue : %d\n",curr->data);
}

#include"1.h"

void queuepush(int* queue , int* top , int* front,int e)
{
    if(*top == QUEUESIZE-1)
    {
        printf("Queue Overflow!!\n");
        return;
    }
    else if(*top==-1 && *front==-1)
    {
        *top=0;
        *front=0;
        *(queue+*top)=e;
        printf("Element with values %d pushed to back of queue.\n",*(queue+*top));
        return;
    }
    else{
        *top=*top+1;
        *(queue+*top)=e;
        printf("Element with values %d pushed to back of queue.\n",*(queue+*top));
        return;

    }
}

void queuepop(int* queue,int* top , int* front)
{
    if(*top==-1 && *front==-1)
    {
        printf("Queue Underflow!!!\n");
        return;
    }
    else if(*front == *top)
    {
        printf("Popped %d from queue %d %d\n",*(queue+*front),*top,*front);
        *top=-1;
        *front=-1;
        return;
    }
    else
    {
        printf("Popped %d from queue\n",*(queue+*front));
        *front=*front+1;
    }
}

void queuepeek(int* queue , int* top , int* front)
{
    printf("Front of queue : %d\n",*(queue+*front));
    printf("Top of queue : %d\n",*(queue+*top));
    return;
}

void queuedisplay(int* queue , int* top, int* front)
{
    int end=*top;
    printf("Start of queue ->");
    for(int i=*front;i<=end;i++)
        printf("%d ->",*(queue+i));
    printf("End of queue\n");
}

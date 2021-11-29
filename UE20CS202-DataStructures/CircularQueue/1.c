#include"1.h"

void queuepush(int* queue , int* top , int* front,int e)
{
    if((*top)+1==*front || (*top == QUEUESIZE-1 && *front==0))
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
        *top=((*top)+1)%QUEUESIZE;
        *(queue+*top)=e;
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
        if(*front==QUEUESIZE)
            *front=*front%QUEUESIZE;
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
    int i=*front;
    while(i!=end+1)
    {
        printf("%d->",*(queue+i));
        i+=1;
        if(i==QUEUESIZE && *top < *front)
            i=i%QUEUESIZE;
    }
    printf("End of queue\n");
}

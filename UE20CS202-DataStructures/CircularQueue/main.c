#include "1.h"

int main()
{
    int queue[QUEUESIZE];
    int top=-1,front=-1;
    while(true)
    {
        printf("1.Push to queue\n");
        printf("2.Pop from queue\n");
        printf("3.Display queue\n");
        printf("4.Peek queue\n");
        printf("5.Exit\n");
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 5)
            return 0;
        else if(choice == 1)
        {
            printf("Enter element to push to queue :");
            int e;
            scanf("%d",&e);
            queuepush(queue, &top , &front , e);
        }
        else if(choice == 2)
        {
           queuepop(queue , &top ,&front); 
        }
        else if(choice == 3)
            queuedisplay(queue,&top,&front);
        else if(choice == 4)
            queuepeek(queue,&top,&front);
    }
}


#include "1_1.h"
#include <stdio.h>

int main()
{
    //considering head of linked list to be front
    struct head* queue=(struct head*)malloc(sizeof(struct head));
    queue->size=-1;
    while(true)
    {
        printf("1.Push onto to queue\n");
        printf("2.Push to front of queue\n");
        printf("3.Pop from queue\n");
        printf("4.Pop from back of queue\n");
        printf("5.Peek from queue\n");
        printf("6.Display queue\n");
        printf("7.Exit\n");
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 7)
            return 0;
        else if(choice == 1)
        {
            int e;
            printf("Enter element to push onto queue : ");
            scanf("%d",&e);
            queuepush(queue ,e);
        }
        else if(choice == 2)
        {
            int e;
            printf("Enter element to push onto queue : ");
            scanf("%d",&e);
            queuepushfront(queue,e);
        }
        else if(choice == 3)
        {
            queuepop(queue);
        }
        else if(choice == 4)
        {
            queuepopback(queue);
        }
        else if(choice == 5)
            queuepeek(queue);
        else if(choice == 6)
            queuedisplay(queue);
    }

}

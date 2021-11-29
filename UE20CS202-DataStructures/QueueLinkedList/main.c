#include "1.h"

int main()
{
    //considering head of linked list to be front
    struct head* queue=(struct head*)malloc(sizeof(struct head));
    queue->size=-1;
    while(true)
    {
        printf("1.Push onto to queue\n");
        printf("2.Pop from queue\n");
        printf("3.Peek from queue\n");
        printf("4.Display queue\n");
        printf("5.Exit\n");
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 5)
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
            queuepop(queue);
        }
        else if(choice == 3)
            queuepeek(queue);
        else if(choice == 4)
            queuedisplay(queue);
    }

}

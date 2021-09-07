#include"1_1.h"

int main(){
    struct head* top = (struct head*)malloc(sizeof(struct head));
    top->nodes = 0;
    while(1)
    {   
        printf("\n1.Insert node at beginning\n");
        printf("2.Insert node in between [indexing from 0]\n");
        printf("3.Insert node at end\n");
        printf("4.Delete node from beginning\n");
        printf("5.Delete node from between[indexing from 0]\n");
        printf("6.Delete node from end\n");
        printf("7.Display the node\n");
        printf("8.Exit\n");
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        {
            int value;
            printf("Enter value : ");
            scanf("%d",&value);
            insertnode(top , 0 , value);
        }
        else if(choice == 2)
        {
            int value;int pos;
            printf("Enter value : ");
            scanf("%d",&value);
            displaylist(top);
            printf("Enter posistion [Indexing starts from 0] : ");
            scanf("%d",&pos);
            insertnode(top , pos , value);
        }
        else if(choice == 3)
        {
            int value;
            printf("Enter value : ");
            scanf("%d",&value);
            insertnode(top,top->nodes,value);
        }
        else if(choice == 4)
        {
            deletenode(top , 0);
        }
        else if(choice == 5)
        {
            int pos;
            displaylist(top);
            printf("Enter index to delete from : ");
            scanf("%d",&pos);
            deletenode(top , pos);
        }
        else if(choice == 6)
            deletenode(top , top->nodes);
        else if(choice == 7)
            displaylist(top);
        else if(choice == 8)
            return 0;


    }
}

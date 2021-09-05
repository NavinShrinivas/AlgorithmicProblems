#include"1_1.h"

int main(){
    struct head* top = NULL;
    top->nodes = 0;
    while(1)
    {
        printf("1.Insert node\n");
        printf("2.Delete node\n");
        printf("3.Display\n");
        printf("4.Exit");
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 4)
            return 0;
        else if(choice == 1)
        {
            int pos;
            int value;
            printf("Enter value : ");
            scanf("%d",&value);
            printf("Enter posistion : ");
            scanf("%d",&pos);
            insertnode(top , pos , value);
        }


    }
}

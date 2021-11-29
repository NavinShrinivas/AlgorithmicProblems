#include "1.h"
int main(){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    while(true)
    {
        printf("1.Push Element\n");
        printf("2.Pop Element\n");
        printf("3.Display Stack\n");
        printf("4.Exit\n");
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 4)
            return 0;
        else if(choice == 1)
        {
           int d;
           printf("Enter element to push : ");
           scanf("%d",&d);
           pushe(st,d);
        }
        else if(choice == 2)
        {
           pope(st); 
        }
        else if(choice == 3)
        {
            displaystack(st);
        }
    }
}

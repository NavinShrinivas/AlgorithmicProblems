#include"1.h"

int main(){
   struct head* head = (struct head*)malloc(sizeof(struct head));
   head->link=NULL;
   head->top=-1;
   while(true)
   {
       printf("1.Push element \n");
       printf("2.Pop element \n");
       printf("3.Display element \n");
       printf("4.Exit\n");
       printf("Enter choice :");
       int choice;
       scanf("%d",&choice);
       if(choice == 4)
           return 0;
        else if(choice ==1)
        {
            int e;
            printf("Enter element to push : ");
            scanf("%d",&e);
            pushe(head , e);
        }
        else if(choice == 2)
            pope(head);
        else if(choice ==3)
            displaystack(head);
   }
}

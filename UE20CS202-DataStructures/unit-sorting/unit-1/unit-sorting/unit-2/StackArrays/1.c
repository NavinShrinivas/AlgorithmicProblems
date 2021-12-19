#include"1.h"

void pushe(struct stack* st , int d)
{
    if(st->top == STACKSIZE-1)
    {
        printf("Stack overflow , Can't add more elements\n");
        return;
    }
    else{
        (st->top)++;
        st->data[st->top]=d;
        printf("Element of value %d is pushed on to stack!\n",st->data[st->top]);
        return;
    }
}

void pope(struct stack* st)
{
    if(st->top==-1)
    {
        printf("Stack Underflow! There is no element to pop.\n");
    }
    else{
        int e=st->data[st->top];
        (st->top)--;
        printf("Element with value %d is popped\n",e);
    }
}
void displaystack(struct stack* st)
{
    printf("Start of stack ->");
    for(int i=0;i<=st->top;i++)
    {
        printf("%d ->",st->data[i]);
    }
    printf("End of stack\n");
}

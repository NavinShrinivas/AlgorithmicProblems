#include"1_1.h"

int precedence(char input)
{
    if(input=='^')
        return 3;
    else if(input == '*' || input == '/')
        return 2;
    else //nothing other than operations can come in
        return 1;
}
void infixpost(struct head* head , char* input)
{
    for(int i=0;i<strlen(input);i++)
    {
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z'))
        {
            printf("%c",*(input+i));
        }
        else if(input[i]=='(')
            pushe(head,'(');
        else if(input[i]==')')
        {
            while(stacktop(head)!='(')
            {
                printf("%c",stacktop(head));
                pope(head);
            }
            pope(head);//removing the last (
        }
        else if(head->top ==-1 || precedence(input[i])>precedence(stacktop(head)))
        {
            pushe(head,input[i]);
        }
        else{
            while(head->top!=-1 && precedence(input[i])<=precedence(stacktop(head)))
            {
                printf("%c",stacktop(head));
                pope(head);
            }
            pushe(head , input[i]);
        }
    }
    while(head->top!=-1)
    {
        printf("%c",stacktop(head));
        pope(head);
    }
}


int main(){
    struct head* head = (struct head*)malloc(sizeof(struct head));
    head->link=NULL;
    head->top=-1; //initially stack is empty
    char input[1000]; //inout buffer
    printf("Enter Expression (With brackets):");
    scanf("%s",input);
    infixpost(head , input);
}


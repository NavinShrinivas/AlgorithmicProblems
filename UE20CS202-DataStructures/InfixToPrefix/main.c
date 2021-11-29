#include"1_1.h"

void srev(char* a , char* input)
{
    for(int i=0;i<strlen(input);i++)
        a[strlen(input)-1-i]=input[i];
}
int precedence(char input)
{
    if(input=='^')
        return 3;
    else if(input == '*' || input == '/')
        return 2;
    else //nothing other than operations can come in
        return 1;
}
void infixpost(struct head* head , char* input,char* ans)
{
    for(int i=0;i<strlen(input);i++)
    {
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z'))
        {
            char temp=*(input+i);
            strcat(ans,&temp);
        }
        else if(input[i]=='(')
            pushe(head,'(');
        else if(input[i]==')')
        {
            while(stacktop(head)!='(')
            {
                char temp=*(input+i);
                strcat(ans,&temp);
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
                char temp=*(input+i);
                strcat(ans,&temp);
                pope(head);
            }
            pushe(head , input[i]);
        }
    }
    while(head->top!=-1)
    {
        char temp=stacktop(head);
        strcat(ans,&temp);
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
    char rev[1000];
    srev(rev,input);
    char ans[1000];
    infixpost(head,rev,ans);
    char copy[1000];
    srev(copy,ans);
    printf("%s",copy);
}

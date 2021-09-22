#include"1_1.h"
int ans=0;
void postfixeval(struct head* head , char* input)
{
    for(int i=0;i<strlen(input);i++)
    {
        if((int)input[i]-48>=0 && (int)input[i]-48<=9)
        {
            pushe(head , input[i]);
        }
        else
        {
            int mida=0;
            switch(input[i])
            {
                case '+':
                {
                    mida=(int)stacktop(head)-48;
                    pope(head);
                    mida+=(int)stacktop(head)-48;
                    pope(head);
                    pushe(head,(char)(mida+48));
                    break;
                }
                case '-':
                {
                    int copy=(int)stacktop(head)-48;
                    pope(head);
                    int secondc = (int)stacktop(head)-48;
                    mida=secondc-copy;
                    pope(head);
                    pushe(head,(char)(mida+48));
                    break;
                }
                case '*':
                {
                    mida=(int)stacktop(head)-48;
                    pope(head);
                    mida*=(int)stacktop(head)-48;
                    pope(head);
                    pushe(head, (char)mida+48);
                    break;
                }
                case '/':
                {
                    mida=(int)stacktop(head)-48;
                    pope(head);
                    mida/=(int)stacktop(head)-48;
                    pope(head);
                    pushe(head, (char)mida+48);
                    break;
                }
            }
        }
    }
}


int main(){
    struct head* head = (struct head*)malloc(sizeof(struct head));
    head->link=NULL;
    head->top=-1; //initially stack is empty
    char input[1000]; //input buffer
    printf("Enter a valid postfix expression:");
    scanf("%s",input);
    postfixeval(head , input);
    printf("Value of above expression : %d",(int)stacktop(head)-48);
}

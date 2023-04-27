//program to reverse a string entered by the user by using stack.
#include<stdio.h>
#include<string.h>
#define max 51
struct Stack
{
    char arr[max];
    int tos;
};
void push(struct Stack *,char);
char pop(struct Stack *);
void reverse(char *,char *);
int isempty(struct Stack);
int main()
{
    char str[max];
    char rev[max];
    char choice;
    do
    {
    fflush(stdin);
    printf("\nEnter a string : ");
    gets(str);
    if(strlen(str)>50)
    {
        printf("\nLength of the string should be less than 50");
        continue;
    }
    reverse(rev,str);
    printf("\noriginal string is : %s",str);
    printf("\nreverse of the string is : %s",rev);
    printf("\nDo you wish to contine(y/n) : ");
    scanf("%c",&choice);
    }while(choice=='y'||choice=='Y');
return 0;
}
void push(struct Stack *ps,char x)
{
    if(ps->tos==max-1)
    {
        printf("\nStack Overflow!!!");
        exit(0);
    }
    ps->arr[++ps->tos]=x;
}
char pop(struct Stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\nStack Underflow!!!");
        exit(0);
    }
    return(ps->arr[ps->tos--]);
}
int isempty(struct Stack s)
{
    if(s.tos==-1)
        return 1;
    else
        return 0;
}
void reverse(char rev[],char str[])
{
    struct Stack s;
    s.tos=-1;
    int i=0;
    while(str[i]!=NULL)
    {
        push(&s,str[i++]);
    }
    i=0;
    while(isempty(s)!=1)
    {
        rev[i++]=pop(&s);
    }
    rev[i]=NULL;
}

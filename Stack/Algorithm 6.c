/*Write a program in C to convert an infix expression into the prefix expression using stack.*/
#include<stdio.h>
#include<ctype.h>
#define max 30
struct stack
{
    char arr[max];
    int tos;
};
void push(struct stack *,char);
char pop(struct stack *);
char peek(struct stack);
int isempty(struct stack);
int isoperand(char);
int prcd(char);
int cmp_prcd(char,char);
void convert(char [ ],char [ ]);
int main()
{
    char infix[max],prefix[max];
    printf("Enter the infix expression : ");
    gets(infix);
    convert(prefix,infix);
    printf("Prefix Expression : %s",prefix);
    return 0;
}
void push(struct stack *ps,char x)
{
    if(ps->tos==max-1)
    {
        printf("Stack Overflow!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
char pop(struct stack *ps)
{
    if(ps->tos==-1)
    {
        printf("Stack Underflow!!!");
        return NULL;
    }
    return(ps->arr[ps->tos--]);
}
char peek(struct stack s)
{
    return(s.arr[s.tos]);
}
int isempty(struct stack s)
{
    return(s.tos==-1);
}
int isoperand(char ch)
{
    return(isalpha(ch)||isdigit(ch));
}
int prcd(char ch)
{
    if(ch=='$')
        return 3;
    else if(ch=='*'||ch=='/'||ch=='%')
        return 2;
    else if(ch=='+'||ch=='-')
        return 1;
}
int cmp_prcd(char optr1,char optr2)
{
    return(prcd(optr2)>=prcd(optr1));
}
void convert(char prefix[],char infix[])
{
    struct stack s;
    char ch;
    int i,j=0;
    s.tos=-1;
    for(i=strlen(infix)-1;i>=0;i--)
    {
        ch=infix[i];
        if(isoperand(ch))
        {
            prefix[j++]=ch;
        }
        else
        {
            while(1)
            {
                if(isempty(s))
                {
                    push(&s,ch);
                    break;
                }
                else
                    if(cmp_prcd(prcd(peek(s)),prcd(ch)))
                    {
                        push(&s,ch);
                        break;
                    }
                    else
                    {
                        prefix[j++]=pop(&s);
                    }

            }
        }
    }
    while(isempty(s)!=1)
    {
        prefix[j++]=pop(&s);
    }
    prefix[j]=NULL;
    strrev(prefix);
}



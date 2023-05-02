/*Program implements algorithm to convert infix expression into postfix expression. Assumption:- user will input valid infix expression only, and 
each operand can be either a single digit or a single alphbate. note: user can enter infix expression containing parenthesis also*/
#include<stdio.h>
#include<ctype.h>
#define max 30
struct stack
{
    char arr[max];
    int tos;
};
typedef struct stack stack;
void push(stack *,char);
char pop(stack *);
char peek(stack);
int isempty(stack);
int isoperand(char);
int prcd(char);
int cmp_prcd(char,char);
void conversion(char [],char []);
int main()
{
    char infix[max],postfix[max];
    printf("Enter Infix Expression : ");
    gets(infix);
    conversion(postfix,infix);
    printf("\nPostfix Expression is : %s",postfix);
    return 0;
}
void push(stack *ps,char x)
{
    if(ps->tos==max-1)
    {
        printf("\nStack Overflow!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
char pop(stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\nStack Underflow!!!");
        return NULL;
    }
    return(ps->arr[ps->tos--]);
}
char peek(stack s)
{
    return(s.arr[s.tos]);
}
int isempty(stack s)
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
    else if(ch=='/'||ch=='*'||ch=='%')
        return 2;
    else if(ch=='+'||ch=='-')
        return 1;
}
int cmp_prcd(char optr1,char optr2)
{
    return(prcd(optr2)>prcd(optr1));
}
void conversion(char postfix[],char infix[])
{
    char ch;
    int i,j=0;
    stack s;
    s.tos=-1;
    for(i=0;infix[i]!=NULL;i++)
    {
        ch=infix[i];
        if(isoperand(ch))
        {
            postfix[j++]=ch;
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
                if(ch=='(')
            {
                push(&s,ch);
                break;
            }
            else
                if(peek(s)=='(')
            {
                push(&s,ch);
                break;
            }
            else
                if(ch==')')
            {
                while(peek(s)!='(')
                {
                    postfix[j++]=pop(&s);
                }
                pop(&s);
                break;
            }
            else
                if(cmp_prcd(peek(s),ch))
            {
                push(&s,ch);
                break;
            }
            else
            {
                postfix[j++]=pop(&s);
            }
        }
        }
    }
    while(isempty(s)!=1)
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]=NULL;
}

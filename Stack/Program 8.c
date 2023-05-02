/*infix to prefix conversion. assumptions: user will enter valid infix expression only, max length of operand can be single digit or single
alphabet, parenthesis are also allowed in the infix expression*/
#include<stdio.h>
#include<string.h>
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
void convert(char [],char []);
int main()
{
    char infix[max],prefix[max];
    printf("Enter infix expression : ");
    gets(infix);
    convert(prefix,infix);
    printf("Prefix Expression : %s",prefix);
    return 0;
}
void push(stack *ps,char x)
{
    if(ps->tos==max-1)
    {
        printf("Stack Overflow!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
char pop(stack *ps)
{
    if(ps->tos==-1)
    {
        printf("Stack Underflow!!!");
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
    else
        if(ch=='/'||ch=='*'||ch=='%')
        return 2;
    else
        if(ch=='+'||ch=='-')
        return 1;
}
int cmp_prcd(char optr1,char optr2)
{
    return(prcd(optr2)>=prcd(optr1));
}
void convert(char prefix[],char infix[])
{
    char ch;
    int i,j=0;
    stack s;
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
                    if(ch==')')
                {
                    push(&s,ch);
                    break;
                }
                else
                    if(peek(s)==')')
                {
                    push(&s,ch);
                    break;
                }
                else
                    if(ch=='(')
                {
                    while(peek(s)!=')')
                    {
                        prefix[j++]=pop(&s);
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


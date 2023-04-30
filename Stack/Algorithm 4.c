/*Write a C program in which takes a valid prefix expression as input then calculates the final evaluated value of this prefix expression using stack.
Assumption:- here user will enter prefix expression with single digit operand only and maximum length of the prefix expression can be 29*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define max 30
struct stack
{
    float arr[max];
    int tos;
};
void push(struct stack *,float);
float pop(struct stack *);
int isoperand(char ch);
float calculate(float,char,float);
float eval_prefix(char []);
int main()
{
    char prefix[max];
    float result;
    printf("Enter a valid prefix expression : ");
    gets(prefix);
    result=eval_prefix(prefix);
    printf("\nResult is %f",result);
    return 0;
}
void push(struct stack *ps,float x)
{
    if(ps->tos==max-1)
    {
        printf("\nStack Overflow!!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
float pop(struct stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\nStack Underflow!!!");
        return -1;
    }
    return ps->arr[ps->tos--];
}
int isoperand(char ch)
{
    return(ch>='0'&&ch<='9');
}
float calculate(float a,char optr,float b)
{
    switch(optr)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '%':
        return fmod(a,b);
    }
}
float eval_prefix(char prefix[])
{
    char ch;
    float a,b,c,result;
    int i;
    struct stack s;
    s.tos=-1;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        ch=prefix[i];
        if(isoperand(ch))
        {
            push(&s,ch-48);
        }
        else
        {
            a=pop(&s);
            b=pop(&s);
            c=calculate(a,ch,b);
            push(&s,c);
        }
    }
    result=pop(&s);
}


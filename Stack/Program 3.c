/*Write a C program which takes a valid postfix expression as input then calculates the final evaluated value of this postfix expression using stack.
Assumption:- here user will enter postfix expression with single digit operand only and maximum length of postfix expression is 29*/
#include<stdio.h>
#include<math.h>
#define max 30
//defining structure Stack
struct Stack
{
    float arr[max];
    int tos;
};
//prototype declaration of programmer defined functions
void push(struct Stack *,float);
float pop(struct Stack *);
int isoperand(char);
float calculate(float,char,float);
float eval_postfix(char []);
//main function starts from here
int main()
{
    char postfix[max];
    float result;
    printf("Enter postfix expression : ");
    gets(postfix);
    result=eval_postfix(postfix);
    printf("\nResult is : %f",result);
    return 0;
}
//defining push function
void push(struct Stack *ps,float x)
{
    if(ps->tos==max-1)
    {
        printf("\nStack Overflow!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
//defining pop function
float pop(struct Stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\nStack Underflow!!!");
        return -1;
    }
    return(ps->arr[ps->tos--]);
}
//defining isoperand function
int isoperand(char ch)
{
    return(ch>='0'&&ch<='9');
}
//defining calculate function
float calculate(float a,char optr,float b)
{
    switch(optr)
    {
    case '+':
        return(a+b);
    case '-':
        return(a-b);
    case '*':
        return(a*b);
    case '/':
        return(a/b);
    case '%':
        return(fmod(a,b));
    }
}
//defining eval_postfix function
float eval_postfix(char postfix[])
{
    struct Stack s;
    s.tos=-1;
    int i;
    char ch;
    float a,b,c,result;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isoperand(ch)==1)
        {
            push(&s,ch-48);
        }
        else
        {
            b=pop(&s);
            a=pop(&s);
            c=calculate(a,ch,b);
            //above three statement can be combined as c=calculate(pop(),ch,pop())
            push(&s,c);
        }
    }
    result=pop(&s);
}


 /*Given a string containing parentheses (e.g., "(()())"),
 determine whether the parentheses are balanced or not.*/
 #include<stdio.h>
 #define max 30
 struct stack
 {
     char arr[max];
     int tos;
 };
 typedef struct stack stack;
 void push(stack *,char);
 char pop(stack *);
 int isempty(stack);
 int check_par_bal(char []);
 int main()
 {
     char expression[max];
     printf("Enter expression : ");
     gets(expression);
     if(check_par_bal(expression))
        printf("\nParenthesis are balanced");
     else
        printf("\nParenthesis are not balanced");
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
int isempty(stack s)
{
    return(s.tos==-1);
}
int check_par_bal(char expression[])
{
    stack s;
    s.tos=-1;
    int i,flag=0;
    char ch;
    for(i=0;expression[i]!=NULL;i++)
    {
        ch=expression[i];
        if(ch=='(')
        {
            push(&s,ch);
        }
        else
            if(ch==')')
        {
            if('('==pop(&s));
            else
                break;
        }
    }
    return(isempty(s));
}

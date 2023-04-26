/*Algorithm to implement push and pop operation on the stack*/
#include<stdio.h>
#define max 5 //assuming max size of stack is 5, so defined a macro max
/*defining a structure named Stack, consists an int type array of
size max, and tos variable representing top of the stack.*/
struct Stack
{
    int arr[max];
    int tos;
};
void push(struct Stack *,int);//push function prototype declaration
int pop(struct Stack *);//pop function prototype declaration
int main()
{
    struct Stack s;//variable s of struct Stack which represents a stack
    s.tos=-1;//initializing top of stack with -1, considering stack is empty initially
    int choice,x;
    //defining a menu with the help of do...while loop
    do
    {
        printf("\nSelect the operation :");
        printf("\n1. push operation");
        printf("\n2. pop operation");
        printf("\n3. Exit the application");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter element to be pushed : ");
            scanf("%d",&x);
            push(&s,x);
            break;
        case 2:
            x=pop(&s);
            printf("\nPopped element is %d\n",x);
            break;
        case 3:
            printf("\nQuitting the Application");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        }
    }while(1);
    return 0;
}
//defining push function
void push(struct Stack *ps,int x)
{
    if(ps->tos==max-1) //check stack overflow
    {
        printf("Stack Overflow!!!!\n\n\n");
        return;
    }
    ps->arr[++ps->tos]=x;
}
//defining pop function
int pop(struct Stack *ps)
{
    if(ps->tos==-1) //check underflow
    {
        printf("\nStack Underflow!!!\n");
        return -1;
    }
    return(ps->arr[ps->tos--]);
}


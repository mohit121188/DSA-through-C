//implementing stack using singly linked list.
#include<stdio.h>
#include<stdlib.h>

//defining structure for node
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
//defining structure for stack
struct stack
{
    node *tos;
};
typedef struct stack stack;
//prototype declarations of the function
void push(stack *,int);
int pop(stack *);
int isempty(stack);
int peek(stack);
void free_nodes(stack *);
//defining the main function
int main()
{
    int choice,x;
    stack s;
    s.tos=NULL;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.isempty");
        printf("\n4.peek");
        printf("\n5.quit");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data element : ");
            scanf("%d",&x);
            push(&s,x);
            break;
        case 2:
            x=pop(&s);
            if(x!=-1)
                printf("\n\"popped element is %d\"\n",x);
            break;
        case 3:
            if(isempty(s))
                printf("\n\"stack is empty\"\n");
            else
                printf("\n\"stack is not empty\"\n");
            break;
        case 4:
            x=peek(s);
            if(x!=-1)
                printf("\n\"top data element in stack is %d\"\n",x);
            else
                printf("\n\"stack is empty\"\n");
            break;
        case 5:
            printf("\n\"quitting the application\"");
            free_nodes(&s);
            printf("\n\"dynamic memory is deallocated and returned to the heap memory pool.\"\n");
            exit(0);
        default:
            printf("\n\"wrong choice try again\"\n");
        }

    }while(1);
    return 0;
}
//1.defining the push function
void push(stack *ps,int x)
{
    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\n\"STACK OVERFLOW: insufficient memory in the heap\"\n");
        return;
    }
    new_node->data=x;
    if(ps==NULL)
    {
        ps->tos=new_node;
        new_node->next=NULL;
        return;
    }
    else
    {
        new_node->next=ps->tos;
        ps->tos=new_node;
        return;
    }
}
//defining pop function
int pop(stack *ps)
{
    node *temp=NULL;
    int x;
    if(ps->tos==NULL)
    {
        printf("\n\"STACK UNDERFLOW\"\n");
        return -1;
    }
    x=ps->tos->data;
    temp=ps->tos;
    ps->tos=ps->tos->next;
    free(temp);
    return x;
}
//defining isempty function
int isempty(stack s)
{
return(s.tos==NULL);
}
//defining peek function
int peek(stack s)
{
    if(s.tos==NULL)
        return -1;
    return(s.tos->data);
}
//defining free_nodes function
void free_nodes(stack *ps)
{
    node *temp=ps->tos;
    if(ps->tos==NULL)
        return;
    while(temp!=NULL)
    {
        free(temp);
        temp=temp->next;
    }
}

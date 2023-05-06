/*Write a C program to reverse the elements of a linear queue.
containing integer elements assumption: max size of linear queue 5*/
#include<stdio.h>
#define MAX 5
#define DEFAULT_STACK {.tos=-1}
#define DEFAULT_QUEUE {.front=-1,.rear=-1}
struct stack
{
    int arr[MAX],tos;
};
struct lqueue
{
    int arr[MAX],front,rear;
};
typedef struct stack stack;
typedef struct lqueue lqueue;
void push(stack *,int);
int pop(stack *);
int isempty_stack(stack);
void enqueue(lqueue *,int);
int dequeue(lqueue *);
int isempty_lqueue(queue);
void reverse(lqueue *);
int main()
{
    lqueue q=DEFAULT_QUEUE;
    int choice,x;
    do
    {
        printf("\nSelect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.reverse");
        printf("\n4.quit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter element : ");
            scanf("%d",&x);
            enqueue(&q,x);
            break;
        case 2:
            printf("\nremoved element : %d\n",dequeue(&q));
            break;
        case 3:
            reverse(&q);
            break;
        case 4:
            printf("\nQuitting");
            exit(0);
        default:
            printf("\nWrong choice!!Try Again!!!");
        }

    }while(1);
    return 0;
}
void push(stack *ps,int x)
{
    if(ps->tos==MAX-1)
    {
        printf("\nStack Overflow!!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
int pop(stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\nStack Underflow!!!");
        return -1;
    }
    return(ps->arr[ps->tos--]);
}
int isempty_stack(stack s)
{
    return(s.tos==-1);
}
void enqueue(lqueue *pq,int x)
{
    if(pq->rear==MAX-1)
    {
        printf("\n!!!Linear Queue Overflow!!!\n");
        return;
    }
    if(pq->rear==-1)
        pq->rear=pq->front=0;
    else
        pq->rear++;
    pq->arr[pq->rear]=x;
}
int dequeue(lqueue *pq)
{
    int x;
    if(pq->front==-1)
    {
        printf("\n!!!Linear Queue Underflow!!!\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==pq->rear)
        pq->front=pq->rear=-1;
    else
        pq->front++;
    return x;
}
int isempty_lqueue(lqueue q)
{
    return(q.rear==-1);
}
void reverse(lqueue *pq)
{
    int i;
    stack s=DEFAULT_STACK;
    if(pq->rear==-1)
    {
        printf("\nLinear Queue is Empty\n");
        return;
    }
    if(pq->rear==pq->front)
    {
        printf("\nSuccessfully Reversed\n");
        return;
    }
    while(isempty_lqueue(*pq)!=1)
        push(&s,dequeue(pq));

    while(isempty_stack(s)!=1)
        enqueue(pq,pop(&s));

    printf("\nSuccessfully Reversed\n");
}

/*SAMPLE OUTPUT : 

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 10

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 10

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

!!!Linear Queue Underflow!!!

removed element : -1

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 3

Linear Queue is Empty

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 100

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 200

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 300

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice :
1

enter element : 400

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 500

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 600

!!!Linear Queue Overflow!!!

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 3

Successfully Reversed

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 500

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 400

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 300

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 200

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 100

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

!!!Linear Queue Underflow!!!

removed element : -1

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 1000

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 3

Successfully Reversed

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 1000

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 2000

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 3000

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 3

Successfully Reversed

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 3000

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 2000

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 4

Quitting
Process returned 0 (0x0)   execution time : 92.003 s
Press any key to continue.
*/

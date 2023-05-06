/*Program to reverse a circular queue*/
#include<stdio.h>
#define MAX 5
#define DEFAULT_STACK {.tos=-1}
#define DEFAULT_QUEUE {.front=-1,.rear=-1}

struct stack
{
    int arr[MAX],tos;
};
struct cqueue
{
    int arr[MAX],front,rear;
};
typedef struct stack stack;
typedef struct cqueue cqueue;
void push(stack *,int);
int pop(stack *);
int isempty_stack(stack);
int peek(stack);
void enqueue(cqueue *,int);
int dequeue(cqueue *);
int isempty_queue(cqueue);
void reverse(cqueue *);
int main()
{
    cqueue q=DEFAULT_QUEUE;
    int choice,x;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.reverse");
        printf("\n4.quit");
        printf("\nenter your choice :  ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the element : ");
            scanf("%d",&x);
            enqueue(&q,x);
            break;
        case 2:
            printf("\n%d is dequeued successfully\n",dequeue(&q));
            break;
        case 3:
            reverse(&q);
            break;
        case 4:
            printf("\nQuitting the Application");
            exit(0);
        default:
            printf("\nWrong Choice!!!Try Again!!!");
        }
    }while(1);
    return 0;
}
void push(stack *ps,int x)
{
    if(ps->tos==MAX-1)
    {
        printf("\n!!!Stack Overflow!!!\n");
        return;
    }
    ps->arr[++ps->tos]=x;
}
int pop(stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\n!!!Stack Underflow!!!\n");
        return -1;
    }
    return(ps->arr[ps->tos--]);
}
int isempty_stack(stack s)
{
    return(s.tos==-1);
}
int peek(stack s)
{
    return(s.arr[s.tos]);
}
void enqueue(cqueue *pq,int x)
{
    if((pq->rear==MAX-1&&pq->front==0)||(pq->rear+1==pq->front))
    {
        printf("\n!!!Circular Queue Overflow!!!\n");
        return;
    }
    if(pq->rear==-1)
        pq->rear=pq->front=0;
    else
    if(pq->rear==MAX-1)
        pq->rear=0;
    else
        pq->rear++;
    pq->arr[pq->rear]=x;
}
int dequeue(cqueue *pq)
{
    int x;
    if(pq->rear==-1)
    {
        printf("\n!!!Circular Underflow!!!\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==pq->rear)
        pq->rear=pq->front=-1;
    else
    if(pq->front==MAX-1)
        pq->front=0;
    else
        pq->front++;
    return x;
}
int isempty_queue(cqueue q)
{
    return(q.rear==-1);
}
void reverse(cqueue *pq)
{
    int i;
    stack s=DEFAULT_STACK;
    if(pq->rear==-1)
    {
        printf("\n!!!Empty Circular Queue!!!\n");
        return;
    }
    if(pq->rear==pq->front)
    {
        printf("\n\"Reversed Successfully\"\n");
        return;
    }

    while(isempty_queue(*pq)!=1)
        push(&s,dequeue(pq));

    while(isempty_stack(s)!=1)
        enqueue(pq,pop(&s));

    printf("\n\"Reversed Successfully\"\n");
}

/* 
SAMPLE OUTPUT : 

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

!!!Empty Circular Queue!!!

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

"Reversed Successfully"

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

10 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 100

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 200

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 300

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 400

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 500

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 600

!!!Circular Queue Overflow!!!

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

"Reversed Successfully"

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

500 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

400 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

"Reversed Successfully"

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

100 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

200 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

300 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

!!!Empty Circular Queue!!!

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

!!!Circular Underflow!!!

-1 is dequeued successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  4

Quitting the Application
Process returned 0 (0x0)   execution time : 99.513 s
Press any key to continue.
*/

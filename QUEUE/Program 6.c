/*Program to reverse a circular queue*/
#include<stdio.h>
#define max 5

struct stack
{
    int arr[max],tos;
};
struct cqueue
{
    int arr[max],front,rear;
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
    cqueue q;
    int choice,x;
    q.front=q.rear=-1;
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
            printf("Rear = %d, Front = %d\n",q.rear,q.front);
            break;
        case 2:
            printf("\n%d is dequeued successfully",dequeue(&q));
            printf("\nRear = %d, Front = %d\n",q.rear,q.front);
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
    if(ps->tos==max-1)
    {
        printf("\n!!!Stack Overflow!!!");
        return;
    }
    ps->arr[++ps->tos]=x;
}
int pop(stack *ps)
{
    if(ps->tos==-1)
    {
        printf("\n!!!Stack Underflow!!!");
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
    if((pq->rear==max-1&&pq->front==0)||(pq->rear+1==pq->front))
    {
        printf("\nCircular Queue Overflow\n");
        return;
    }
    if(pq->rear==-1&&pq->front==-1)
    {
        pq->rear=pq->front=0;
    }
    else
    if(pq->rear==max-1&&pq->front!=max-1)
    {
        pq->rear=0;
    }
    else
    {
        pq->rear=pq->rear+1;
    }
    pq->arr[pq->rear]=x;
}
int dequeue(cqueue *pq)
{
    int x;
    if(pq->rear==-1&&pq->front==-1)
    {
        printf("\n!!!Circular Underflow!!!");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==pq->rear)
    {
        pq->rear=pq->front=-1;
    }
    else
        if(pq->front==max-1&&pq->rear!=max-1)
    {
        pq->front=0;
    }
    else
    {
        pq->front++;
    }
    return x;
}
int isempty_queue(cqueue q)
{
    return(q.rear==-1&&q.front==-1);
}
void reverse(cqueue *pq)
{
    int i;
    stack s;
    s.tos=-1;
    if(pq->rear==-1&&pq->front==-1)
    {
        printf("\nEmpty Circular Queue\n");
        return;
    }
    if(pq->rear==pq->front)
    {
        printf("\nReversed Successfully\n");
        return;
    }

    if(pq->rear>pq->front)
    {

        while(isempty_queue(*pq)!=1)
        {
            push(&s,dequeue(pq));
        }
    }
    else
        if(pq->front>pq->rear)
    {
        while(isempty_queue(*pq)!=1)
        {
            push(&s,dequeue(pq));
        }
    }
    while(isempty_stack(s)!=1)
    {
        enqueue(pq,pop(&s));
    }
    printf("\nReversed Successfully\n");
}

/*sample Output

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 10
Rear = 0, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

Reversed Successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

10 is dequeued successfully
Rear = -1, Front = -1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

Empty Circular Queue

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 100
Rear = 0, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 200
Rear = 1, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 300
Rear = 2, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 400
Rear = 3, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 500
Rear = 4, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 600

Circular Queue Overflow
Rear = 4, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

Reversed Successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

500 is dequeued successfully
Rear = 4, Front = 1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

400 is dequeued successfully
Rear = 4, Front = 2

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

300 is dequeued successfully
Rear = 4, Front = 3

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

200 is dequeued successfully
Rear = 4, Front = 4

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

100 is dequeued successfully
Rear = -1, Front = -1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

!!!Circular Underflow!!!
-1 is dequeued successfully
Rear = -1, Front = -1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 20
Rear = 0, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 40
Rear = 1, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 60
Rear = 2, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 80
Rear = 3, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 100
Rear = 4, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 120

Circular Queue Overflow
Rear = 4, Front = 0

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

20 is dequeued successfully
Rear = 4, Front = 1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

40 is dequeued successfully
Rear = 4, Front = 2

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 120
Rear = 0, Front = 2

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 140
Rear = 1, Front = 2

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  1

Enter the element : 160

Circular Queue Overflow
Rear = 1, Front = 2

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  3

Reversed Successfully

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

140 is dequeued successfully
Rear = 4, Front = 1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

120 is dequeued successfully
Rear = 4, Front = 2

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

100 is dequeued successfully
Rear = 4, Front = 3

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

80 is dequeued successfully
Rear = 4, Front = 4

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

60 is dequeued successfully
Rear = -1, Front = -1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  2

!!!Circular Underflow!!!
-1 is dequeued successfully
Rear = -1, Front = -1

select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
enter your choice :  4

Quitting the Application
Process returned 0 (0x0)   execution time : 203.370 s
Press any key to continue.

*/

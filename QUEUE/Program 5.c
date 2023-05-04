/*Write a C program to reverse the elements of a linear queue.
containing integer elements assumption: max size of linear queue 5*/
#include<stdio.h>
#define max 5
struct stack
{
    int arr[max],tos;
};
struct lqueue
{
    int arr[max],front,rear;
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
    lqueue q;
    int choice,x;
    q.front=q.rear=-1;
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
            printf("\nQueue reversed successfully\n");
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
    if(ps->tos==max-1)
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
    if(pq->rear==max-1)
    {
        printf("\n!!!Linear Queue Overflow!!!\n");
        return;
    }
    if(pq->rear==-1&&pq->front==-1)
    {
        pq->rear=pq->front=0;
    }
    else
    {
        pq->rear=pq->rear+1;
    }
    pq->arr[pq->rear]=x;
}
int dequeue(lqueue *pq)
{
    int x;
    if(pq->front==-1&&pq->rear==-1)
    {
        printf("\n!!!Linear Queue Underflow!!!\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==max-1&&pq->rear==max-1)
    {
        pq->front=pq->rear=-1;
    }
    else
    {
        pq->front=pq->front+1;
    }
    return x;
}
int isempty_lqueue(lqueue q)
{
    return(q.rear==-1&&q.front==-1);
}
void reverse(lqueue *pq)
{
    int i;
    stack s;
    s.tos=-1;
    for(i=pq->front;i<=pq->rear;i++)
        push(&s,pq->arr[i]);
    i=pq->front;
    while(isempty_stack(s)!=1)
    {
        pq->arr[i++]=pop(&s);
    }
}

/*sample output : 

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
Enter your choice : 1

enter element : 20

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 30

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 40

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 1

enter element : 50

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

removed element : 20

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 3

Queue reversed successfully

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 50

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 40

Select the operation :
1.enqueue
2.dequeue
3.reverse
4.quit
Enter your choice : 2

removed element : 30

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
Enter your choice : 4

Quitting
Process returned 0 (0x0)   execution time : 31.120 s
Press any key to continue.

*/

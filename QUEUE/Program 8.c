/*Write a C program to calculate the sum of the elements in a circular queue.
after calculating sum original queue must not be disturbed*/
#include<stdio.h>
#define MAX 5
#define DEFAULT {.front=-1,.rear=-1}
struct cqueue
{
    int arr[MAX],front,rear;
};
typedef struct cqueue cqueue;
void enqueue(cqueue *,int);
int dequeue(cqueue *);
int isempty_queue(cqueue);
int sum(cqueue);
int main()
{
    cqueue q=DEFAULT;
    int choice,x;
    do
    {
        printf("\nSelect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.sum");
        printf("\n4.quit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the element : ");
            scanf("%d",&x);
            enqueue(&q,x);
            break;
        case 2:
            printf("\ndequeued element : %d\n",dequeue(&q));
            break;
        case 3:
            printf("\nsum is %d\n",sum(q));
            break;
        case 4:
            printf("\nQuitting the Application");
            exit(0);
        default:
            printf("\nWrong choice!!try again");
        }
    }while(1);
    return 0;
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
    if(pq->front==-1)
    {
        printf("\n!!!Queue Underflow!!!\n");
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
int sum(cqueue q)
{
    int s=0;
    if(isempty_queue(q)==1)
    {
        printf("\nQueue is Empty\n");
        return 0;
    }
    while(isempty_queue(q)!=1)
        s=s+dequeue(&q);
    return s;
}

/*
SAMPLE OUTPUT

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

Queue is Empty

sum is 0

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 10

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 10

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

Queue is Empty

sum is 0

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 100

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

sum is 100

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 200

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 300

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 400

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 500

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 600

!!!Circular Queue Overflow!!!

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 100

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

sum is 1400

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 1

enter the element : 50

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

sum is 1450

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 200

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 300

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 400

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 500

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

sum is 50

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

dequeued element : 50

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

Queue is Empty

sum is 0

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 2

!!!Queue Underflow!!!

dequeued element : -1

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 3

Queue is Empty

sum is 0

Select the operation :
1.enqueue
2.dequeue
3.sum
4.quit
Enter your choice : 4

Quitting the Application
Process returned 0 (0x0)   execution time : 108.093 s
Press any key to continue.
*/

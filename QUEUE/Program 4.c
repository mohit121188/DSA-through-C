/*Write a C program to count the number of elements in a Circular queue.*/
#include<stdio.h>
#define MAX 5
#define DEFAULTS {.rear=-1,.front=-1}
struct cqueue
{
    int arr[MAX],front,rear;
};
typedef struct cqueue cqueue;
void enqueue(cqueue *,int);
int dequeue(cqueue *);
int isempty(cqueue);
int count(cqueue);
int main()
{
    int choice,x;
    cqueue q=DEFAULTS;
    do
    {
        printf("\nSelect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.count");
        printf("\n4.exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter element : ");
            scanf("%d",&x);
            enqueue(&q,x);
            break;
        case 2:
            printf("\nRemoved elmement : %d",dequeue(&q));
            break;
        case 3:
            printf("\nNo. of elmements : %d\n",count(q));
            break;
        case 4:
            printf("\nQuitting");
            exit(0);
        default:
            printf("\nWrong choice!!Try Again!!");
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
    else
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
        printf("\n!!!Circular Queue Underflow!!!\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->rear==pq->front)
        pq->rear=pq->front=-1;
    else
    if(pq->front==MAX-1)
        pq->front=0;
    else
        pq->front++;
    return x;
}

int isempty(cqueue q)
{
    return(q.rear==-1);
}
int count(cqueue q)
{
    int k=0;
    while(isempty(q)!=1)
    {
        dequeue(&q);
        k++;
    }
    return k;
}

/* SAMPLE OUTPUT

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

!!!Circular Queue Underflow!!!

Removed elmement : -1
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 0

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 10

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 20

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 2

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 10
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 20
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 0

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 100

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 200

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 300

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 400

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 500

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 600

!!!Circular Queue Overflow!!!

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 5

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 100
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 200
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 600

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 700

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 800

!!!Circular Queue Overflow!!!

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 5

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 300
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 400
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 500
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 600
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 700
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

!!!Circular Queue Underflow!!!

Removed elmement : -1
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 0

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 4

Quitting
Process returned 0 (0x0)   execution time : 79.033 s
Press any key to continue.
*/

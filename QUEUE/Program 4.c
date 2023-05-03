/*Write a C program to count the number of elements in a Circular queue.*/
#include<stdio.h>
#define max 5
struct cqueue
{
    int arr[max],front,rear;
};
typedef struct cqueue cqueue;
void enqueue(cqueue *,int);
int dequeue(cqueue *);
int count(cqueue);
int main()
{
    int choice,x;
    cqueue q;
    q.front=q.rear=-1;
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
    if((pq->rear==max-1&&pq->front==0)||(pq->rear+1==pq->front))
    {
        printf("\n!!!Circular Queue Overflow!!!\n");
        return;
    }
    else
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
    if(pq->front==-1&&pq->rear==-1)
    {
        printf("\n!!!Circular Queue Underflow!!!\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->rear==pq->front)
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
        pq->front=pq->front+1;
    }
    return x;
}

int count(cqueue q)
{
    if(q.front==-1&&q.rear==-1)
        return 0;
    else
    if(q.rear==q.front)
        return 1;
    else
    if(q.rear>q.front)
        return(q.rear-q.front+1);
    else
    if(q.front>q.rear)
        return(max-q.front+q.rear+1);
}

/*
Sample Output : 
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
Enter your choice : 1

Enter element : 30

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 40

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 1

Enter element : 50

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
Enter your choice : 1

Enter element : 60

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 3

No. of elmements : 4

Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 30
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 40
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 50
Select the operation :
1.enqueue
2.dequeue
3.count
4.exit
Enter your choice : 2

Removed elmement : 60
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
Process returned 0 (0x0)   execution time : 71.087 s
Press any key to continue. */

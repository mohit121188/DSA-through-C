/*Program to implement a linear queue

enqueue Algorithm:
Step 1: Check for OVERFLOW
Step 2: if the QUEUE is FULL then print the message QUEUE OVERFLOW and RETURN.
Step 3: if the QUEUE is NOT FULL then increment REAR by 1.
Step 4: INSERT the element in the QUEUE at the position pointed/marked by REAR.
Step 5: FINISH and RETURN 

dequeue Algorithm:
Step 1: Check for UNDERFLOW
Step 2: if the QUEUE is EMPTY then print the message QUEUE UNDERFLOW and RETURN.
Step 3: if the QUEUE is NOT EMPTY then REMOVE the element pointed by FRONT.
Step 4: INCREMENT the FRONT by 1.
Step 5: RETURN the DELETED element.

*/
#include<stdio.h>
#define max 5
struct queue
{
int arr[max],front,rear;
};
typedef struct queue queue;
void enqueue(queue *,int);
int dequeue(queue *);
int main()
{
    queue q;
    q.front=q.rear=-1;
    int choice,x;
    do
    {
        printf("\nSelect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.quit");
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
            printf("\nRemoved element : %d",dequeue(&q));
            break;
        case 3:
            printf("\nQuitting the Application");
            exit(0);
            break;
        default:
            printf("\nWrong selection!!try again");
        }
    }while(1);
    return 0;
}
void enqueue(queue *pq,int x)
{
    if(pq->rear==max-1)
    {
        printf("\nQueue is overflow!!\n");
        return;
    }
    if(pq->front==-1&&pq->rear==-1)
    {
        pq->front=pq->rear=0;
    }
    else
    {
        pq->rear++;
    }
    pq->arr[pq->rear]=x;
}
int dequeue(queue *pq)
{
    int x;
    if(pq->front==-1)
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==max-1)
        pq->front=pq->rear=-1;
    else
        pq->front=pq->front+1;
    return(x);
}

/*
Sample Output: 

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 1

Enter element : 10

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 1

Enter element : 20

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 1

Enter element : 30

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 1

Enter element : 40

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 1

Enter element : 50

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 1

Enter element : 60

Queue is overflow!!

Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 2

Removed element : 10
Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 2

Removed element : 20
Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 2

Removed element : 30
Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 2

Removed element : 40
Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 2

Removed element : 50
Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 2

Queue Underflow

Removed element : -1
Select the operation :
1.enqueue
2.dequeue
3.quit
Enter your choice : 3

Quitting the Application
Process returned 0 (0x0)   execution time : 399.998 s
Press any key to continue.*/

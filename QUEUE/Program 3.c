/*Write a C program to count the number of elements in a Linear queue.*/
#include<stdio.h>
#define max 5
struct queue
{
    int arr[max],front,rear;
};
typedef struct queue queue;
void enqueue(queue *,int);
int dequeue(queue *);
int count(queue);
int main()
{
    int choice,x;
    queue q;
    q.front=q.rear=-1;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.count");
        printf("\n4.quit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the element : ");
            scanf("%d",&x);
            enqueue(&q,x);
            break;
        case 2:
            printf("\nRemoved element is %d\n",dequeue(&q));
            break;
        case 3:
            printf("\nNo. of elmement : %d\n",count(q));
            break;
        case 4:
            printf("\nQuitting");
            exit(0);
        default:
            printf("\nWrong choice!!!Try Again!!");
        }
    }while(1);
    return 0;
}
void enqueue(queue *pq,int x)
{
    if(pq->rear==max-1)
    {
        printf("\nQueue Overflow");
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
int dequeue(queue *pq)
{
    int x;
    if(pq->front==-1&&pq->rear==-1)
    {
        printf("\nQueue underflow");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==pq->rear)
    {
        pq->front=pq->rear=-1;
    }
    else
    {
        pq->front=pq->front+1;
    }
    return x;
}

int count(queue q)
{
    if(q.front==-1&&q.rear==-1)
    {
        return 0;
    }
    return(q.rear-q.front+1);

}
/*Sample Output: 

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 3

No. of elmement : 0

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 10

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Queue underflow
Removed element is -1

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 3

No. of elmement : 0

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 20

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 30

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 3

No. of elmement : 3

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 10

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 20

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 30

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 3

No. of elmement : 0

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Queue underflow
Removed element is -1

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 20

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 30

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 40

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 50

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 60

Queue Overflow
select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 3

No. of elmement : 5

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 4

Quitting
Process returned 0 (0x0)   execution time : 68.943 s
Press any key to continue.
*/

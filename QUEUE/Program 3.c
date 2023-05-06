/*Write a C program to count the number of elements in a Linear queue*/
#include<stdio.h>
#define MAX 5
#define DEFAULT {.front=-1,.rear=-1 }
struct queue
{
    int arr[MAX],front,rear;
};
typedef struct queue queue;
void enqueue(queue *,int);
int dequeue(queue *);
int isempty(queue);
int count(queue);
int main()
{
    int choice,x;
    queue q=DEFAULT;
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
    if(pq->rear==MAX-1)
    {
        printf("\n!!!Queue Overflow!!!\n");
        return;
    }
    if(pq->rear==-1)
        pq->rear=pq->front=0;
    else
        pq->rear++;
    pq->arr[pq->rear]=x;
}
int dequeue(queue *pq)
{
    int x;
    if(pq->front==-1)
    {
        printf("\n!!!Queue underflow!!!");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==pq->rear)
        pq->front=pq->rear=-1;
    else
        pq->front++;
    return x;
}
int isempty(queue q)
{
    return(q.rear==-1);
}
int count(queue q)
{
    int k=0;
    while(isempty(q)!=1)
    {
        dequeue(&q);
        k++;
    }
    return k;
}

/*Sample Output

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

!!!Queue underflow!!!
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

Enter the element : 100

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 200

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 300

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 400

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 500

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 1

Enter the element : 600

!!!Queue Overflow!!!

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
Enter your choice : 2

Removed element is 100

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 200

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 300

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 400

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

Removed element is 500

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 2

!!!Queue underflow!!!
Removed element is -1

select the operation :
1.enqueue
2.dequeue
3.count
4.quit
Enter your choice : 4

Quitting
Process returned 0 (0x0)   execution time : 38.449 s
Press any key to continue.
*/

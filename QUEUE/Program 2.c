/*implement enqueue and dequeue operation on circular queue of max size 5*/
#include<stdio.h>
#define MAX 5
#define DEFAULTS {.front=-1,.rear=-1}
struct cqueue
{
    int arr[MAX],front,rear;
};
typedef struct cqueue cqueue;
void enqueue(cqueue *,int);
int dequeue(cqueue *);
int main()
{
    int choice,x;
    cqueue q=DEFAULTS;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.quit");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the element : ");
            scanf("%d",&x);
            enqueue(&q,x);
            break;
        case 2:
            printf("\nremoved element is : %d\n",dequeue(&q));
            break;
        case 3:
            printf("\nQuittint the Application");
            exit(0);
            break;
        default:
            printf("\nWrong choice!!Try again!!");
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
        printf("\n!!!Circular Queue Underflow!!!");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->front==pq->rear)
        pq->front=pq->rear=-1;
    else
    if(pq->front==MAX-1)
        pq->front=0;
    else
        pq->front++;
    return x;
}

/*sample output

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 10

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

!!!Circular Queue Underflow!!!
removed element is : -1

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 20

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 30

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 40

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 50

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 60

!!!Circular Queue Overflow!!!

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 10

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 20

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 60

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 1

enter the element : 70

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 30

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 40

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 50

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 60

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

removed element is : 70

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 2

!!!Circular Queue Underflow!!!
removed element is : -1

select the operation :
1.enqueue
2.dequeue
3.quit
enter your choice : 3

Quittint the Application
Process returned 0 (0x0)   execution time : 73.140 s
Press any key to continue.*/

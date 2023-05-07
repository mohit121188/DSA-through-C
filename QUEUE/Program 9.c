/*Write a C program to find the largest element and smallest element in the linear queue*/
#include<stdio.h>
#define MAX 5
#define DEFAULTS {.front=-1,.rear=-1}
struct lqueue
{
    int arr[MAX],front,rear;
};
typedef struct lqueue lqueue;
void enqueue(lqueue *,int);
int dequeue(lqueue *);
int isempty(lqueue);
int largest(lqueue);
int smallest(lqueue);
int main()
{
    lqueue q=DEFAULTS;
    int x,choice;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.find largest element");
        printf("\n4.find smallest element");
        printf("\n5.quit");
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
            x=dequeue(&q);
            if(x!=-1)
                printf("\n\"removed element : %d\"\n",x);
            break;
        case 3:
            x=largest(q);
                if(x!=-1)
                    printf("\n\"Largest element : %d\"\n",x);
            break;
        case 4:
            x=smallest(q);
            if(x!=-1)
                printf("\n\"smallest element is %d\"\n",smallest(q));
            break;
        case 5:
            printf("\n\"Quitting the application\"\n");
            exit(0);
        }
    }while(1);
    return 0;
}
void enqueue(lqueue *pq,int x)
{
    if(pq->rear==MAX-1)
    {
        printf("\n\"QUEUE OVERFLOW\"\n");
        return;
    }
    if(pq->rear==-1)
        pq->rear=pq->front=0;
    else
        pq->rear++;
    pq->arr[pq->rear]=x;
}
int dequeue(lqueue *pq)
{
    int x;
    if(pq->front==-1)
    {
        printf("\n\"QUEUE UNDERFLOW\"\n");
        return -1;
    }
    x=pq->arr[pq->front];
    if(pq->rear==pq->front)
        pq->rear=pq->front=-1;
    else
        pq->front++;
    return x;
}

int isempty(lqueue q)
{
    return(q.rear==-1);
}
 int largest(lqueue q)
 {
     int val,x;
     if(isempty(q)==1)
     {
         printf("\n\"QUEUE IS UNDERFLOW\"\n");
         return -1;
     }
     val=dequeue(&q);
     while(isempty(q)!=1)
     {
         x=dequeue(&q);
         if(val<x)
            val=x;
     }
     return val;
 }
 int smallest(lqueue q)
 {
     int val,x;
     if(isempty(q)==1)
     {
         printf("\n\"QUEUE IS UNDERFLOW\"\n");
         return -1;
     }
     val=dequeue(&q);
     while(isempty(q)!=1)
     {
         x=dequeue(&q);
         if(val>x)
            val=x;
     }
     return val;
 }


/*SAMPLE OUTPUT

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"QUEUE UNDERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 3

"QUEUE IS UNDERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 4

"QUEUE IS UNDERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 1

enter the element : 50

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 1

enter the element : 70

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 1

enter the element : 110

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 1

enter the element : 40

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 1

enter the element : 90

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 1

enter the element : 55

"QUEUE OVERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 3

"Largest element : 110"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 4

"smallest element is 40"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"removed element : 50"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"removed element : 70"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"removed element : 110"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 3

"Largest element : 90"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 4

"smallest element is 40"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"removed element : 40"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 3

"Largest element : 90"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 4

"smallest element is 90"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"removed element : 90"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 3

"QUEUE IS UNDERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 4

"QUEUE IS UNDERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 2

"QUEUE UNDERFLOW"

select the operation :
1.enqueue
2.dequeue
3.find largest element
4.find smallest element
5.quit
enter your choice : 5

"Quitting the application"

Process returned 0 (0x0)   execution time : 120.818 s
Press any key to continue.

*/

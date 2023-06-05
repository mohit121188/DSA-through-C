//Program to implement a Linear Queue using singly linked list
//header files
#include<stdio.h>
#include<stdlib.h>
#define DEFAULTS_QUEUE {.rear=NULL,.front=NULL}
//defining a structure named ListNode
struct ListNode
{
    int data;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
//defining a structure named Queue
struct Queue
{
    ListNode *front,*rear;
};
typedef struct Queue Queue;
//declarations of the functions to handle the queue
void enQueue(Queue *,int);
int deQueue(Queue *);
int freeQueue(Queue *);
//define main function
int main()
{
    Queue q=DEFAULTS_QUEUE;
    int x;
    int choice;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.clear");
        printf("\n4.exit");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
          printf("\nenter the element : ");
          scanf("%d",&x);
          enQueue(&q,x);
          break;
        case 2:
            x=deQueue(&q);
            if(x!=-1)
            printf("\nremoved element is %d ",x);
            break;
        case 3:
            x=freeQueue(&q);
            if(x==1)
                printf("\nqueue is cleared successfully\n");
            else
                printf("\nqueue is can't be cleared successfully\n");
                break;
        case 4:
            x=freeQueue(&q);
            if(x==1)
                printf("\nqueue is cleared successfully\n");
            else
                printf("\nqueue is can't be cleared successfully\n");
            printf("\nQuitting the Application");
            exit(0);
        default:
            printf("\noops wrong choice!!try again!!\n");
        }
    }while(1);
    return 0;
}
//defining enQueue
void enQueue(Queue *pq,int x)
{
    ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory can't be allocated\"\n");
        return;
    }
    new_node->data=x;
    new_node->next=NULL;
    if(pq->rear==NULL)
    {
        pq->front=new_node;
        pq->rear=new_node;
        return;
    }
    pq->rear->next=new_node;
    pq->rear=new_node;
}
//defining deQueue
int deQueue(Queue *pq)
{
    int x;
    ListNode *temp=NULL;
    if(pq->front==NULL)
    {
        printf("\n\"EMPTY QUEUE\"\n");
        return -1;
    }
    x=pq->front->data;
    if(pq->front==pq->rear)
    {
        free(pq->front);
        pq->front=pq->rear=NULL;
    }
    else
    {
    temp=pq->front;
    pq->front=pq->front->next;
    free(temp);
    }
    return x;
}
//defining freeQueue
int freeQueue(Queue *pq)
{
    ListNode *current=NULL;
    ListNode *next=NULL;
    if(pq->front==NULL)
    {
        return 1;
    }
    else
        if(pq->front==pq->rear)
    {
        free(pq->front);
        pq->front=pq->rear=NULL;
    }
    else
    {
        current=pq->front;
        next=current->next;
        while(current!=NULL)
        {
            free(current);
            current=next;
            if(current!=NULL)
            {
                next=current->next;
            }
        }
        pq->front=pq->rear=NULL;
    }
    if(pq->front==NULL&&pq->rear==NULL)
        return 1;
    else
        return 0;
}
/*Sample output

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

"EMPTY QUEUE"

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 10

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 20

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 30

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 40

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 50

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

removed element is 10
select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

removed element is 20
select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

removed element is 30
select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

removed element is 40
select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

removed element is 50
select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

"EMPTY QUEUE"

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 100

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 200

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 300

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 1

enter the element : 400

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 3

queue is cleared successfully

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 2

"EMPTY QUEUE"

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 5

oops wrong choice!!try again!!

select the operation :
1.enqueue
2.dequeue
3.clear
4.exit
enter your choice : 4

queue is cleared successfully

Quitting the Application
Process returned 0 (0x0)   execution time : 47.386 s
Press any key to continue.

*/

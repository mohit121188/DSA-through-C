
#include<stdio.h>
#include<stdlib.h>
//defining a structure named ListNode
struct ListNode
{
    int data;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
//declarations of the functions to handle the Doubly linked list
ListNode * getLast(ListNode *);
void insertAtBeg(struct ListNode **,int);
void delFromBeg(struct ListNode **);
void insertAtEnd(ListNode **,int);
void delFromEnd(ListNode **);
void insertAtPosFromBeg(ListNode **,int,int);
void insertAtPosFromEnd(ListNode **,int,int);
void delFromPosBeg(ListNode **,int);
void delFromPosEnd(ListNode **,int);
void searchPosByData(ListNode *,int);
void findAndReplace(ListNode **,int,int);
int countNodes(ListNode *);
void reverseList(ListNode **);
void removeDuplicate(ListNode **);
void removeNode(ListNode **,int);
void largestData(ListNode *);
void smallestData(ListNode *);
void printNthDataFromBeg(ListNode *,int);
void printNthDataFromEnd(ListNode *,int);
void printListForward(struct ListNode *);
void printListBackward(struct ListNode *);
void freeList(struct ListNode **);

//defining main function
int main()
{
    ListNode *head=NULL;
    int choice,data,pos,replacement,count,n;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.  insert at the beginning");
        printf("\n2.  delete from the beginning");
        printf("\n3.  insert at the end");
        printf("\n4.  delete from the end");
        printf("\n5.  print the list");
        printf("\n6. clear the list");
        printf("\n7. exit the application");
        printf("\n8. clear screen");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nprovide the value of data : ");
            scanf("%d",&data);
            insertAtBeg(&head,data);
            break;
        case 2:
            delFromBeg(&head);
            break;
        case 3:
            printf("\nprovide the value of data : ");
            scanf("%d",&data);
            insertAtEnd(&head,data);
            break;
        case 4:
            delFromEnd(&head);
            break;
        case 5:
            printf("\nprinting the list: \n");
            printListForward(head);
            printf("\n");
            break;
        case 6:
            freeList(&head);
            printf("\nlist is cleared successfully\n");
            break;
        case 7:
            freeList(&head);
            printf("\nQuitting the application");
            exit(0);
        case 9:
            system("cls");
            break;
        default:
            printf("\nWrong choice!!Try Again");
        }
    }while(1);
    return 0;
}
//getLast
ListNode * getLast(ListNode *head)
{
    ListNode *temp=head;
    if(head==NULL)
        return NULL;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    return temp;
}
//insertAtBeg
void insertAtBeg(ListNode **phead,int data)
{
    ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));
    ListNode *last_node=NULL;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    if(*phead==NULL)
    {
        *phead=new_node;
        (*phead)->next=*phead;
        return;
    }
    last_node=getLast(*phead);
    new_node->next=*phead;
    *phead=new_node;
    last_node->next=*phead;
}
//delFromBeg
void delFromBeg(ListNode **phead)
{
    ListNode *temp=*phead;
    ListNode *last=NULL;
    if(*phead==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    if((*phead)->next==*phead)
    {
        free(*phead);
        *phead=NULL;
    }
    while(temp->next!=*phead)
    {
        temp=temp->next;
    }
    last=temp;
    temp=*phead;
    (*phead)=(*phead)->next;
    last->next=*phead;
    free(temp);
    temp=NULL;
}

//insertAtEnd
void insertAtEnd(ListNode **phead,int data)
{
    ListNode *temp=*phead,*new_node=NULL;
    new_node=(ListNode *)malloc(sizeof(ListNode));
    if(new_node==NULL)
    {
        printf("\n\"Error:Memory Allocation Problem\"\n");
        return;
    }
    new_node->data=data;
    if(*phead==NULL)
    {
        *phead=new_node;
        (*phead)->next=*phead;
        return;
    }
    while(temp->next!=*phead)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=*phead;
}
//delFromEnd
void delFromEnd(ListNode **phead)
{
    ListNode *temp=NULL,*previous=NULL;
    if(*phead==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    if((*phead)->next==*phead)
    {
        free(*phead);
        *phead=NULL;
        return;
    }
    temp=*phead;
    while(temp->next!=*phead)
    {
        previous=temp;
        temp=temp->next;
    }
    free(temp);
    temp=NULL;
    previous->next=*phead;
}
//insertAtPosFromBeg
void insertAtPosFromBeg(ListNode **phead,int pos,int data)
{
    ListNode *new_node=NULL,*temp=NULL;
    int i;
    if(pos<=0)
    {
        printf("\n\"position can neither be zero nor negative\"\n");
        return;
    }
    new_node=(ListNode *)malloc(sizeof(ListNode));
    if(new_node==NULL)
    {
        printf("\n\"Error:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    if(pos==1)
    {
        if(*phead==NULL)
        {
            *phead=new_node;
            (*phead)->next=*phead;
            return;
        }
        else
        {
            new_node->next=*phead;
            *phead=new_node;
            return;
        }
    }
    temp=*phead;
    for(i=1;i<=pos-1;i++)
    {
        temp=temp->next;
    }

}

//printListForward
void printListForward(ListNode *head)
{
    ListNode *temp=head;
    if(head==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

//freeList
void freeList(ListNode **phead)
{
    ListNode *temp=NULL,*next=NULL;
    if(*phead==NULL)
    {
        return;
    }
    if((*phead)->next==NULL)
    {
        free(*phead);
        *phead=NULL;
    }
    temp=*phead;
    next=temp->next;
    while(temp->next!=*phead)
    {
        free(temp);
        temp=next;
        if(temp->next!=*phead)
            next=temp->next;
    }
    free(temp);
    temp=NULL;
    next=NULL;
    *phead=NULL;
}

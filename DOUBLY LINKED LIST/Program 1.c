
#include<stdio.h>
#include<stdlib.h>
//defining a structure named ListNode
struct ListNode
{
    struct ListNode *prev;
    int data;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
//declarations of the functions to handle the Doubly linked list
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
        printf("\n2.  delete at the beginning");
        printf("\n3.  insert at the end");
        printf("\n4.  delete from the end");
        printf("\n5.  insert at a specific position from beginning");
        printf("\n6.  insert at a specific position from end");
        printf("\n7.  delete from a specific position from beginning");
        printf("\n8.  delete from a specific position from end");
        printf("\n9.  search position of a node by it's data");
        printf("\n10. find and replace the data");
        printf("\n11. count the nodes in the list");
        printf("\n12. reverse the list");
        printf("\n13. remove duplicate from the list");
        printf("\n14. remove data from the list");
        printf("\n15. print largest value in the list");
        printf("\n16. print smallest value in the list");
        printf("\n17. print nth data from the beginning");
        printf("\n18. print nth data from the end");
        printf("\n19.  print the list in forward direction");
        printf("\n20.  print the list in backward direction");
        printf("\n21. clear the list");
        printf("\n22. exit the application");
        printf("\n23. clear screen");
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
            printf("\nprovide the value of data : ");
            scanf("%d",&data);
            printf("\nprovide the value of position from beginning : ");
            scanf("%d",&pos);
            insertAtPosFromBeg(&head,pos,data);
            break;
        case 6:
            printf("\nprovide the value of data : ");
            scanf("%d",&data);
            printf("\nprovide the value of position from end : ");
            scanf("%d",&pos);
            insertAtPosFromEnd(&head,pos,data);
            break;
        case 7:
            printf("\nprovide the value of position from beginning : ");
            scanf("%d",&pos);
            delFromPosBeg(&head,pos);
            printf("\n\"node at position %d from beginning is deleted\"\n",pos);
            break;
        case 8:
            printf("\nprovide the value of position from end : ");
            scanf("%d",&pos);
            delFromPosEnd(&head,pos);
            break;
        case 9:
            printf("\nprovide the data to be searched : ");
            scanf("%d",&data);
            searchPosByData(head,data);
            break;
        case 10:
            printf("\nprovide data needs to be find : ");
            scanf("%d",&data);
            printf("\nprovide data that acts as replacement : ");
            scanf("%d",&replacement);
            findAndReplace(&head,data,replacement);
            break;
        case 11:
            count=countNodes(head);
            printf("\nnumber of nodes in the list are  : %d",count);
            break;
        case 12:
            reverseList(&head);
            break;
        case 13:
            removeDuplicate(&head);
            break;
        case 14:
            printf("\nenter data : ");
            scanf("%d",&data);
            removeNode(&head,data);
            break;
        case 15:
            largestData(head);
            break;
        case 16:
            smallestData(head);
            break;
        case 17:
            printf("\nprovide the value of n from beginning : ");
            scanf("%d",&n);
            printNthDataFromBeg(head,n);
            break;
        case 18:
            printf("\nprovide the value of n from end : ");
            scanf("%d",&n);
            printNthDataFromEnd(head,n);
            break;
        case 19:
            printf("\nprinting the list in forward direction: \n");
            printListForward(head);
            printf("\n");
            break;
        case 20:
            printf("\nprinting the list in backward direction: \n");
            printListBackward(head);
            printf("\n");
            break;
        case 21:
            freeList(&head);
            printf("\nlist is cleared successfully\n");
            break;
        case 22:
            freeList(&head);
            printf("\nQuitting the application");
            exit(0);
        case 23:
            system("cls");
            break;
        default:
            printf("\nWrong choice!!Try Again");
        }
    }while(1);
    return 0;
}

//defining insertAtBeg
void insertAtBeg(ListNode **phead,int data)
{
    ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    if(*phead==NULL)
    {
        new_node->prev=NULL;
        new_node->next=NULL;
        *phead=new_node;
        return;
    }
    new_node->prev=NULL;
    new_node->next=*phead;
    (*phead)->prev=new_node;
    *phead=new_node;
}

//delAtBeg
void delFromBeg(ListNode **phead)
{
    ListNode *temp=NULL;
    if(*phead==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    if((*phead)->next==NULL)
    {
        free(*phead);
        *phead=NULL;
        return;
    }
    temp=*phead;
    *phead=(*phead)->next;
    (*phead)->prev=NULL;
    free(temp);
}

//insertAtEnd
void insertAtEnd(ListNode **phead,int data)
{
    ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));
    ListNode *temp=NULL;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    new_node->next=NULL;
    if(*phead==NULL)
    {
        new_node->prev=NULL;
        *phead=new_node;
        return;
    }
    temp=*phead;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}

//delFromEnd
void delFromEnd(ListNode **phead)
{
ListNode *temp=*phead;
ListNode *previous=NULL;
if(*phead==NULL)
{
    printf("\n\"list is empty\"\n");
    return;
}
while((*phead)->next==NULL)
{
    free(*phead);
    *phead=NULL;
    return;
}
while(temp->next!=NULL)
{
    temp=temp->next;
}
previous=temp->prev;
previous->next=NULL;
free(temp);
temp=NULL;
}

//insertAtPosFromBeg
void insertAtPosFromBeg(ListNode **phead,int pos,int data)
{
    ListNode *current_node=NULL,*prev_node=NULL,*new_node=NULL;
    int i;
    if(pos<=0)
    {
        printf("\n\"ERROR:position can't be zero or negative\"\n");
        return;
    }
    new_node=(ListNode *)malloc(sizeof(ListNode));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    if(*phead==NULL)
    {
        if(pos==1)
        {
            *phead=new_node;
            new_node->next=NULL;
            new_node->prev=NULL;
            new_node->data=data;
            return;
        }
        else
        {
            printf("\n\"%dth position from the beginning not found\"\n",pos);
            return;
        }
    }
    current_node=*phead;
    for(i=1;i<=pos-1;i++)
    {
        prev_node=current_node;
        current_node=current_node->next;
        if(current_node==NULL)
            break;
    }
    if(i<pos-1)
    {
        printf("\n\"%dth position from the beginning not found\"\n",pos);
        return;
    }
    if(i==pos-1)
    {
        prev_node->next=new_node;
        new_node->next=NULL;
        new_node->prev=prev_node;
        return;
    }
    if(i==pos)
    {
        new_node->next=current_node;
        current_node->prev=new_node;
        prev_node->next=new_node;
        new_node->prev=prev_node;
        return;
    }

}

//insertAtPosFromEnd
void insertAtPosFromEnd(ListNode **phead,int pos,int data)
{
    ListNode *curr_node=NULL,*prev_node=NULL,*new_node=NULL,*temp=NULL,*last=NULL;
    int i;
    new_node=(ListNode *)malloc(sizeof(ListNode));
    if(pos<=0)
    {
        printf("\n\"position can't be zero or negetive\"\n");
        return;
    }
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(*phead==NULL)
    {
        if(pos==1)
        {
            *phead=new_node;
            return;
        }
        else
        {
            printf("\n\"%dth position from the end is not found in the list\"\n",pos);
            return;
        }
    }
    temp=*phead;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    last=temp;
    curr_node=last;
    for(i=1;i<=pos-1;i++)
    {
        prev_node=curr_node;
        curr_node=curr_node->prev;
        if(curr_node==NULL)
            break;
    }
    if(i==pos)
    {
           if(i==1)
           {
               curr_node->next=new_node;
               new_node->prev=curr_node;
               return;
           }
           else
           {
            curr_node->next=new_node;
            new_node->prev=curr_node;
            prev_node->prev=new_node;
            new_node->next=prev_node;
            return;
           }
    }
    else
    if(i==pos-1)
    {
        prev_node->prev=new_node;
        new_node->next=prev_node;
        *phead=new_node;
        return;
    }
    else
    {
        printf("\n\"%dth position from the end is not found in the list\"\n",pos);
        return;
    }
}
//delFromPosBeg
void delFromPosBeg(ListNode **phead,int pos)
{
    ListNode *temp=NULL,*previous=NULL;
    int i;
    if(pos<=0)
    {
        printf("\n\"position can neither be negative or zero\"\n");
        return;
    }
    if(*phead==NULL)
    {
        printf("\"list is empty\"\n");
        return;
    }
    temp=*phead;
    for(i=1;i<=pos-1;i++)
    {
        previous=temp;
        temp=temp->next;
        if(temp==NULL)
            break;
    }
    if(temp!=NULL)
    {
        if(temp->next==NULL&&temp->prev==NULL)
        {
            free(temp);
            temp=NULL;
            *phead=NULL;
        }
        else
        if(temp->next==NULL&&temp->prev!=NULL)
        {
            previous->next=NULL;
            temp=NULL;
            free(temp);
        }
        else
        if(temp->next!=NULL&&temp->prev==NULL)
        {
            *phead=temp->next;
            (*phead)->prev=NULL;
            free(temp);
            temp=NULL;
        }
        else
        {
            previous->next=temp->next;
            temp->next->prev=previous;
            free(temp);
            temp=NULL;
        }
    }
    else
    {
        printf("\nthere is not any node at %dth position",pos);
    }
    return;
}

//delFromPosEnd
void delFromPosEnd(ListNode **phead,int pos)
{
    ListNode *temp=NULL,*previous=NULL;
    int i;
    if(pos<=0)
    {
        printf("\n\"position can neither be zero nor negative\"\n");
        return;
    }
    if(*phead==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    temp=*phead;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    for(i=1;i<=pos-1;i++)
    {
        previous=temp;
        temp=temp->prev;
        if(temp==NULL)
            break;
    }
    if(temp!=NULL)
    {
    if(temp->next==NULL&&temp->prev==NULL)
    {
        free(temp);
        temp=NULL;
        *phead=NULL;
    }
    else
    if(temp->next==NULL&&temp->prev!=NULL)
    {
        temp->prev->next=NULL;
        free(temp);
        temp=NULL;
    }
    else
    if(temp->next!=NULL&&temp->prev==NULL)
    {
        *phead=temp->next;
        (*phead)->prev=NULL;
        free(temp);
        temp=NULL;
    }
    else
    {
       previous->prev=temp->prev;
       temp->prev->next=previous;
       free(temp);
       temp=NULL;
    }
    }
    else
    {
        printf("\n\"there is not any node at %dth position\"\n",pos);
    }
}

//searchPosByData
void searchPosByData(ListNode *head,int data)
{
    ListNode *temp=head;
    int pos=0,flag=0;
    if(head==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        pos++;
        if(data==temp->data)
        {
            printf("\n\"Data value %d is found at Node position %d",data,pos);
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
        printf("\n\"data value %d is not present in the list\"\n");
}

//findAndReplacement
void findAndReplace(ListNode **phead,int data,int replacement)
{
    ListNode *temp=*phead;
    int flag=0;
    if(*phead==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            temp->data=replacement;
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\n\"data not found in the list\"\n");
    }
}
//count nodes
int countNodes(ListNode *head)
{
    ListNode *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
//reverseList
void reverseList(ListNode **phead)
{
    ListNode *curr_node=NULL,*prev_node=NULL;
    if(*phead==NULL)
        return;
    if((*phead)->next==NULL)
        return;
    curr_node=*phead;
    *phead=NULL;
    while(curr_node!=NULL)
    {
        prev_node=curr_node;
        curr_node=curr_node->next;
        if(*phead==NULL)
        {
            *phead=prev_node;
            prev_node->next=NULL;
            prev_node->prev=NULL;
        }
        else
        {
            prev_node->next=*phead;
            (*phead)->prev=prev_node;
            prev_node->prev=NULL;
            *phead=prev_node;
        }
    }

}

//removeDuplicate
void removeDuplicate(ListNode **phead)
{
    ListNode *temp=NULL,*next_node=NULL;
    int *ptr=NULL,i=0,j,flag=0;
    if(*phead==NULL)
    {
        return;
    }
    if((*phead)->next==NULL)
    {
        return;
    }
    ptr=(int *)malloc(countNodes(*phead)*sizeof(int));
    if(ptr==NULL)
    {
        printf("\n\"Error:memory allocation problem\"\n");
        return;
    }
    else
    {
        temp=*phead;
        next_node=temp->next;
        while(temp!=NULL)
        {
            flag=0;
            for(j=0;j<i;j++)
            {
                if(ptr[j]==temp->data)
                {
                    flag=1;
                    if(temp->next==NULL)
                    {
                        temp->prev->next=NULL;
                        free(temp);
                        temp=NULL;
                        break;
                    }
                    else
                    {
                        temp->prev->next=temp->next;
                        temp->next->prev=temp->prev;
                        free(temp);
                        temp=NULL;
                        break;
                    }
                }
            }
            if(flag==0)
                {
                ptr[i++]=temp->data;
                }
            temp=next_node;
            if(temp!=NULL)
                next_node=temp->next;
        }
    }
}

void removeNode(ListNode **phead,int data)
{
    ListNode *temp=*phead,*next_node=NULL;
    if(*phead==NULL)
    {
        return;
    }
    if((*phead)->next==NULL)
    {
        if((*phead)->data==data)
        {
            free(*phead);
            *phead=NULL;
            return;
        }
    }
    temp=*phead;
    next_node=(*phead)->next;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            if(temp->next==NULL)
            {
                temp->prev->next=NULL;
                free(temp);
                temp=NULL;
            }
            else
            if(temp->prev==NULL)
            {
                (*phead)=(*phead)->next;
                (*phead)->prev=NULL;
                free(temp);
                temp=NULL;
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                temp=NULL;
            }
        }
        temp=next_node;
        if(temp!=NULL)
            next_node=temp->next;
    }
}

//largestData
void largestData(ListNode *head)
{
    int max;
    ListNode *temp=head;
    if(head==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    max=head->data;
    while(temp!=NULL)
    {
        if(max<temp->data)
        {
            max=temp->data;
        }
        temp=temp->data;
    }
    printf("\n\"largest value in the list is %d\"\n",max);
}

//smallestData
void smallestData(ListNode *head)
{
    ListNode *temp=head;
    int min;
    if(head==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    min=temp->data;
    while(temp!=NULL)
    {
        if(min>temp->data)
        {
            min=temp->data;
        }
        temp=temp->next;
    }
    printf("\n\"smallest value in the list is %d\"\n",min);
}
//printNthDataFromBeg
void printNthDataFromBeg(ListNode *head,int n)
{
    int i;
    ListNode *temp=head;
    if(n<=0)
    {
        printf("\n\"value of n can neither be zero nor negative\"\n");
        return;
    }
    if(head==NULL)
    {
        printf("\n\"%dth node not found, list is empty\"\n",n);
        return;
    }
    for(i=1;i<=n-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
            break;
    }
    if(temp==NULL)
        printf("\n\"%dth node not found in the list\"\n",n);
    else
        printf("\n\"value at %dth node is %d\"\n",n,temp->data);

}
//printNthNodeFromEnd
void printNthDataFromEnd(ListNode *head,int n)
{
    ListNode *temp=head;
    int i;
    if(n<=0)
    {
        printf("\n\"value of n can neither be zero nor negetive\"\n");
        return;
    }
    if(head==NULL)
    {
        printf("\n\"%dth node not found, list is empty\"\n",n);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    for(i=1;i<=n-1;i++)
    {
        temp=temp->prev;
        if(temp==NULL)
            break;
    }
    if(temp==NULL)
        printf("\n\"%dth not not found in the list\"\n",n);
    else
        printf("\n\"value at %dth node is %d\"\n",n,temp->data);

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
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//printListBackward
void printListBackward(ListNode *head)
{
    ListNode *temp=head;
    if(head==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}

//freeList
void freeList(ListNode **phead)
{
    ListNode *current=NULL,*next=NULL;
    if(*phead==NULL)
    {
        return;
    }
    if((*phead)->next==NULL)
    {
        free(*phead);
        *phead=NULL;
        return;
    }
    current=*phead;
    next=current->next;
    while(current!=NULL)
    {
        free(current);
        current=next;
        if(current!=NULL)
            next=current->next;
    }
    *phead=NULL;
}

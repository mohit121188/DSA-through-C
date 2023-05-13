/*Perform various operations over SINGLY LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>
//defining structure for node of list
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void ins_at_end(node **,int);
void del_from_end(node **);
void insert_at_beg(node **,int);
void del_from_beg(node **);
void insert_at_pos(node **,int,int);
void del_from_pos(node **,int);
int search_pos(node *,int);
void find_and_replace(node **,int,int);
void display_list(node *);
int count_nodes(node *);
void reverse_list(node **);
void remove_duplicate(node **);
void clear_list(node **);
int main()
{
    node *start=NULL;
    int choice,x,pos,y;
    do
    {
        system("cls");
        printf("\nselect the operation : ");
        printf("\n1.insert data at end");
        printf("\n2.delete from the end");
        printf("\n3.insert at beginning");
        printf("\n4.delete from the beginning");
        printf("\n5.insert at a specific position");
        printf("\n6.delete from a specific position");
        printf("\n7.search the position of a node with the key data value");
        printf("\n8.find and replace");
        printf("\n9.display the list");
        printf("\n10.count the nodes");
        printf("\n11.reverse the list");
        printf("\n12.remove duplicate elements from the list");
        printf("\n13.clear the list");
        printf("\n14.quit");
        printf("\nenter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data : ");
            scanf("%d",&x);
            ins_at_end(&start,x);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 2:
            del_from_end(&start);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 3:
            printf("\nenter the data : ");
            scanf("%d",&x);
            insert_at_beg(&start,x);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 4:
            del_from_beg(&start);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 5:
            printf("\nenter data : ");
            scanf("%d",&x);
            printf("\nenter position : ");
            scanf("%d",&pos);
            insert_at_pos(&start,x,pos);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 6:
            printf("\nenter position : ");
            scanf("%d",&pos);
            del_from_pos(&start,pos);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 7:
            printf("\nenter data key value to be searched : ");
            scanf("%d",&x);
            pos=search_pos(start,x);
            if(pos==-1)
                printf("\n\"SEARCH FAILED : element not found\"\n");
            else
                printf("\n\"element found at %dth position\"",pos);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 8:
           printf("\nfind : ");
           scanf("%d",&x);
           printf("\nreplace with : ");
           scanf("%d",&y);
           find_and_replace(&start,x,y);
           printf("\n\"press any key to continue......\"\n");
            getch();
           break;

        case 9:
            printf("\n\"displaying the singly linked list\"\n");
            display_list(start);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 10:
            printf("\n\"number of nodes in the singly list are : %d\"\n",count_nodes(start));
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 11:
            reverse_list(&start);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 12:
            remove_duplicate(&start);
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 13:
            clear_list(&start);
            printf("\n\"list is destroyed successfully\"\n");
            printf("\n\"press any key to continue......\"\n");
            getch();
            break;
        case 14:
            clear_list(&start);
            printf("\n\"linked list is destroyed successfully\"\n");
            printf("\n\"Quitting Application\"\n");
            exit(0);
        }
    }while(1);
    return 0;
}
//1. defining ins_at_end function
void ins_at_end(node **pstart,int x)
{
    node *temp=*pstart;
    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:insufficient memory space\"\n");
        return;
    }
    new_node->data=x;
    new_node->next=NULL;
    if(*pstart==NULL)
    {
        *pstart=new_node;
        printf("\n\"%d is successfully added at the end of the linked list\"\n",x);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    printf("\n\"%d is successfully added at the end of the linked list\"\n",x);
}
//2. defining del_from_end function
void del_from_end(node **pstart)
{
    node *temp=*pstart;
    if(*pstart==NULL)
    {
        printf("\n\"singly linked list is empty\"\n");
        return;
    }
    if((*pstart)->next==NULL)
    {
        free(*pstart);
        printf("\n\"end node of singly linked list deleted successfully\"\n");
        *pstart=NULL;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    printf("\n\"end node of singly linked list deleted successfully\"\n");
    temp->next=NULL;
}
//3. insert at the beginning
void insert_at_beg(node **pstart,int x)
{
    node *new_node=(node *)malloc(sizeof(node));
    if(new_node==NULL)
    {
      printf("\n\"ERROR:insufficient memory space\"\n");
    return;
    }
    new_node->data=x;
    if(*pstart==NULL)
    {
        *pstart=new_node;
        new_node->next=NULL;
        printf("\n\"%d is successfully added at the beginning of the singly linked list\"\n",x);
        return;
    }
    new_node->next=*pstart;
    *pstart=new_node;
    printf("\n\"%d is successfully added at the beginning of the singly linked list\"\n",x);
}
//4. defining the function del_from_beg
void del_from_beg(node **pstart)
{
    node *temp;
    if(*pstart==NULL)
    {
        printf("\n\"singly linked list is empty\"\n");
        return;
    }
    if((*pstart)->next==NULL)
    {
        free(*pstart);
        *pstart=NULL;
        printf("\n\"node at the beginning is successfully deleted from the singly linked list\"\n");
        return;
    }
    temp=(*pstart)->next;
    free(*pstart);
    *pstart=temp;
    printf("\n\"node at the beginning is successfully deleted from the singly linked list\"\n");
}
//5. insert at some specific position
void insert_at_pos(node **pstart,int x,int pos)
{

  node *new_node=(node *)malloc(sizeof(node));
  int last_node_pos=count_nodes(*pstart);
  node *temp=*pstart;
  int i;
  if(new_node==NULL)
  {
      printf("\n\"ERROR:insufficient memory space\"\n");
      return;
  }
  if(pos>last_node_pos+1||pos<0)
  {
      printf("\n\"invalid position\"\n");
      return;
  }
  new_node->data=x;
  if(pos==1)
  {
      if(*pstart==NULL)
      {
          *pstart=new_node;
          new_node->next=NULL;
          printf("\n\"%d is inserted at %dth position in singly linked list\"\n",x,pos);
          return;
      }
      else
      {
          new_node->next=*pstart;
          *pstart=new_node;
          printf("\n\"%d is inserted at %dth position in singly linked list\"\n",x,pos);
          return;
      }
  }
  else
  if(pos==last_node_pos+1)
  {
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=NULL;
    printf("\n\"%d is inserted at %dth position in singly linked list\"\n",x,pos);
 }
  else
  {
   for(i=1;i<=pos-2;i++)
   {
       temp=temp->next;
   }
   new_node->next=temp->next;
   temp->next=new_node;
   printf("\n\"%d is inserted at %dth position in singly linked list\"\n",x,pos);
 }
  }
//6.defining del_from_pos function
void del_from_pos(node **pstart,int pos)
{
    int last_node_pos=count_nodes(*pstart);
    int i;
    node *temp=*pstart;
    node *temp1=NULL;
    if(*pstart==NULL)
    {
        printf("\n\"singly linked list is empty\"\n");
        return;
    }
    if(pos<1||pos>last_node_pos)
    {
        printf("\n\"invalid position\"\n");
        return;
    }
    if(pos==1)
    {
        if(count_nodes(*pstart)==1)
        {
            free(*pstart);
            printf("\n\"node at %dth position is destroyed\"\n",pos);
            *pstart=NULL;
        }
        else
        {
            (*pstart)=(*pstart)->next;
            free(temp);
            printf("\n\"node at %dth position is destroyed\"\n",pos);
        }
    }
    else
    if(pos==last_node_pos)
    {
       while(temp->next->next!=NULL)
       {
           temp=temp->next;
       }
       free(temp->next);
       temp->next=NULL;
       printf("\n\"node at %dth position is destroyed\"\n",pos);
    }
    else
    {
            for(i=1;i<=pos-2;i++)
            {
                temp=temp->next;
            }
            temp1=temp->next;
            temp->next=temp->next->next;
            free(temp1);
            printf("\n\"node at %dth position is destroyed\"\n",pos);
    }

}

//7. defining search_pos function
int search_pos(node *start,int x)
{
    node *temp=start;
    int pos=0;
    if(start==NULL)
    {
        printf("\n\"singly linked list is empty\"\n");
        return -1;
    }
    while(temp!=NULL)
    {
        pos++;
        if(x==temp->data)
            break;
        temp=temp->next;
    }
    if(temp==NULL)
        return -1;
    else
        return pos;
}

//8.defining find_and_replace

void find_and_replace(node **pstart,int x,int y)
{
    int k=0;
    node *temp=*pstart;
    if(*pstart==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    while(temp!=NULL)
    {
        k++;
        if(temp->data==x)
        {
            del_from_pos(pstart,k);
            insert_at_pos(pstart,y,k);
        }
        temp=temp->next;
    }
}
//9. defining display_list function
void display_list(node *start)
{
    node *temp=start;
    if(start==NULL)
    {
        printf("\n\"singly linked list is empty\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("\b\b \n");
}
//10.defining the count_nodes function
int count_nodes(node *start)
{
    node *temp=start;
    int k=0;
    if(start==NULL)
    {
        return 0;
    }
    while(temp!=NULL)
    {
        k++;
        temp=temp->next;
    }
    return k;
}

//11.defining reverse_list function
void reverse_list(node **pstart)
{
    node *current_node=NULL;
    node *next_node=NULL;
    if(*pstart==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    if((*pstart)->next==NULL)
    {
        printf("\n\"singly linked list is reversed successfully\"\n");
        return;
    }
    current_node=(*pstart)->next;
    (*pstart)->next=NULL;
    while(current_node!=NULL)
    {
       next_node=current_node->next;
       current_node->next=(*pstart);
       (*pstart)=current_node;
       current_node=next_node;
    }
    printf("\n\"singly linked list is reversed successfully\"\n");
    }

//12.defining remove_duplicate function
void remove_duplicate(node **pstart)
{
    int *visited=NULL;
    int count=count_nodes(*pstart);
    node *temp=*pstart;
    node *prev_node=NULL;
    int i=0,j,flag1=0,flag2=0;
    count=count_nodes(*pstart);
    visited=(int *)calloc(count,sizeof(int));
    if(*pstart==NULL)
    {
        printf("\n\"singly linked list is empty\"\n");
        return;
    }
    while(temp!=NULL)
    {
        flag1=0;
        for(j=0;j<=i-1;j++)
        {
            if(temp->data==visited[j])
            {
                flag1=1;
                flag2=1;
                break;
            }
        }
        if(flag1==1)
        {
            prev_node->next=temp->next;
            free(temp);
            temp=prev_node->next;
        }
        else
        {
            visited[i++]=temp->data;
            prev_node=temp;
            temp=temp->next;
        }

    }
    if(flag2==0)
        printf("\n\"there are no duplicate elements in the singly linked list\"\n");
    else
        printf("\n\"all duplicate elements are removed from the singly linked list\"\n");
}




//13,14. defining the clear_list function
void clear_list(node **pstart)
{
    node *temp=*pstart;
    node *next_temp;
    while(temp!=NULL)
    {
        next_temp=temp->next;
        free(temp);
        temp=next_temp;
    }
    *pstart=NULL;
}

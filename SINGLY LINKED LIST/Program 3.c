#include<stdio.h>
struct node
{
    char ch;
    struct node *next;
};
typedef struct node node;
void insert_at_end(node **,char);
int count_nodes(node *);
char * list_to_string(node *);
void free_list(node **);
int main()
{
    char ch=NULL,*str;
    node *start=NULL;
    int count;
    printf("\nEnter a string : ");
    while(1)
    {
        scanf("%c",&ch);
        if(ch==10)
            break;
        insert_at_end(&start,ch);
    }
    str=list_to_string(start);
    printf("\nyour string : %s",str);
    free_list(&start);
    free(str);
    return 0;
}
void insert_at_end(node **pstart,char ch)
{
    node *new_node=(node *)malloc(sizeof(node));
    node *temp=*pstart;
    if(new_node==NULL)
    {
        printf("\n\"Error:insufficient memory in heap\"\n");
        return;
    }
    new_node->ch=ch;
    new_node->next=NULL;
    if(*pstart==NULL)
    {
        *pstart=new_node;
         return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

int count_nodes(node *start)
{
    node *temp=start;
    int count=0;
    if(start==NULL)
        return 0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
char * list_to_string(node *start)
{
    node *temp=start;
    int i=0;
    char *str=NULL;
    if(start==NULL)
    {
        printf("\n\"list is empty\"\n");
        return NULL;
    }
    str=(char *)malloc((count_nodes(start)+1)*sizeof(char));
    if(str==NULL)
    {
        printf("\n\"ERROR : insufficient memory in the heap\"\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        str[i++]=temp->ch;
        temp=temp->next;
    }
    str[i]='\0';
    return str;
}
void free_list(node **pstart)
{
    node *temp=NULL,*next_node=NULL;
    if(*pstart==NULL)
    {
        return;
    }
    temp=*pstart;
    while(temp!=NULL)
    {
        next_node=temp->next;
        free(temp);
        temp=next_node;
    }
    *pstart=NULL;
}

/*SAMPLE OUTPUT

Enter a string : hii, this is mohit, singly linked list is a very interesting topic of DSA.

your string : hii, this is mohit, singly linked list is a very interesting topic of DSA.
Process returned 0 (0x0)   execution time : 20.021 s
Press any key to continue.
*/

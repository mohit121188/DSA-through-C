#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define DEFAULT_STACK {.tos=NULL}
#define DEFAULT_QUEUE {.front=NULL,.rear=NULL}
#define DEFAULT_BST {.root=NULL}
#define DEFAULT_SEARCH_STATUS {.status=false,.par=NULL}
//defining a structure named BSTNode
struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};
typedef struct BSTNode BSTNode;

//defining a structure named BST
struct BST
{
    BSTNode *root;
};
typedef struct BST BST;

//defining a structure named searchStatus
struct SearchStatus
{
    bool status;
    BSTNode *par;
};
typedef struct SearchStatus SearchStatus;

//defining a structure named StackNode
struct StackNode
{
    BSTNode *address;
    struct StackNode *next;
};
typedef struct StackNode StackNode;

//defining a structure named Stack
struct Stack
{
    StackNode *tos;
};
typedef struct Stack Stack;

//defining a structure named QueueNode
struct QueueNode
{
    BSTNode *address;
    struct QueueNode *next;
};
typedef struct QueueNode QueueNode;

//defining a structure name Queue
struct Queue
{
    QueueNode *front,*rear;

};
typedef struct Queue Queue;


//declarations of the functions to handle Stack
void push(Stack *,BSTNode *);
BSTNode * pop(Stack *);
BSTNode * peek(Stack);
int isEmpty(Stack);
void freeStack(Stack *);



//declaration of the functions to handle Queue
void enQueue(Queue *,BSTNode *);
BSTNode * deQueue(Queue *);
int isEmptyQueue(Queue);
void freeQueue(Queue *);



//declaration of the functions to handle binary search tree
void insertBST(BST *,int);
void levelOrderTraversal(BST);
int countNodes(BST);
void preOrderTraversal(BST);
void inOrderTraversal(BST);
void postOrderTraversal(BST);
SearchStatus findNode(BST,int);
SearchStatus maxVal(BST);
SearchStatus minVal(BST);
int height(BST);
int depthNode(BST,int);
void delNode(BST *,int);
void delCase1(BST *,BSTNode *,BSTNode *);
void delCase2(BST *,BSTNode *,BSTNode *);
void delCase3(BST *,BSTNode *,BSTNode *);
void freeBST(BST *);

//defining main function
int main()
{
    int choice,data;
    BST bst=DEFAULT_BST;
    SearchStatus result=DEFAULT_SEARCH_STATUS;
    do
    {
        printf("\nselect the operation: ");
        printf("\n\"Note:all the data elements must be distinct\"\n");
        printf("\n1.insert a data in BST ");
        printf("\n2.level order traversal ");
        printf("\n3.preorder traversal");
        printf("\n4.inorder traversal");
        printf("\n5.postorder traversal");
        printf("\n6.count nodes in the BST");
        printf("\n7.search a node containing key data and also find it's parent node");
        printf("\n8.max data value in the tree");
        printf("\n9.min data value in the tree");
        printf("\n10.delete a node");
        printf("\n11.clear the BST");
        printf("\n12.exit");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data : ");
            scanf("%d",&data);
            insertBST(&bst,data);
            printf("\n%d is successfully added to the BST\n",data);
            break;
        case 2:
            printf("\nLevel order traversal of the BST is : \n");
            levelOrderTraversal(bst);
            printf("\n");
            break;
        case 3:
            printf("\npreorder traversal of the BST is : \n");
            preOrderTraversal(bst);
            printf("\n");
            break;
        case 4:
            printf("\ninorder traversal of the BST is : \n");
            inOrderTraversal(bst);
            printf("\n");
            break;
        case 5:
            printf("\npostorder traversal of BST is : \n");
            postOrderTraversal(bst);
            printf("\n");
            break;
        case 6:
            printf("\n\"number of nodes in the BST are : %d\"\n",countNodes(bst));
            break;
        case 7:
            printf("\nenter the data to be searched : ");
            scanf("%d",&data);
            result=findNode(bst,data);
            if(result.status==true&&result.par==NULL)
                printf("\n\"requested data %d is found at root of the tree\"\n",data);
            else
            if(result.status==false)
                printf("\n\"requested data %d not found in the tree\"\n",data);
            else
                printf("\n\"requested data %d is found with parent node value %d\"\n",data,result.par->data);
            break;
        case 8:
            result=maxVal(bst);
            if(result.status==false)
                printf("\n\"Tree is Empty\"\n");
            else
                printf("\n\"max data value is %d\"\n",result.par->data);
            break;
        case 9:
            result=minVal(bst);
            if(result.status==false)
                printf("\n\"Tree is Empty\"\n");
            else
                printf("\n\"min data value is %d\"\n",result.par->data);
            break;
        case 10:
            printf("\nenter the data to be deleted : ");
            scanf("%d",&data);
            delNode(&bst,data);
            break;
        case 11:
            freeBST(&bst);
            if(bst.root==NULL)
                printf("\nBST is cleared successfully\n");
            else
                printf("\nError:unable to clear BST successfully");
            break;
        case 12:
            printf("\nQuitting the Application");
            freeBST(&bst);
            exit(0);
        default:
            printf("\nWrong choice dear!!!");
        }
    }while(1);
    return 0;
}

//defining push
void push(Stack *pstk,BSTNode * address)
{
     StackNode *new_node=(StackNode *)malloc(sizeof(StackNode));
     if(new_node==NULL)
     {
         printf("\nError:memory allocation problem");
         return;
     }
     new_node->address=address;
     new_node->next=NULL;
     if(pstk->tos==NULL)
     {
         pstk->tos=new_node;
         return;
     }
     new_node->next=pstk->tos;
     pstk->tos=new_node;
}

//defining pop
BSTNode * pop(Stack *pstk)
{
    BSTNode *popped_element=NULL;
    StackNode *temp=NULL;
    if(pstk->tos==NULL)
    {
        return NULL;
    }
    if(pstk->tos->next==NULL)
    {
        popped_element=pstk->tos->address;
        free(pstk->tos);
        pstk->tos=NULL;
        return popped_element;
    }
    popped_element=pstk->tos->address;
    temp=pstk->tos;
    pstk->tos=pstk->tos->next;
    free(temp);
    return popped_element;
}

//defining peek
BSTNode * peek(Stack stk)
{
    if(stk.tos==NULL)
        return NULL;
    return(stk.tos->address);
}

//defining isEmpty
int isEmpty(Stack stk)
{
    return(stk.tos==NULL);
}

//defining freeStack
void freeStack(Stack *pstk)
{
    StackNode *temp=NULL,*next=NULL;
    if(pstk->tos==NULL)
    {
        return;
    }
    if(pstk->tos->next==NULL)
    {
        free(pstk->tos);
        pstk->tos=NULL;
    }
    temp=pstk->tos;
    next=pstk->tos->next;
    while(temp!=NULL)
    {
        free(temp);
        temp=next;
        if(next!=NULL)
            next=next->next;
    }
    pstk->tos=NULL;
}


//defining enQueue
void enQueue(Queue *pq,BSTNode *address)
{
    QueueNode *new_node=(QueueNode *)malloc(sizeof(QueueNode));
    if(new_node==NULL)
    {
        printf("\n\"Error:Memory Allocation Problem\"\n");
        return;
    }
    new_node->address=address;
    new_node->next=NULL;
    if(pq->rear==NULL)
    {
        pq->rear=new_node;
        pq->front=new_node;
        return;
    }
    pq->rear->next=new_node;
    pq->rear=new_node;
    return;
}

//defining deQueue
BSTNode * deQueue(Queue *pq)
{
    QueueNode *temp=NULL;
    BSTNode *address=NULL;
    if(pq->front==NULL)
    {
        return NULL;
    }
    if(pq->front->next==NULL)
    {
        address=pq->front->address;
        free(pq->front);
        pq->front=pq->rear=NULL;
        return address;
    }
    temp=pq->front;
    address=temp->address;
    pq->front=pq->front->next;
    free(temp);
    return address;
}

//defining isEmptyQueue
int isEmptyQueue(Queue q)
{
    return(q.front==NULL);
}

//defining freeQueue
void freeQueue(Queue *pq)
{
    QueueNode *temp=NULL;
    if(pq->front==NULL)
    {
        return;
    }
    if(pq->front->next==NULL)
    {
        free(pq->front);
        pq->front=NULL;
        return;
    }
    temp=pq->front;
    pq->front=pq->front->next;
    while(temp!=NULL)
    {
        free(temp);
        temp=pq->front;
        if(pq->front!=NULL)
            pq->front=pq->front->next;
    }
    pq->rear=NULL;
}


//defining insertBST
void insertBST(BST *pbst,int data)
{
    BSTNode *new_node=(BSTNode *)malloc(sizeof(BSTNode));
    BSTNode *par=NULL,*child=NULL;
    if(new_node==NULL)
    {
        printf("\nError:Memory Allocation Problem");
        return;
    }
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    if(pbst->root==NULL)
    {
        pbst->root=new_node;
        return;
    }
    child=pbst->root;
    while(child!=NULL)
    {
        if(data<child->data)
        {
            par=child;
            child=child->left;
        }
        else
        {
            par=child;
            child=child->right;
        }
    }
    if(data<par->data)
    {
        par->left=new_node;
    }
    else
    {
        par->right=new_node;
    }
}

//defining levelOrderTraversal
void levelOrderTraversal(BST bst)
{
    BSTNode *temp=NULL;
    Queue queue=DEFAULT_QUEUE;
    if(bst.root==NULL)
    {
        printf("\n\"BST is empty\"\n");
        return;
    }
    temp=bst.root;
    enQueue(&queue,temp);
    while(isEmptyQueue(queue)!=1)
    {
        temp=deQueue(&queue);
        printf("%d ",temp->data);
        if(temp->left!=NULL)
                enQueue(&queue,temp->left);
        if(temp->right!=NULL)
                enQueue(&queue,temp->right);
    }
    freeQueue(&queue);
}

//defining countNodes
int countNodes(BST bst)
{
    BSTNode *temp=bst.root;
    Queue queue=DEFAULT_QUEUE;
    int count=0;
    if(bst.root==NULL)
        return 0;
    enQueue(&queue,temp);
    while(1)
    {
        temp=deQueue(&queue);
        if(temp==NULL)
            break;
        count++;
        if(temp->left!=NULL)
            enQueue(&queue,temp->left);
        if(temp->right!=NULL)
            enQueue(&queue,temp->right);
    }
    freeQueue(&queue);
    return count;
}

//defining freeBST
void freeBST(BST *pbst)
{
    BSTNode *temp=pbst->root;
    Queue queue=DEFAULT_QUEUE;
    if(pbst->root==NULL)
        return;
    enQueue(&queue,temp);
    while(isEmptyQueue(queue)!=1)
    {
        temp=deQueue(&queue);
        if(temp->left!=NULL)
                enQueue(&queue,temp->left);
        if(temp->right!=NULL)
                enQueue(&queue,temp->right);
        free(temp);
    }
    pbst->root=NULL;
}

//defining preOrderTraversal
void preOrderTraversal(BST bst)
{
    BSTNode *temp=bst.root;
    Stack stk=DEFAULT_STACK;
    if(bst.root==NULL)
    {
        printf("\nEmpty BST");
        return;
    }
    while(1)
    {
        printf("%d ",temp->data);
        if(temp->right!=NULL)
            push(&stk,temp->right);
        if(temp->left==NULL)
            {
            temp=pop(&stk);
            if(temp==NULL)
                break;
            }
        else
            temp=temp->left;
    }
freeStack(&stk);
}

//defining inOrderTraversal
void inOrderTraversal(BST bst)
{
    BSTNode *temp=bst.root;
    Stack stk=DEFAULT_STACK;
    if(bst.root==NULL)
    {
        printf("\nempty BST");
        return;
    }
   while(1)
   {
       while(temp!=NULL)
       {
           push(&stk,temp);
           temp=temp->left;
       }
       temp=pop(&stk);

       if(temp==NULL)
        break;
        else
        printf("%d ",temp->data);

        if(temp->right!=NULL)
            temp=temp->right;
        else
            temp=NULL;
    }
    freeStack(&stk);
}

//defining postOrderTraversal
void postOrderTraversal(BST bst)
{
    BSTNode *temp=bst.root;
    BSTNode **list=NULL;
    int i=0;
    Stack stk=DEFAULT_STACK;
    if(bst.root==NULL)
    {
        printf("\nEmpty Tree");
        return;
    }
    list=(BSTNode **)malloc(countNodes(bst)*sizeof(BSTNode *));
    if(list==NULL)
    {
        printf("\nERROR:memory allocation problem\"\n");
        return;
    }
    push(&stk,temp);
    while(isEmpty(stk)!=1)
    {
        temp=pop(&stk);
        list[i++]=temp;
        if(temp->left!=NULL)
            push(&stk,temp->left);
        if(temp->right!=NULL)
            push(&stk,temp->right);
    }
    i--;
    while(i>=0)
    {
        printf("%d ",list[i--]->data);
    }
    free(list);
    freeStack(&stk);
}

//defining findNode
SearchStatus findNode(BST bst,int data)
{
    BSTNode *child=bst.root,*par=NULL;
    SearchStatus result=DEFAULT_SEARCH_STATUS;
    if(bst.root==NULL)
    {
        printf("\n\"Tree is Empty\"\n");
        return result;
    }
    while(child!=NULL)
    {
        if(child->data==data)
            break;
        else
        if(data<child->data)
        {
            par=child;
            child=child->left;
        }
        else
        {
            par=child;
            child=child->right;
        }
    }
    if(child!=NULL)
    {
        result.par=par;
        result.status=true;
    }
return result;
}

//defining maxVal
SearchStatus maxVal(BST bst)
{
    BSTNode *child=bst.root,*par=NULL;
    SearchStatus result=DEFAULT_SEARCH_STATUS;
    if(bst.root==NULL)
    {
        return result;
    }
    while(child!=NULL)
    {
        par=child;
        child=child->right;
    }
    result.par=par;
    result.status=true;
    return result;
}

//defining minVal
SearchStatus minVal(BST bst)
{
    BSTNode *child=bst.root,*par=NULL;
    SearchStatus result=DEFAULT_SEARCH_STATUS;
    if(bst.root==NULL)
    {
        return result;
    }
    while(child!=NULL)
    {
        par=child;
        child=child->left;
    }
    result.status=true;
    result.par=par;
    return result;
}

//defining delNode
void delNode(BST *pbst,int data)
{
    SearchStatus result=DEFAULT_SEARCH_STATUS;
    BSTNode *node=NULL;
    if(pbst->root==NULL)
    {
        printf("\n\"Tree is Empty\"\n");
        return;
    }
    result=findNode(*pbst,data);
    if(result.status==false)
    {
        printf("\n\"requested node with data %d is not found\"\n",data);
        return;
    }
    else
    if(result.status==true&&result.par==NULL)
    {
        node=pbst->root;
    }
    else
    {
        if(data<result.par->data)
        {
            node=result.par->left;
        }
        else
        {
            node=result.par->right;
        }

    }
    if(node->left==NULL&&node->right==NULL)
    {
        delCase1(pbst,node,result.par);
        printf("\n\"node is successfully deleted\"\n");
        return;
    }
    else
    if((node->left!=NULL&&node->right==NULL)||(node->left==NULL&&node->right!=NULL))
    {
        delCase2(pbst,node,result.par);
        printf("\n\"node is successfully deleted\"\n");
        return;
    }
    else
    {
        delCase3(pbst,node,result.par);
        printf("\n\"node is successfully deleted\"\n");
        return;
    }
}

//delCase1
void delCase1(BST *pbst,BSTNode *node,BSTNode *par)
{
    if(node==pbst->root)
    {
        free(node);
        pbst->root=NULL;
        return;
    }
    if(node->data<par->data)
    {
        free(node);
        par->left=NULL;
        return;
    }
    else
    {
        free(node);
        par->right=NULL;
        return;
    }
}

//delCase2
void delCase2(BST *pbst,BSTNode *node,BSTNode *par)
{
    BSTNode *temp=NULL;
    if(pbst->root==node)
    {
        if(node->left!=NULL)
        {
            pbst->root=node->left;
            free(node);
            return;
        }
        else
        {
            pbst->root=node->right;
            free(node);
            return;
        }
    }
    if(node->left!=NULL)
        temp=node->left;
    else
        temp=node->right;
    if(par->left==node)
    {
        par->left=temp;
        free(node);
    }
    else
    {
        par->right=temp;
        free(node);
    }

}

//defining delCase3
void delCase3(BST *pbst,BSTNode *node,BSTNode *par)
{
 BSTNode *successor=NULL,*psuccessor=NULL,*temp=NULL;
 psuccessor=node;
 successor=node->right;
 temp=successor->left;
 while(temp!=NULL)
 {
     psuccessor=successor;
     successor=temp;
     temp=temp->left;
 }
 if(psuccessor->right==successor)
 {
     if(successor->right==NULL)
     {
         psuccessor->right=NULL;
     }
     else
     {
         psuccessor->right=successor->right;
     }
 }
 else
 {
     if(successor->right==NULL)
     {
         psuccessor->left=NULL;
     }
     else
     {
         psuccessor->left=successor->right;
     }
 }
 successor->left=node->left;
 successor->right=node->right;
 if(pbst->root==node)
 {
     pbst->root=successor;
     free(node);
     return;
 }
 if(par->left==node)
 {
     par->left=successor;
     free(node);
 }
 else
 {
     par->right=successor;
     free(node);
 }

}

/*sample output 

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 500

500 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 300

300 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 700

700 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 200

200 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 400

400 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 600

600 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 800

800 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 900

900 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 1

enter the data : 850

850 is successfully added to the BST

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 2

Level order traversal of the BST is :
500 300 700 200 400 600 800 900 850

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 3

preorder traversal of the BST is :
500 300 200 400 700 600 800 900 850

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 4

inorder traversal of the BST is :
200 300 400 500 600 700 800 850 900

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 5

postorder traversal of BST is :
200 400 300 600 850 900 800 700 500

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 6

"number of nodes in the BST are : 9"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 7

enter the data to be searched : 500

"requested data 500 is found at root of the tree"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 7

enter the data to be searched : 900

"requested data 900 is found with parent node value 800"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 7

enter the data to be searched : 1500

"requested data 1500 not found in the tree"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 8

"max data value is 900"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 9

"min data value is 200"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 10

enter the data to be deleted : 1500

"requested node with data 1500 is not found"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 10

enter the data to be deleted : 900

"node is successfully deleted"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 4

inorder traversal of the BST is :
200 300 400 500 600 700 800 850

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 10

enter the data to be deleted : 500

"node is successfully deleted"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 4

inorder traversal of the BST is :
200 300 400 600 700 800 850

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 10

enter the data to be deleted : 800

"node is successfully deleted"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 4

inorder traversal of the BST is :
200 300 400 600 700 850

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 11

BST is cleared successfully

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 6

"number of nodes in the BST are : 0"

select the operation:
"Note:all the data elements must be distinct"

1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.search a node containing key data and also find it's parent node
8.max data value in the tree
9.min data value in the tree
10.delete a node
11.clear the BST
12.exit
enter your choice : 12

Quitting the Application

*/

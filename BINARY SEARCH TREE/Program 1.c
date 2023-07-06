#include<stdio.h>
#include<stdlib.h>
#define DEFAULT_BST {.root=NULL}
#define DEFAULT_STACK {.tos=NULL}
#define DEFAULT_QUEUE {.front=NULL,.rear=NULL}
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

//declaration of the functions to handle binary search tree
void insertBST(BST *,int);
void levelOrderTraversal(BST);
int countNodes(BST);
void preOrderTraversal(BST);
void inOrderTraversal(BST);
void postOrderTraversal(BST);
void freeBST(BST *);

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

int main()
{
    int choice,data;
    BST bst=DEFAULT_BST;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.insert a data in BST ");
        printf("\n2.level order traversal ");
        printf("\n3.preorder traversal");
        printf("\n4.inorder traversal");
        printf("\n5.postorder traversal");
        printf("\n6.count nodes in the BST");
        printf("\n7.clear the BST");
        printf("\n8.exit");
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
            freeBST(&bst);
            if(bst.root==NULL)
                printf("\nBST is cleared successfully\n");
            else
                printf("\nError:unable to clear BST successfully");
            break;
        case 8:
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

/*Sample Output

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 500

500 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 300

300 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 200

200 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 400

400 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 700

700 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 600

600 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 1

enter the data : 800

800 is successfully added to the BST

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 2

Level order traversal of the BST is :
500 300 700 200 400 600 800

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 3

preorder traversal of the BST is :
500 300 200 400 700 600 800

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 4

inorder traversal of the BST is :
200 300 400 500 600 700 800

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 5

postorder traversal of BST is :
200 400 300 600 800 700 500

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 6

"number of nodes in the BST are : 7"

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 7

BST is cleared successfully

select the operation :
1.insert a data in BST
2.level order traversal
3.preorder traversal
4.inorder traversal
5.postorder traversal
6.count nodes in the BST
7.clear the BST
8.exit
enter your choice : 8

Quitting the Application
Process returned 0 (0x0)   execution time : 36.240 s
Press any key to continue.
*/

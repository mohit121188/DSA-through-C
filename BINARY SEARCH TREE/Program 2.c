#include<stdio.h>
#include<stdlib.h>
#define DEFAULT_BST {.root=NULL}
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
//declaration of the functions to handle BST
void insertNode(BST *,int);
void preorderTraversal(BSTNode *);
void inorderTraversal(BSTNode *);
void postorderTraversal(BSTNode *);
void freeTree(BSTNode **);

//defining main function

int main()
{
    BST bst=DEFAULT_BST;
    int choice,data;
    do
    {
        printf("\n\nselect the operation on the BST : ");
        printf("\n1.insert");
        printf("\n2.preorder traversal");
        printf("\n3.inorder traversal");
        printf("\n4.postorder traversal");
        printf("\n5.clear the tree");
        printf("\n6.close the application");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data : ");
            scanf("%d",&data);
            insertNode(&bst,data);
            break;
        case 2:
            printf("\npreorder traversal : ");
            if(bst.root==NULL)
                printf("\nTREE IS EMPTY");
            else
                preorderTraversal(bst.root);
            break;
        case 3:
            printf("\ninorder traversal : ");
            if(bst.root==NULL)
                printf("\nTREE IS EMPTY");
            else
                inorderTraversal(bst.root);
            break;
        case 4:
            printf("\npostorder traversal : ");
            if(bst.root==NULL)
                printf("\nTREE IS EMPTY");
            else
                postorderTraversal(bst.root);
            break;
        case 5:
            freeTree(&(bst.root));
            printf("\nBST is cleared successfully");
            break;
        case 6:
            freeTree(&(bst.root));
            printf("\nQuitting the Application");
            exit(0);
            break;
        default:
            printf("\nwrong choice try again");
        }
    }while(1);
    return 0;
}

//defining insertNode
void insertNode(BST *pbst,int data)
{
    BSTNode *new_node=(BSTNode *)malloc(sizeof(BSTNode));
    BSTNode *child=NULL,*par=NULL;
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
    par=NULL;
    while(child!=NULL)
    {
        par=child;
        if(data<child->data)
            child=child->left;
        else
            child=child->right;
    }
    if(data<par->data)
    {
        par->left=new_node;
    }
    else
        par->right=new_node;
}
//defining preorderTraversal
void preorderTraversal(BSTNode *node)
{
    if(node==NULL)
        return;
    printf("%d ",node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
//defining inorderTraversal
void inorderTraversal(BSTNode *node)
{
    if(node==NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ",node->data);
    inorderTraversal(node->right);
}
//defining postorderTraversal
void postorderTraversal(BSTNode *node)
{
    if(node==NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ",node->data);
}

//defining freeTree
void freeTree(BSTNode **proot)
{
    if(*proot==NULL)
    {
        return;
    }
    freeTree(&(*proot)->left);
    freeTree(&(*proot)->right);
    free(*proot);
    *proot=NULL;
}

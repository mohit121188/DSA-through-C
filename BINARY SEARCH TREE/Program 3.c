#include<stdio.h>
#include<stdlib.h>
#define DEFAULT_BST {.root=NULL}
#include<stdbool.h>
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

//declaration of the functions to handle the Binary Search Tree
void inserNode(BST *,int);
void preorderTraversal(BSTNode *);
void inorderTraversal(BSTNode *);
void postorderTraversal(BSTNode *);
bool isBST(BSTNode *);
void freeBST(BSTNode **);

//defining main function
int main()
{
    int choice,data;
    bool loop_status=true;
    BST bst=DEFAULT_BST;
    do
    {
        printf("\n\nselect the operation : ");
        printf("\n1.insert");
        printf("\n2.preorder traversal");
        printf("\n3.inorder traversal");
        printf("\n4.postorder traversal");
        printf("\n5.check validity");
        printf("\n6.clear the tree");
        printf("\n7.exit the application");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data : ");
            scanf("%d",&data);
            inserNode(&bst,data);
            break;
        case 2:
            printf("\npreorder traversal :\n");
            preorderTraversal(bst.root);
            break;
        case 3:
            printf("\ninorder traversal : \n");
            inorderTraversal(bst.root);
            break;
        case 4:
            printf("\npostorder traversal : \n");
            postorderTraversal(bst.root);
            break;
        case 5:
            if(isBST(bst.root)==true)
                printf("\nIt is a valid BST");
            else
                printf("\nIt is an invalid BST");
            break;
        case 6:
            freeBST(&(bst.root));
            printf("\nBST is cleared successfully");
            break;
        case 7:
            freeBST(&(bst.root));
            printf("\nquitting the menu\n\n");
            loop_status=false;
            break;
        default:
            printf("\ninvalid choice");
        }
    }while(loop_status==true);
    printf("\nto check the correctness of the function isBST ");
    printf("\nwe created a invalid BST manually");
    BSTNode *root=NULL;
    BSTNode *new_node=(BSTNode *)malloc(sizeof(BSTNode));
    new_node->data=50;
    new_node->left=NULL;
    new_node->right=NULL;
    root=new_node;
    new_node=(BSTNode *)malloc(sizeof(BSTNode));
    new_node->data=30;
    new_node->left=NULL;
    new_node->right=NULL;
    root->left=new_node;
    new_node=(BSTNode *)malloc(sizeof(BSTNode));
    new_node->data=70;
    new_node->left=NULL;
    new_node->right=NULL;
    root->right=new_node;
    new_node=(BSTNode *)malloc(sizeof(BSTNode));
    new_node->data=90;
    new_node->left=NULL;
    new_node->right=NULL;
    root->right=new_node;
    root->left->left=new_node;
    printf("\nlet's see it's inorder traversal\n");
    inorderTraversal(root);
    printf("\nlet's check it's validity\n");
    if(isBST(root)==true)
        printf("\nIt is a valid BST\n");
    else
        printf("\nIt is not a valid BST\n");
    return 0;
}
//defining insertNode
void inserNode(BST *pbst,int data)
{
    BSTNode *new_node=(BSTNode *)malloc(sizeof(BSTNode));
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
    BSTNode *child=pbst->root,*par=NULL;
    while(child!=NULL)
    {
        par=child;
        if(data<child->data)
            child=child->left;
        else
            child=child->right;
    }
    if(data<par->data)
        par->left=new_node;
    else
        par->right=new_node;
}

//defining preorderTraversal
void preorderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//defining inorderTraversal
void inorderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

//defining postorderTraversal
void postorderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}

//Deleting the BST
void freeBST(BSTNode **proot)
{
    if(*proot==NULL)
        return;
    if((*proot)->left!=NULL)
        freeBST((*proot)->left);
    if((*proot)->right!=NULL)
        freeBST((*proot)->right);
    free(*proot);
    *proot=NULL;
}

//defining isBST
bool isBST(BSTNode *root)
{
    static bool val=true;
    if(root==NULL)
        return val;
    else
        if(root->left==NULL&&root->right==NULL)
        return val;
    else
        if(root->left!=NULL)
    {
        if(root->left->data<root->data)
        {
            val=true;
            isBST(root->left);
        }
        else
        {
            val=false;
            return val;
        }
    }
    else
        if(root->right!=NULL)
    {
        if(root->right->data>root->data)
        {
            val=true;
            isBST(root->right);
        }
        else
        {
            val=false;
            return val;
        }
    }
}


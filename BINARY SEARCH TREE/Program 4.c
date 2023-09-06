/*Menu driven program to perfrom various operation on BST*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//define a structure named BSTNode
struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};
typedef struct BSTNode BSTNode;

//define a structure named ResultStatus
struct ResultStatus
{
    bool status;
    BSTNode *address;
};
typedef struct ResultStatus ResultStatus;

//declaration of the functions to handle Binary Search Tree
BSTNode * insertNode(BSTNode *,int);
bool validateBST(BSTNode *);
void preorderTraversal(BSTNode *);
void inorderTraversal(BSTNode *);
void postorderTraversal(BSTNode *);
BSTNode * findNode(BSTNode *,int);
void findPar(BSTNode *,int,ResultStatus *);
BSTNode * findMin(BSTNode *);
BSTNode * findMax(BSTNode *);
BSTNode * delNode(BSTNode *,int);
void clearBST(BSTNode **);

//defining main function
int main()
{
    BSTNode *root=NULL,*pnode=NULL;
    int choice,data;
    ResultStatus result={false,NULL};
    do
    {
        printf("\nselect the operation : ");
        printf("\n1. insert");
        printf("\n2. validate");
        printf("\n3. preorder traversal");
        printf("\n4. inorder traversal");
        printf("\n5. postorder traversal");
        printf("\n6. find a data");
        printf("\n7. find the parent node's data");
        printf("\n8. find min data element");
        printf("\n9. find max data element");
        printf("\n10. delete a data");
        printf("\n11. clear the tree");
        printf("\n12. Quit the application");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data : ");
            scanf("%d",&data);
            root=insertNode(root,data);
            printf("\n%d is inserted successfully\n",data);
            break;
        case 2:
            if(validateBST(root)==true)
                printf("\nIt is a valid BST\n");
            else
                printf("\nIt is a Invalid BST\n");
            break;
        case 3:
            printf("\npreorder traversal is : \n");
            preorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("\ninorder traversal is : \n");
            inorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("\npostorder traversal is : \n");
            postorderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("\nenter the data : ");
            scanf("%d",&data);
            pnode=findNode(root,data);
            if(pnode==NULL)
                printf("\ndata not found\n");
            else
                printf("\n%d is found\n",pnode->data);
            break;
        case 7:
            result.address=NULL;
            result.status=false;
            printf("\nenter the data : ");
            scanf("%d",&data);
            findPar(root,data,&result);
            if(result.status==false)
                printf("\nData not found\n");
            else
            if(result.status==true&&result.address==NULL)
                printf("\nData is found at the root of the tree\n");
            else
                printf("\nParent of %d is %d\n",data,result.address->data);
            break;
        case 8:
            pnode=findMin(root);
            if(pnode==NULL)
                printf("\nData not found\n");
            else
                printf("\nMinimum data element is %d\n",pnode->data);
            break;
        case 9:
            pnode=findMax(root);
            if(pnode==NULL)
                printf("\nData not found\n");
            else
                printf("\nMaximum data element is %d\n",pnode->data);
            break;
        case 10:
            printf("\nenter the data to be deleted : ");
            scanf("%d",&data);
            root=delNode(root,data);
            printf("\n%d deleted successfully from the tree\n",data);
            break;
        case 11:
            clearBST(&root);
            printf("\nBST cleared successfully\n");
            break;
        case 12:
            clearBST(&root);
            printf("\nQuitting the application\n");
            exit(0);
        default:
            printf("\nwrong choice!!!try again!!!");
        }
    }while(1);
    return 0;
}

//insertNode
BSTNode * insertNode(BSTNode *root,int data)
{
    if(root==NULL)
    {
        root=(BSTNode *)malloc(sizeof(BSTNode));
        if(root==NULL)
            printf("\nError:Memory Not Available\n");
        else
        {
            root->data=data;
            root->left=root->right=NULL;
        }
    }
    else
    if(data<root->data)
        root->left=insertNode(root->left,data);
    else
        root->right=insertNode(root->right,data);

    return root;
}

//validateBST
bool validateBST(BSTNode *root)
{
    if(root==NULL)
        return true;
    else
    if(root->left==NULL&&root->right==NULL)
        return true;
    else
    if(root->left!=NULL&&root->right==NULL)
    {
        if(root->left->data<root->data)
            return validateBST(root->left);
        else
            return false;
    }
    else
    if(root->left==NULL&&root->right!=NULL)
    {
        if(root->right->data>root->data)
            return validateBST(root->right);
        else
            return false;
    }
    else
    if(root->left!=NULL&&root->right!=NULL)
    {
        if(root->left->data<root->data&&root->right->data>root->data)
            return validateBST(root->left)&&validateBST(root->right);
        else
            return false;
    }

}

//preorderTraversal
void preorderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//inorderTraversal
void inorderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

//postorderTraversal
void postorderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}

//findNode
BSTNode * findNode(BSTNode *root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    if(root->data==data)
    {
        return root;
    }
    else
    if(data<root->data)
        return findNode(root->left,data);
    else
        return findNode(root->right,data);
}

//findPar
void findPar(BSTNode *root,int data,ResultStatus *presult)
{
    if(root==NULL)
    {
        presult->status=false;
        return;
    }
    else
    if(root->data==data)
    {
        presult->status=true;
        return;
    }
    else
    if(data<root->data)
    {
        presult->address=root;
        findPar(root->left,data,presult);
    }
    else
    {
        presult->address=root;
        findPar(root->right,data,presult);
    }
}

//findMin
BSTNode * findMin(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    else
    if(root->left==NULL)
        return root;
    else
        findMin(root->left);
}

//findMax
BSTNode * findMax(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    else
    if(root->right==NULL)
        return root;
    else
        findMax(root->right);
}

BSTNode * delNode(BSTNode *root,int data)
{
    BSTNode *temp=NULL;
    if(root==NULL)
        printf("\nEmpty Tree\n");
    else
    if(root->data==data)
    {
        if(root->left==NULL&&root->right==NULL)  //zero child case
        {
            free(root);
            root=NULL;
        }
        else
        if(root->left!=NULL&&root->right==NULL) //one left child zero right child
        {
            temp=root;
            root=root->left;
            free(temp);
            temp=NULL;
        }
        else
        if(root->left==NULL&&root->right!=NULL) //one right child zero left child
        {
            temp=root;
            root=root->right;
            free(temp);
            temp=NULL;
        }
        else
        if(root->left!=NULL&&root->right!=NULL) //two child
        {
            temp=findMax(root->left);
            root->data=temp->data;
            root->left=delNode(root->left,root->data);
        }
    }
    else
    if(data<root->data)
        root->left=delNode(root->left,data);
    else
        root->right=delNode(root->right,data);
    return root;
}

//clearBST
void clearBST(BSTNode **proot)
{
    if(*proot==NULL)
        return;
    clearBST(&(*proot)->left);
    clearBST(&(*proot)->right);
    free(*proot);
    *proot=NULL;
}


/*sample output*/
/*
select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 50

50 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 30

30 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 20

20 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 40

40 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 70

70 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 60

60 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 1

enter the data : 80

80 is inserted successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 2

It is a valid BST

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 3

preorder traversal is :
50 30 20 40 70 60 80

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 4

inorder traversal is :
20 30 40 50 60 70 80

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 5

postorder traversal is :
20 40 30 60 80 70 50

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 6

enter the data : 50

50 is found

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 6

enter the data : 30

30 is found

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 6

enter the data : 1000

data not found

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 7

enter the data : 50

Data is found at the root of the tree

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 7

enter the data : 20

Parent of 20 is 30

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 8

Minimum data element is 20

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 9

Maximum data element is 80

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 10

enter the data to be deleted : 30

30 deleted successfully from the tree

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 4

inorder traversal is :
20 40 50 60 70 80

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 10

enter the data to be deleted : 50

50 deleted successfully from the tree

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 4

inorder traversal is :
20 40 60 70 80

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 11

BST cleared successfully

select the operation :
1. insert
2. validate
3. preorder traversal
4. inorder traversal
5. postorder traversal
6. find a data
7. find the parent node's data
8. find min data element
9. find max data element
10. delete a data
11. clear the tree
12. Quit the application
enter your choice : 12

Quitting the application

Process returned 0 (0x0) */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//define a structure named BSTNode
struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
    int height;
};
typedef struct BSTNode BSTNode;

//define a structure named ResultStatus
struct ResultStatus
{
    bool status;
    BSTNode *address;
};
typedef struct ResultStatus ResultStatus;


//declarations of the functions to handle BST
int maxValue(int,int);
int getHight(BSTNode *);
BSTNode * insertNode(BSTNode *,int);
bool validateBST(BSTNode *);
void preorder(BSTNode *);
void inorder(BSTNode *);
void postorder(BSTNode *);
BSTNode * findNode(BSTNode *,int);
void findPar(ResultStatus *,BSTNode *,int);
BSTNode * findMin(BSTNode *);
BSTNode * findMax(BSTNode *);
BSTNode * clearTree(BSTNode *);
BSTNode * delNode(BSTNode *,int);

//defining main function
int main()
{
    BSTNode *root=NULL,*node;
    int choice,data;
    ResultStatus result={.status=false,.address=NULL};
    do
    {
        printf("\nSelect the operation\n");
        printf("\n1.\tinsert a data");
        printf("\n2.\tcheck the validity of BST");
        printf("\n3.\tpreorder traversal");
        printf("\n4.\tinorder traversal");
        printf("\n5.\tpostorder traversal");
        printf("\n6.\tfind a node");
        printf("\n7.\tfind the parent");
        printf("\n8.\tfind the smallest data value");
        printf("\n9.\tfind the largest data value");
        printf("\n10.\tdelete a node");
        printf("\n11.\tclear the tree");
        printf("\n12.\texit the application");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data : ");
            scanf("%d",&data);
            root=insertNode(root,data);
            node=findNode(root,data);
            if(node==NULL)
                printf("\nData insertion failed\n");
            else
                printf("\n%d inserted successfully\n",node->data);
            break;
        case 2:
            if(validateBST(root)==false)
                printf("\nIt is not a valid BST\n");
            else
                printf("\nIt is a valid BST\n");
            break;
        case 3:
            printf("\nPreorder Traversal : \n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nInorder Traversal : \n");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nPostorder Traversal : \n");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("\nEnter the data to be found : ");
            scanf("%d",&data);
            node=findNode(root,data);
            if(node==NULL)
                printf("\n%d not found in the BST\n",data);
            else
                printf("\n%d is available in the BST\n",node->data);
            break;
        case 7:
            result.status=false;
            result.address=NULL;
            printf("\nEnter the data whose parent is to be found : ");
            scanf("%d",&data);
            findPar(&result,root,data);
            if(result.status==false)
            {
                printf("\n%d not found in the BST\n",data);
            }
            else
            {
                if(result.address==NULL)
                    printf("\n%d is ROOT Node\n",data);
                else
                    printf("\nParent of the %d is %d\n",data,result.address->data);
            }
            break;
        case 8:
            node=findMin(root);
            if(node==NULL)
                printf("\nSearch operation unsuccessfull\n");
            else
                printf("\nsmallest data element is %d\n",node->data);
            break;
        case 9:
            node=findMax(root);
            if(node==NULL)
                printf("\nSearch operation unsuccessfull\n");
            else
                printf("\nLargest data element is %d\n",node->data);
            break;
        case 10:
            printf("\nenter the data to be deleted : ");
            scanf("%d",&data);
            root=delNode(root,data);
            node=findNode(root,data);
            if(node==NULL)
                printf("\n%d deleted successfully\n",data);
            else
                printf("\n%d is not deleted\n",node->data);
            break;
        case 11:
            root=clearTree(root);
            printf("\nTree is cleared successfully\n");
            break;
        case 12:
            root=clearTree(root);
            printf("\nTree is cleared successfully\n");
            printf("\nQuitting the Application\n");
            exit(0);
            break;
        default:
            printf("\nWrong choice!!!Try Again!!!\n");
        }
    }while(1);
    return 0;
}


//define maxValue
int maxValue(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

//define getHeight
int getHight(BSTNode *root)
{
    if(root==NULL)
        return -1;
    return root->height;
}

//define insertNode
BSTNode * insertNode(BSTNode *root,int data)
{
    if(root==NULL)
    {
        root=(BSTNode *)malloc(sizeof(BSTNode));
        if(root==NULL)
            printf("\nError:Memory can't be allocated\n");
        else
        {
        root->data=data;
        root->left=root->right=NULL;
        root->height=0;
        }
    }
    else
    if(data<root->data)
    {
        root->left=insertNode(root->left,data);
    }
    else
    {
        root->right=insertNode(root->right,data);
    }
    root->height=maxValue(getHight(root->left),getHight(root->right))+1;
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

//define preorder
void preorder(BSTNode *root)
{
    if(root==NULL)
        return;
    printf("\nData : %d, Height : %d\n",root->data,root->height);
    preorder(root->left);
    preorder(root->right);
}

//define inorder
void inorder(BSTNode *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("\nData : %d, Height : %d\n",root->data,root->height);
    inorder(root->right);
}

//define postorder
void postorder(BSTNode *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("\nData : %d, Height : %d\n",root->data,root->height);
}

//define findNode
BSTNode * findNode(BSTNode *root,int data)
{
    if(root==NULL)
        return NULL;
    else
    if(data==root->data)
        return root;
    else
    if(data<root->data)
        return findNode(root->left,data);
    else
        return findNode(root->right,data);
}

//define findPar
void findPar(ResultStatus *presult,BSTNode *root,int data)
{
    if(root==NULL)
    {
        presult->status=false;
        return;
    }
    else
    if(data==root->data)
    {
        presult->status=true;
        return;
    }
    else
    if(data<root->data)
    {
        presult->address=root;
        findPar(presult,root->left,data);
    }
    else
    {
        presult->address=root;
        findPar(presult,root->right,data);
    }
}

//define findMin
BSTNode * findMin(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    else
    if(root->left==NULL)
        return root;
    else
        return findMin(root->left);
}

//define findMax
BSTNode * findMax(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    else
    if(root->right==NULL)
        return root;
    else
        return findMax(root->right);
}

//define clearTree
BSTNode * clearTree(BSTNode *root)
{
    if(root==NULL)
        return NULL;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
    root=NULL;
    return root;
}

//define DelNode
BSTNode * delNode(BSTNode *root,int data)
{
    BSTNode *temp=NULL;
    if(root==NULL)
    {
        printf("\nDATA NOT FOUND\n");
    }
    else
    if(data==root->data)
    {
        if(root->left==NULL&&root->right==NULL) //zero child
        {
            free(root);
            root=NULL;
        }
        else
        if(root->left!=NULL&&root->right==NULL)//only one left child
        {
            temp=root;
            root=root->left;
            free(temp);
            temp=NULL;
        }
        else
        if(root->left==NULL&&root->right!=NULL)//only one right child
        {
            temp=root;
            root=root->right;
            free(temp);
            temp=NULL;
        }
        else
        {
            temp=findMax(root->left);
            root->data=temp->data;
            root->left=delNode(root->left,root->data);
            temp=NULL;
        }
    }
    else
    if(data<root->data)
    {
        root->left=delNode(root->left,data);
    }
    else
    {
        root->right=delNode(root->right,data);
    }
    if(root!=NULL)
    root->height=maxValue(getHight(root->left),getHight(root->right))+1;
    return root;
}

/*Sample Output*/
/*
Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 50

50 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 30

30 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 70

70 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 20

20 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 40

40 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 60

60 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 80

80 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 10

10 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 25

25 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 55

55 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 90

90 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 1

enter the data : 28

28 inserted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 2

It is a valid BST

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 3

Preorder Traversal :

Data : 50, Height : 4

Data : 30, Height : 3

Data : 20, Height : 2

Data : 10, Height : 0

Data : 25, Height : 1

Data : 28, Height : 0

Data : 40, Height : 0

Data : 70, Height : 2

Data : 60, Height : 1

Data : 55, Height : 0

Data : 80, Height : 1

Data : 90, Height : 0


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 4

Inorder Traversal :

Data : 10, Height : 0

Data : 20, Height : 2

Data : 25, Height : 1

Data : 28, Height : 0

Data : 30, Height : 3

Data : 40, Height : 0

Data : 50, Height : 4

Data : 55, Height : 0

Data : 60, Height : 1

Data : 70, Height : 2

Data : 80, Height : 1

Data : 90, Height : 0


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 5

Postorder Traversal :

Data : 10, Height : 0

Data : 28, Height : 0

Data : 25, Height : 1

Data : 20, Height : 2

Data : 40, Height : 0

Data : 30, Height : 3

Data : 55, Height : 0

Data : 60, Height : 1

Data : 90, Height : 0

Data : 80, Height : 1

Data : 70, Height : 2

Data : 50, Height : 4


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 6

Enter the data to be found : 55

55 is available in the BST

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 6

Enter the data to be found : 50

50 is available in the BST

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 6

Enter the data to be found : 100

100 not found in the BST

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 7

Enter the data whose parent is to be found : 20

Parent of the 20 is 30

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 7

Enter the data whose parent is to be found : 60

Parent of the 60 is 70

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 7

Enter the data whose parent is to be found : 50

50 is ROOT Node

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 8

smallest data element is 10

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 9

Largest data element is 90

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 10

enter the data to be deleted : 90

90 deleted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 4

Inorder Traversal :

Data : 10, Height : 0

Data : 20, Height : 2

Data : 25, Height : 1

Data : 28, Height : 0

Data : 30, Height : 3

Data : 40, Height : 0

Data : 50, Height : 4

Data : 55, Height : 0

Data : 60, Height : 1

Data : 70, Height : 2

Data : 80, Height : 0


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 10

enter the data to be deleted : 50

50 deleted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 4

Inorder Traversal :

Data : 10, Height : 0

Data : 20, Height : 2

Data : 25, Height : 1

Data : 28, Height : 0

Data : 30, Height : 3

Data : 40, Height : 4

Data : 55, Height : 0

Data : 60, Height : 1

Data : 70, Height : 2

Data : 80, Height : 0


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 10

enter the data to be deleted : 70

70 deleted successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 4

Inorder Traversal :

Data : 10, Height : 0

Data : 20, Height : 2

Data : 25, Height : 1

Data : 28, Height : 0

Data : 30, Height : 3

Data : 40, Height : 4

Data : 55, Height : 0

Data : 60, Height : 1

Data : 80, Height : 0


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 11

Tree is cleared successfully

Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 4

Inorder Traversal :


Select the operation

1.      insert a data
2.      check the validity of BST
3.      preorder traversal
4.      inorder traversal
5.      postorder traversal
6.      find a node
7.      find the parent
8.      find the smallest data value
9.      find the largest data value
10.     delete a node
11.     clear the tree
12.     exit the application
enter your choice : 12

Tree is cleared successfully

Quitting the Application

Process returned 0 (0x0)   execution time : 287.614 s
Press any key to continue.
*/

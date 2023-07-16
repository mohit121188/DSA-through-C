//style 1:
#include<stdio.h>
int findMin(int arr[],int n)
{
    static int min,index=0;
    if(index==n)
        return min;
    if(index==0)
        min=arr[index];
    if(min>arr[index])
        min=arr[index];
    index++;
    return(findMin(arr,n));
}
int main()
{
    int *arr=NULL;
    int n,i;
    printf("\nenter the number of elements to be stored in the array : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("\nError:memory allocation problem");
        return 1;
    }
    for(i=0;i<=n-1;i++)
    {
        printf("\nenter %dth element  : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nminimum element is %d",findMin(arr,n));
    return 0;
}

style 2:
#include<stdio.h>
int min(int,int);
int findMin(int arr[],int);
int main()
{
    int *arr=NULL;
    int n,i;
    printf("\nenter the size of array : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("\nError:Memory allocation problem");
        return 0;
    }
    for(i=0;i<=n-1;i++)
    {
        printf("\nenter element at %dth index : ",i);
        scanf("%d",(arr+i));
    }
    printf("\nminimum value of the array is : %d",findMin(arr,n));
    return 0;
}
int min(int x,int y)
{
    if(x<=y)
        return x;
    else
        return y;
}
int findMin(int arr[],int n)
{
    if(n==1)
        return arr[n-1];
    else
        return(min(arr[n],findMin(arr,n-1)));
}


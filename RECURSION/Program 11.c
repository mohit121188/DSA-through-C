
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

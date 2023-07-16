//style 1:
#include<stdio.h>
int greatest(int arr[],int n)
{
        static int max,index=0;
        if(index==n)
            return max;
        if(index==0)
            max=arr[0];
        if(max<arr[index])
            max=arr[index];
        index++;
        greatest(arr,n);
}
int main()
{
    int *arr=NULL;
    int n,i,max;
    printf("\nenter the number of elements to be stored : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("\nError:Memory allocation problem");
        return 1;
    }
    for(i=0;i<=n-1;i++)
    {
        printf("\nenter the %dth element in the array : ",i);
        scanf("%d",(arr+i));
    }
    max=greatest(arr,n);
    printf("\ngreatest number is %d",max);
    return 0;
}



//style 2:
#include<stdio.h>
#include<stdlib.h>
int max(int,int);
int findMax(int [],int);
int main()
{
    int n;
    int *arr=NULL;
    int i;
    printf("\nenter the number of elements to be stored in the array : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("\nERROR:memory allocation problem");
        return 1;
    }
    for(i=0;i<=n-1;i++)
    {
        printf("\nenter %dth element in the array : ",i);
        scanf("%d",(arr+i));
    }
    printf("\nmax element is %d",findMax(arr,n));
    return 0;
}

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int findMax(int arr[],int n)
{
    if(n==1)
        return(arr[n-1]);
    else
        return(max(arr[n],findMax(arr,n-1)));
}


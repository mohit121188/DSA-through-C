#include<stdio.h>
int greatest(int arr[],int size)
{
        static int max=0,index=0;
        if(index==5)
            return max;
        if(max<arr[index])
            max=arr[index];
        index++;
        greatest(arr,size);
}
int main()
{
    int arr[5]={30,1000,40,50,10};
    int max;
    max=greatest(arr,5);
    printf("\ngreatest number is %d",max);
    return 0;
}

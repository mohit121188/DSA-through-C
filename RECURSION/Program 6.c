#include<stdio.h>
#include<stdlib.h>

void display(int [],int);

int main()
{
    int arr[5]={10,20,30,40,50};
    display(arr,4);
    return 0;
}

void display(int arr[],int n)
{
    if(n==-1)
        return;
    display(arr,n-1);
    printf("\nelement at %dth index is %d",n,arr[n]);
}

/*Sample output

element at 0th index is 10
element at 1th index is 20
element at 2th index is 30
element at 3th index is 40
element at 4th index is 50

*/

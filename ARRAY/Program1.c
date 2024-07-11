/*Program 1: Find a pair with the given sum in an array*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("\nenter the size of array : ");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    if(p==NULL)
    {
        printf("\nMemory can't be allocated\n");
        return 1;
    }
    int i;
    for(i=0;i<=n-1;i++)
    {
        printf("\nenter data element at %dth indes : ",i);
        scanf("%d",p+i);
    }
    int target;
    printf("\nenter the target sum : ");
    scanf("%d",&target);
    printf("\ndisplaying the required pairs : \n");
    int j;
    for(i=0;i<=n-1;i++)
    {
        for(j=i;j<=n-1;j++)
        {
            if(p[i]+p[j]==target)
                printf("\n(%d,%d)\n",p[i],p[j]);
        }
    }
    return 0;
}

/* output : 
  enter the size of array : 10

enter data element at 0th indes : 2

enter data element at 1th indes : 4

enter data element at 2th indes : 5

enter data element at 3th indes : 6

enter data element at 4th indes : 3

enter data element at 5th indes : 7

enter data element at 6th indes : 8

enter data element at 7th indes : 9

enter data element at 8th indes : 1

enter data element at 9th indes : 12

enter the target sum : 10

displaying the required pairs :

(2,8)

(4,6)

(5,5)

(3,7)

(9,1)

Process returned 0 (0x0)   execution time : 50.412 s
Press any key to continue.*/

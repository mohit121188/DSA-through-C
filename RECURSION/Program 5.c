#include<stdio.h>
#include<stdlib.h>
//declaration of fib function
int fib(int);
int main()
{
    int n,i;
    printf("\nenter the value of n : ");
    scanf("%d",&n);
    if(n<1)
    {
        printf("\nError : value of n should be greater than or equal to 1");
        return 0;
    }
    else
    {
        printf("\ndisplaying the fibonacci series : \n");
        for(i=1;i<=n;i++)
        {
            printf("%dth element is :\t %d\n",i,fib(i));
        }
    }
    return 0;
}

//defining fib function
int fib(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return(fib(n-1)+fib(n-2));
}

/*Sample Output 

enter the value of n : 10

displaying the fibonacci series :
1th element is :         0
2th element is :         1
3th element is :         1
4th element is :         2
5th element is :         3
6th element is :         5
7th element is :         8
8th element is :         13
9th element is :         21
10th element is :        34

  */

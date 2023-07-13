#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n==1)
        return 0;
    else
    if(n==2)
        return 1;
    else
        return(fib(n-1)+fib(n-2));
}

int main()
{
    int n;
    int e;
    printf("\nenter the value of n : ");
    scanf("%d",&n);
    e=fib(n);
    printf("\n%dth element of the fibonacci series is %d\n",n,e);
    return 0;
}

/* Sample Output 

enter the value of n : 6

6th element of the fibonacci series is 5

*/

//Write a recursive program to calculate sum of integers from 1 to n, where value of n is entered by user.
#include<stdio.h>
//declaration of the function name sum
int sum(int);
int main()
{
    int n,s;
    printf("\nenter an integer number : ");
    scanf("%d",&n);
    s=sum(n);
    printf("\nsum of integers from 1 to %d is %d\n",n,s);
    return 0;
}
int sum(int n)
{
    if(n==1)
        return 1;
    else
        return(n+sum(n-1));
}
/*sample output
enter an integer number : 10

sum of integers from 1 to 10 is 55
  */

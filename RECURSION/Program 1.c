//C program to calculate factorial of a number using recursion 
#include<stdio.h>
//declaration of factorial function
int factorial(int);
int main()
{
    int n,fact;
    printf("\nenter an integer number : ");
    scanf("%d",&n);
    fact=factorial(n);
    printf("\nfactorial of %d is %d\n",n,fact);
    return 0;
}
int factorial(int n)
{
    if(n==1||n==0)
        return 1;
    else
        return(n*factorial(n-1));
}
/*sample output*/
enter an integer number : 6

factorial of 6 is 720
*/

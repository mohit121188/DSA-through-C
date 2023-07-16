#include<stdio.h>
int checkPrime(int n,int i)
{
    if(i>n/2)
        return 1;
    if(n%i==0)
        return 0;
    return(checkPrime(n,i+1));
}
int main()
{
    int n;
    printf("\nenter a number : ");
    scanf("%d",&n);
    if(checkPrime(n,2)==1)
        printf("\nIT IS A PRIME NUMBER\n");
    else
        printf("\nIT IS NOT A PRIME NUMBER\n");
    return 0;
}

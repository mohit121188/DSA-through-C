#include<stdio.h>
#include<stdlib.h>
int getHCF(int n1,int n2)
{
    if(n2==0)
        return n1;
    else
        return(getHCF(n2,n1%n2));
}
int main()
{
    int n1,n2;
    printf("\nenter two integer numbers : ");
    scanf("%d %d",&n1,&n2);
    printf("HCF is %d\n",getHCF(n1,n2));
    return 0;
}

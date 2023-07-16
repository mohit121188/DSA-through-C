#include<stdio.h>
int decimalToBinary(int);
int main()
{
    int d;
    int b;
    printf("\nenter an integer number : ");
    scanf("%d",&d);
    b=decimalToBinary(d);
    printf("\nbinary number is %d",b);
    return 0;
}
int decimalToBinary(int d)
{
    if(d==0)
        return 0;
    return(d%2+10*decimalToBinary(d/2));
}

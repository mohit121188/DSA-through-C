#include<stdio.h>
int power(int,int);
int main()
{
    int x,y;
    printf("\nenter the value of base : ");
    scanf("%d",&x);
    printf("\nenter the value of exponent : ");
    scanf("%d",&y);
    printf("\n%d to the power %d is %d\n",x,y,power(x,y));
    return 0;
}
int power(int x,int y)
{
    static int result=1;
    if(y==1)
        return x;
    else
        return(result*x*power(x,y-1));
}

#include<stdio.h>
void printOdd(int n1,int n2)
{
    if(n1>n2)
        return;
    else
    if(n1%2==0)
        printOdd(n1+1,n2);
    else
        if(n1%2!=0)
    {
        printf("%d ",n1);
        printOdd(n1+2,n2);
    }
}
int main()
{
    int n1,n2;
    printf("\nenter the range %c to %c : \n",63,63);
    scanf("%d",&n1);
    printf("to\n");
    scanf("%d",&n2);
    printf("\ndisplaying all odd numbers in this range : \n");
    printOdd(n1,n2);
    return 0;
}

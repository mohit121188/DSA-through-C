#include<stdio.h>
void hailStone(int n)
{
    sleep(1);
    printf("%d ",n);
    if(n==1)
        return;
    if(n%2==0)
        n=n/2;
    else
        n=3*n+1;
    hailStone(n);
}

int main()
{
    int n;
    printf("\nenter the starting number of hailstone sequence : ");
    scanf("%d",&n);
    printf("\ndisplaying the hailstone sequence : \n");
    hailStone(n);
    return 0;
}

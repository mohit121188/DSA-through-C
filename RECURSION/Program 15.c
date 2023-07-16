#include<stdio.h>
int getLCM(int n1,int n2)
{
    static int lcm;
    lcm=lcm+n1;
    if(lcm%n1==0&&lcm%n2==0)
        return lcm;
    else
        getLCM(n1,n2);
}

int main()
{
    int a,b;
    printf("\nenter two numbers : ");
    scanf("%d %d",&a,&b);
    printf("LCM of %d and %d is %d",a,b,getLCM(a,b));
    return 0;
}

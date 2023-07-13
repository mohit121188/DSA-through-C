#include<stdio.h>
#include<conio.h>

int sumDigits(int n)
{
    if(n==0)
        return 0;
    return((n%10)+sumDigits(n/10));
}

int main()
{
    int n;
    printf("\nenter an integer number : ");
    scanf("%d",&n);
    printf("\nsum of the digits is %d\n",sumDigits(n));
    return 0;
}

/*Sample Output

enter an integer number : 6377

sum of the digits is 23

*/

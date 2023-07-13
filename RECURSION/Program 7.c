#include<stdio.h>
#include<stdlib.h>

int countDigits(int n)
{
    if(n==0)
        return 0;
    else
        return(1+countDigits(n/10));
}

int main()
{
    int n;
    printf("\nenter an integer number : ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("\nnumber of digits are 1\n");
    }
    else
    {
    printf("\nnumber of digits are %d\n",countDigits(n));
    }
    return 0;
}

/*Sample output

enter an integer number : 63772

number of digits are 5

*/

//Write a program in C to print the first 20 natural numbers using recursion.
#include<stdio.h>
#include<stdlib.h>
void fun(int n)
{
    if(n==21)
        return;

    printf("%d\n",n);
    fun(n+1);
}
int main()
{
    fun(1);
    return 0;
}

/*Sample Output : 

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20

  */

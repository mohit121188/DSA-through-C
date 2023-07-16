#include<stdio.h>
#include<stdlib.h>
void reverse(char [],int);
int main()
{
    char str[30];
    printf("\nenter a string : ");
    gets(str);
    printf("\nstring you have entered is %s",str);
    printf("\nreverse of the string is : ");
    reverse(str,strlen(str)-1);
    return 0;
}
void reverse(char str[],int i)
{
    if(i==-1)
        return;
    printf("%c",str[i]);
    reverse(str,i-1);
}

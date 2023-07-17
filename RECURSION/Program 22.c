#include<stdio.h>
char getFirst(char []);
int main()
{
    char str[30];
    char first;
    printf("\nenter a string : ");
    gets(str);
    first=getFirst(str);
    if(first=='$')
        printf("\nCapital letter not found in the string");
    else
        printf("\nfirst capital letter in the string is %c",first);
    return 0;
}
char getFirst(char str[])
{
    static int i;
    if(str[i]==NULL)
        return '$';
    else
    if(str[i]>=65&&str[i]<=90)
        return str[i];
    else
        {   i++;
            return(getFirst(str));
        }
}

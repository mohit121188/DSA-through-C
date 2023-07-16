#include<stdio.h>
int isPalindrome(char [],int);
int main()
{
    char str[30];
    printf("\nenter a string : ");
    gets(str);
    if(isPalindrome(str,strlen(str)-1))
        printf("\nyes it is palindrome");
    else
        printf("\nit is not palindrome");
    return 0;
}
int isPalindrome(char str[],int l)
{
    static int i;
    if(i>=l)
        return 1;
    else
    if(str[i]!=str[l])
        return 0;
    else
    if(str[i++]==str[l--])
        return(isPalindrome(str,l));

}

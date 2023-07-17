#include<stdio.h>
void stringCopy(char [],char []);
int main()
{
    char source[10]="Mohit";
    char target[10];
    stringCopy(target,source);
    printf("\nsource string is %s",source);
    printf("\ntarget string is %s",target);
    return 0;
}
void stringCopy(char target[],char source[])
{
    static int i;
    if(source[i]==NULL)
    {
        target[i]=NULL;
        return;
    }
    else
    {
        target[i]=source[i];
        i++;
        stringCopy(target,source);
    }
}

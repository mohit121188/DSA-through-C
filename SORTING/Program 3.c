//Program to implement insertion sorting
#include<stdio.h>
#include<stdlib.h>
//prototype declaration of functions
void create_list(int **,int);
void display_list(int *,int);
void insertion_sort_inc(int *,int);
void insertion_sort_dec(int *,int);
//defining the main function
int main()
{
    int *list=NULL,size,choice;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.create a new list");
        printf("\n2.display the list");
        printf("\n3.sort in increasing order(Insertion Sorting)");
        printf("\n4.sort in decreasing order(Insertion Sorting)");
        printf("\n5.quit");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter size of the list : ");
            scanf("%d",&size);
            create_list(&list,size);
            break;
        case 2:
            display_list(list,size);
            break;
        case 3:
            insertion_sort_inc(list,size);
            printf("\n\"list is sorted in ascending order\"\n");
            break;
        case 4:
           insertion_sort_dec(list,size);
            printf("\n\"list is sorted in descending order\"\n");
            break;
        case 5:
            printf("\n\"quitting the application\"");
            exit(0);
            free(list);
            break;
        default:
            printf("\n\"enter correct choice\"");
        }
    }while(1);
    return 0;
}
//defining the create_list function
void create_list(int **plist,int size)
{
    int i;

    if(*plist!=NULL)
        free(*plist);//deallocating previously allocated memory if any

    *plist=(int *)malloc(size*sizeof(int));
    if(*plist==NULL)
    {
        printf("\n\"insufficient memory space\"");
        return;
    }
    printf("\n\"memory allocated auccessfully\"\n");
    for(i=0;i<=size-1;i++)
    {
        printf("\nenter element at index %d : ",i);
        scanf("%d",*plist+i);
    }
    printf("\n\"list created successfully\"\n");
}
//defining the display_list function
void display_list(int list[],int size)
{
    int i;
    printf("\n\"displaying the list\"\n");
    for(i=0;i<=size-1;i++)
    {
        printf("%d, ",list[i]);
    }
    printf("\b\b \n");
}
//defining the insertion sorting for increasing order
void insertion_sort_inc(int list[],int size)
{
    int i,j,temp;
    for(i=1;i<=size-1;i++)
    {
        j=i;
        while(list[j]<list[j-1]&&j>=1)
        {
            temp=list[j-1];
            list[j-1]=list[j];
            list[j]=temp;
            j--;
        }
    }
}
//defining insertion sorting for decreasing order
void insertion_sort_dec(int list[],int size)
{
    int i,j,temp;
    for(i=1;i<=size-1;i++)
    {
        j=i;
        while(list[j]>list[j-1]&&j>=1)
        {
            temp=list[j-1];
            list[j-1]=list[j];
            list[j]=temp;
            j--;
        }
    }
}
/*  SAMPLE OUTPUT

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 1

enter size of the list : 5

"memory allocated auccessfully"

enter element at index 0 : 4

enter element at index 1 : 3

enter element at index 2 : 5

enter element at index 3 : 1

enter element at index 4 : 2

"list created successfully"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 2

"displaying the list"
4, 3, 5, 1, 2

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 3

"list is sorted in ascending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 2

"displaying the list"
1, 2, 3, 4, 5

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 4

"list is sorted in descending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 2

"displaying the list"
5, 4, 3, 2, 1

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 1

enter size of the list : 10

"memory allocated auccessfully"

enter element at index 0 : 50

enter element at index 1 : 20

enter element at index 2 : 77

enter element at index 3 : 250

enter element at index 4 : 998

enter element at index 5 : 123

enter element at index 6 : 450

enter element at index 7 : 595

enter element at index 8 : 320

enter element at index 9 : 190

"list created successfully"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 2

"displaying the list"
50, 20, 77, 250, 998, 123, 450, 595, 320, 190

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 3

"list is sorted in ascending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 2

"displaying the list"
20, 50, 77, 123, 190, 250, 320, 450, 595, 998

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 4

"list is sorted in descending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 2

"displaying the list"
998, 595, 450, 320, 250, 190, 123, 77, 50, 20

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Insertion Sorting)
4.sort in decreasing order(Insertion Sorting)
5.quit
enter your choice : 5

"quitting the application"
Process returned 0 (0x0)   execution time : 108.099 s
Press any key to continue.

*/

//SELECTION SORTING
/* Steps SELECTION SORTING : 
1.  Find the smallest value in the list.
2.  Swap it with the first value in the list.
3.  Repeat the above steps for the remaining unsorted portion of the list.
4.  Continue this process until the entire list is sorted.
*/
#include<stdio.h>
#include<stdlib.h>
//prototype declaration of functions
void create_list(int **,int);
void display_list(int *,int);
void sel_sort_inc(int *,int);
void sel_sort_dec(int *,int);
//defining the main function
int main()
{
    int *list=NULL,size,choice;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.create a new list");
        printf("\n2.display the list");
        printf("\n3.sort in increasing order(Selection Sorting)");
        printf("\n4.sort in decreasing order(Selection Sorting)");
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
            sel_sort_inc(list,size);
            printf("\n\"list is sorted in ascending order\"\n");
            break;
        case 4:
            sel_sort_dec(list,size);
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
//defining sel_sort_inc function
void sel_sort_inc(int list[],int size)
{
    int min,temp,i,j;
    for(i=0;i<=size-1;i++)
    {
        min=i;
        for(j=i+1;j<=size-1;j++)
        {
            if(list[j]<list[min])
                min=j;
        }
        temp=list[i];
        list[i]=list[min];
        list[min]=temp;
    }
}
//defining sel_sort_dec function
void sel_sort_dec(int list[],int size)
{
    int i,j,max,temp;
    for(i=0;i<=size-1;i++)
    {
        max=i;
        for(j=i;j<=size-i-1;j++)
        {
            if(list[j]>max)
            {
                max=j;
            }
        }
        temp=list[size-i-1];
        list[size-i-1]=list[max];
        list[max]=temp;
    }
}

/*SAMPLE OUTPUT

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 1

enter size of the list : 5

"memory allocated auccessfully"

enter element at index 0 : 4

enter element at index 1 : 3

enter element at index 2 : 5

enter element at index 3 : 2

enter element at index 4 : 1

"list created successfully"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 2

"displaying the list"
4, 3, 5, 2, 1

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 3

"list is sorted in ascending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 2

"displaying the list"
1, 2, 3, 4, 5

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 4

"list is sorted in descending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 2

"displaying the list"
5, 4, 3, 2, 1

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 1

enter size of the list : 10

"memory allocated auccessfully"

enter element at index 0 : 5

enter element at index 1 : 9

enter element at index 2 : 2

enter element at index 3 : 11

enter element at index 4 : 19

enter element at index 5 : 15

enter element at index 6 : 14

enter element at index 7 : 17

enter element at index 8 : 4

enter element at index 9 : 13

"list created successfully"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 2

"displaying the list"
5, 9, 2, 11, 19, 15, 14, 17, 4, 13

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 3

"list is sorted in ascending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 2

"displaying the list"
2, 4, 5, 9, 11, 13, 14, 15, 17, 19

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 4

"list is sorted in descending order"

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 2

"displaying the list"
19, 17, 15, 14, 13, 11, 9, 5, 4, 2

select the operation :
1.create a new list
2.display the list
3.sort in increasing order(Selection Sorting)
4.sort in decreasing order(Selection Sorting)
5.quit
enter your choice : 5

"quitting the application"
Process returned 0 (0x0)   execution time : 123.272 s
Press any key to continue.
*/

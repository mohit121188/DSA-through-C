/*program to create a list of integers dynamically, sort it in increasing
  and decreasing order using bubble sort*/
  
#include<stdio.h>
#include<malloc.h>
void bubble_sort_inc(int [],int);
void bubble_sort_dec(int [],int);
int main()
{
    int *list=NULL,i;
    int size,choice;
    do
    {
        printf("\nselect the operation : ");
        printf("\n1.create a new list");
        printf("\n2.perform bubble sort(increasing order)");
        printf("\n3.perform bubble sort(decreasing order)");
        printf("\n4.display list");
        printf("\n5.Quit");
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter size of the list : ");
            scanf("%d",&size);
            list=(int *)malloc(size*sizeof(int));
            if(list==NULL)
            {
                printf("\n\"Insufficient Memory\"\n");
            }
            else
            {
                printf("\n\"Memory Allocated Successfully\"\n");
                for(i=0;i<=size-1;i++)
                {
                    printf("\nenter element at index %d : ",i);
                    scanf("%d",&list[i]);
                }
                printf("\n\"List Created Successfully\"\n");
            }
            break;
        case 2:
            bubble_sort_inc(list,size);
            printf("\n\"List Sorted in Increasing Order\"\n");
            break;
        case 3:
            bubble_sort_dec(list,size);
            printf("\n\"List Sorted in Decreasing Order\"\n");
            break;
        case 4:
            printf("\n\"Displaying the List\"\n");
            for(i=0;i<=size-1;i++)
                {
                    printf("%d, ",list[i]);
                }
                printf("\b\b \n");
            break;
        case 5:
            printf("\n\"Quitting the Application\"\n");
            free(list);
            printf("\n\"Memory Deallcated Successfully\"");
            exit(0);
            break;
        default:
            printf("\n\"Wrong choice, try again\"\n");
            }
    }while(1);
    return 0;
}
void bubble_sort_inc(int list[],int size)
{
    int pass,i,temp,swapped=1;
    for(pass=0;pass<size-1&&swapped;pass++)
    {
        swapped=0;
        for(i=0;i<size-pass-1;i++)
        {
            if(list[i]>list[i+1])
            {
                temp=list[i];
                list[i]=list[i+1];
                list[i+1]=temp;
                swapped=1;
            }
        }
    }
}
void bubble_sort_dec(int list[],int size)
{
    int pass,i,temp,swapped=1;
    for(pass=0;pass<size-1&&swapped;pass++)
    {
        swapped=0;
        for(i=0;i<size-pass-1;i++)
        {
            if(list[i]<list[i+1])
            {
                temp=list[i];
                list[i]=list[i+1];
                list[i+1]=temp;
                swapped=1;
            }
        }
    }
}

/*SAMPLE OUTPUT

select the operation :
1.create a new list
2.perform bubble sort(increasing order)
3.perform bubble sort(decreasing order)
4.display list
5.Quit
enter your choice : 1

enter size of the list : 10

"Memory Allocated Successfully"

enter element at index 0 : 500

enter element at index 1 : 900

enter element at index 2 : 100

enter element at index 3 : 400

enter element at index 4 : 300

enter element at index 5 : 200

enter element at index 6 : 600

enter element at index 7 : 700

enter element at index 8 : 650

enter element at index 9 : 800

"List Created Successfully"

select the operation :
1.create a new list
2.perform bubble sort(increasing order)
3.perform bubble sort(decreasing order)
4.display list
5.Quit
enter your choice : 2

"List Sorted in Increasing Order"

select the operation :
1.create a new list
2.perform bubble sort(increasing order)
3.perform bubble sort(decreasing order)
4.display list
5.Quit
enter your choice : 4

"Displaying the List"
100, 200, 300, 400, 500, 600, 650, 700, 800, 900

select the operation :
1.create a new list
2.perform bubble sort(increasing order)
3.perform bubble sort(decreasing order)
4.display list
5.Quit
enter your choice : 3

"List Sorted in Decreasing Order"

select the operation :
1.create a new list
2.perform bubble sort(increasing order)
3.perform bubble sort(decreasing order)
4.display list
5.Quit
enter your choice : 4

"Displaying the List"
900, 800, 700, 650, 600, 500, 400, 300, 200, 100

select the operation :
1.create a new list
2.perform bubble sort(increasing order)
3.perform bubble sort(decreasing order)
4.display list
5.Quit
enter your choice : 5

"Quitting the Application"

"Memory Deallcated Successfully"
Process returned 0 (0x0)   execution time : 95.911 s
Press any key to continue.

*/

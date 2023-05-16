/*Program to reverse a text(multiple lines string) entered by user, there should not be any limit on the length of the text
from programmer's side, limit on the length of the text will be imposed by operating system depending
on the RAM of computer, retrieve reversed text in an char array, then print it on console, then re-reverse the text and retrieve
it in an char array to obtain the original text and print it*/
#include<stdio.h>
#include<stdlib.h>
#define DEFAULTS_STRING {.head=NULL}
/*defining structure named ListNode1, each variable of this structure contain two fields, one is
char variable which can hold a character value and second one is a pointer variable which can hold
the address of next node of list*/
struct ListNode1
{
    char ch;
    struct ListNode1 *next;
};
typedef struct ListNode1 ListNode1;
/*defining a structure named ListNode2, each variable of this structure contain two fields,
one field is a pointer variable of CharListNode * type which can hold the address of a node of CharListNode
and second field is also a pointer variable which can hold address of the next node of the list*/
struct ListNode2
{
    ListNode1 *address;
    struct ListNode2 *next;
};
typedef struct ListNode2 ListNode2;
/*defining structure named String, each variable of this structure is useful to represent a string,
each variable of this structure contains only one field, this field is a pointer of type ListNode1,
this pointer will hold the address of first node of linked list in which we will store the string*/
struct String
{
    ListNode1 *head;
};
typedef struct String String;
/*defining structure named Stack, each variable of this structure will contain one field of pointer
to ListNode2 type, this pointer field will act as the top of stack.*/
struct Stack
{
 ListNode2 *tos;
};
typedef struct Stack Stack;
//prototype declarations of functions to handle the string
String createString();
void insertAtEnd(String *,char);
int stringLength(String);
char * listToString(String);
//prototype declarations of functions handle stack
void push(Stack *,ListNode1 *);
ListNode1 * pop(Stack *);
isEmpty(Stack);
//prototype declaration of reverseString function
void reverseString(String *);
//defining main function
int main()
{
    String str=DEFAULTS_STRING;
    char *arr_str;
    str=createString();
    arr_str=(char *)malloc((stringLength(str)+1)*sizeof(char));
    if(arr_str==NULL)
    {
        printf("\n\"ERROR: insufficient memory space in heap\"\n");
        return 1;
    }
    arr_str=listToString(str);
    printf("\ntext you entered : \n%s",arr_str);
    reverseString(&str);
    arr_str=listToString(str);
    printf("\ntext after reversal : %s\n",arr_str);
    reverseString(&str);
    arr_str=listToString(str);
    printf("\ntext after re-reversal : \n%s\n",arr_str);
    return 0;
}
//Defining createString
String createString()
{
    String str=DEFAULTS_STRING;
    char ch;
    char prev_char='\0';
    printf("\nenter a text : ");
    printf("\nNote:start your text from next line and end it with two consecutive enter key : \n");
    while(1)
    {
        scanf("%c",&ch);
        if(ch==10&&prev_char==10)
            break;
        if(ch==10&&prev_char!='\0')
            ch='\n';
        insertAtEnd(&str,ch);
        prev_char=ch;
    }
    return str;
}
//Defining insertAtEnd
void insertAtEnd(String *pstr,char ch)
{
    ListNode1 *new_node=(ListNode1 *)malloc(sizeof(ListNode1));
    ListNode1 *temp=pstr->head;
    if(new_node==NULL)
    {
        printf("\n\"ERROR : insufficient memory space\"\n");
        return;
    }
    new_node->ch=ch;
    new_node->next=NULL;
    if(pstr->head==NULL)
    {
        pstr->head=new_node;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
//defining stringLength function
int stringLength(String str)
{
    ListNode1 *temp=str.head;
    int count=0;
    if(str.head==NULL)
        return 0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
//defining listToString function
char * listToString(String str)
{
    ListNode1 *temp=str.head;
    char *arr_str=NULL;
    int count=0,i=0;
    if(str.head==NULL)
    {
        printf("\n\"empty string\"\n");
        return NULL;
    }
    arr_str=(char *)malloc((stringLength(str)+1)*sizeof(char));
    if(arr_str==NULL)
    {
        printf("\n\"ERROR : insufficient memory space in heap\"\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        arr_str[i++]=temp->ch;
        temp=temp->next;
    }
    arr_str[i]=NULL;
    return arr_str;
}
//defining push
void push(Stack *pstk,ListNode1 *address)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"STACK OVERFLOW\"\n");
        return;
    }
    new_node->address=address;
    if(pstk->tos==NULL)
    {
        pstk->tos=new_node;
        new_node->next=NULL;
        return;
    }

    new_node->next=pstk->tos;
    pstk->tos=new_node;
}
//defining pop
ListNode1 * pop(Stack *pstk)
{
    ListNode1 *popped_element=NULL;
    ListNode2 *temp=NULL;
    if(pstk->tos==NULL)
    {
        printf("\n\"STACK UNDERFLOW\"\n");
        return NULL;
    }
    popped_element=pstk->tos->address;
    temp=pstk->tos;
    pstk->tos=pstk->tos->next;
    free(temp);
    return popped_element;
}
//defining isEmpty
int isEmpty(Stack stk)
{
    return(stk.tos==NULL);
}
//defining reverseString
void reverseString(String *pstr)
{
    ListNode1 *temp=NULL;
    ListNode1 *popped_element=NULL;
    Stack stk;
    stk.tos=NULL;
    if(pstr->head==NULL)
    {
        printf("\n\"empty string\"\n");
        return;
    }
    temp=pstr->head;
    while(temp!=NULL)
    {
        push(&stk,temp);
        temp=temp->next;
    }
    pstr->head=NULL;
    while(isEmpty(stk)!=1)
    {
        temp=pstr->head;
        popped_element=pop(&stk);
        popped_element->next=NULL;
        if(pstr->head==NULL)
        {
            pstr->head=popped_element;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=popped_element;
        }
    }

}
/*SAMPLE OUTPUT

enter a text :
Note:start your text from next line and end it with two consecutive enter key :
Name:   Mohit Jain
Age:    35 Years
Degree: ME
Field:  CSE
College:IET-DAVV, Indore(MP)
Skills: C,C++,DSA
Job:    Teacher
City:   Indore, Indore is a beautiful city, famous for it's food, it is commercial capital of MP.


text you entered :
Name:   Mohit Jain
Age:    35 Years
Degree: ME
Field:  CSE
College:IET-DAVV, Indore(MP)
Skills: C,C++,DSA
Job:    Teacher
City:   Indore, Indore is a beautiful city, famous for it's food, it is commercial capital of MP.

text after reversal :
.PM fo latipac laicremmoc si ti ,doof s'ti rof suomaf ,ytic lufituaeb a si erodnI ,erodnI       :ytiC
rehcaeT :boJ
ASD,++C,C       :sllikS
)PM(erodnI ,VVAD-TEI:egelloC
ESC     :dleiF
EM :eergeD
sraeY 53        :egA
niaJ tihoM      :emaN

text after re-reversal :
Name:   Mohit Jain
Age:    35 Years
Degree: ME
Field:  CSE
College:IET-DAVV, Indore(MP)
Skills: C,C++,DSA
Job:    Teacher
City:   Indore, Indore is a beautiful city, famous for it's food, it is commercial capital of MP.


Process returned 0 (0x0)   execution time : 176.123 s
Press any key to continue.

*/

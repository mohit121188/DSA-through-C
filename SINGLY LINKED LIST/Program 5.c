/*Program to evaluate a postfix expression entered by user using stack, postfix expression and
stack has no size limit,they are dynamic, only size limit can be imposed by OS depending on Heap size of memory*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define DEFAULTS_STRING {.head=NULL}
#define DEFAULT_STACK {.tos=NULL}
//defining structure ListNode1
struct ListNode1
{
    char ch;
    struct ListNode1 *next;
};
typedef struct ListNode1 ListNode1;
//defining structure ListNode2
struct ListNode2
{
    float val;
    struct ListNode2 *next;
};
typedef struct ListNode2 ListNode2;
//defining structure for String
struct String
{
    ListNode1 *head;
};
typedef struct String String;
//defining structure for Stack
struct Stack
{
    ListNode2 *tos;
};
typedef struct Stack Stack;
//declaring functions to handle String
String inputPostfix();
void insertAtEnd(String *,char);
int stringLength(String);
char * listToString(String);
//display_list
void display_list(String);
//declaring functions to handle stack
void push(Stack *,float);
float pop(Stack *);
int isEmpty(Stack);
//declaring other required functions to implement algo of postfix evaluation
int isStringDigits(char *);
float calculate(float,char,float);
float evalPostfix(char *);
//defining main
int main()
{
    String str=DEFAULTS_STRING;
    char *postfix=NULL;
    float result;
    str=inputPostfix();
    if(str.head==NULL)
    {
        printf("\n\"ERROR:insufficient memory available in heap\"\n");
        return 1;
    }
    postfix=(char *)malloc((stringLength(str)+1)*sizeof(char));
    if(postfix==NULL)
    {
        printf("\n\"ERROR:insufficient memory available in heap\"\n");
        return 1;
    }
    postfix=listToString(str);
    result=evalPostfix(postfix);
    if(result==-1)
        printf("\n\"ERROR: NO EXPRESSION FOUND\"\n");
    else
        printf("\n\"Result is %f\"\n",result);
    return 0;
}
//defining createString
String inputPostfix()
{
    String str=DEFAULTS_STRING;
    char ch;
    printf("\nenter postfix expression");
    printf("\nNote : (1)separate each token(operand or operator) by a delimiter \"space\"");
    printf("\n       (2)press entery key to end the postfix expression\n");
    printf("give your input : ");
    while(1)
    {
        scanf("%c",&ch);
        if(ch==10)
            break;
        insertAtEnd(&str,ch);
    }
    return str;
}
//defining insertAtEnd
void insertAtEnd(String *pstr,char ch)
{
    ListNode1 *new_node=(ListNode1 *)malloc(sizeof(ListNode1));
    ListNode1 *temp=pstr->head;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:insufficient memory in heap\"\n");
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
//defining stringLength
int stringLength(String str)
{
    ListNode1 *temp=str.head;
    int count=0;
    if(str.head==NULL)
    {
        return 0;
    }
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
//defining listToString
char * listToString(String str)
{
    ListNode1 *temp=str.head;
    char *arr_str=NULL;
    int i=0;
    if(str.head==NULL)
    {
        printf("\n\"empty string\"\n");
        return NULL;
    }
    arr_str=(char *)malloc((stringLength(str)+1)*sizeof(char));
    if(arr_str==NULL)
    {
        printf("\n\"ERROR:insufficient memory in heap\"\n");
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
//defining display_list
void display_list(String str)
{
    ListNode1 *temp=str.head;
    if(str.head==NULL)
    {
        printf("\n\"empty string\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%c\n",temp->ch);
        temp=temp->next;
    }
}
//defining push
void push(Stack *pstk,float x)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"STACK OVERFLOW\"\n");
        return;
    }
    new_node->val=x;
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
float pop(Stack *pstk)
{
    float y;
    ListNode2 *temp=pstk->tos;
    if(pstk->tos==NULL)
    {
        printf("\n\"STACK UNDERFLOW\"\n");
        return -1;
    }
    temp=pstk->tos;
    pstk->tos=pstk->tos->next;
    y=temp->val;
    free(temp);
    return y;
}
//defining isEmpty
int isEmpty(Stack stk)
{
    return(stk.tos==NULL);
}
//defining isOperand
int isStringDigits(char *pstr)
{
    int i=0;
    while(pstr[i]!=NULL)
    {
        if(isdigit(pstr[i])==0)
            break;
        i++;
    }
    if(strlen(pstr)==i)
        return 1;
    else
        return 0;
}
//defining calculate
float calculate(float a,char optr,float b)
{
    switch(optr)
    {
    case '+':
        return(a+b);
    case '-':
        return(a-b);
    case '*':
        return(a*b);
    case '/':
        return(a/b);
    case '%':
        return(fmod(a,b));
    default:
        printf("\n\"invalid operator\"\n");
    }
}
//defining eval_postfix
float evalPostfix(char postfix[])
{
    char *token;
    float result;
    Stack stk=DEFAULT_STACK;
    if(strlen(postfix)==0)
        return -1;
    token=strtok(postfix," ");
    while(token!=NULL)
    {
        if(isStringDigits(token)==1)
        {
            push(&stk,atoi(token));
        }
        else
        {
            push(&stk,calculate(pop(&stk),token[0],pop(&stk)));
        }
        token=strtok(NULL," ");
    }
    result=pop(&stk);
    return result;
}

/* SAMPLE OUTPUT

enter postfix expression
Note : (1)separate each token(operand or operator) by a delimiter "space"
       (2)press entery key to end the postfix expression
give your input : 10 5 + 20 * 30 2 / - 15 +

"Result is 300.000000"

Process returned 0 (0x0)   execution time : 45.116 s
Press any key to continue.
 */

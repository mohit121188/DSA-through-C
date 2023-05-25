/*Program to evaluate a prefix expression entered by user by using stack. Note: prefix expression and stack are implemented using singly linked list dynamically*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#define DEFAULT_STRINGS {.head=NULL}
#define DEFAULT_TOKEN_LIST {.head=NULL}
#define DEFAULT_STACKS {.tos=NULL}
#define DEFAULT_RESULT {.val=0,.error_status=0}
//defining a structure named ListNode 1
struct ListNode1
{
    char ch;
    struct ListNode1 *next;
};
typedef struct ListNode1 ListNode1;
//defining a structure named String
struct String
{
    ListNode1 *head;
};
typedef struct String String;
//defining a structure named ListNode2
struct ListNode2
{
  char * token;
  struct ListNode2 *next;
};
typedef struct ListNode2 ListNode2;
//defining a structure named TokenList
struct TokenList
{
    ListNode2 *head;
};
typedef struct TokenList TokenList;
//defining a structure name ListNode3
struct ListNode3
{
    float val;
    struct ListNode3 *next;
};
typedef struct ListNode3 ListNode3;
//defining a structure named Stack
struct Stack
{
    ListNode3 *tos;
};
typedef struct Stack Stack;
//defining a structure named Result
struct Result
{
    float val;
    int error_status;
};
typedef struct Result Result;
//declaration of the functions to handle string
void inputString(String *);
void insertAtEnd(String *,char);
void printString(String);
int lengthString(String);
char * listToArray(String);
int isAllDigit(char *);
//prototype declarations of the functions to handle Token list
TokenList createTokenList(String,char *);
void insertTokenAtEnd(TokenList*,char *);
void printTokenList(TokenList);
void reverseTokenList(TokenList *);
//declaration of the stack related functions
void push(Stack *,float);
float pop(Stack *);
int isStackEmpty(Stack);
float peek(Stack);
//declarations of the functions required to evaluate postfix expression
int isOperator(char *);
int isOperand(char *);
float calculate(float,char,float);
Result evalPrefix(String);
//main function here
int main()
{
    String prefix=DEFAULT_STRINGS;
    Result result=DEFAULT_RESULT;
    printf("\nenter prefix expression(Note:use space as delimiter between tokens)\n");
    printf("\ngive your input here : ");
    inputString(&prefix);
    result=evalPrefix(prefix);
    if(result.error_status==0)
            printf("\nresult is %f",result.val);
    return 0;
}

//defining inputString
void inputString(String *pstr)
{
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch==10)
            break;
        insertAtEnd(pstr,ch);
    }
}
//defining insertAtEnd
void insertAtEnd(String *pstr,char ch)
{
    ListNode1 *new_node=(ListNode1 *)malloc(sizeof(ListNode1));
    ListNode1 *temp=pstr->head;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
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
//defining printString
void printString(String str)
{
    ListNode1 *temp=str.head;
    if(str.head==NULL)
    {
        printf("\n\"EMPTY STRING\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%c",temp->ch);
        temp=temp->next;
    }
}
//defining lengthString
int lengthString(String str)
{
    int len=0;
    ListNode1 *temp=str.head;
    if(str.head==NULL)
    {
        return 0;
    }
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
//defining listToArray
char * listToArray(String str)
{
    char *arr=NULL;
    ListNode1 *temp=str.head;
    int i=0;
    if(str.head==NULL)
    {
        printf("\n\"String is empty\"\n");
        return NULL;
    }
    arr=(char *)malloc((lengthString(str)+1)*sizeof(char));
    if(arr==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        arr[i++]=temp->ch;
        temp=temp->next;
    }
    arr[i]=NULL;
    return arr;
}
//defining isAllDigit
int isAllDigit(char *pstr)
{
    int i=0,len;
    len=strlen(pstr);
    if(len==0)
    {
        printf("\n\"EMPTY STRING\"\n");
        return 0;
    }
    while(pstr[i]!=NULL)
    {
        if(isdigit(pstr[i])!=1)
        {
            return 0;
        }
        i++;
    }
    if(len==i)
    {
        return 1;
    }
}
//defining createTokenList
TokenList createTokenList(String str,char *delimiter)
{
    TokenList tkl=DEFAULT_TOKEN_LIST;
    char *arr=NULL;
    char *token=NULL;
    if(str.head==NULL)
    {
        printf("\n\"Empty String\"\n");
        return tkl;
    }
    arr=listToArray(str);
    if(arr==NULL)
    {
        printf("\n\"ERROR:can't convert String to Array\"\n");
        return tkl;
    }
    token=strtok(arr,delimiter);
    while(token!=NULL)
    {
        insertTokenAtEnd(&tkl,token);
        token=strtok(NULL,delimiter);
    }
    free(arr);
    return tkl;

}
//defining insertTokenAtEnd
void insertTokenAtEnd(TokenList *ptkl,char *token)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    ListNode2 *temp=ptkl->head;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }

    new_node->token=(char *)malloc((strlen(token)+1)*sizeof(char));

    if(new_node->token==NULL)
    {
       printf("\n\"ERROR:memory allocation problem\"\n");
       return;
    }

    strcpy(new_node->token,token);
    new_node->next=NULL;

    if(ptkl->head==NULL)
    {
        ptkl->head=new_node;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
//defining printTokenList
void printTokenList(TokenList tkl)
{
    ListNode2 *temp=tkl.head;
    if(tkl.head==NULL)
    {
        printf("\n\"empty token list\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%s-->",temp->token);
        temp=temp->next;
    }
    printf("null");
}
//defining reverseTokenList
void reverseTokenList(TokenList *ptkl)
{
    ListNode2 *current_node=NULL,*temp=NULL;
    if(ptkl->head==NULL)
    {
        printf("\n\"can't reverse a empty list\"\n");
        return;
    }
    if(ptkl->head->next==NULL)
    {
        return;
    }
    current_node=ptkl->head;
    ptkl->head=NULL;
    while(current_node!=NULL)
    {
        temp=current_node;
        current_node=current_node->next;
        if(ptkl->head==NULL)
        {
            ptkl->head=temp;
            ptkl->head->next=NULL;
        }
        else
        {
            temp->next=ptkl->head;
            ptkl->head=temp;
        }

    }
}
//defining push function
void push(Stack *pstk,float x)
{
    ListNode3 *new_node=(ListNode3 *)malloc(sizeof(ListNode3));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:STACK OVERFLOW, can't allocate memory\"\n");
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
    float popped_element;
    ListNode3 *temp=NULL;
    if(pstk->tos==NULL)
    {
        printf("\n\"STACK UNDERFLOW\"\n");
        return -1;
    }
    popped_element=pstk->tos->val;
    temp=pstk->tos;
    pstk->tos=pstk->tos->next;
    free(temp);
}
//defining isStackEmpty
int isStackEmpty(Stack stk)
{
    return(stk.tos==NULL);
}
//defining peek
float peek(Stack stk)
{
    if(stk.tos==NULL)
    {
        printf("\n\"EMPTY STACK\"\n");
        return -1;
    }
    return(stk.tos->val);
}
//defining isOperator
int isOperator(char *ptoken)
{
    if(ptoken[0]=='$'||ptoken[0]=='*'||ptoken[0]=='/'||ptoken[0]=='%'||ptoken[0]=='+'||ptoken[0]=='-')
        return 1;
    else
        return 0;
}
//define calculate
float calculate(float a,char optr,float b)
{
    switch(optr)
    {
    case '$':
        return(pow(a,b));
    case '*':
        return(a*b);
    case '/':
        return(a/b);
    case '%':
        return(fmod(a,b));
    case '+':
        return(a+b);
    case '-':
        return(a-b);
    default:
        printf("\n\"algorithm can't operate %c\"\n",optr);
    }
}
//defining isOperand
int isOperand(char *ptoken)
{
    return(isAllDigit(ptoken));
}
//defining evalPrefix
Result evalPrefix(String prefix)
{
    ListNode2 *temp=NULL;
    Stack stk=DEFAULT_STACKS;
    TokenList tkl=DEFAULT_TOKEN_LIST;
    Result result=DEFAULT_RESULT;
    float a,b;
    tkl=createTokenList(prefix," ");
    reverseTokenList(&tkl);
    temp=tkl.head;
    while(temp!=NULL)
    {
        if(isOperand(temp->token))
            push(&stk,(float)atoi(temp->token));
        else
        if(isOperator(temp->token))
            {
            a=pop(&stk);
            b=pop(&stk);
            push(&stk,calculate(a,temp->token[0],b));
            }
        else
            {
            printf("\n\"ERROR : token '%s' can't be recognized by algorithm \"\n",temp->token);
            result.error_status=1;
            return result;
            }
         temp=temp->next;
    }
    result.val=pop(&stk);
    return result;
}

/* SAMPLE OUTPUT

enter prefix expression(Note:use space as delimiter between tokens)

give your input here : + * - 10 5 / 20 4 3 $ 2 3

result is 28.000000
Process returned 0 (0x0)   execution time : 11.897 s
Press any key to continue.

*/

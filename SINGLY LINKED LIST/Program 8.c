//Program to convert an infix expression into prefix expression using stack. note:infix expression, stacks are dynamic in nature.
//header files
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define DEFAULT_STRINGS {.head=NULL}
#define DEFAULT_STACKS {.tos=NULL}
#define DEFAULT_TOKEN_LIST {.head=NULL}

//defining a structure named ListNode1
struct ListNode1
{
    char ch;
    struct ListNode1 *next;
};
typedef struct ListNode1 ListNode1;

//declaration of the functions to handle singly linked list 1
void insertAtEndList1(ListNode1 **,char);
void insertAtBegList1(ListNode1 **,char);
char delFromBegList1(ListNode1 **);
int countNodesList1(ListNode1 *);
void printList1(ListNode1 *);
void freeList1(ListNode1 **);

//defining structure named ListNode2
struct ListNode2
{
    char *token;
    struct ListNode2 *next;
};
typedef struct ListNode2 ListNode2;
//declaration of the functions to handle singly linked list2
void inserAtEndList2(ListNode2 **,char *);
void insertAtBegList2(ListNode2 **,char *);
char * delFromBegList2(ListNode2 **);
void printList2(ListNode2 *);
int countNodesList2(ListNode2 *);
void reverseList2(ListNode2 **);
int freeList2(ListNode2 **);

//defining a structure named String
struct String
{
    ListNode1 *head;
};
typedef struct String String;
//declaration of functions to handle string
void inputStr(String *);
void printStr(String);
int lenStr(String);
int freeStr(String *);
char * listToArray(String);
int freeArray(char **);

//defining a structure named Stack
struct Stack
{
    ListNode1 *tos;
};
typedef struct Stack Stack;

//declaration of the functions to handle stack
void push(Stack *,char);
char pop(Stack *);
int isEmptyStack(Stack);
char peek(Stack);
int freeStack(Stack *);

//defining structure named TokenList
struct TokenList
{
    ListNode2 *head;
};
typedef struct TokenList TokenList;
//declaration of functions to handle TokenList
TokenList createTokenListFromString(String,char *);
TokenList createTokenListFromArray(char *,char *);
void printTokenList(TokenList);
void reverseTokenList(TokenList *);
int freeTokenList(TokenList *);
void insertSpaceBetweenTokens(TokenList *);
String TokenListToString(Token);

//declarations of functions supporting infix to prefix conversion
int isValidInfix(String);
int isOperator(char);
int isParenthesis(char);
void formatInfix(String *);
int doInsertSpace(char,char);
void putSpace(ListNode1 *,ListNode1 *);
char * infixToPrefix(String);
int precOperator(char);
int doPop(char,char);

//defining main function
int main()
{
String infix=DEFAULT_STRINGS;
char *prefix=NULL;
printf("\nenter an infix expression : ");
inputStr(&infix);
prefix=infixToPrefix(infix);
printf("\nprefix : %s",prefix);
freeStr(&infix);
free(prefix);
return 0;
}

//defining insertAtEndList1
void insertAtEndList1(ListNode1 **phead,char ch)
{
    ListNode1 *temp=*phead;
    ListNode1 *new_node=(ListNode1 *)malloc(sizeof(ListNode1));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->ch=ch;
    new_node->next=NULL;
    if(*phead==NULL)
    {
        *phead=new_node;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

//defining printList1
void printList1(ListNode1 *head)
{
    ListNode1 *temp=head;
    if(head==NULL)
    {
        printf("\n\"EMPTY LINKED LIST1\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%c",temp->ch);
        temp=temp->next;
    }
}

//defining countNodesList1
int countNodesList1(ListNode1 *head)
{
    ListNode1 *temp=head;
    int count=0;
    if(head==NULL)
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

//defining freeList1
void freeList1(ListNode1 **phead)
{
    ListNode1 *temp=*phead;
    ListNode1 *next_node=NULL;
    if(*phead==NULL)
    {
        return;
    }
    while(temp!=NULL)
    {
        next_node=temp->next;
        free(temp);
        temp=next_node;
    }
    *phead=NULL;
}

//defining insertAtBegList1
void insertAtBegList1(ListNode1 **phead,char ch)
{
    ListNode1 *new_node=(ListNode1 *)malloc(sizeof(ListNode1));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->ch=ch;
    if(*phead==NULL)
    {
        *phead=new_node;
        (*phead)->next=NULL;
        return;
    }
    new_node->next=*phead;
    *phead=new_node;
}

//define delFromBegList1
char delFromBegList1(ListNode1 **phead)
{
    char ch;
    ListNode1 *temp=NULL;
    if(*phead==NULL)
    {
        printf("\n\"LIST IS EMPTY\"\n");
        return NULL;
    }
    temp=*phead;
    *phead=(*phead)->next;
    ch=temp->ch;
    free(temp);
    return ch;
}

//defining inserAtEndList2
void inserAtEndList2(ListNode2 **phead,char *token)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    ListNode2 *temp=NULL;
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
    if(*phead==NULL)
    {
        *phead=new_node;
        return;
    }
    temp=*phead;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

//defining insertAtBegList2
void insertAtBegList2(ListNode2 **phead,char *token)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation issue\"\n");
        return;
    }
    new_node->token=(char *)malloc((strlen(token)+1)*sizeof(char));
    strcpy(new_node->token,token);
    if(new_node->token==NULL)
    {
        printf("\n\"ERROR:memory allocation issue\"\n");
        return;
    }
    if(*phead==NULL)
    {
        *phead=new_node;
        new_node->next=NULL;
        return;
    }
    new_node->next=*phead;
    *phead=new_node;

}

//define delFromBegList2
char * delFromBegList2(ListNode2 **phead)
{
char * del_element=NULL;
ListNode2 *temp=*phead;
if(*phead==NULL)
{
    printf("\nLIST IS EMPTY\n");
    return NULL;
}
del_element=(char *)malloc((strlen(temp->token)+1)*sizeof(char));
if(del_element==NULL)
{
    printf("\nERROR:memory allocation problem\"\n");
    return NULL;
}
strcpy(del_element,temp->token);
if(temp->next==NULL)
{
 free(temp->token);
 free(temp);
 *phead=NULL;
}
else
{
    *phead=temp->next;
    free(temp->token);
    free(temp);
}
return del_element;
}

//define printList2
void printList2(ListNode2 *head)
{
    ListNode2 *temp=head;
    if(head==NULL)
    {
        printf("\n\"EMPTY LIST\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%s ",temp->token);
        temp=temp->next;
    }
}

//define countNodesList2
int countNodesList2(ListNode2 *head)
{
    ListNode2 *temp=head;
    int count=0;
    if(head==NULL)
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

//define reverseList2
void reverseList2(ListNode2 **phead)
{
    ListNode2 *temp=NULL,*next_node=NULL;
    if(*phead==NULL)
    {
        printf("\n\"EMPTY LIST\"\n");
        return;
    }
    if((*phead)->next==NULL)
    {
        return;
    }
    temp=*phead;
    *phead=NULL;
    while(temp!=NULL)
    {
        if(*phead==NULL)
        {
            *phead=temp;
             next_node=temp->next;
            (*phead)->next=NULL;
        }
        else
        {
            next_node=temp->next;
            temp->next=*phead;
            *phead=temp;
        }
        temp=next_node;
    }
}

//defining freeList2
int freeList2(ListNode2 **phead)
{
    ListNode2 *temp=*phead,*next_node=NULL;
    if(*phead==NULL)
    {
        return 1;
    }
    while(temp!=NULL)
    {
        next_node=temp->next;
        free(temp->token);
        free(temp);
        temp=next_node;
    }
    *phead=NULL;
    if(*phead==NULL)
        return 1;
    else
        return 0;
}

//defining inputStr
void inputStr(String *pstr)
{
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch==10)
            break;
        insertAtEndList1(&pstr->head,ch);
    }
}

//defining printStr
void printStr(String str)
{
    printList1(str.head);
}

//defining lenStr
int lenStr(String str)
{
    int len;
    len=countNodesList1(str.head);
    return len;
}

//defining freeStr
int freeStr(String *pstr)
{
    freeList1(&pstr->head);
    if(pstr->head==NULL)
        return 1;
    else
        return 0;

}

//defining listToArray
char * listToArray(String str)
{
    char *arr=NULL;
    int i=0;
    ListNode1 *temp=str.head;
    if(str.head==NULL)
    {
        printf("\n\"EMPTY STRING\"\n");
        return NULL;
    }
    arr=(char *)malloc((lenStr(str)+1)*sizeof(char));
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

//defining freeArray
int freeArray(char **parr)
{
   free(*parr);
   *parr=NULL;
   if(*parr==NULL)
        return 1;
   else
        return 0;
}

//defining push
void push(Stack *pstk,char ch)
{
    insertAtBegList1(&pstk->tos,ch);
}

//defining pop
char pop(Stack *pstk)
{
    char ch;
    ch=delFromBegList1(&pstk->tos);
    return ch;
}

//defining isEmptyStack
int isEmptyStack(Stack stk)
{
    return(stk.tos==NULL);
}

//defining peek
char peek(Stack stk)
{
    if(stk.tos==NULL)
        return NULL;
    else
        return stk.tos->ch;
}

//defining freeStack
int freeStack(Stack *pstk)
{
    freeList1(&pstk->tos);
}

//defining createTokenList
TokenList createTokenListFromString(String str,char *delimiter)
{
    TokenList tkl=DEFAULT_TOKEN_LIST;
    char *arr=NULL;
    char *token=NULL;
    if(str.head==NULL)
    {
        printf("\n\"string is empty\"\n");
        return tkl;
    }
    arr=(char *)malloc((lenStr(str)+1)*sizeof(char));
    if(arr==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return tkl;
    }
    arr=listToArray(str);
    token=strtok(arr,delimiter);
    while(token!=NULL)
    {
        inserAtEndList2(&tkl.head,token);
        token=strtok(NULL,delimiter);
    }
    if(freeArray(&arr));
    else
        printf("\ncan't deallocation problem");
    return tkl;
}

//defining createTokenListFromArray
TokenList createTokenListFromArray(char *arr,char *delimiter)
{
    char *token=NULL;
    TokenList tkl=DEFAULT_TOKEN_LIST;
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return tkl;
    }
    token=strtok(arr,delimiter);
    while(token!=NULL)
    {
        inserAtEndList2(&tkl.head,token);
        token=strtok(NULL,delimiter);
    }
    return tkl;
}

//defining printTokenList
void printTokenList(TokenList tkl)
{
    ListNode2 *temp=tkl.head;
    if(tkl.head==NULL)
    {
        printf("\n\"TOKEN LIST IS EMPTY\"\n");
        return;
    }

    while(temp!=NULL)
    {
        printf("%s ",temp->token);
        temp=temp->next;
    }
}

//defining freeTokenList
int freeTokenList(TokenList *ptkl)
{
    ListNode2 *current_node=ptkl->head,*next_node=NULL;
    if(ptkl->head==NULL)
    {
        return 1;
    }
    while(current_node!=NULL)
    {
        next_node=current_node->next;
        free(current_node);
        current_node=next_node;
    }
    ptkl->head=NULL;
    if(ptkl->head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//defining reverseTokenList
void reverseTokenList(TokenList *ptkl)
{
    if(ptkl->head==NULL)
    {
        printf("\n\"EMPTY TOKEN LIST\"\n");
        return;
    }
    if(ptkl->head->next==NULL)
    {
        return;
    }
   reverseList2(&ptkl->head);
}

//define insertSpaceBetweenTokens
void insertSpaceBetweenTokens(TokenList *ptkl)
{
    ListNode2 *prev=NULL,*current=NULL,*space_node=NULL;
    if(ptkl->head==NULL)
    {
        printf("\nEMPTY TOKEN LIST");
        return;
    }
    if(ptkl->head->next==NULL)
    {
        return;
    }
    prev=ptkl->head;
    current=ptkl->head->next;
    while(current!=NULL)
    {
        space_node=(ListNode2 *)malloc(sizeof(ListNode2));
        if(space_node==NULL)
        {
            printf("\n\"ERROR:memory allocation problem\"\n");
            return;
        }
        space_node->token=(char *)malloc(2*sizeof(char));
        if(space_node==NULL)
        {
            printf("\n\"ERROR:memory allocation problem\"\n");
            return;
        }
        strcpy(space_node->token," ");
        prev->next=space_node;
        space_node->next=current;
        prev=current;
        current=current->next;
    }
}

//defining TokenListToArray
String TokenListToString(TokenList tkl)
{
    String str=DEFAULT_STRINGS;
    ListNode2 *temp=tkl.head;
    int i;
    char space=' ';
    if(tkl.head==NULL)
    {
        printf("\n\"EMPTY TOKENLIST\"\n");
        return str;
    }

    while(temp!=NULL)
    {
        i=0;
        while(temp->token[i]!=NULL)
        {
         insertAtEndList1(&(str.head),temp->token[i]);
         i++;
        }
        if(temp->next!=NULL)
        {
            insertAtEndList1(&(str.head),' ');
        }
        temp=temp->next;
    }
    return str;
}

//define function isValidInfix
int isValidInfix(String str)
{
    ListNode1 *temp=str.head;
    int flag=1;
    if(str.head==NULL)
    {
        printf("\n\"Empty String\"\n");
        return 0;
    }
    while(temp!=NULL)
    {
        if(isalpha(temp->ch)||isdigit(temp->ch)||isOperator(temp->ch)||isParenthesis(temp->ch))
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\n\"ERROR:Invalid symbol %c found\"\n",temp->ch);
    }
    return flag;
}

//define isOperator
int isOperator(char ch)
{
    if(ch=='$'||ch=='*'||ch=='/'||ch=='%'||ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}

//define isParenthesis
int isParenthesis(char ch)
{
    if(ch=='('||ch==')')
        return 1;
    else
        return 0;
}

//formatInfix
void formatInfix(String *pstr)
{
    ListNode1 *current_node=NULL,*next_node=NULL;
    if(pstr->head==NULL)
    {
        printf("\n\"EMPTY STRING\"\n");
        return;
    }
    if(pstr->head->next==NULL)
    {
        return;
    }
    current_node=pstr->head;
    next_node=current_node->next;
    while(next_node!=NULL)
    {
        if(doInsertSpace(current_node->ch,next_node->ch))
        {
            putSpace(current_node,next_node);
        }
        current_node=next_node;
        next_node=current_node->next;
    }

}

//doInsertSpace
int doInsertSpace(char ch1,char ch2)
{
    if(isdigit(ch1)&&isalpha(ch2))
        return 0;
    else
        if(isdigit(ch2)&&isalpha(ch1))
        return 0;
    else
        if(isdigit(ch1)&&isdigit(ch2))
        return 0;
    else
        if(isalpha(ch1)&&isalpha(ch2))
        return 0;
    else
        return 1;
}

//define putSpace
void putSpace(ListNode1 *current_node,ListNode1 *next_node)
{
    ListNode1 *temp=(ListNode1 *)malloc(sizeof(ListNode1));
    if(temp==NULL)
    {
        printf("\n\"ERROR:memory can't be allocated\"\n");
        return;
    }
    temp->ch=' ';
    temp->next=next_node;
    current_node->next=temp;
}

//defining infixToPrefix
char * infixToPrefix(String str)
{
   TokenList tkl=DEFAULT_TOKEN_LIST;
   ListNode2 *temp=NULL;
   char *infix=NULL;
   char *prefix=NULL;
   Stack stk=DEFAULT_STACKS;
   char popped[2];
   String pref_str=DEFAULT_STRINGS;
   if(str.head==NULL)
   {
       printf("\n\"EMPTY STRING\"\n");
       return;
   }
   infix=(char *)malloc((lenStr(str)+1)*sizeof(char));
   if(infix==NULL)
   {
       printf("\n\"ERROR:memory allocation problem\"\n");
       return NULL;
   }
   formatInfix(&str);
   tkl=createTokenListFromString(str," ");
   reverseTokenList(&tkl);
   temp=tkl.head;
   prefix=(char *)malloc((lenStr(str)+1)*sizeof(char));
   if(prefix==NULL)
   {
       printf("\n\"ERROR:memory allocation problem\"\n");
       return NULL;
   }
   prefix[0]=NULL;
   while(temp!=NULL)
   {
       if(!isOperator(temp->token[0])&&!(isParenthesis(temp->token[0])))
       {
           if(strlen(prefix)==0)
           {
               strcpy(prefix,temp->token);
               strcat(prefix," ");
           }
           else
           {
               strcat(prefix,temp->token);
               strcat(prefix," ");
           }
       }
       else
       {
       while(1)
       {
           if(isEmptyStack(stk))
           {
               push(&stk,temp->token[0]);
               break;
           }
           else
            if(temp->token[0]==')')
           {
               push(&stk,temp->token[0]);
               break;
           }
           else
            if(peek(stk)==')')
           {
               push(&stk,temp->token[0]);
               break;
           }
           else
            if(temp->token[0]=='(')
           {
               while(peek(stk)!=')')
               {
                   popped[0]=pop(&stk);
                   popped[1]='\0';
                   strcat(prefix,popped);
                   strcat(prefix," ");
               }
               pop(&stk);
               break;
           }
           else
            if(doPop(peek(stk),temp->token[0]))
           {
               popped[0]=pop(&stk);
               popped[1]=NULL;
               strcat(prefix,popped);
               strcat(prefix," ");
           }
           else
           {
               push(&stk,temp->token[0]);
               break;
           }

       }
       }
       temp=temp->next;
}
while(isEmptyStack(stk)!=1)
{
    popped[0]=pop(&stk);
    popped[1]=NULL;
    strcat(prefix,popped);
    strcat(prefix," ");
}
prefix[strlen(prefix)-1]=NULL;
freeStack(&stk);
free(infix);
freeTokenList(&tkl);
tkl=createTokenListFromArray(prefix," ");
reverseTokenList(&tkl);
pref_str=TokenListToString(tkl);
prefix=listToArray(pref_str);
return prefix;
}

//define precOperator
int precOperator(char optr)
{
    switch(optr)
    {
    case '$':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    }
}

//define doPop
int doPop(char optr1,char optr2)
{
    if(precOperator(optr1)>precOperator(optr2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Sample Output 1 : 

enter an infix expression :  (A+B)+C-(D-E)$F

prefix : - + + A B C $ - D E F
*/

/* Sample Output 2:

enter an infix expression :  (4 + 5 * (3 + 2) - 7) / (2 + 3 * (6 - 4)) $ 2

prefix : / - + 4 * 5 + 3 2 7 $ + 2 * 3 - 6 4 2

*/

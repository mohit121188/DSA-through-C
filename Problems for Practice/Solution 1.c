//Program to evaluate an infix expression using two stacks.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define DEFAULT_RETRIEVED1 {.data=0,.status=false}
#define DEFAULT_RETRIEVED2 {.status=false,.data='\0'}
#define DEFAULT_STRING {.head=NULL}
#define DEFAULT_STACK {.tos=NULL}
#define DEFAULT_TOKENLIST {.head=NULL}
#define DEFAULT_FINAL_RESULT {.data=0,.status=false}
//define a structure named ListNode1
struct ListNode1
{
 float data;
 struct ListNode1 *next;
};
typedef struct ListNode1 ListNode1;
//define a structure Status
struct retrieved1
{
    float data;
    bool status;
};
typedef struct retrieved1 retrieved1;
//declaration of the functions to handle list1
void insertAtBegList1(ListNode1 **,float);
retrieved1 delFromBegList1(ListNode1 **);
retrieved1 readFirstFromList1(ListNode1 *);
int freeList1(ListNode1 **);


//define structure named ListNode2
struct ListNode2
{
    char data;
    struct ListNode2 *next;
};
typedef struct ListNode2 ListNode2;
//define structure named StatusList2
struct retrieved2
{
    char data;
    bool status;
};
typedef struct retrieved2 retrieved2;
//declaration of functions to handle ListNode2
void insertAtBegList2(ListNode2 **,char);
void inserAtEndList2(ListNode2 **,char);
void printList2(ListNode2 *);
retrieved2 delFromBegList2(ListNode2 **);
retrieved2 readFirstFromList2(ListNode2 *);
int freeList2(ListNode2 **);
char * listToArray(ListNode2 *);
int countNodesList2(ListNode2 *);
void insertNodeBetween(ListNode2 *,ListNode2 *,char);

//define a structure named ListNode3
struct ListNode3
{
char *token;
struct ListNode3 *next;
};
typedef struct ListNode3 ListNode3;
//declarations of the function to handle ListNode3
void insertAtBegList3(ListNode3 **,char *);
void insertAtEndList3(ListNode3 **,char *);
void printList3(ListNode3 *);
int freeList3(ListNode3 **);


//define a structure named String
struct String
{
    ListNode2 *head;
};
typedef struct String String;
//declaration of the functions to handle a String
void inputStr(String *);
void printStr(String);
int lenStr(String);
char * stringAsArray(String);
int freeStr(String *);


//define structure named Stack1
struct Stack1
{
    ListNode1 *tos;
};
typedef struct Stack1 Stack1;
//declarations of the functions to handle the stack
void pushStack1(Stack1 *,float);
retrieved1 popStack1(Stack1 *);
int isEmptyStack1(Stack1);
retrieved1 peekStack1(Stack1);
int freeStack1(Stack1 *);



//defining a structure named Stack2
struct Stack2
{
    ListNode2 *tos;
};
typedef struct Stack2 Stack2;
//declaration of the functions to handle stack2
void pushStack2(Stack2 *,char);
retrieved2 popStack2(Stack2*);
int isEmptyStack2(Stack2);
retrieved2  peekStack2(Stack2);
int freeStack2(Stack2 *);



//define a structure named TokenList
struct TokenList
{
    ListNode3 *head;
};
typedef struct TokenList TokenList;
//declaration of the functions
TokenList createTokenList(String,char *);
void printTokenList(TokenList);
int freeTokenList(TokenList *);



//defining a structure named FinalResult
struct FinalResult
{
    float data;
    bool status;
};
typedef struct FinalResult FinalResult;
//declaration of the functions
int doInsertSpace(char,char);
void putSpaceBetween(ListNode2 *,ListNode2 *);
void formatInfix(String *infix);
FinalResult evaluateInfix(String infix);
int isOperator(char);
int isParenthesis(char);
int validOperand(char *);
int isOperandAllDigits(char *);
int isValidToken(char *);
int getOperandValue(char *);
float calculate(float,char,float);
int doPop(char,char);
int priorityOperator(char);
int balParenthesis(TokenList);

//defining main function
int main()
{
String infix=DEFAULT_STRING;
FinalResult result=DEFAULT_FINAL_RESULT;
int choice,x;
do
{
    printf("\nSelect operation : ");
    printf("\n1. calculate infix expression ");
    printf("\n2. exit");
    printf("\nenter your choice : ");
    fflush(stdin);
    x=scanf("%d",&choice);
    if(x!=1)
    {
        printf("\n\"choice value should be integer only\"\n");
        x=3;
    }
    switch(choice)
    {
    case 1:
        printf("\nEnter the infix expression : ");
        fflush(stdin);
        inputStr(&infix);
        result=evaluateInfix(infix);
        if(result.status==true)
        {
            printf("Result : %f\n",result.data);
        }
        else
        {
            printf("\n\"ERROR:error encountered while evaluation\"\n");
        }
        freeStr(&infix);
        break;
    case 2:
        printf("\nQuitting the Application");
        freeStr(&infix);
        exit(0);
    default:
        printf("\nEnter correct choice\n");
    }
}while(1);
return 0;
}

//define insertAtBegList1
void insertAtBegList1(ListNode1 **phead,float data)
{
    ListNode1 *new_node=(ListNode1 *)malloc(sizeof(ListNode1));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory not available\"\n");
        return;
    }
    new_node->data=data;
    if(*phead==NULL)
    {
        *phead=new_node;
        new_node->next=NULL;
        return;
    }
    new_node->next=*phead;
    *phead=new_node;
}
//define delAtBegList1
retrieved1 delFromBegList1(ListNode1 **phead)
{
    retrieved1 result=DEFAULT_RETRIEVED1;
    ListNode1 *temp=NULL;
    if(*phead==NULL)
    {
        return result;
    }
    result.data=(*phead)->data;
    result.status=true;
    temp=*phead;
    *phead=(*phead)->next;
    free(temp);
    return result;
}
//define readFirstFromList1
retrieved1 readFirstFromList1(ListNode1 *head)
{
    retrieved1 result=DEFAULT_RETRIEVED1;
    if(head==NULL)
    {
        printf("\n\"LIST OF 'floats' IS EMPTY\"\n");
        return result;
    }
    result.data=head->data;
    result.status=true;
    return result;
}
//define freeList1
int freeList1(ListNode1 **phead)
{
    ListNode1 *current=NULL,*next=NULL;
    int flag=0;
    if(*phead==NULL)
    {
        flag=1;
    }
    else
    if((*phead)->next==NULL)
    {
        free(*phead);
        *phead=NULL;
        flag=1;
    }
    else
    {
    current=*phead;
    next=(*phead)->next;
    while(current!=NULL)
    {
        free(current);
        current=next;
        if(current!=NULL)
            next=current->next;
    }
    *phead=NULL;
    flag=1;
    }
    return flag;
}


//define insertAtBegList2
void insertAtBegList2(ListNode2 **phead,char data)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    if(*phead==NULL)
    {
        *phead=new_node;
        (*phead)->next=NULL;
        return;
    }
    new_node->next=*phead;
    *phead=new_node;
}
//define inserAtEndList2
void inserAtEndList2(ListNode2 **phead,char data)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"Error:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    new_node->next=NULL;
    if(*phead==NULL)
    {
        *phead=new_node;
        return;
    }
    ListNode2 *temp=*phead;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    }
//define printList2
void printList2(ListNode2 *head)
{
    if(head==NULL)
    {
        printf("\n\"LIST OF 'char' IS EMPTY\"\n");
        return;
    }
    ListNode2 *temp=head;
    while(temp!=NULL)
    {
        printf("%c",temp->data);
        temp=temp->next;
    }
}
//define delFromBegList2
retrieved2 delFromBegList2(ListNode2 **phead)
{
    retrieved2 result=DEFAULT_RETRIEVED2;
    ListNode2 *temp=NULL;
    if(*phead==NULL)
    {
        return result;
    }
    result.data=(*phead)->data;
    result.status=true;
    temp=*phead;
    *phead=(*phead)->next;
    free(temp);
    return result;
}
//define readFirstFromList2
retrieved2 readFirstFromList2(ListNode2 *head)
{
    retrieved2 result=DEFAULT_RETRIEVED2;
    if(head==NULL)
    {
        printf("\n\"LIST OF 'char' IS EMPTY\"\n");
        return result;
    }
    result.data=head->data;
    result.status=true;
    return result;
}
//define freeList2
int freeList2(ListNode2 **phead)
{
    int flag=0;
    ListNode2 *current=NULL,*next=NULL;
    if(*phead==NULL)
    {
        flag=1;
        return flag;
    }
    if((*phead)->next==NULL)
    {
        free(*phead);
        *phead=NULL;
        flag=1;
        return flag;
    }
    current=*phead;
    next=current->next;
    while(current!=NULL)
    {
        free(current);
        current=next;
        if(current!=NULL)
            next=current->next;
    }
    *phead=NULL;
    flag=1;
    return flag;
}
//define listToArray
char * listToArray(ListNode2 *head)
{
    ListNode2 *temp=head;
    int i=0;
    char *ptr=NULL;
    if(head==NULL)
    {
        printf("\n\"LIST OF 'char' IS EMPTY\"\n");
        return NULL;
    }
    ptr=(char *)malloc((countNodesList2(head)+1)*sizeof(char));
    if(ptr==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return NULL;
    }
    while(temp!=NULL)
    {
        ptr[i++]=temp->data;
        temp=temp->next;
    }
    ptr[i]=NULL;
    return ptr;
}
//define countNodesList2
int countNodesList2(ListNode2 *head)
{
    int count=0;
    ListNode2 *temp=head;
    if(head==NULL)
        return count;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
//define insertCharBetween
void insertNodeBetween(ListNode2 *node1,ListNode2 *node2,char data)
{
    ListNode2 *new_node=(ListNode2 *)malloc(sizeof(ListNode2));
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->data=data;
    if(node1==NULL||node2==NULL)
    {
        printf("\n\"ERROR:PROVIDED NOT CAN'T BE NULL to insertNodeBetween\"\n");
        return;
    }
    new_node->next=node2;
    node1->next=new_node;
}


//define insertAtBegList3
void insertAtBegList3(ListNode3 **phead,char *token)
{
    ListNode3 *new_node=(ListNode3 *)malloc(sizeof(ListNode3));
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
    new_node->next=*phead;
    *phead=new_node;
}
//define insertAtEndList3
void insertAtEndList3(ListNode3 **phead,char *token)
{
    ListNode3 *new_node=(ListNode3 *)malloc(sizeof(ListNode3));
    ListNode3 *temp=*phead;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return;
    }
    new_node->token=(char *)malloc((strlen(token)+1)*sizeof(char));
    if(new_node->token==NULL)
    {
        printf("\nERROR:memory allocation problem\"\n");
        return;
    }
    strcpy(new_node->token,token);
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
//define printList3
void printList3(ListNode3 *head)
{
    if(head==NULL)
    {
        printf("\n\"LIST OF 'tokens' IS EMPTY\"\n");
        return;
    }
    ListNode3 *temp=head;
    while(temp!=NULL)
    {
        printf("%s ",temp->token);
        temp=temp->next;
    }
}
//define freeList3
int freeList3(ListNode3 **phead)
{
    int flag=0;
    if(*phead==NULL)
    {
        flag=1;
        return flag;
    }
    if((*phead)->next==NULL)
    {
        free((*phead)->token);
        (*phead)->token=NULL;
        free(*phead);
        *phead=NULL;
        flag=1;
        return flag;
    }
    ListNode3 *current_node=NULL,*next_node=NULL;
    while(current_node!=NULL)
    {
        free(current_node->token);
        current_node->token=NULL;
        free(current_node);
        current_node=NULL;
        current_node=next_node;
        if(current_node!=NULL)
            next_node=current_node->next;
    }
    *phead=NULL;
    if(*phead==NULL)
        flag=1;
    return flag;
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
        inserAtEndList2(&(pstr->head),ch);
    }
}
//define printStr
void printStr(String str)
{
    printList2(str.head);
}
//stringAsArray
char * stringAsArray(String str)
{
    char *ptr=listToArray(str.head);
    return ptr;
}
//define lenStr
int lenStr(String str)
{
    return countNodesList2(str.head);
}
//define freeStr
int freeStr(String *pstr)
{
    freeList2(&(pstr->head));
    if(pstr->head==NULL)
        return 1;
    else
        return 0;
}


//define pushStack1
void pushStack1(Stack1 *pstk,float data)
{
    insertAtBegList1(&(pstk->tos),data);
}
//define popStack1
retrieved1 popStack1(Stack1 *pstk)
{
    retrieved1 result=DEFAULT_RETRIEVED1;
    result=delFromBegList1(&(pstk->tos));
    if(result.status==false)
        printf("\n\"STACK OF 'char' IS UNDERFLOW\"\n");
    return result;
}
//isEmptyStack1
int isEmptyStack1(Stack1 stk)
{
    return(stk.tos==NULL);
}
//peekStack1
retrieved1 peekStack1(Stack1 stk)
{
    retrieved1 result=DEFAULT_RETRIEVED1;
    if(stk.tos==NULL)
    {
        return result;
    }
    result=readFirstFromList1(stk.tos);
    return result;
}
//define freeStack1
int freeStack1(Stack1 *pstk)
{
    int flag=0;
    freeList1(&(pstk->tos));
    if(pstk->tos==NULL)
        flag=1;
    return flag;
}


//defining pushStack2
void pushStack2(Stack2 *pstk,char data)
{
    insertAtBegList2(&(pstk->tos),data);
}
//defining popStack2
retrieved2  popStack2(Stack2 *pstk)
{
    retrieved2 result=DEFAULT_RETRIEVED2;
    result=delFromBegList2(&(pstk->tos));
    return result;
}
//defining isEmptyStack2
int isEmptyStack2(Stack2 stk)
{
    return(stk.tos==NULL);
}
//defining peekStack2
retrieved2 peekStack2(Stack2 stk)
{
    retrieved2 result=DEFAULT_RETRIEVED2;
    result=readFirstFromList2(stk.tos);
    if(result.status==false)
    {
        printf("\n\"STACK OF 'char' IS EMPTY\"\n");
        return result;
    }
    return result;
}
//defining freeStack2
int freeStack2(Stack2 *pstk)
{
    int flag=0;
    if(pstk->tos==NULL)
    {
        flag=1;
        return flag;
    }
    freeList2(&(pstk->tos));
    if(pstk->tos==NULL)
        flag=1;
    return flag;
}


//defining createTokenList
TokenList createTokenList(String infix,char *delimiter)
{
    TokenList tkl=DEFAULT_TOKENLIST;
    char *arr=NULL;
    char *token=NULL;
    if(infix.head==NULL)
    {
        printf("\n\"STRING IS EMPTY\"\n");
        return tkl;
    }
    arr=(char *)malloc((lenStr(infix)+1)*sizeof(char));
    if(arr==NULL)
    {
        printf("\n\"ERROR:memory allocation problem\"\n");
        return tkl;
    }
   formatInfix(&infix);
   arr=stringAsArray(infix);
   token=strtok(arr,delimiter);
   while(token!=NULL)
   {
       insertAtEndList3(&(tkl.head),token);
       token=strtok(NULL,delimiter);
   }
   free(arr);
    return tkl;
}
//define printTokenList
void printTokenList(TokenList tkl)
{
    ListNode3 *temp=tkl.head;
    if(tkl.head==NULL)
    {
        printf("\n\"EMPTY TOKEN LIST\"\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%s ",temp->token);
        temp=temp->next;
    }
}
//define freeTokenList
int freeTokenList(TokenList *ptkl)
{
    int flag=0;
    freeStack1(&(ptkl->head));
    if(ptkl->head==NULL)
        flag=1;
    return flag;

}

//define doInsertSpace
int doInsertSpace(char ch1,char ch2)
{
    if(isalpha(ch1)&&isalpha(ch2))
        return 0;
    else
        if(isdigit(ch1)&&isdigit(ch2))
        return 0;
    else
        if(isdigit(ch1)&&isalpha(ch2))
        return 0;
    else
        if(isalpha(ch1)&&isdigit(ch2))
        return 0;
    else
        if(isalpha(ch1)&&(ch2=='_'))
        return 0;
    else
        if(ch1=='_'&&isalpha(ch2))
        return 0;
     else
        if(isdigit(ch1)&&(ch2=='_'))
        return 0;
    else
        if(ch1=='_'&&isdigit(ch2))
        return 0;
    else
        return 1;
}
//define putSpaceBetween
void putSpaceBetween(ListNode2 *node1,ListNode2 *node2)
{
    if(doInsertSpace(node1->data,node2->data))
        insertNodeBetween(node1,node2,' ');
}
//void formatInfix
void formatInfix(String *pstr)
{
    ListNode2 *node1=NULL,*node2=NULL;
    if(pstr->head==NULL)
    {
        printf("\n\"EMPTY INFIX EXPRESSION\"\n");
        return;
    }
    if(pstr->head->next==NULL)
    {
        return;
    }
    node1=pstr->head;
    node2=pstr->head->next;
    while(node2!=NULL)
    {
        putSpaceBetween(node1,node2);
        node1=node2;
        node2=node2->next;
    }
}
//defining isOperator
int isOperator(char ch)
{
    if(ch=='$'||ch=='*'||ch=='/'||ch=='%'||ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}
//defining isParenthesis
int isParenthesis(char ch)
{
    if(ch=='('||ch==')')
        return 1;
    else
        return 0;
}
//defining isOperand
int validOperand(char *token)
{
    int flag=0;
    int i=0;
    while(token[i]!=NULL)
    {
        if(!isalnum(token[i]))
        {
            flag=0;
            break;
            i++;
        }
    }
    if(strlen(token)==i)
        flag=1;
    return flag;
}
//defining isOperandAlldigit
int isOperandAllDigit(char *token)
{
    int i=0;
    int flag=0;
    while(token[i]!=NULL)
    {
        if(!isdigit(token[i]))
        {
            flag=0;
            break;
        }
        i++;
    }
if(strlen(token)==i)
    flag=1;

return flag;
}
//defining isValidSymbol
int isValidToken(char *token)
{
   int i=0;
   int flag;
   while(token[i]!=NULL)
   {
       if(!isdigit(token[i])&&!isalpha(token[i])&&!isOperator(token[i])&&!isParenthesis(token[i]))
       {
           flag=0;
           break;
       }
       i++;
   }
   if(strlen(token)==i)
   {
       flag=1;
   }
   return flag;
}
//defining processOperand
int getOperandValue(char *token)
{
    int val;
    do
    {
    printf("\nProvide value of variable %s : ",token);
    if(scanf("%d",&val)==0)
    {
        printf("\n\"WARNING:provide only integer value\"\n");
    }
    else
    {
        break;
    }
    }while(1);
    return val;
}
//defining calculate
float calculate(float a,char optr,float b)
{
    switch(optr)
    {
    case '$':
        return pow(a,b);
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '%':
        return fmod(a,b);
    case '+':
        return a+b;
    case '-':
        return a-b;
    }
}
//defining priorityOperator
int priorityOperator(char optr)
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
    default:
        printf("\n\"ERROR:invalid operator %c found\"\n",optr);
    }
}
//defining doPop
int doPop(char optr1,char optr2)
{
    return(priorityOperator(optr2)<=priorityOperator(optr1));
}
//defining balParenthesis
int balParenthesis(TokenList tkl)
{
    ListNode3 *temp=tkl.head;
    Stack2 stk2=DEFAULT_STACK;
    retrieved2 popped_value=DEFAULT_RETRIEVED2;
    int flag;
    while(temp!=NULL)
    {
        if(temp->token[0]=='(')
        {
            pushStack2(&stk2,temp->token[0]);
        }
        else
        if(temp->token[0]==')')
        {
            popped_value=popStack2(&stk2);
            if(popped_value.data=='\0')
                return 0;
        }
        temp=temp->next;
    }
    if(isEmptyStack2(stk2))
        flag=1;
    else
        flag=0;
    freeStack2(&stk2);
    return flag;
}
//defining evaluateInfix
FinalResult evaluateInfix(String infix)
{
    FinalResult result=DEFAULT_FINAL_RESULT;
    TokenList tkl=DEFAULT_TOKENLIST;
    ListNode3 *temp=NULL;
    char *token=NULL;
    Stack1 stk1=DEFAULT_STACK;
    Stack2 stk2=DEFAULT_STACK;
    float a;
    if(infix.head==NULL)
    {
        printf("\n\"Empty Infix Expression\"\n");
        return result;
    }
    tkl=createTokenList(infix," ");
    if(!balParenthesis(tkl))
    {
        printf("\n\"ERROR:can't evaluate, parenthesis are not balanced\"");
        result.status=false;
        return result;
    }
    temp=tkl.head;
    while(temp!=NULL)
    {
        if(isValidToken(temp->token))
        {
            if(!isOperator(temp->token[0])&&!isParenthesis(temp->token[0]))
            {
                if(isOperandAllDigit(temp->token))
                {
                    pushStack1(&stk1,atoi(temp->token));
                }
                else
                {
                    printf("\nprovide the value of variable %s : ",temp->token);
                    scanf("%f",&a);
                    pushStack1(&stk1,a);
                }
            }
            else
            {
                while(1)
                {
                    if(isEmptyStack2(stk2))
                    {
                        pushStack2(&stk2,temp->token[0]);
                        break;
                    }
                    else
                    if(temp->token[0]=='(')
                    {
                        pushStack2(&stk2,temp->token[0]);
                        break;
                    }
                    else
                    if(peekStack2(stk2).data=='(')
                    {
                        pushStack2(&stk2,temp->token[0]);
                        break;
                    }
                    else
                    if(temp->token[0]==')')
                    {
                        while(peekStack2(stk2).data!='(')
                        {
                            pushStack1(&stk1,calculate(popStack1(&stk1).data,popStack2(&stk2).data,popStack1(&stk1).data));
                        }
                        popStack2(&stk2);
                        break;
                    }
                    else
                    if(doPop(peekStack2(stk2).data,temp->token[0]))
                    {
                            pushStack1(&stk1,calculate(popStack1(&stk1).data,popStack2(&stk2).data,popStack1(&stk1).data));
                    }
                    else
                    {
                        pushStack2(&stk2,temp->token[0]);
                        break;
                    }

                }
            }
        }
        else
        {
            printf("\n\"ERROR:invalid token %s\"\n",temp->token);
            result.status=false;
            return result;
            break;
        }
        temp=temp->next;
    }
    while(!isEmptyStack2(stk2))
    {
       pushStack1(&stk1,calculate(popStack1(&stk1).data,popStack2(&stk2).data,popStack1(&stk1).data));
    }
    result.data=popStack1(&stk1).data;
    result.status=true;
    freeTokenList(&tkl);
    freeStack1(&stk1);
    freeStack2(&stk2);
    return result;
}

/* Sample output

Select operation :
1. calculate infix expression
2. exit
enter your choice : 1

Enter the infix expression : (4 - 2) * ((8 + 3) / (6 - 4))
Result : 11.000000

Select operation :
1. calculate infix expression
2. exit
enter your choice : 1

Enter the infix expression : ((15 - 3) / 2 + (4 * 6)) * ((9 - 2) + (5 * 3)) / (7 + 1)
Result : 82.500000

Select operation :
1. calculate infix expression
2. exit
enter your choice : 1

Enter the infix expression : x1+(x2*x3)/10

provide the value of variable x1 : 10

provide the value of variable x2 : 50

provide the value of variable x3 : 20
Result : 110.000000

Select operation :
1. calculate infix expression
2. exit
enter your choice : 2

Quitting the Application

*/

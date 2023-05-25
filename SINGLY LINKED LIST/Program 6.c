/*C program to convert an infix expression to postfix expression. note: both stack and infix expression are stored dynamically using singly linked list*/
#include <stdio.h>
#include <stdlib.h>
#define DEFAULTS_STRING {.head=NULL}
#define DEFAULTS_STACK {.tos=NULL}
//defining structure named ListNode1
struct ListNode
{
    char ch;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
//defining structure named String
struct String
{
    ListNode *head;
};
typedef struct String String;
//defining structure named Stack
struct Stack
{
    ListNode *tos;
};
typedef struct Stack Stack;
//declaration of functions to process a string
void inputString(String *);
int lengthString(String);
void insertAtEnd(String *,char);
void printString(String);
char * listToArray(String);
//declarations of functions to process infix expression
void insertDelimiter(String *);
int isOperator(char ch);
int isParenthesis(char ch);
int isAllowed(char ch);
void putSpaceBetween(ListNode *,ListNode *);
char * infixToPostfix(String);
int precedence(char);
int doPop(char,char);

//declaring push,pop,isempty,peek operations on stack
void push(Stack *,char);
char pop(Stack *);
int isEmpty(Stack);
char peek(Stack);
//Declaring freeString and freeStack function
void freeString(String *);
void freeStack(Stack *);
int main()
{
    String infix=DEFAULTS_STRING;
    char *postfix=NULL;
    printf("\nenter infix expression : ");
    inputString(&infix);
    insertDelimiter(&infix);
    postfix=infixToPostfix(infix);
    printf("\npostfix expression is : %s\n",postfix);
    freeString(&infix);
    free(postfix);
    postfix=NULL;
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
    ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));
    ListNode *temp=pstr->head;
    if(new_node==NULL)
    {
        printf("\n\"ERROR:unable to insert %c\"\n",ch);
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
//defining lengthString
int lengthString(String str)
{
    int len=0;
    ListNode *temp=str.head;
    if(str.head==NULL)
        return 0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
//defining printString
void printString(String str)
{
    ListNode *temp=str.head;
    if(str.head==NULL)
    {
        printf("");
        return;
    }
    while(temp!=NULL)
    {
        printf("%c",temp->ch);
        temp=temp->next;
    }
}
//defining listToArray
char * listToArray(String str)
{
    ListNode *temp=str.head;
    char *arr=NULL;
    int i=0;
    if(str.head==NULL)
    {
        return NULL;
    }
    arr=(char *)malloc((lengthString(str)+1)*sizeof(char));
    if(arr==NULL)
    {
        printf("\n\"Error:can't store in array\"\n");
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
//defining precedence
int precedence(char ch)
{
    if(ch=='$')
        return 3;
    else
    if(ch=='*'||ch=='/'||ch=='%')
        return 2;
    else
    if(ch=='+'||ch=='-')
        return 1;
}
//defining doPop
int doPop(char optr1,char optr2)
{
    return(precedence(optr1)>=precedence(optr2));
}
//defining isOperator
int isOperator(char ch)
{
    if(ch=='$'||ch=='*'||ch=='/'||ch=='%'||ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}
//defining insertDelimiter
void insertDelimiter(String *pstr)
{
    ListNode *current_node=pstr->head;
    ListNode *prev_node=NULL;
    if(pstr->head==NULL)
    {
        printf("\n\"list is empty\"\n");
        return;
    }
    if(pstr->head->next==NULL)
    {
        return;
    }
    while(current_node!=NULL)
    {
        if(prev_node==NULL);
        else
        if(isdigit(prev_node->ch)&&isOperator(current_node->ch))
        {
            putSpaceBetween(prev_node,current_node);
        }
        else
        if(isOperator(prev_node->ch)&&isdigit(current_node->ch))
        {
            putSpaceBetween(prev_node,current_node);
        }
        else
        if(isalpha(prev_node->ch)&&isOperator(current_node->ch))
        {
            putSpaceBetween(prev_node,current_node);
        }
        else
        if(isOperator(prev_node->ch)&&isalpha(current_node->ch))
        {
            putSpaceBetween(prev_node,current_node);
        }
        else
        if(isParenthesis(prev_node->ch)||isParenthesis(current_node->ch))
        {
            putSpaceBetween(prev_node,current_node);
        }
        prev_node=current_node;
        current_node=current_node->next;
    }
}
//defining isParenthesis
int isParenthesis(char ch)
{
    if(ch=='('||ch==')')
        return 1;
    else
        return 0;
}
//defining isAllowed
int isAllowed(char ch)
{
    if(isalpha(ch))
        return 1;
    else
    if(isdigit(ch))
        return 1;
    else
    if(isParenthesis(ch))
        return 1;
    else
    if(isOperator(ch))
        return 1;
    else
        return 0;
}
//defining putSpaceBetween
void putSpaceBetween(ListNode *prev_node,ListNode *current_node)
{
    ListNode *temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("\n\"ERROR:error occured while inserting delimiter\"\n");
        return;
    }
    temp->ch=32;
    temp->next=current_node;
    prev_node->next=temp;
}
//defining infix to postfix conversion
char * infixToPostfix(String infix)
{
  Stack stk=DEFAULTS_STACK;
  char *token=NULL;
  char *popped_element=(char *)malloc(2*sizeof(char));
  if(popped_element==NULL)
  {
      printf("\n\"ERROR:can't allocate memory for popped element\"\n");
      return NULL;
  }
  char *postfix=(char *)malloc((lengthString(infix)+1)*sizeof(char));
  if(postfix==NULL)
  {
      printf("\n\"ERROR:can't allocate memory for postfix\"\n");
      return NULL;
  }
  postfix[0]='\0';
  if(infix.head==NULL)
  {
      printf("\n\"String is empty\"\n");
      return NULL;
  }
  char *arr=listToArray(infix);
  token=strtok(arr," ");
  while(token!=NULL)
  {

      if((isOperator(token[0])!=1)&&(isParenthesis(token[0])!=1))
      {
          if(strlen(postfix)==0)
          {
              strcpy(postfix,token);
              strcat(postfix," ");
          }
          else
          {
              strcat(postfix,token);
              strcat(postfix," ");
          }
      }
      else
      {
          while(1)
          {
              if(isEmpty(stk))
              {
                  push(&stk,token[0]);
                  break;
              }
              else
              if(token[0]=='(')
              {
                  push(&stk,token[0]);
                  break;
              }
              else
              if(peek(stk)=='(')
              {
                  push(&stk,token[0]);
                  break;
              }
              else
              if(token[0]==')')
              {
                  while(peek(stk)!='(')
                  {
                      popped_element[0]=pop(&stk);
                      popped_element[1]=NULL;
                      strcat(postfix,popped_element);
                      strcat(postfix," ");
                  }
                  pop(&stk);
                  break;
              }
              else
              {
                  if(doPop(peek(stk),token[0]))
                  {
                      popped_element[0]=pop(&stk);
                      popped_element[1]=NULL;
                      strcat(postfix,popped_element);
                      strcat(postfix," ");
                  }
                  else
                  {
                      push(&stk,token[0]);
                      break;
                  }
              }


          }
      }
      token=strtok(NULL," ");
  }
  while(isEmpty(stk)!=1)
  {
      popped_element[0]=pop(&stk);
      popped_element[1]=NULL;
      strcat(postfix,popped_element);
      strcat(postfix," ");
  }
  freeStack(&stk);
return postfix;

}
//defining push function
void push(Stack *pstk,char ch)
{
    ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));
    if(new_node==NULL)
    {
        printf("\n\"STACK OVERFLOW:can't create new node\"\n");
        return;
    }
    new_node->ch=ch;
    if(pstk->tos==NULL)
    {
        pstk->tos=new_node;
        new_node->next=NULL;
        return;
    }
    new_node->next=pstk->tos;
    pstk->tos=new_node;
}
//defining pop function
char pop(Stack *pstk)
{
    ListNode *temp;
    char ch;
    if(pstk->tos==NULL)
    {
        printf("\n\"STACK UNDERFLOW\"\n");
        return NULL;
    }
    temp=pstk->tos;
    pstk->tos=pstk->tos->next;
    ch=temp->ch;
    free(temp);
    return(ch);
}
//defining isEmpty function
int isEmpty(Stack stk)
{
    return(stk.tos==NULL);
}
//defining the peek function
char peek(Stack stk)
{
    if(isEmpty(stk))
        return NULL;
    else
        return(stk.tos->ch);
}
//defining freeStack
void freeStack(Stack *pstk)
{
    ListNode *temp=NULL,*next_node=NULL;
    if(pstk->tos==NULL)
    {
        return;
    }
    temp=pstk->tos;
    while(temp!=NULL)
    {
        next_node=temp->next;
        free(temp);
        temp=next_node;
    }
    pstk->tos=NULL;
}
//defining freeString
void freeString(String *pstr)
{
    ListNode *temp=NULL,*next_node=NULL;
    if(pstr->head==NULL)
        return;
    temp=pstr->head;
    while(temp!=NULL)
    {
        next_node=temp->next;
        free(temp);
        temp=next_node;
    }
    pstr->head=NULL;
}

/*Sample output 1 : 
enter infix expression : (4+(6*2))/(3-1)

postfix expression is : 4 6 2 * + 3 1 - /

Process returned 0 (0x0)   execution time : 16.073 s
Press any key to continue.
*/ 

/*Sample Output 2 : 
enter infix expression : ((((((2+3)*5)-8)/4)+((7-2)*3))/((6*2)-1))+((9-4)*(12+(10/2)))

postfix expression is : 2 3 + 5 * 8 - 4 / 7 2 - 3 * + 6 2 * 1 - / 9 4 - 12 10 2 / + * +

Process returned 0 (0x0)   execution time : 40.863 s
Press any key to continue.
*/

/*Sample Output 3:
enter infix expression : x1+x2+(abc/10)%xyz

postfix expression is : x1 x2 + abc 10 / xyz % +

Process returned 0 (0x0)   execution time : 27.994 s
Press any key to continue.
*/

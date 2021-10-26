#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct stack
{int size;
  int top;
  char *s;
 };
 int isOperand(char a)
 {
     if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'||a=='!')
        return 0;
     else return 1;
 }
 int precedence(char a)
 {
     if(a=='+'||a=='-')
        return 1;
     else if(a=='*'||a=='/')
               return 2;
               else if(a=='^'||a=='!')
                        return 3;
     return 0;
 }
 void push(struct stack *a,int len, char x)
 {
     if(a->top==len-1)
        printf("Stack is Full");
     else
        {   a->top++;
             a->s[a->top]=x;
        }
 }
 char pop(struct stack *st)
 {
     char temp;
    if(st->top==-1)
        printf("Its Underflow\n");
    else temp=st->s[st->top--];
    return temp;
 }
int isEmpty(struct stack st)
{
if(st.top==-1)
return 1;
return 0;
}
char stackTop(struct stack st)
{
if(!isEmpty(st))
return st.s[st.top];
return -1;
}
char *InfixToPostfix(char *infix)
{  int len,i=0,j=0;
    len=strlen(infix);
    struct stack st;
    st.top=-1;
    st.size=len;
    st.s=(char *)malloc(sizeof(struct stack));
    char *postfix=(char *)malloc(sizeof(int)*len+2);
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
          { if(infix[i]=='('|| infix[i]==')')
          {
           i++;
           }
             else postfix[j++]=infix[i++];
          }
        else { if(precedence(infix[i])>precedence(stackTop(st)))
                        push(&st,st.size,infix[i++]);
                else postfix[j++]=pop(&st);
        }
    }
    while(!isEmpty(st))
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{  char s[1000];
    printf("Enter Expression to convert:\n");
    scanf("%s",&s);
    printf("Postfix Expression: %s",InfixToPostfix(&s));
    return 0;
}

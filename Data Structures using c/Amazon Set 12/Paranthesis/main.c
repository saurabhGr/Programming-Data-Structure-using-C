#include <stdio.h>
#include <stdlib.h>
struct stack
{int size;
int top;
char *s;
};
int isEmpty(struct stack a)
{
    if(a.top==-1)
    return 0;
    else return 1;
}
void push(struct stack *a,int size,int x)
{
    if(a->top==a->size-1)
        printf("Hey..Stack is Overflow\n");
    else {
        a->top++;
        a->s[a->top]=x;
    }
}
int pop(struct stack *a)
{   int temp=-1;
    if(a->top==-1){}
    else temp=a->s[a->top--];
    return temp;
}
void display(struct stack a)
{int i;
    for(i=0;i<=a.top;i++)
    {
        printf("|%d|",a.s[i]);
    }
    printf("\n");
}
int main()
{ struct stack st;
int i=0;
    printf("Enter size of Stack\n");
    scanf("%d",&st.size);
    st.s=(char *)malloc(sizeof(struct stack));
    st.top=-1;
    printf("Stack is created...\n");
char brac[st.size];
printf("Enter Your paranthesises: ");
scanf("%s",brac);
for(i=0;i<st.size;i++)
{
     if(st.s[st.top]=='[')
     { if(brac[i]=='['||brac[i]=='{'||brac[i]=='(')
         push(&st,st.size,brac[i]);
     }
     else if(st.s[st.top]=='{')
        { if(brac[i]=='{'||brac[i]=='(')
         push(&st,st.size,brac[i]);
          else if(brac[i]=='[')
          {
              printf("\nError in Paranthesis");
              return 0;
          }
     }
    if(st.s[st.top]=='(')
                 { if(brac[i]=='(')
                       push(&st,st.size,brac[i++]);
                       else if(brac[i]=='{'|| brac[i]=='[')
                              {
                                  printf("\nError in Paranthesis");
                                   return 0;
                               }
                 }
        if(brac[i]==')')
        {
           if(st.s[st.top]=='{'||st.s[st.top]=='[')
            {
                printf("\nError in Paranthesis");
                                   return 0;
            }
            else pop(&st);
        }
        if(brac[i]=='}')
        {
           if(st.s[st.top]=='('||st.s[st.top]=='[')
            {
                printf("\nError in Paranthesis");
                                   return 0;
            }
            else pop(&st);
        }
        if(brac[i]==']')
        {
           if(st.s[st.top]=='{'||st.s[st.top]=='(')
            {
                printf("\nError in Paranthesis");
                                   return 0;
            }
            else pop(&st);
        }
}
printf("True\n");
    return 0;
}

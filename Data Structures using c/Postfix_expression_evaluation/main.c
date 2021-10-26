#include <stdio.h>
#include <stdlib.h>
struct stack
{int size;
int top;
int *s;
};
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
    if(a->top==-1)
        printf("Its Underflow\n");
    else temp=a->s[a->top--];
    return temp;
}
int isOperand(char a)
 {
     if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'||a=='!')
        return 0;
     else return 1;
 }
int PostfixEvaluation(char *postfix)
     {
        int x1,x2,r=0 ;
        int len,i=0;
        len=strlen(postfix);
        struct stack st;
        st.top=-1;
        st.size=len;
        st.s=(char *)malloc(sizeof(struct stack));
        for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
           push(&st,st.size,postfix[i]-'0');
       else
          {
              x2=pop(&st); x1=pop(&st);
              switch(postfix[i])
                   {
                      case '+':r=x1+x2; break;
                      case '-':r=x1-x2; break;
                      case '*':r=x1*x2; break;
                      case '/':r=x1/x2; break;
                   }
            push(&st,st.size,r);
         }
    }
    return pop(&st);
}

int main()
{
    char ch[1000];
    printf("Enter Postfix Expression to Evaluate\n");
    scanf("%s",&ch);
   printf("Evaluated value of Postfix Expression is %d\n",PostfixEvaluation(&ch));
    return 0;
}

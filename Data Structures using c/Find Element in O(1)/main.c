#include <stdio.h>
#include <stdlib.h>
struct stack
{int size;
int top;
int *s;
};
int isFull(struct stack a)
{
    if(a.top==a.size-1)
        printf("Stack is Overflow\n");
    else if(a.top==-1)
            printf("Stack is Empty\n");
            else printf("Stack contain some Elements\n");
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
{   int temp;
    if(a->top==-1)
        printf("Its Underflow\n");
    else temp=a->s[a->top--];
    return temp;
}
int getmin(int min)
{
    printf("Min Element in Stack is:%d\n",min);
}
int main()
{ struct stack st;
   int ch,x,temp,min,y;
    printf("Enter size of Stack\n");
    scanf("%d",&st.size);
    st.s=(int *)malloc(sizeof(struct stack));
    st.top=-1;
    printf("Stack is created...\n");
    printf("Menu for Stack Operations\n");
        printf("Press 1 for Push(x)\n");
        printf("Press 2 for Pop()\n");
        printf("Press 3 to Display Min elements in Stack\n");
        printf("Press 4 to Exit...\n");
    do
    {       printf("Enter Your choice\n");
             scanf("%d",&ch);
             switch(ch)
                 {
                   case 1: printf("Enter Element to Push to Stack\n");
                                scanf("%d",&x);
                                if(st.top==-1)
                                {
                                    min=x;
                                push(&st,st.size,x);
                                }
                                else if(x>=min)
                                          push(&st,st.size,x);
                                           else if(x<min)
                                             {
                                                 y=(2*x)-min;
                                                 min=x;
                                                 push(&st,st.size,y);

                                            }
                                break;
                   case 2: temp=pop(&st);
                                if(temp<min)
                                {
                                    min=(2*min)-temp;
                                }
                                printf("Top element has been Poped off\n");
                                break;
                   case 3: getmin(min);
                                break;
                 }
    }while(ch<4);
    return 0;
}

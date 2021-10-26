#include <stdio.h>
#include <stdlib.h>
struct stack
{int size;
int top;
int *s;
};
int isEmpty(struct stack a)
{
    if(a.top==-1)
    printf("Stack is Underflow\n");
    else printf("Stack contain some elements\n");
}
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
{   int temp=-1;
    if(a->top==-1)
        printf("Its Underflow\n");
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
int ch,x,temp;
    printf("Enter size of Stack\n");
    scanf("%d",&st.size);
    st.s=(int *)malloc(sizeof(struct stack));
    st.top=-1;
    printf("Stack is created...\n");
    isEmpty(st);
    printf("Menu for Stack Operations\n");
        printf("Press 1 for Push(x)\n");
        printf("Press 2 for Pop()\n");
        printf("Press 3 to check IsEmpty?\n");
        printf("Press 4 to check isFull?\n");
        printf("Press 5 to Display elements in Stack\n");
        printf("Press 6 to Exit...\n");
    do
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
             switch(ch)
                 {
                   case 1: printf("Enter Element to Push to Stack\n");
                                scanf("%d",&x);
                                push(&st,st.size,x);
                                break;
                   case 2: temp=pop(&st);
                                if(temp>-1)
                                printf("%d is poped off\n",temp);
                                break;
                   case 3: isEmpty(st);
                                break;
                   case 4: isFull(st);
                                break;
                   case 5: display(st);
                                break;
                 }
    }while(ch<6);
    return 0;
}

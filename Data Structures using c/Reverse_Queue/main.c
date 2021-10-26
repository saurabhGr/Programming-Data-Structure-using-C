
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
struct stack
{ int size;
   int top;
   int *s;
};
void enqueue(struct queue *q,int x)
{
   if(q->rear==q->size-1)
    printf("Queue is Full\n");
   else
    {
    q->rear++;
    q->Q[q->rear]=x;
    }
}
void Extended_enqueue(struct queue *q,int x,struct stack *st)
{
   if(q->rear==q->size-1)
    printf("Queue is Full\n");
   else
    {
    q->rear++;
    st->top++;
    q->Q[q->rear]=x;
    st->s[st->top]=x;
    }
}
int dequeue(struct queue *q)
{  int x=-1;
    if(q->rear==q->front)
        printf("Queue is Empty\n");
    else
        {
         q->front++;
          x=q->Q[q->front];
        }
        return x;
}
int pop(struct stack *a)
{   int temp=-1;
    if(a->top==-1)
        printf("Its Underflow\n");
    else temp=a->s[a->top--];
    return temp;
}
void reverseQueue(struct stack *st,struct queue *q)
{  int x,i;
    if(st->top==-1)
        printf("Queue is Empty\n");
    else
        {  q->rear=q->front=-1;
            for(i=st->top+1;i>0;i--)
             { x=pop(st);
                 enqueue(q,x);
             }
        }
}
void display(struct queue q)
{ int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("|_%d_|",q.Q[i]);
}
int main()
{ int ch,x,y;
   struct queue s1;
   printf("Enter Size of Queue\n");
   scanf("%d",&s1.size);
   s1.front=s1.rear=-1;
   s1.Q=(int *)malloc(s1.size*sizeof(int));
   struct stack st;
   st.size=s1.size;
   st.top=-1;
   st.s=(int *)malloc(st.size*sizeof(int));
   do
   {  printf("\n..|||  Menu  |||..\n");
       printf("Press 1 for Enqueue\n");
       printf("Press 2 for Dequeue\n");
       printf("Press 3 for Display Queue\n");
       printf("Press 4 for Reverse Queue\n");
       printf("Press 5 for Exit\n");
       scanf("%d",&ch);
   switch(ch)
   {
       case 1: printf("Enter Element to Enqueue\n");
                    scanf("%d",&x);
                    Extended_enqueue(&s1,x,&st);
                    break;
       case 2: y=dequeue(&s1);
                    if(y>-1)
                    printf("%d is Dequeued\n",y);
                    break;
       case 3: display(s1);
                    break;
       case 4: reverseQueue(&st,&s1);
                    printf("Reversed Queue is\n");
                    display(s1);
                    break;
   }
   }while(ch<5);
    return 0;
}

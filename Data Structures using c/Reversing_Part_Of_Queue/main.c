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
void stack_enqueue(struct queue *q,int x,struct stack *st)
{
   if(q->rear==q->size-1)
    printf("Queue is Full\n");
   else
    {
    q->rear++;
    if(st->size>q->rear)
         {st->top++;
           st->s[st->top]=x;}
    q->Q[q->rear]=x;
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
void reverse_K_Queue(struct stack *st,struct queue *q)
{  int x,i,tempFront,tempRear;
    tempFront=q->front;
    tempRear=q->rear;
    if(st->top==-1)
        printf("Queue is Empty\n");
    else
        {  q->rear=q->front=-1;
            for(i=st->size;i>0;i--)
             { x=pop(st);
                 enqueue(q,x);
             }
        }
        q->front=tempFront;
        q->rear=tempRear;
}
void display(struct queue q)
{ int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("|_%d_|",q.Q[i]);
}
int main()
{ int ch,x;
   struct queue s1;
   printf("Enter Size of Queue\n");
   scanf("%d",&s1.size);
   s1.front=s1.rear=-1;
   s1.Q=(int *)malloc(s1.size*sizeof(int));
   struct stack st;
   printf("Enter number of Elements to be Reverse:\n");
   scanf("%d",&st.size);
   st.top=-1;
   st.s=(int *)malloc(st.size*sizeof(int));
   do
   {
       printf("\nPress 1 for Enqueue\n");
       printf("Press 2 for Reverse_k Element of Queue\n");
       printf("Press 3 for Exit\n");
       scanf("%d",&ch);
   switch(ch)
   {
       case 1: printf("Enter Element to Enqueue\n");
                    scanf("%d",&x);
                    stack_enqueue(&s1,x,&st);
                    display(s1);
                    break;
       case 2: reverse_K_Queue(&st,&s1);
                    printf("Reversed Queue is\n");
                    display(s1);
                    break;
   }
   }while(ch<3);
    return 0;
}

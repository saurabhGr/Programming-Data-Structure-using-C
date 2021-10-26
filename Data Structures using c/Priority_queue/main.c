#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void prioenqueue(struct queue *q,int x)
{
   if(q->rear==q->size-1)
    printf("Queue is Full\n");
   else
    {
    q->rear++;
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
void display(struct queue q)
{ int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("|_%d_|",q.Q[i]);
}
int BubbleSort(struct queue *q)
{
    int i,j,x;
  for(i=q->front+1;i<=q->rear;i++)
  {
      for(j=q->front+1;j<q->rear-i;j++)
     {
         if(q->Q[j]>q->Q[j+1])
         {
             x=q->Q[j];
             q->Q[j]=q->Q[j+1];
             q->Q[j+1]=x;
         }
     }
  }
}
int main()
{ int ch,x,y;
   struct queue s1;
   printf("This Priority Queue is Implmented\nBased on Element priority\n");
   printf("Enter Size of Queue\n");
   scanf("%d",&s1.size);
   s1.front=s1.rear=-1;
   s1.Q=(int *)malloc(s1.size*sizeof(int));
   do
   {  printf("\n.........|||  Menu  |||.........\n");
       printf("Press 1 for PrioEnqueue\n");
       printf("Press 2 for PrioDequeue\n");
       printf("Press 3 for Display Priority Queue\n");
       printf("Press 4 for Exit\n");
       scanf("%d",&ch);
   switch(ch)
   {
       case 1: printf("Enter Element to Priority Enqueue\n");
                    scanf("%d",&x);
                    prioenqueue(&s1,x);
                     BubbleSort(&s1);
                    break;
       case 2: y=dequeue(&s1);
                    if(y>-1)
                    printf("%d is Dequeued\n",y);
                    break;
       case 3: display(s1);
   }
   }while(ch<4);
    return 0;
}

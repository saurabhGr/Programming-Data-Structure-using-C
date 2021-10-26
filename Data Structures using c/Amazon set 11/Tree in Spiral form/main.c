#include <stdio.h>
#include <stdlib.h>
int n,count;
struct Node
     {
        struct Node *lchild;
        int data;
        struct Node *rchild;
     }*root=NULL;
struct Queue
    {
        int size;
        int front;
        int rear;
        struct Node **Q;
     };
void create(struct Queue *q,int size)
    {
         q->size=size;
         q->front=q->rear=0;
         q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
     }
void enqueue(struct Queue *q,struct Node *x)
{
         if((q->rear+1)%q->size==q->front)
             printf("Queue is Full");
         else
             {
                q->rear=(q->rear+1)%q->size;
                q->Q[q->rear]=x;
              }
}
struct Node * dequeue(struct Queue *q)
{
        struct Node* x=NULL;
         if(q->front==q->rear)
            printf("Queue is Empty\n");
         else
             {
                 q->front=(q->front+1)%q->size;
                  x=q->Q[q->front];
             }
    return x;
}
int isEmpty(struct Queue q)
      {
           return q.front==q.rear;
      }
void Treecreate(int bstarr[])
{
      struct Node *p,*t;
       int x,i=1;
      struct Queue q;
      create(&q,100);
      printf("Enter root value ");
      scanf("%d",&x);
      bstarr[0]=x;
      root=(struct Node *)malloc(sizeof(struct Node));
      root->data=x;
      root->lchild=root->rchild=NULL;
      enqueue(&q,root);
      while(!isEmpty(q))
         {
             p=dequeue(&q);
             printf("enter left child of %d ",p->data);
             scanf("%d",&x);
             if(x!=-1)
                {
                    t=(struct Node *)malloc(sizeof(struct Node));
                    t->data=x;
                    bstarr[i++]=x;
                    t->lchild=t->rchild=NULL;
                    p->lchild=t;
                    enqueue(&q,t);
                 }
             printf("enter right child of %d ",p->data);
             scanf("%d",&x);
          if(x!=-1)
            {
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data=x;
                bstarr[i++]=x;
                t->lchild=t->rchild=NULL;
               p->rchild=t;
               enqueue(&q,t);
            }
     }
}
struct stack
{int size;
int top;
struct Node  **s;
};
void createStack(struct stack *st)
    {
         st->size=n;
         st->top=-1;
         st->s=(struct Node **)malloc(st->size*sizeof(struct Node *));
     }
void push(struct stack *a,struct Node *x)
{
    if(a->top==a->size-1)
        printf("Hey..Stack is Overflow\n");
    else {
        a->top++;
        a->s[a->top]=x;
    }
}
struct Node *pop(struct stack *a)
{   struct Node *temp=NULL;
    if(a->top==-1)
        printf("Its Underflow\n");
    else temp=a->s[a->top--];
    return temp;
}
int SpiralTraversal(struct Node *temp)
{ int level=0;
struct Node *endt=temp;
    struct stack st1,st2;
    createStack(&st1);
    createStack(&st2);
    if(temp)
    {
        push(&st1,temp);
        while(endt)
       {if(level++%2==0)
        while(st1.top!=-1)
        {
            temp=pop(&st1);
            printf("%d ",temp->data);
            if(temp->lchild)
                    push(&st2,temp->lchild);
            if(temp->rchild)
                    push(&st2,temp->rchild);
        }
        if(level++%2!=0)
        while(st2.top!=-1)
        {
            temp=pop(&st2);
            printf("%d ",temp->data);
            if(temp->rchild)
                push(&st1,temp->rchild);
            if(temp->lchild)
                push(&st1,temp->lchild);
        }
        endt=endt->lchild;
       }
    }
}
int main()
{int i;
    printf("Input -1 if no element in left or right child\n");
    printf("Enter total Nodes in your Tree: ");
    scanf("%d",&n);
    int bstarr[n];
Treecreate(bstarr);
printf("Stored tree is: ");
for(i=0;i<n;i++)
printf("%d ",bstarr[i]);
printf("\n");
SpiralTraversal(root);
return 0;
}

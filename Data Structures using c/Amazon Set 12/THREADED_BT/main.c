#include <stdio.h>
#include <stdlib.h>
int n;
struct Node
     {
        struct Node *lchild;
        int data;
        struct Node *rchild;
        struct Node *thread;
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
struct Node *dequeue(struct Queue *q)
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
      printf("Eneter root value ");
      scanf("%d",&x);
      bstarr[0]=x;
      root=(struct Node *)malloc(sizeof(struct Node));
      root->data=x;
      root->lchild=root->rchild=root->thread=NULL;
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
                    t->lchild=t->rchild=t->thread=NULL;
                    p->lchild=t;
                    p->thread=t;
                    enqueue(&q,t);
                 }
             printf("enter right child of %d ",p->data);
             scanf("%d",&x);
          if(x!=-1)
            {
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data=x;
                bstarr[i++]=x;
                t->lchild=t->rchild=t->thread=NULL;
               p->rchild=t;
               p->lchild->thread=t;
               enqueue(&q,t);
            }
     }
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
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
printf("\nThread Traversal is:");
Inorder(root);
return 0;
}

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
int Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
int DiffLevelOddEven(struct Node *temp,int level)
{
    if(temp==NULL)
         return 0;
    else {if(level%2==0)
                {count=count+temp->data;
                printf("lav%d ",count);}
                else count=count-temp->data;
                DiffLevelOddEven(temp->lchild,level+1);
                DiffLevelOddEven(temp->rchild,level+1);
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
printf("Inorder Traversal of BT is:  ");
Inorder(root);
DiffLevelOddEven(root,0);
printf("\nThe Difference of Odd and Even level nodes is: %d",count);
return 0;
}

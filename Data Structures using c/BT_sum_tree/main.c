#include <stdio.h>
#include <stdlib.h>
int n;
struct node
     {
        struct node *left;
        int data;
        struct node *right;
     }*root=NULL;
struct Queue
    {
        int size;
        int front;
        int rear;
        struct node **Q;
     };
void create(struct Queue *q,int size)
    {
         q->size=size;
         q->front=q->rear=0;
         q->Q=(struct node **)malloc(q->size*sizeof(struct node *));
     }
void enqueue(struct Queue *q,struct node *x)
{
         if((q->rear+1)%q->size==q->front)
             printf("Queue is Full");
         else
             {
                q->rear=(q->rear+1)%q->size;
                q->Q[q->rear]=x;
              }
}
struct node * dequeue(struct Queue *q)
{
        struct node* x=NULL;
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
      struct node *p,*t;
       int x,i=1;
      struct Queue q;
      create(&q,100);
      printf("Eneter root value ");
      scanf("%d",&x);
      bstarr[0]=x;
      root=(struct node *)malloc(sizeof(struct node));
      root->data=x;
      root->left=root->right=NULL;
      enqueue(&q,root);
      while(!isEmpty(q))
         {
             p=dequeue(&q);
             printf("enter left child of %d ",p->data);
             scanf("%d",&x);
             if(x!=-1)
                {
                    t=(struct node *)malloc(sizeof(struct node));
                    t->data=x;
                    bstarr[i++]=x;
                    t->left=t->right=NULL;
                    p->left=t;
                    enqueue(&q,t);
                 }
             printf("enter right child of %d ",p->data);
             scanf("%d",&x);
          if(x!=-1)
            {
                t=(struct node *)malloc(sizeof(struct node));
                t->data=x;
                bstarr[i++]=x;
                t->left=t->right=NULL;
               p->right=t;
               enqueue(&q,t);
            }
     }
}
int checkChildrenSum(struct node *root)
{
    int lsum=0,rsum=0;
    if(!root||(!(root->left)&&!(root->right)))
      return 1;
    if(root->left)
    lsum = root->left->data;
    if(root->right)
    rsum = root->right->data;
    return ((root->data == (lsum + rsum))&& checkChildrenSum(root->left)&& checkChildrenSum(root->right))? 1: 0;
}
int main()
{int i;
    printf("Input -1 if no element in left or right child\n");
    printf("Enter total nodes in your Tree: ");
    scanf("%d",&n);
    int bstarr[n];
    Treecreate(bstarr);
    printf("Stored tree is: ");
     for(i=0;i<n;i++)
      printf("%d ",bstarr[i]);
    checkChildrenSum(root)? printf("Given tree satisfies children sum property"):
     printf("Given tree not satisfies children sum property");
   return 0;
}

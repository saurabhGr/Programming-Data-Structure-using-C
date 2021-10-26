#include <stdio.h>
#include <stdlib.h>
int n,dist;
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
      printf("Eneter root value ");
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
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
struct Node *LCA(struct Node *root,int p,int q)
{
    if(!root)
        return root;
    if(root->data==p|| root->data==q)
        { dist++;
            return root;}
    struct Node *left=LCA(root->lchild,p,q);
    struct Node *right=LCA(root->rchild,p,q);
    if(left&&right)
        return root;
        if(left!=NULL||right!=NULL)
            dist++;
    return left?left:right;
}
int height(struct Node *temp,int p)
{
    if(!temp)
        return -1;
    if(temp->data==p)
        return 0;
   return 1+height(temp->lchild,p);
    return 1+height(temp->rchild,p);
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
printf("\nBinary Tree is Converted to BST\n");
printf("Inorder Traversal of BST is:  ");
Inorder(root);
int p,q;
do{
printf("Enter two Nodes to find their LCA.:");
scanf("%d%d",&p,&q);
struct Node *point=LCA(root,p,q);
printf("LCA of %d and %d is=%d and Distence is %d",p,q,point->data,dist);
dist=0;}while(1);
return 0;
}

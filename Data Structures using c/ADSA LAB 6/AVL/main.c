#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
void Insert(int key)
{
    struct Node *t=root;
    struct Node *r=NULL,*p;
    if(root==NULL)
     {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
     }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else  return;
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
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
int Postorder(struct Node *p)
{
    if(p)
    {  Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}
int Preorder(struct Node *p)
{
    if(p)
    {  printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

struct Node * Search(int key)
{
      struct Node *t=root;
      while(t!=NULL)
        {
           if(key==t->data)
               return t;
           else if(key<t->data)
                       t=t->lchild;
                else  t=t->rchild;
         }
return NULL;
}

int main()
{
struct Node *temp;
int n,tmp,i;
printf("Enter number of Nodes\n");
scanf("%d",&n);
printf("Enter elements to insert into AVL\n");
for(i=0;i<n;i++)
{
    scanf("%d",&tmp);
    Insert(tmp);
}

printf("Inorder Traversal of BST is:  ");
Inorder(root);
printf("\nPostorder Traversal of BST is: ");
Postorder(root);
printf("\nPreorder Traversal of BST is: ");
Preorder(root);
return 0;
}

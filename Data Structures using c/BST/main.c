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
int main()
{
struct Node *temp;
printf("\nEnter number of Node in Your tree: ");
int n,i,val;
scanf("%d",&n);
printf("\nEnter ur Elemnts: ");
for(i=0;i<n;i++)
{
    scanf("%d",&val);
    Insert(val);
}
printf("Inorder Traversal of BST is:  ");
Inorder(root);
printf("\nPostorder Traversal of BST is: ");
Postorder(root);
printf("\nPreorder Traversal of BST is: ");
Preorder(root);
printf("\n");
return 0;
}

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

int TraversalAscending(struct Node *p)
{
    if(p)
    {
        TraversalAscending(p->lchild);
        printf("%d ",p->data);
        TraversalAscending(p->rchild);
    }
}
int TraversalDescending(struct Node *p)
{
    if(p)
    {
        TraversalDescending(p->rchild);
        printf("%d ",p->data);
        TraversalDescending(p->lchild);
    }
}

int main()
{
Insert(50);
Insert(10);
Insert(40);
Insert(20);
Insert(30);
printf(" Ascending Order Traversal in BST is:  ");
TraversalAscending(root);
printf("\nDescending Order Traversal in BST is:  ");
TraversalDescending(root);
return 0;
}

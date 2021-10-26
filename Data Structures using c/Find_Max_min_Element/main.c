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

int MinEle(struct Node *p)
{
    if(p)
    { if(p->lchild==NULL)
           printf("%d ",p->data);
        MinEle(p->lchild);
    }
}
int MaxEle(struct Node *p)
{
    if(p)
    {   if(p->rchild==NULL)
            printf("%d ",p->data);
        MaxEle(p->rchild);
    }
}

int main()
{
Insert(20);
Insert(18);
Insert(15);
Insert(17);
Insert(23);
Insert(25);
Insert(12);
Insert(4);
printf("Minimum Element in BST is:  ");
MinEle(root);
printf("\nMaximum Element in BST is:  ");
MaxEle(root);
return 0;
}

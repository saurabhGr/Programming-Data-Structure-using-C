#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
int i,k,j;
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

int KSmallestEle(struct Node *p)
{
    if(p)
    {
        KSmallestEle(p->lchild);
         if(j++==k-1)
        printf("%d ",p->data);
        KSmallestEle(p->rchild);
    }
}
int KlargestEle(struct Node *p)
{
    if(p)
    {
        KlargestEle(p->rchild);
        if(i++==k-1)
        {printf("%d ",p->data);
        }
        KlargestEle(p->lchild);
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
Inorder(root);
printf("\nEnter Value of K: ");
scanf("%d",&k);
printf("\nK Smallest Element in BST is:  ");
KSmallestEle(root);
printf("\nK Largest Element in BST is:  ");
KlargestEle(root);
return 0;
}

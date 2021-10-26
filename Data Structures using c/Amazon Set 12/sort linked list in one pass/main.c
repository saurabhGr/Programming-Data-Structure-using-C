#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
struct node
{
int data;
struct node *next;
}*first=NULL,*last=NULL;
void create(int key)
{
struct node *t;
if(!first)
      {  t=(struct node *)malloc(sizeof(struct node));
          t->data=key;
          t->next=NULL;
           last=first=t;
       }
else
      {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=key;
        t->next=NULL;
        last->next=t;
        last=t;
      }
}
void Display(struct node *p)
{
        while(p)
         {
            printf("%d ",p->data);
            p=p->next;
         }
}
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
        else if(key>=t->data)
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
int main()
{
struct node *temp1;
int n,key,temp;
printf("Enter total number of Node to insert\n");
scanf("%d",&n);
temp=n;
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
printf("\nYour Stored Linked List is: ");
Display(first);
temp1=first;
while(temp1!=NULL)
{
    Insert(temp1->data);
    temp1=temp1->next ;
}
printf("\nSorted Linked List in One Pass is: ");
Inorder(root);
return 0;
}

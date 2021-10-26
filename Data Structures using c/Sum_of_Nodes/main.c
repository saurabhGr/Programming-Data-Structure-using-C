#include <stdio.h>
#include <stdlib.h>
int n,i,arr[100];
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

int insertArray(int key)
{
     printf("%d ",key);
    arr[i++]=key;
    return 0 ;
}
void Display()
{  int i;
    for(i=0;i<n;i++)
    printf("%d",arr[i]);
}
void ReadNode(struct Node *p)
{
    if(p)
    {
        ReadNode(p->lchild);
        insertArray(p->data);
        ReadNode(p->rchild);
    }
}
int main()
{
    int key,sum,j,k,temp;
    printf("Enter number of Node in your BST\n");
    scanf("%d",&n);
    temp=n;
    printf("Enter Nodes: \n");
    while(n>0)
    {
        scanf("%d",&key);
        n--;
        Insert(key);
    }
    ReadNode(root);
    printf("\nEnter sum to find as sum of Node\n");
    scanf("%d",&sum);
    Display();
    for(j=0;j<temp;j++)
    {
        for(k=j+1;k<temp;k++)
        {
            if(sum==(arr[j]+arr[k]))
            {
                printf("Yes, Sum is found  %d+%d",arr[j],arr[k]);
                return 0;
            }
        }
    }
    printf("Sum is not found\n");
return 0;
}

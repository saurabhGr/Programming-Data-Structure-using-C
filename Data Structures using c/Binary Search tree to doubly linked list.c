#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

void Insert(int key)
{
    struct node *t=root;
    struct node *r=NULL,*p;
    if(root==NULL)
     {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->left=p->right=NULL;
        root=p;
        return;
     }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->left;
        else if(key>t->data)
            t=t->right;
        else  return;
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->left=p->right=NULL;
    if(key<r->data) r->left=p;
    else r->right=p;
}
struct node *BTtoDLL(struct node *root)
{ if(root->left)
      {
          struct node *leftSubtree=BTtoDLL(root->left);
          for(;leftSubtree->right;leftSubtree=leftSubtree->right);
          leftSubtree->right=root;
          root->left=leftSubtree;
      }
    if(root->right)
    {
        struct node *rightSubtree=BTtoDLL(root->right);
        for(;rightSubtree->left;rightSubtree=rightSubtree->left);
        rightSubtree->left=root;
        root->right=rightSubtree;
    }
    return root;
}
void DisplayDLL(struct node *head)
{
    struct node *temp=head;
     while(temp->left)
	{
		temp = temp->left;
	}
	while(temp!=NULL)
    {printf("%d ", temp->data);
       temp=temp->right;}

}
int main()
{
struct node *head;
printf("Enter number of Node in Your tree: ");
int n,i,val;
scanf("%d",&n);
printf("\nEnter ur Elemnts: ");
for(i=0;i<n;i++)
{
    scanf("%d",&val);
    Insert(val);
}
head=BTtoDLL(root);
printf("\nSorted Doubly Linked list is: ");
DisplayDLL(head);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNewNode(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
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
    {printf("%d\t", temp->data);
       temp=temp->right;}

}

int main()
{
    struct node *root,*head;
	root = CreateNewNode(4);
	root->left = CreateNewNode(2);
	root->right = CreateNewNode(7);
	root->left->left = CreateNewNode(1);
	root->left->right = CreateNewNode(3);
	root->right->left = CreateNewNode(6);
	root->right->right=CreateNewNode(8);
	head=BTtoDLL(root);
	DisplayDLL(head);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int lsm,rsm;
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
int checkChildrenSum(struct node *root)
{
    int lsum = 0, rsum = 0;
    if(root)
       {   if((!(root->left) && !(root->right)))
            {root->data=0;
            printf("%d ",root->data);
           return 0;}
       }
       if(!root)
        return 0;
    if(root->left)
       lsum = root->left->data;
    if(root->right)
       rsum = root->right->data;
       checkChildrenSum(root->left);
       checkChildrenSum(root->right);
       root->data=lsum+rsum;
       printf("%d ",root->data);
       return 0;
}
int main()
{
    struct node *root,*head;
	root = CreateNewNode(50);
	root->left = CreateNewNode(30);
	root->right = CreateNewNode(20);
	root->left->left = CreateNewNode(12);
	root->left->right = CreateNewNode(5);
	root->right->left = CreateNewNode(2);
	checkChildrenSum(root);
	return 0;
}

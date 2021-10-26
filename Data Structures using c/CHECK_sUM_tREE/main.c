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
int checkChildrenSum(struct node *root)
{
    int lsum = 0, rsum = 0;
    if(!root || (!(root->left) && !(root->right)))
        return 1;
    if(root->left)
       lsum = root->left->data;
    if(root->right)
       rsum = root->right->data;
       return ((root->data == (lsum + rsum)) && checkChildrenSum(root->left) && checkChildrenSum(root->right))? 1: 0;
}
int main()
{  printf("50 30 20 12 5 2");
    struct node *root,*head;
	root = CreateNewNode(50);
	root->left = CreateNewNode(30);
	root->right = CreateNewNode(20);
	root->left->left = CreateNewNode(12);
	root->left->right = CreateNewNode(5);
	root->right->left = CreateNewNode(2);
	checkChildrenSum(root)? printf("\nGiven tree satisfies children sum property"): printf("\nGiven tree not satisfies children sum property");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node
{
int key;
int height;
struct Node *left;
struct Node *right;
};
int height(struct Node *temp)
{
    if(!temp)
        return 0;
    return temp->height;
}
int max(int a,int b)
{
    return a>b?a:b;
}
struct Node *newNode(int key)
{
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->key=key;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}
struct Node *leftrotate(struct Node *temp)
{
    struct Node *tmp1=temp->right;
    struct Node *tmp2=tmp1->left;
    tmp1->left=temp;
    temp->right=tmp2;
    temp->height=max(height(temp->left),height(temp->right))+1;
    tmp1->height=max(height(tmp1->left),height(tmp1->right))+1;
    return tmp1;
}
struct Node *rightrotate(struct Node *temp)
{
    struct Node *tmp1=temp->left;
    struct Node *tmp2=tmp1->right;
    tmp1->right=temp;
    temp->left=tmp2;
    temp->height=max(height(temp->left),height(temp->right))+1;
    tmp1->height=max(height(tmp1->left),height(tmp1->right))+1;
    return tmp1;
}
int balancefactor(struct Node *temp)
{
    if(!temp)
        return 0;
    return height(temp->left)-height(temp->right);
}
struct Node *insert(struct Node *temp,int key)
{
    if(!temp)
        return newNode(key);
    if(key<temp->key)
        temp->left=insert(temp->left,key);
   else if(key>temp->key)
        temp->right=insert(temp->right,key);
    temp->height=1+max(height(temp->left),height(temp->right));
    int bf=balancefactor(temp);
    if(bf>1&& key<temp->left->key)
        return rightrotate(temp);
    if(bf<-1&&key>temp->right->key)
        return leftrotate(temp);
    if(bf>1&&key>temp->right->key)
        {temp->left=leftrotate(temp->left);
    return rightrotate(temp);}
    if(bf<-1&& key<temp->right->key)
    {
        temp->right=rightrotate(temp->right);
        return leftrotate(temp);
    }
    return temp;
}
struct Node *minValueNode(struct Node *temp)
{
    struct Node *current=temp;
    while(current->left)
        current=current->left;
    return current;
}
struct Node *deleteNode(struct Node *temp,int key)
{
    if(temp==NULL)
        return temp;
    if(key<temp->key)
        temp->left=deleteNode(temp->left,key);
    else if(key>temp->key)
            temp->right=deleteNode(temp->right,key);
    else {
            if((temp->left==NULL)||(temp->right==NULL))
            { struct Node *tmp=temp->left?temp->left:temp->right;
            if(!tmp)
            {
                tmp=temp;
                temp=NULL;
            }
            else *temp=*tmp;
            free(tmp);
        }
        else{
            struct Node *tmp=minValueNode(temp->right);
            temp->key=tmp->key;
            temp->right=deleteNode(temp->right,tmp->key);
        }
    }
    if(!temp)
        return temp;
    temp->height=1+max(height(temp->left),height(temp->right));
    int bf=balancefactor(temp);
    if(bf>1&& balancefactor(temp->left)>=0)
        return rightrotate(temp);
    if(bf<-1&&balancefactor(temp->right)<=0)
        return leftrotate(temp);
    if(bf>1&&balancefactor(temp->left)<0)
        {temp->left=leftrotate(temp->left);
    return rightrotate(temp);}
    if(bf<-1&& balancefactor(temp->right)>0)
    {
        temp->right=rightrotate(temp->right);
        return leftrotate(temp);
    }
    return temp;
}
void preorder(struct Node *temp)
{
    if(temp)
    {
        printf("%d ",temp->key);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct Node *temp)
{
    if(temp)
    {
        inorder(temp->left);
        printf("%d ",temp->key);
        inorder(temp->right);
    }
}
void postorder(struct Node *temp)
{
    if(temp)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->key);
    }
}
int main()
{int ch,key;
struct Node *root=NULL;
    printf("This is an Implementation of AVL tree with various Opertions.\n");
    do
        { printf("Press 1- To Insert a Node in AVL\n");
           printf("Press 2- To Delete a Node from AVL\n");
           printf("Press 3- To view AVL in Inorder Traversal\n");
           printf("Press 4- To view AVL in Preorder Traversal\n");
           printf("Press 5- To view AVL in Postorder Traversal\n");
           printf("Press 6- To Exit\n");
           scanf("%d",&ch);
           switch(ch)
           {
               case 1: printf("Enter Key value to insert\n");
                            scanf("%d",&key);
                            root=insert(root,key);
                            break;
               case 2: printf("Enter key value to Delete\n");
                            scanf("%d",&key);
                            root=deleteNode(root,key);
                            break;
               case 3: printf("\nInorder Traversal is: ");
                            inorder(root);
                            break;
               case 4: printf("\nPreorder Traversal is: ");
                            preorder(root);
                            break;
               case 5: printf("\nPostorder Traversal is: ");
                            postorder(root);
                            break;
               default: printf("Thank you for Testing..Bye Bye\n");
           }
        } while(ch<6);
        return 0;
}

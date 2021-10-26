#include <stdio.h>
#include <stdlib.h>
struct BtreeNode
{
    int count ;
    int data[5] ;
    struct BtreeNode *child[5] ;
};
int FindNode(int val,struct BtreeNode *n,int *pos)
{
    if(val<n->data[1])
    {
        *pos=0;
        return 0;
    }
    else
    {
        *pos=n->count;
        while((val<n->data[*pos])&&*pos>1)
            (*pos )--;
        if(val==n->data[*pos])
            return 1;
        else return 0;
    }
}
void PutIntoNode(int val,struct BtreeNode *c,struct BtreeNode *n,int k)
{
    int i;
    for(i=n->count;i>k;i--)
    {
        n->data[i+1]=n->data[i];
        n->child[i+1]=n->child[i];
    }
    n->data[k+1]=val;
    n->child[k+1]=c;
    n->count++;
}
void SplittingNode(int val,struct BtreeNode *c,struct BtreeNode *n,int k,int *y,struct BtreeNode **newnode)
{
    int i,mid;
    if(k<=2)
      mid=2;
    else
      mid=2+1;
    *newnode=(struct BtreeNode *)malloc(sizeof(struct BtreeNode));
    for(i=mid+1;i<=4;i++)
    {
        (*newnode)->data[i-mid]=n->data[i];
        (*newnode)->child[i-mid]=n->child[i];
    }
    (*newnode)->count=4-mid;
    n->count=mid;
    if(k<=2)
        PutIntoNode(val,c,n,k);
    else
        PutIntoNode(val,c,*newnode,k - mid);
    *y=n->data[n->count];
    (*newnode)->child[0]=n->child[n->count];
    n->count--;
}
int setval(int val,struct BtreeNode *n,int *p,struct BtreeNode **c)
{
    int k;
    if(n==NULL)
    {
        *p=val;
        *c=NULL;
        return 1;
    }
    else
    {
        if(FindNode(val,n,&k))
            printf("\nKey value already exists.\n");
        if(setval(val,n->child[k],p,c))
        {
            if(n->count<4)
            {
                PutIntoNode(*p,*c,n,k);
                return 0;
            }
            else
            {
                SplittingNode(*p,*c,n,k,p,c);
                return 1;
            }
        }
        return 0;
    }
}
struct BtreeNode *InsertionBTree(int val,struct BtreeNode *root)
{
    int i;
    struct BtreeNode *c,*n;
    int flag;
    flag=setval(val,root,&i,&c);
    if(flag)
    {
        n=(struct BtreeNode *)malloc(sizeof(struct BtreeNode));
        n->count=1;
        n->data[1]=i;
        n->child[0]=root;
        n->child[1]=c;
        return n;
    }
    return root;
}

struct BtreeNode *search(int val,struct BtreeNode *root,int *pos)
{
    if (root==NULL)
        return NULL;
    else
    {
        if(FindNode(val,root,pos))
            return root;
        else return search(val,root->child[*pos],pos);
    }
}
void inorder(struct BtreeNode *root)
{
    int i;
    if(root!=NULL)
    {
        for(i=0;i<root->count;i++)
        {
            inorder(root->child[i]);
            printf("%d\t",root->data[i+1]);
        }
        inorder(root->child[i]);
    }
}
int main( )
{   int key;
printf ( "B-tree of order 5:\n" );
    struct BtreeNode *root=NULL;
    do
    { printf("\nEnter key to insert: ");
       scanf("%d",&key);
       root=InsertionBTree(key,root);
       inorder(root);
    } while(1);
    return 0;
}

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
void MergingNodes(struct BtreeNode *node,int k)
{
    int i;
    struct BtreeNode *temp1,*temp2;
    temp1=node->child[k];
    temp2=node->child[k-1];
    temp2->count++;
    temp2->data[temp2->count]=node->data[k];
    temp2->child[temp2->count]=node->child[0];
    for(i=1;i<=temp1->count;i++)
    {
        temp2->count++;
        temp2->data[temp2->count]=temp1->data[i];
        temp2->child[temp2->count]=temp1->child[i];
    }
    for (i =k;i<node->count;i++)
    {
        node->data[i]=node->data[i+1];
        node->child[i]=node->child[i+1];
    }
    node->count--;
    free(temp1);
}
void clear(struct BtreeNode *node,int k)
{
    int i;
    for(i=k+1;i<=node->count;i++)
    {
        node->data[i-1]=node->data[i];
        node->child[i-1]=node->child[i];
    }
    node->count--;
}
void SuccsseorVal(struct BtreeNode *node,int i)
{
    struct BtreeNode *temp;

    temp=node->child[i];
    while(temp->child[0])
        temp=temp->child[0];
    node->data[i]=temp->data[1];
}
void rightshift(struct BtreeNode *node,int k)
{
    int i;
    struct BtreeNode *temp;
    temp=node->child[k];
    for(i=temp->count;i>0;i-- )
    {
        temp->data[i+1]=temp->data[i];
        temp->child[i+1]=temp->child[i];
    }
    temp->child[1]=temp->child[0];
    temp->count++;
    temp->data[1]=node->data[k];
    temp=node->child[k-1];
    node->data[k]=temp->data[temp->count];
    node->child[k]->child[0]=temp->child[temp->count];
    temp->count--;
}
void leftshift(struct BtreeNode *node,int k)
{
    int i;
    struct BtreeNode *temp;
    temp=node->child[k-1];
    temp->count++;
    temp->data[temp->count]=node->data[k];
    temp->child[temp->count]=node->child[k]->child[0];
    temp=node->child[k];
    node->data[k]=temp->data[1];
    temp->child[0]=temp->child[1];
    temp->count--;
    for(i=1;i<=temp->count;i++)
    {
        temp->data[i]=temp->data[i+1];
        temp->child[i]=temp->child[i+1];
    }
}
void restore(struct BtreeNode *node,int i)
{
    if (i==0)
    {
        if(node->child[1]->count>2)
            leftshift(node,1);
        else
            MergingNodes(node,1);
    }
    else
    {
        if(i==node->count)
        {
            if(node->child[i-1]->count>2)
                rightshift(node,i);
            else
                MergingNodes(node,i);
        }
        else
        {
            if(node->child[i-1]->count>2)
                rightshift(node,i);
            else
            {
                if(node->child[i+1]->count>2)
                    leftshift(node,i+1);
                else
                    MergingNodes(node,i);
            }
        }
    }
}
int temp_delHelper(int val,struct BtreeNode *root)
{
    int i,flag;
    if(root==NULL)
        return 0;
    else
    {
        flag=FindNode(val,root,&i);
        if(flag)
        {
            if(root->child[i-1])
            {
                SuccsseorVal(root,i);
                flag=temp_delHelper(root->data[i],root->child[i]);
                if(!flag)
                    printf("\nValue %d not found.",val);
            }
            else
                clear(root,i);
        }
        else
            flag=temp_delHelper(val,root->child[i]);
        if(root->child[i]!=NULL)
        {
            if(root->child[i]->count<2)
                restore(root,i);
        }
        return flag;
    }
}
struct BtreeNode *Deletion_BTree(int val,struct BtreeNode *root)
{
    struct BtreeNode *temp;
    if(!temp_delHelper(val,root))
        printf("\nValue %d not found.",val);
    else
    {
        if(root->count==0)
        {
            temp=root;
            root=root->child[0];
            free(temp);
        }
    }
    return root;
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
void preorder(struct BtreeNode *root)
{
    int i;
    if(root!=NULL)
    {
        for(i=0;i<root->count;i++)
        {  printf("%d\t",root->data[i+1]);
            preorder(root->child[i]);
        }
        preorder(root->child[i]);
    }
}
int main()
{
    struct BtreeNode *root=NULL;
    int ch,key,n;
    printf ("B-tree of order 5:\n");
    do
    { printf("\nPress 1 to Insert a Value\tPress 2 to Delete a Value\n");
       printf("Press 3 to Traverse Inorder\tPress 4 for Preorder\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:printf("Enter number of keys to insert: ");
                       scanf("%d",&n);
                       printf("\nEnter %d keys to insert: ",n);
                       while(n>0)
                      { scanf("%d",&key);
                         root=InsertionBTree(key,root);
                         n--;}
                       break;
           case 2:printf("\nEnter Key to Delete: ");
                       scanf("%d",&key);
                       root=Deletion_BTree(key,root);
                       printf ( "\nB-Tree After deletion of Key value is:\n" );
                       inorder(root);
                       break;
            case 3:printf("B-Tree in Inorder Traversal is: ");
                      inorder(root);
                      break;
            case 4:printf("B-Tree in preorder Traversal is: ");
                      preorder(root);
                      break;
       }
    } while(ch<5);
    return 0;
}

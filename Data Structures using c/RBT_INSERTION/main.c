#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *p;
    struct Node *l;
    struct Node *r;
    int color;
}*root=NULL;
struct Node *NILL;
struct Node *insertion(struct Node *parent, struct Node *temp)
{ if(!parent)
     return temp;
   if(parent->data>temp->data)
   {
       parent->l=insertion(parent->l,temp);
       parent->l->p=parent;
   }
    else if(parent->data<temp->data)
    {
        parent->r=insertion(parent->r,temp);
        parent->r->p=parent;
    }
    return parent;
}
void leftrotate(struct Node *temp)
{
    struct Node *right=temp->r;
    temp->r=temp->l;
    if(temp->r)
        temp->r->p=temp;
    right->p=temp->p;
    if(!temp->p)
        root=right;
    else if (temp==temp->p->l)
        temp->p->l=right;
    else
        temp->p->r=right;
    right->l=temp;
    temp->p=right;
}
void rightrotate(struct Node* temp)
{
    struct Node *left=temp->l;
    temp->l=left->r;
    if(temp->l)
        temp->l->p=temp;
    left->p=temp->p;
    if(!temp->p)
        root=left;
    else if(temp==temp->p->l)
        temp->p->l=left;
    else
        temp->p->r=left;
    left->r=temp;
    temp->p=left;
}
void coloring_rearrange(struct Node *root, struct Node *temp)
{
    struct Node *parent=NULL;
    struct Node *gp=NULL;
    while((temp!=root)&&(temp->color!=0)&&(temp->p->color==1))
    {
        parent=temp->p;
        gp=temp->p->p;
        if(parent==gp->l)
        {
            struct Node *par_sib=gp->r;
            if(par_sib!=NULL && par_sib->color==1)
            {
                gp->color=1;
                parent->color=0;
                par_sib->color=0;
                temp=gp;
            }
            else {
                    if(temp==parent->r)
                    {
                        leftrotate(parent);
                        temp=parent;
                        parent=temp->p;
                    }
                   rightrotate(gp);
                   int temp_color=parent->color;
                   parent->color=gp->color;
                   gp->color=temp_color;
                   temp=parent;
            }
        }
    else {
        struct Node *par_sib=gp->l;
        if((par_sib!=NULL)&&(par_sib->color==1))
        {
            gp->color=1;
            parent->color=0;
            par_sib->color=0;
            parent=gp;
        }
        else {
            if(temp==parent->l)
            {
                rightrotate(parent);
                temp=parent;
                parent=temp->p;
            }
            leftrotate(gp);
            int temp_color=parent->color;
            parent->color=gp->color;
            gp->color=temp_color;
            temp=parent;
        }
    }
    }
    root->color=0;
}
void inorder(struct Node *root)
{
    if(!root)
    return;
    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}
void preorder(struct Node *root)
{
    if(!root)
    return;
    printf("%d ",root->data);
    preorder(root->l);
    preorder(root->r);
}
void postorder(struct Node *root)
{
    if(!root)
    return;
    postorder(root->l);
    postorder(root->r);
    printf("%d ",root->data);
}
void RBTtransform(struct Node *u, struct Node *v)
{
	if(u->p==NILL)
		root = v;
	else if(u == u->p->l)
		u->p->l = v;
	else u->p->r = v;
	v->p = u->p;
}
struct Node *tree_minimum(struct Node *temp)
{
	while(temp->l!=NILL)
		temp= temp->l;
	return temp;
}
void RBT_relocate(struct Node *x){
	struct Node *w;
	while(x != root && x->color == 0){
		if(x == x->p->l){
			w = x->p->r;
			if(w->color == 1){
				w->color = 0;
				x->p->color = 1;
				leftrotate(x->p);
				w = x->p->r;
			}
			if(w->l->color == 0 && w->r->color == 0){
				w->color = 1;
				x->p->color = 0;
				x = x->p;
			}
			else{
				if(w->r->color == 0){
					w->color = 1;
					w->l->color = 0;
					rightrotate(w);
					w = x->p->r;
				}
				w->color = x->p->color;
				x->p->color = 0;
				x->r->color = 0;
				leftrotate(x->p);
				x = root;
			}
		}
		else{
			w = x->p->l;
			if(w->color == 1){
				w->color = 0;
				x->p->color = 0;
				rightrotate(x->p);
				w = x->p->l;
			}
			if(w->l->color == 0 && w->r->color == 0){
				w->color = 1;
				x->p->color = 0;
				x = x->p;
			}
			else{
				if(w->l->color == 0){
					w->color = 1;
					w->r->color = 0;
					leftrotate(w);
					w = x->p->l;
				}
				w->color = x->p->color;
				x->p->color = 0;
				w->l->color = 0;
				rightrotate(x->p);
				x = root;
			}
		}
	}
	x->color = 0;
}
void RBTdelete(struct Node *temp)
{
	struct Node *x,*y;
	int ypreviousColor;
	y=temp;
	ypreviousColor=y->color;
	if(temp->l == NILL)
        {
		x = temp->r;
		RBTtransform(temp,temp->r);
	   }
	else if(temp->r == NILL){
		x = temp->l;
		RBTtransform(temp, temp->l);
	}
	else{
		y = tree_minimum(temp->r);
		ypreviousColor = y->color;
		x = y->r;
		if(y->p ==temp)
			x->p = y;
		else{
			RBTtransform(y, y->r);
			y->r =temp->r;
			y->r->p = y;
		}
		RBTtransform(temp, y);
		y->l = temp->l;
		y->l->p = y;
		y->color =temp->color;
	}
	if(ypreviousColor == 0)
		RBT_relocate(x);
}
struct Node *tree_search(int key){
	struct Node *x;
	x=root;
	while(x!=NILL && x->data!=key)
        {
		if(key<x->data)
			x=x->l;
		else
			x = x->r;
	   }
	return x;
}
int main()
{
    int ch,val,key;
    NILL=(struct Node *)malloc(sizeof(struct Node));
    NILL->color=0;
        printf("Press 1 to Insert Node in RBT\n");
        printf("Press 2 to Traverse in Inorder\n");
        printf("Press 3 to Traverse in Postorder\n");
        printf("Press 4 to Traverse in Preorder\n");
        printf("Press 5 to Delete a Node from RBT:\n");
    do
    {  printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter Value of Node to insert in RBT\n");
                         scanf("%d",&val);
                         struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
                         temp->r=NULL;
                         temp->l=NULL;
                         temp->p=NULL;
                         temp->data=val;
                         temp->color=1;
                         root=insertion(root,temp);
                         coloring_rearrange(root,temp);
                         break;
          case 2:  printf("\nInorder Traversal of RBT is: ");
                        inorder(root);
                        break;
          case 3:  printf("\nPostorder Traversal of RBT is: ");
                        postorder(root);
                        break;
          case 4:  printf("\nPreorder Traversal of RBT is: ");
                        preorder(root);
                        break;
          case 5: printf("\nEnter key node to Delete from RBT: ");
	                   scanf("%d", &key);
                       RBTdelete(tree_search(key));
                       printf("\nInorder Traversal of RBT is: ");
                       inorder(root);
                       break;
        }
    }while(ch<6);
    return 0;
}

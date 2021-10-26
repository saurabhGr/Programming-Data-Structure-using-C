void RBTtransform(struct Node *u, struct Node *v)
{
	if(u->p == NILL)
		root = v;
	else if(u == u->p->l)
		u->p->l = v;
	else u->p->r = v;
	v->p = u->p;
}
struct Node *tree_minimum(struct Node *temp){
	while(temp->l != NILL)
		temp= temp->l;
	return temp;
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
int n,val,i;
    scanf("%d",&n);
    printf("Enter %d nodes one after another: ",n);
    for(i=0;i<n;i++)
    {  scanf("%d",&val);
        struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
        temp->r=NULL;
        temp->l=NULL;
        temp->p=NULL;
        temp->data=val;
        temp->color=1;
        root=insertion(root,temp);
        coloring_rearrange(root,temp);
    }
    printf("\nPreorder Traversal of RBT is: ");
    preorder(root);
    printf("\nInorder Traversal of RBT is: ");
    inorder(root);
    printf("\nPostorder Traversal of RBT is: ");
    postorder(root);



struct node *tree_search(int key){
	struct node *x;
	x=root;
	while(x!=NULL && x->key!=key)
        {
		if(key<x->key)
			x=x->l;
		else
			x = x->r;
	   }
	return x;
}

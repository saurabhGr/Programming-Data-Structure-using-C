#include<stdio.h>
#include<malloc.h>
struct node
       {
         int n;
         int degree;
         struct node *parent;
         struct node *child;
         struct node *sibling;
       }*H=NULL;

struct node *createNode(int key)
  {
   struct node *temp;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->n=key;
   return temp;
 }

struct  node *mergeBinomialHeap(struct node *H1,struct node *H2)
{
  struct node *H=NULL;
  struct node *p1=H1,*p2=H2,*a,*b;
  if(p1)
  {
    if(p2&&p1->degree<=p2->degree)
      H=p1;
    else if(p2&&p1->degree>p2->degree)
      H=p2;
  else
      H=p1;
  }
 else
   H=p2;

while(p1&&p2)
 {
   if(p1->degree<p2->degree)
      p1=p1->sibling;
   else if(p1->degree==p2->degree)
      {
        a=p1->sibling;
        p1->sibling=p2;
        p1=a;
      }
   else
      {
        b=p2->sibling;
        p2->sibling=p1;
        p2=b;
      }
  }
  return H;
}

void merge_two_binomialTree_sameorder(struct node *root1,struct node *root2)
  {
    root1->parent=root2;
    root1->sibling=root2->child;
    root2->child=root1;
    root2->degree=root2->degree+1;
  }

struct node *unionBinomialHeap(struct node *H1,struct node *H2)
 {
   struct node *prev,*next,*temp,*newH=NULL;
   newH=mergeBinomialHeap(H1,H2);
   if(!newH)
    return newH;
   prev=NULL;
   temp=newH;
   next=temp->sibling;
   while(next!=NULL)
      {
        if((temp->degree!=next->degree)||((next->sibling!=NULL)&&(next->sibling)->degree==temp->degree))
        {
        prev=temp;
        temp=next;
        }
       else
        {
         if(temp->n<=next->n)
         {
           temp->sibling=next->sibling;
           merge_two_binomialTree_sameorder(next,temp);
         }
         else
         {
          if(prev==NULL)
             newH=next;
          else
             prev->sibling=next;
          merge_two_binomialTree_sameorder(temp,next);
          temp=next;
         }
     }
    next=temp->sibling;
   }
 return newH;
}

struct node *InsertionBinomialHeap(struct node *H, struct node *newNode )
{
    struct node *H1 =NULL;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->sibling = NULL;
    newNode->degree = 0;
    H1 = newNode;
    H = unionBinomialHeap(H, H1);
    return H;
}

int print(struct node *H)
{
    struct node *temp;
    if(!H)
      {
      printf("\nBinomial Heap is empty");
      return 0;
      }
      temp=H;
      printf("Roots are:\n");
    while(temp)
    {
      printf("%d",temp->n);
      if(temp->sibling)
      printf("-->");
      temp=temp->sibling;
    }
   printf("\n");
   return 0;
 }
int main()
{
    printf("Enter number of key value: ");
    int n,i,key;
    struct node *newNode;
    scanf("%d",&n);
    printf("\nEnter Elements in your Binomial heap: ");
     for(i=1;i<=n;i++)
     {
      scanf("%d",&key);
      newNode=createNode(key);
      H=InsertionBinomialHeap(H,newNode);
    }
    print(H);
    return 0;
}

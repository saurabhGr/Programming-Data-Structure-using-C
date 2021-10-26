#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
int i;
struct Node *t,*last;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}
}
void Display(struct Node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
int insert(struct Node *p,int key)
{
    struct Node *s,*temp;
    s=(struct Node *)malloc(sizeof(struct Node));
    s->data=key;
    s->next=NULL;
    while(p->next->data<s->data)
        p=p->next;
        temp=p->next;
        p->next=s;
        s->next=temp;
}
int main()
{
    printf("Enter total sorted Element to insert\n");
  int n,i,ele;
   scanf("%d",&n);
  int A[n];
  printf("Enter Element in sorted order\n");
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
   create(A,n);
   printf("Enter Element to Insert in Sorted LL\n");
   scanf("%d",&ele);
    insert(first,ele);
    Display(first);
return 0;
}

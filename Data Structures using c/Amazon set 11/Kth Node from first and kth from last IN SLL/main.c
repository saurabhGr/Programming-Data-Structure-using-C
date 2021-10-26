#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL,*last=NULL;
int len=1;
void create(int key)
{
struct Node *t;
if(!first)
      {  t=(struct Node *)malloc(sizeof(struct Node));
          t->data=key;
          t->next=NULL;
           last=first=t;
       }
else
      {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->next=NULL;
        last->next=t;
        last=t;
        len++;
      }
}
void Display(struct Node *p)
{
        while(p)
         {
            printf("%d ",p->data);
            p=p->next;
         }
}
void printnthNodeFromEnd(struct Node *p)
{ printf("\nEnter Index of Node to get Value from end and begining: ");
int nth,temp,nthbeg,temp2=1,exc;
struct Node *q=p;
    scanf("%d",&nth);
    nthbeg=nth;
    temp=(len-nth);
        while(temp-->0)
            p=p->next;
         while(temp2++<nthbeg)
            q=q->next;
        exc=p->data;
        p->data=q->data;
        q->data=exc;

}
int main()
{
int n,key,temp;
printf("Enter total number of Node to insert\n");
scanf("%d",&n);
temp=n;
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
printf("Stored Linked List is: ");
Display(first);
printnthNodeFromEnd(first);
printf("\nLinked List after swap kth nodes from both ends is: ");
Display(first);
return 0;
}

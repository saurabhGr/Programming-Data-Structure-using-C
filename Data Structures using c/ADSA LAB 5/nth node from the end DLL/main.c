#include <stdio.h>
#include <stdlib.h>
struct Node
{
struct Node *prev;
int data;
struct Node *next;
}*first=NULL,*last=NULL;
int len;
void create(int key)
{
struct Node *t;
if(!first)
      {  t=(struct Node *)malloc(sizeof(struct Node));
          t->data=key;
          t->next=NULL;
          t->prev=NULL;
           last=first=t;
           len++;
       }
else
      {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->next=NULL;
        t->prev=last;
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
{ printf("\nEnter Index of Node to get Value from end: ");
int nth,temp;
    scanf("%d",&nth);
    temp=nth;
        while(temp-->1)
            p=p->prev;
         printf("Value at index %d from End is %d ",nth,p->data);
}
int main()
{
int n,key,temp;
printf("Enter total number of Node to insert in DLL\n");
scanf("%d",&n);
temp=n;
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
printf("Stored Doubly Linked List is: ");
Display(first);
printnthNodeFromEnd(last);
return 0;
}

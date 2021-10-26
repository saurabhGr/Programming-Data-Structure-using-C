#include <stdio.h>
#include <stdlib.h>
struct Node
{
struct Node *prev;
int data;
struct Node *next;
}*first=NULL,*last=NULL;

void create(int key)
{
struct Node *t;
if(!first)
      {  t=(struct Node *)malloc(sizeof(struct Node));
          t->data=key;
          t->next=NULL;
          t->prev=NULL;
           last=first=t;
       }
else
      {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
      }
}
void SegregateEvenOdd(struct Node *p)
{
        while(p)
         { if(p->data%2==0)
            printf("%d ",p->data);
            p=p->next;
         }
         p=first;
         while(p)
         { if(p->data%2!=0)
            printf("%d ",p->data);
            p=p->next;
         }
}
int main()
{
int n,key;
printf("Enter total number of Node to insert in DLL\n");
scanf("%d",&n);
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
printf("\nSegregrated Odd and Even Nodes in Doubly Linked list: ");
SegregateEvenOdd(first);
return 0;
}

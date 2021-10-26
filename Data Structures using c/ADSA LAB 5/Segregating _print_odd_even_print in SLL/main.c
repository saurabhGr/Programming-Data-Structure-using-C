#include <stdio.h>
#include <stdlib.h>
struct Node
{
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
           last=first=t;
       }
else
      {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->next=NULL;
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
printf("Enter total number of Node to insert\n");
scanf("%d",&n);
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
printf("\nSegregrated Odd and Even Nodes in Linked list: ");
SegregateEvenOdd(first);
return 0;
}

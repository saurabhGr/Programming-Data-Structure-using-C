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
void Display(struct Node *p)
{
        while(p)
         {
            printf("%d ",p->data);
            p=p->next;
         }
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
printf("\nYour Stored Linked List is: ");
Display(first);
return 0;
}

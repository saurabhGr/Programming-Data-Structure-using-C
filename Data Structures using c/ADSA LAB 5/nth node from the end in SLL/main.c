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
{   printf("Stored Linked List is: ");
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
    temp=(len-nth);
        while(temp>0)
         {
            p=p->next;
            temp--;
         }
         printf("Value at index %d from End is %d ",nth,p->data);
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
Display(first);
printnthNodeFromEnd(first);
return 0;
}

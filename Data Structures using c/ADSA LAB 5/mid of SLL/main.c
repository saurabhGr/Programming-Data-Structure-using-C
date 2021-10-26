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
void findmiddle(struct Node *p)
{int temp;
        if(len%2!=0)
        temp=len/2;
    else temp=len/2;
    while(temp)
    {
        p=p->next;
        temp--;
    }
    printf("\nMid Element in this Linked List is %d ",p->data);
}
int main()
{
int n,key;
printf("Enter total number of Node to insert\n");
scanf("%d",&n);
printf("Enter Elements in Sorted Order\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
Display(first);
findmiddle(first);
return 0;
}

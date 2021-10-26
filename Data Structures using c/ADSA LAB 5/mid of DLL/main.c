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
    printf("\nMid Element in this Doubly Linked List is %d ",p->data);
}
int main()
{
int n,key;
printf("Enter total number of Node to insert in DLL\n");
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

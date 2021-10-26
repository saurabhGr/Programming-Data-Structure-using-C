#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL,*last=NULL;
int n;
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
int loop(struct Node *temp)
{
    struct Node *tp[n];
    int i;
    for(i=0;i<n;i++)
    {
        tp[i]=temp;
        temp=temp->next;
    }
    temp=first;
    for(i=0;i<n;i++)
    {
        if(last->next==tp[i])
        {printf("Yes, it has loop at %d element\n",last->next->data);
             return 0;}
    }
    return 0;
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
int key,temp,x;
struct Node *tmp;
printf("Enter total number of Node to insert\n");
scanf("%d",&n);
temp=n;
printf("Enter Elements\n");
while(temp>0)
    { scanf("%d",&key);
       create(key);
       temp--;
     }
     tmp=first;
printf("\nYour Stored Linked List is: ");
Display(first);
printf("\nEnter index of xth node to attach: ");
scanf("%d",&x);
if(x>0)
{
    while(n-(x++)>0)
    {
        tmp=tmp->next;
    }
    last->next=tmp;
loop(first);
}
else printf("Loop is not Found\n");
return 0;
}

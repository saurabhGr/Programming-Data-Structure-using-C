#include <stdio.h>
#include <stdlib.h>
struct Node
{
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
           last=first=t;
           len++;
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
{   printf("Linked List after swapping Nodes by changing Link is: ");
        while(p)
         {
            printf("%d ",p->data);
            p=p->next;
         }
}
void swappingNodesusingLink(struct Node *p)
{int a,b;
struct Node *temp1,*temp2,*temp3,*temp4,*temp5;
temp1=temp2=temp3=temp4=temp5=p;
    printf("Enter Elements to be Swapped: ");
    scanf("%d%d",&a,&b);
    temp3=temp1->next;
    while(temp1->data!=a)
           {  temp2=temp1;
               temp1=temp1->next;
               temp3=temp1->next;}
    while(temp4->data!=b)
    {
        temp5=temp4;
        temp4=temp4->next;
    }
    if( first!=temp1&&temp4->next==NULL)
    {
         temp1->next=NULL;
        temp5->next=temp1;
        temp2->next=temp4;
        temp4->next=temp3;
    }
    else if(first==temp1&&first->next==temp4&&temp4->next==NULL)
             {
                  temp4->next=temp1;
                   first=temp4;
                   temp1->next==NULL;
             }
   else if(first!=temp1&&temp4->next!=NULL)
            {
               temp1->next=temp4->next;
               temp5->next=temp1;
               temp2->next=temp4;
               temp4->next=temp3;
             }
   else  if(first==temp1&&temp4->next==NULL)
            {
              first=temp4;
              temp4->next=temp3;
              temp5->next=temp1;
              temp1->next=NULL;
             }
    else if(first==temp1&&first->next==temp4&&temp4->next!=NULL)
            {
                 temp1->next=temp4->next;
                 temp4->next=temp1;
                 first=temp4;
             }
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
swappingNodesusingLink(first);
Display(first);
return 0;
}

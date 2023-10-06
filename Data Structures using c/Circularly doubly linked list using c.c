#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
int n;
struct Node
{
struct Node *prev;
int data;
struct Node *next;
}*first=NULL;
struct Node *last;
void create(int A[],int n)
{
struct Node *t;
int i;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->prev=first->next=first;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->data=A[i];
t->prev=last;
last->next=t;
last=last->next;
}
if(last->next==NULL)
    {last->next=first;
    first->prev=last;}
}

int Display(struct Node *p)
{ printf("\nNewly created DLL is: ");
for(;p!=last;p=p->next)
{
   printf("%d ",p->data);
}
printf("%d ",p->data);
printf("\n");
return 0;
}

int Delete(int index)
{
struct Node *temp;
temp=first;
int x,i;
if(index==1)
{
      if(first->next)
       {
        first=first->next;
        last->next=first;
        first->prev=last;
        printf("hel");
        x=temp->data;
        free(temp);
        return x;
       }
}
else
{
for(i=0;i<index-1;i++)
temp=temp->next;
if(temp->next!=last->next)
{temp->next->prev=temp->prev;
temp->prev->next=temp->next;
 x=temp->data;
        free(temp);
        return x;
}
else if(temp->next==last->next)
      {  last=last->prev;
          temp->prev->next=temp->next;
         first->prev=last;
          x=temp->data;
          free(temp);
        return x;
        }
}
}
int main()
{
  printf("Enter total Element to insert\n");
  int i,index;
   scanf("%d",&n);
  int A[n];
  printf("Enter Elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
create(A,n);
Display(first);
printf("\nEnter index to Delete from DLL: ");
scanf("%d",&index);
printf("Deleted Element is %d \n",Delete(index));
Display(first);
return 0;
}

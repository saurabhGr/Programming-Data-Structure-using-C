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
int BinarySearchDLL(int key,int l,int h)
{
    struct Node *temp=first;
    int mid,t;
           mid=(l+h)/2;
           t=mid;
               while(t-->0)
            temp=temp->next;
            if(temp==NULL||l==h)
                return 0;
           else if(key==temp->data)
            return temp->data;
            else if(key>temp->data)
                      BinarySearchDLL(key,mid+1,len);
            else if(key<temp->data)
                      BinarySearchDLL(key,l,mid);
}

int main()
{
int n,key,search,temp;
printf("Enter total number of Node to insert in DLL\n");
scanf("%d",&n);
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
printf("Enter key to search\n");
scanf("%d",&search);
Display(first);
temp=BinarySearchDLL(search,1,len);
if(temp>0)
printf("\nYes key Found is: %d",temp);
else printf("\nSorry,Element not found\n");
return 0;
}


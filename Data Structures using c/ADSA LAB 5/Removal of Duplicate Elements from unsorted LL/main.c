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
void Display(struct Node *p)
{
        while(p)
         {
            printf("%d ",p->data);
            p=p->next;
         }
}
int FindDuplicateUnsorted(struct Node *q)
{ struct Node *p,*tmp,*del;
int count=0;
    while(q)
    { p=q->next;
       tmp=q;
        while(p)
         { if(q->data==p->data)
                {printf("\nDuplicate found %d\n",q->data);
                   del=p;
                  if(p->next==NULL)
                    {tmp->next=NULL;
                    p->next=NULL;
                    p->prev=NULL;
                    free(p);
                    }
                  else
                  {tmp->next=p->next;
                  p->next->prev=tmp;
                    p=tmp->next;
                    free(del);
                    }
                  count++;
                }
            else {p=p->next;
                       tmp=tmp->next;}
         }
         q=q->next;
    }
return count;
}
int FindDuplicateInSorted(struct Node *t)
{
    struct Node *p;
    int times=0;
    while(t)
    {
       if(t->next!=NULL)
       {
            p=t->next;
      if(p)
        {if(p->data==t->data)
           {
            printf("\nDuplicate Element is Found %d\n",t->data);
            if(p->next==NULL)
               {
                   t->next==NULL;
                   p->prev==NULL;
               }
           else{ t->next=p->next;
            p->next->prev=t;
            p->next=NULL;
            p->prev=NULL;}
            times++;
            free(p);
           }
           if(p->data<t->data)
           {
               printf("Caution!! Linked List is not Sorted\n");
               return -1;
           }
            }
       }
        t=t->next;
    }
    return times;
}

int main()
{
int n,key,ch,ct;
printf("Enter total number of Node to insert\n");
scanf("%d",&n);
printf("Enter Elements\n");
while(n>0)
    { scanf("%d",&key);
       create(key);
       n--;
     }
Display(first);
do
{
    printf("\nPress 1 for Finding Duplicate in Unsorted Linked List\n");
    printf("Press 2 for Finding Duplicate in Sorted Linked List\n");
    printf("Press 3 to Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:   if(FindDuplicateUnsorted(first)>0){}
                       else printf("\nHurreh, No Duplicate Found\n");
                       Display(first);
                       break;
         case 2:   ct=FindDuplicateInSorted(first);
                        Display(first);
                        if(ct>0){}
                          else if(ct==-1){}
                          else printf("\nHurreh, No Duplicate Found\n");
                        break;

    }
}while(ch<3);
return 0;
}

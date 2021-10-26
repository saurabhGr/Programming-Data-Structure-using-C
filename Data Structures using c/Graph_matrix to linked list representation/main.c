#include<stdio.h>
#include<stdlib.h>
struct node
  {
     int value;
     struct node *next;
  };
void main()
{
   int n,i,j;
   printf("Enter size of matrix: ");
   scanf("%d", &n);
   int arr[n][n];
   printf("\nEnter adjacency matrix :\n");
   for(i=0;i<n;i++)
       for(j=0;j<n;j++)
           scanf("%d",&arr[i][j]);
   struct node *head[1000]={NULL};
   struct node *t;
   struct node *temp;
   for(i=0;i<n;i++)
    {
       t=(struct node*)malloc(sizeof(struct node*));
       t->value=i+1;
       t->next=NULL;
       head[i]=t;
       for(j=0;j<n;j++)
         {
            if(arr[i][j]==1)
              {
                 t=(struct node*)malloc(sizeof(struct node*));
                 t->value=j+1;
                 t->next=NULL;
                 temp=head[i];
                 while(temp->next)
                     temp=temp->next;
                 temp->next=t;
              }
            }
        }
    printf("\nGraph:\n");
    for(i=0;i<n;i++)
        {
           temp=head[i];
           while(temp)
           {
                printf("%d -> ",temp->value);
                temp=temp->next;
            }
    printf("NULL\n");
         }
    printf("\n");
}

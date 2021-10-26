#include <stdio.h>
#include <stdlib.h>
struct Node
     {
        int data;
        struct Node *next;
    }*front=NULL,*rear=NULL;
void enqueue(int x)
    {
       struct Node *t;
       t=(struct Node*)malloc(sizeof(struct Node));
       if(t==NULL)
          printf("Queue is FULL\n");
       else
    {
       t->data=x;
       t->next=NULL;
       if(front==NULL)
          front=rear=t;
      else
        {
           rear->next=t;
           rear=t;
        }
     }
}
int dequeue()
    {
       int x=-1;
       struct Node* t;
        if(front==NULL)
          printf("Queue is Empty\n");
        else
    {
       x=front->data;
       t=front;
       front=front->next;
       free(t);
    }
return x;
}
int isEmpty()
   {
      return front==NULL;
      }

void BFS(int n,int G[][n],int start)
   {
      int i=start,j,x;
      int visited[n];
      for(x=0;x<n;x++)
        visited[x]=0;
       printf("%d ",i);
       visited[i]=1;
       enqueue(i);
       while(!isEmpty())
        {
           i=dequeue();
           for(j=1;j<n;j++)
             {
                if(G[i][j]==1 && visited[j]==0)
                 {
                    printf("%d ",j);
                    visited[j]=1;
                    enqueue(j);
                  }
              }
          }
     }
int main()
{  int n;
    printf("Enter number of nodes in Graph\n");
    scanf("%d",&n);
    int G[n][n];
    printf("Enter matrix\n");
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             scanf("%d",&G[i][j]);
    printf("Enter starting position: ");
    int start;
    scanf("%d",&start);
    printf("\nBFS traversal of graph G is:");
    BFS(n,G,start);
    return 0;
}

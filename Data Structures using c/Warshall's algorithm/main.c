#include<stdio.h>
#define MAX 65536
void warshall(int n, int cost[][n]);
int main()
  {
     int nodes, i, j;
     printf("Implementation of WARSHALL's ALGORITHM\n");
     printf("Enter no. of nodes in your graph: ");
     scanf("%d", &nodes);
     int graph[nodes][nodes],key;
     printf("For Infinity enter -1\n");
     printf("Enter weights of graph:\n");
     for(i=0;i<nodes;i++)
           for(j=0;j<nodes;j++)
              {scanf("%d",&key);
                 if(key==-1)
                     graph[i][j]=MAX;
                  else graph[i][j]=key;}
warshall(nodes,graph);
return 0;
}
void warshall(int n, int cost[][n])
{
       int i,j,k;
       // for loop used for k times to generate matrix number of node times
      for(k=0;k<n;k++)
         { // used for generating matrix
            for(i=0;i<n;i++)
               {
                  for(j=0;j<n;j++)
                     {
                        if(cost[i][k]+cost[k][j]<cost[i][j])
                           cost[i][j]=cost[i][k]+cost[k][j];
                      }
               }
          }
    printf("\nShortest path matrix:\n");
    for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++)
           {
              if(cost[i][j]==MAX)
                 printf("INFINITY\n");
              else printf("%d\t",cost[i][j]);
           }
           printf("\n");
         }
         printf("\n");
  }

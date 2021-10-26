#include <stdio.h>
#include <stdlib.h>
int vertices;
void DFS(int G[][vertices],int start,int n)
  {
      static int visited[7]={0};
      int j;
      if(visited[start]==0)
       {
         printf("%d ",start);
         visited[start]=1;
         for(j=1;j<n;j++)
           {
              if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
            }
         }
  }
int main()
{ int i,j;
   printf("Enter number of vertices: ");
   scanf("%d",&vertices);
   int G[vertices][vertices];
   printf("Enter matrix table\n");
   for(i=0;i<vertices;i++)
       for(j=0;j<vertices;j++)
          scanf("%d",&G[i][j]);
   int start;
   printf("\nEnter start position: ");
   scanf("%d",&start);
   DFS(G,start,vertices);
   return 0;
}


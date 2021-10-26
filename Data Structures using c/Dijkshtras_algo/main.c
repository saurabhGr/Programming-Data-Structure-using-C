#include<stdio.h>
#define MAX 65536
void dijkstra(int n, int cost[][n], int source);
int main()
{
   int n,i,j;
    printf("Implementation of DIJKSTRA's ALGORITHM\n\n");
    printf("Enter No. of nodes in your graph: ");
    scanf("%d",&n);
    int graph[n][n],t=0,key;
    printf("Enter weights of graph:\n");
    for(i=0;i<n;i++)
          for(j=0; j<n; j++)
             {
                 scanf("%d",&key);
                   if(key==0)
                       graph[i][j]=MAX;
                    else
                       graph[i][j]=key;
             }
    printf("\nEnter source vertices for Traversing in graph: ");
    scanf("%d",&t);
    dijkstra(n,graph,t);
    return 0;
}
void dijkstra(int n, int cost[][n], int source)
{
        int distence[n],parent[n],visit[n],i,j;
        for(i=0;i<n;i++)
            {
               distence[i]=cost[source][i];
               visit[i]=0;
               parent[i]=source;
             }
               distence[source]=0;
               visit[source]=1;
        int count=1,min,next;
        printf("\nUpdation of distence vector:\n");
        while(count<n-1)
        {
             min=MAX;
             for(i=0;i<n;i++)
                {
                   if(distence[i]<min&&!visit[i])
                      {
                         min=distence[i];
                         next=i;
                       }
                }
        visit[next]=1;
       for(i=0;i<n;i++)
            printf("%d ",distence[i]);
       printf("\n");
       for(i=0;i<n;i++)
            if(!visit[i])
            {
               if(min+cost[next][i]<distence[i])
                 {
                    distence[i]=min+cost[next][i];
                    parent[i]=next;
                 }
            }
        for(i=0;i<n;i++)
            printf("%d ",distence[i]);
        printf("\n");
        count++;
       }
       for(i=0;i<n;i++)
           {
              if(i!=source)
                printf("\nDistance from %d to %d is: %d",source,i,distence[i]);
           }
       printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
int Profit(int arr[], int p, int q)
{ int i,j;
    if(q<=p)
        return 0;
    int profit=0;
    for(i=p;i<q;i++) {
        for(j=i+1;j<=q;j++) {
            if(arr[j]>arr[i]) {
                int temp = arr[j]-arr[i] + Profit(arr,p,i-1) + Profit(arr,j+1,q);
                profit = max(profit, temp);
            }
        }
    }
    return profit;
}
int main()
{
    printf("Enter size of array of stocks Days:");
    int n,i,temp;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
      printf("%d ",Profit(arr,0,n-1));
    return 0;
}

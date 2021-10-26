#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,temp=-1;
    printf("Enter Size of Array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array element\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i]<arr[j] && i<n-1)
            { temp=arr[j];
                printf("%d ",temp);
                break;
            }
            if(i==n-1||j==n-1)
                 printf("-1 ");
            }

    }
    return 0;
}

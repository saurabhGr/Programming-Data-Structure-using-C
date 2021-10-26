#include <stdio.h>
#include <stdlib.h>
int power(int a,int b)
{  int i;
     long long int res=1;
    if(b==0)
        return 1;
    if(a==0)
        return 0;
    else {
        for(i=0;i<b;i++)
        res=res*a;
        return res;
             }
}
int main()
{int n,i,j,k,a,b,c;
    printf("Enter size of Array\n");
    scanf("%d",&n);
    printf("Enter Elements of Array\n");
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {  a=arr[i];
        for(j=0;j<n;j++)
           {
              b=arr[j];
              for(k=0;k<n;k++)
              {c=arr[k];
                  if(power(a,2)==power(b,2)+power(c,2))
                  {
                      printf("Yes\n");
                      return 0;
                  }
              }
           }

    }
    printf("No\n");
    return 0;
}

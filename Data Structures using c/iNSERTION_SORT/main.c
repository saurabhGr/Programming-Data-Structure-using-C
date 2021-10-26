#include <stdio.h>
int main()
{
int n,i,j,temp, key=0;
scanf("%d",&n);
int a[n];
for (i= 0; i<n; i++)
scanf("%d", &a[i]);
for (i=1 ; i<=n-1; i++)
{
     temp= a[i];
    for (j=i-1 ; j>= 0; j--)
        {
                 if (a[j] > temp)
                 {
                     a[j+1] =a[j];
                       key=1;
                 }
                else
                   break;
        }
           if (key)
           a[j+1] = temp;
 }
for (i= 0; i<n; i++)
{printf("%d\t",a[i]);}
return 0;
}

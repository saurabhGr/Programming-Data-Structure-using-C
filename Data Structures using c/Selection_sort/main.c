#include <stdio.h>
int n;
int a[100];
void selection_sort()
{
int i,j,key,sort;
for(i=0;i<n;i++)
{
sort=i;
for (j=i+1;j<n;j++)
{
if (a[j]<a[sort])
sort=j;
}
key=a[i];
a[i]=a[sort];
a[sort]=key;
}
}
int main()
{
int i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
selection_sort();
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}

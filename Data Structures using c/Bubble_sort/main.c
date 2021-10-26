#include <stdio.h>
void bubble_sort(int a[],int n) {
int i=0,j=0,tmp;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if (a[j]>a[j+1])
{
tmp=a[j];
a[j]=a[j+1];
a[j+1]=tmp;
}
}
}
}
int main() {
int n,i;
scanf("%d", &n);
int a[n];
for (i=0;i<n;i++)
scanf("%d",&a[i]);
bubble_sort(a,n);
for (i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}

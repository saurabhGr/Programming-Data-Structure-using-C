#include <stdio.h>
void swap(int *a, int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}
void quickSort(int a[], int f, int l) {
int i,j,pivot;
if(f<l)
{
pivot=f;
i=f;
j=l;
while(i<j)
{
while(a[i]<=a[pivot] && i<l)
i++;
while(a[j]>a[pivot])
j--;
if(i<j)
{
swap(&a[i],&a[j]);
}
}
swap(&a[pivot],&a[j]);
quickSort(a,f,j-1);
quickSort(a,j+1,l);
}
}
int main() {
int n,i;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quickSort(a,0,n-1);
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}

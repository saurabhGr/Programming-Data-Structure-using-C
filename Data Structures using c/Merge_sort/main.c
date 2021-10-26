#include <stdio.h>
void merge_sort(int i, int j, int a[], int b[]) {
int mid,left,right,k;
if(j<=i)
return;
mid=(i+j)/2;
merge_sort(i,mid,a,b);
merge_sort(mid+1,j,a,b);
left=i;
right=mid+1;
for (k=i;k<=j;k++) {
if (left==mid+1) {
b[k]=a[right++];
} else if(right==j+1) {
b[k]=a[left++];
} else if(a[left]<a[right]) {
b[k]=a[left++];
} else {
b[k]=a[right++];
}
}
for(k=i;k<=j;k++) {
a[k]=b[k];
}
}
int main() {
int n,i;
scanf("%d",&n);
int a[n],b[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
merge_sort(0,n-1,a,b);
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}

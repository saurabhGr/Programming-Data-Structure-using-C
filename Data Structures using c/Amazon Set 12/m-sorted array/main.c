#include <stdio.h>
#include <stdlib.h>
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
void Display(int arr[], int size)
{ int i;
   for (i=0; i <size; i++)
       printf("%d ",arr[i]);
}
int main()
{ int m,n,i,val;
    printf("Enter Number of arrays: ");
    scanf("%d",&m);
    printf("\nEnter Size of array: ");
    scanf("%d",&n);
    int t=m*n;
    int arr[t],brr[t];
    printf("Enter all the arrays element\n");
    for(i=0;i<t;i++)
    {
        scanf("%d",&val);
        arr[i]=val;
    }
    merge_sort(0,t-1,arr,brr);
    printf("All the Elements after Merging m array of n size are:\n");
    Display(arr,t);
    return 0;
}

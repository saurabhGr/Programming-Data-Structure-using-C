#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
      {
           int temp=*x;
                 *x=*y;
                 *y=temp;
        }
void Merge(int A[],int l,int mid,int h)
        {
           int i=l,j=mid+1,k=l;
           int B[100];
           while(i<=mid && j<=h)
                 {
                    if(A[i]<A[j])
                       B[k++]=A[i++];
                   else
                       B[k++]=A[j++];
                  }
                for(;i<=mid;i++)
                     B[k++]=A[i];
                for(;j<=h;j++)
                     B[k++]=A[j];
                for(i=l;i<=h;i++)
                     A[i]=B[i];
        }
void MergeSort(int A[],int l,int h)
       {
               int mid;
               if(l<h)
                 {
                    mid=(l+h)/2;
                    MergeSort(A,l,mid);
                    MergeSort(A,mid+1,h);
                    Merge(A,l,mid,h);
                 }
        }
int median(int a[],int n)
{
    if(n%2==0)
          printf("Array Median is %d\n",(a[(n-1)/2]+a[((n-1)/2)+1])/2);
       else printf("Array Median is %d\n",a[(n-1)/2]);
}
int main()
{   int n,m,i;
     printf("Enter size of two diff Array's\n");
     scanf("%d%d",&n,&m);
     int a[n],b[n];
     printf("Enter array 1 Elements\n");
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
      printf("Enter array 2 Elements\n");
     for(i=0;i<m;i++)
        scanf("%d",&b[i]);
       MergeSort(a,0,n);
       MergeSort(b,0,m);
       median(a,n);
       median(b,m);
return 0;
}

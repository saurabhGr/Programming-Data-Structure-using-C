#include <stdio.h>
#include <stdlib.h>
int getLargest(int arr[],int n)
{
    int i,largest;
    largest=arr[0];
    for(i=0;i<n;i++)
    {
        if(largest<arr[i])
        {
            largest=arr[i];
        }
    }
    return largest;
}
void RadixSort(int arr[],int n)
{
    int i,temp[100][100],n_digit=0,pass,temp_cnt[100];
    int largest,div=1,r,j,k;
    largest=getLargest(arr,n);
    while(largest>0)
    {
        n_digit++;
        largest/=10;
    }
    for(pass=0;pass<n_digit;pass++)
    {
        for(i=0;i<10;i++)
        {
            temp_cnt[i]=0;
        }
        for(i=0;i<n;i++)
        {
            r=(arr[i]/div)%10;
            temp[r][temp_cnt[r]]=arr[i];
            temp_cnt[r]+=1;
        }
        div*=10;
        i=0;
        for(j=0;j<10;j++)
        {
            for(k=0;k<temp_cnt[j];k++)
            {
                arr[i]=temp[j][k];
                i++;
            }
        }

    }

}
void CountSort(int arr[],int n)
{
int i,j,max,*C;
max=getLargest(arr,n);
C=(int *)malloc(sizeof(int)*(max+1));
for(i=0;i<max+1;i++)
{
C[i]=0;
}
for(i=0;i<n;i++)
{
C[arr[i]]++;
}
i=0;j=0;
while(j<max+1)
{
if(C[j]>0)
{
arr[i++]=j;
C[j]--;
}
else
j++;
}
}
void BucketSort(int arr[], int n)
{
 int i,j;
 int max=getLargest(arr,n);
 int temp[n];
 for(i=0;i<n;i++)
 {
  temp[i]=0;
 }
 for(i=0;i<n;i++)
 {
  (temp[arr[i]])++;
 }
 for(i=0,j=0;i<n;i++)
 {
  for(;temp[i]>0;(temp[i])--)
  {
   arr[j++] = i;
  }
 }
}
int main()
{ int n,i,ch;
   printf("Enter count of Number to be sorted:\n");
   scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        do
        {
             printf("\n\nMenu\n");
             printf("1.Radix Sort\n");
             printf("2.Counting Sort\n");
             printf("3.Bucket Sort\n");
             printf("4.Exit\n");
             printf("enter you choice ");
             scanf("%d",&ch);
             switch(ch)
                 {
                   case 1:RadixSort(arr,n);
                               for(i=0;i<n;i++)
                                   {
                                       printf("%d\t",arr[i]);
                                    }
                         break;
                   case 2:CountSort(arr,n);
                               for(i=0;i<n;i++)
                                   {
                                       printf("%d\t",arr[i]);
                                    }
                         break;
                   case 3:BucketSort(arr,n);
                               for(i=0;i<n;i++)
                                   {
                                       printf("%d\t",arr[i]);
                                    }
                         break;
                 }
        }while(ch<4);
    return 0;
}

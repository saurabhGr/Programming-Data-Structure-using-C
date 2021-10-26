#include <stdio.h>
#include <stdlib.h>
void Display(int arr[],int size,int n)
{ int i;
     printf("%d Iteration is: ",n);
     for(i=0;i<size;i++)
     printf("%d ",arr[i]);
     printf("\n");
}
int main()
{ int arr[]={5,3,8,9,16};
   int n,i,j,size=5,sum=0;
   printf("Enter how many times you want to iterate to find sum:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {  size--;
       for(j=0;j<size;j++)
       arr[j]=arr[j+1]-arr[j];
       Display(arr,size,i);
   }
   for(i=0;i<size;i++)
    sum=sum+arr[i];
   printf("Sum after nth Iteration is=%d",sum);
     return 0;
}

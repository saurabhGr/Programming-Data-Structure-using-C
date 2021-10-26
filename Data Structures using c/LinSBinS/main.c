#include <stdio.h>
#include <stdlib.h>
int n;
int LinSearch(int arr[],int key)
      {
          int i;
          for(i=0;i<n;i++)
          {
              if(arr[i]==key)
                return i;
          }
          return -1;
      }
int BinSearch(int arr[], int key)
{
    int l=0,mid,h=n;
        while(l<=h)
           {
               mid=(l+h)/2;
               if(key==arr[mid])
               return mid;
               else if(key<arr[mid])
                            h=mid-1;
                       else
                            l=mid+1;
            }
            return -1;
}

int main()
{
     int i,ch,key,index;
   printf("Enter size of Array:\n");
   scanf("%d",&n);
   printf("Enter all Elements seperated by Space\n");
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter Element you want to find\n");
        scanf("%d",&key);
        do
        {
             printf("\n\nMenu\n");
             printf("1.Linear Search\n");
             printf("2.Binary Search\n");
             printf("3.Exit\n");
             printf("enter you choice ");
             scanf("%d",&ch);
             switch(ch)
                 {
                   case 1:index=LinSearch(arr,key);
                                      if(index>=0)
                                        printf("\nElement Found at Index %d\n",index);
                                      else printf("\nError Element not Found\n");
                         break;
                   case 2:index=BinSearch(arr,key);
                                       if(index>=0)
                                       printf("\nElement Found at Index %d\t",index);
                                       else printf("\nError Element not Found\n");
                         break;
                 }
        }while(ch<3);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int n;
int coinchange(int arr[],int val)
{
    int count=0,rem,i;
    for(i=0;i<n;i++)
       if(val/arr[i]>0)
        {count =count + val/arr[i];
        val=val%arr[i];
        }
        if(val>0)
            {printf("Your Note can't be changed to coin.\n ");
            return -1;}
        else if(val==0)
               return count;
}
int main()
{printf("\nEnter diffrent coins in Number: ");
scanf("%d",&n);
  int arr[n],i,val,numberofcoin;
  printf("\nEnter coin's value in Decreasing Order: ");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nEnter Value of Your Note to convert.: ");
  scanf("%d",&val);
 numberofcoin=coinchange(arr,val);
 if(numberofcoin>0)
 printf("Number of coin you have to collect is: %d",numberofcoin);
    return 0;
}

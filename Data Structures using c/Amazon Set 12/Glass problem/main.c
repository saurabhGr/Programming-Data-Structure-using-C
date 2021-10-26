#include <stdio.h>
#include <stdlib.h>

int main()
{
int amt,n;
printf("\nEnter amount of Water you have: ");
scanf("%d",&amt);
printf("\nEnter number of Glass: ");
scanf("%d",&n);
int i,j;
float val;
for(i=1;i<n;i++)
{
    for(j=1;j<=i;j++)
    {
        if(amt/i>=1)
            amt--;
        if(amt/i<1&&amt!=0)
            {val=(float)amt/(float)i;
            printf("Jth glass in ith row contains: %f liter",val);
            amt=0;
              }
    }
}
return 0;
}

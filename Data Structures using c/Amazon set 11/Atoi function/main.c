#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int atooi(char arr[])
{
    int i,n,incr=0;
    n=strlen(arr);
    for(i=0;i<n;i++)
        if((int)arr[i]<=57&&(int)arr[i]>=48)
             incr++;
       if(incr==n)
            {for(i=0;i<n;i++)
                if((int)arr[i]<=57&&(int)arr[i]>=48)
                    printf("%d",(int)arr[i]-48);}
       else printf("-1");
}
int main()
{char arr[1000];
    printf("Enter Number String to convert to Number: ");
    scanf("%s",arr);
    atooi(arr);
    return 0;
}

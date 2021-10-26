#include <stdio.h>
#include <stdlib.h>
int arr[10],i,n;
void insertArray(int key)
{ printf("%d",key);
    arr[i++]=key;
}
void Display()
{  int j;
    for(j=0;j<n;j++)
    printf("%d",arr[j]);
}
int main()
{
    int m;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d",&m);
         insertArray(m);
         n--;
    }
       Display();
    return 0;
}

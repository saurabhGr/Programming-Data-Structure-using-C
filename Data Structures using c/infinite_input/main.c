#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[1000];
    int i = 0,n=0;
    printf("Enter any letter to stop:\n");
    printf("Enter infinte stream of data:\n");
    while(scanf("%d\n", &a[i]) == 1)
    i++;
        n=i;
        printf(" %d th element is %d",n,a[n-1]);
    return 0;
}

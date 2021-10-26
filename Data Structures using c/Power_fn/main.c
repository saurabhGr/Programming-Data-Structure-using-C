#include <stdio.h>
#include <stdlib.h>
long long int power(int a,int b)
{  int i;
     long long int res=1;
    if(b==0)
        return 1;
    if(a==0)
        return 0;
    else {
        for(i=0;i<b;i++)
        res=res*a;
        return res;
             }
}
int main()
{  int a,b;
    printf("Enter number and it's power\n");
    scanf("%d%d",&a,&b);
    printf("Output is %lld:\t",power(a,b));
    return 0;
}

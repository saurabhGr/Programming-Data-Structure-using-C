#include <stdio.h>
#include <stdlib.h>
int n;
int gcd(int x,int y)
{
    if (x==0)
       return y;
    if (y==0)
       return x;
    if (x==y)
        return x;
    if (x>y)
        return gcd(x-y,y);
    return gcd(x,y-x);
}
int coprime(int a, int b)
{
    if ( gcd(a,b) == 1)
        return a;
    else
        return -1;
}
int main()
{ int a[1000];
printf("Enter n value in Zn: ");
scanf("%d",&n);
int i,j=0,val=0;
for(i=0;i<n;i++)
        {
            if(coprime(i,n)>0)
            {
                a[j++]=coprime(i,n);
                val++;
            }
        }
printf("Set of Zn* in modular arithmetic for integers in Zn is: ");
for(i=0;i<val;i++)
{
    printf("%d ",a[i]);
}
    return 0;
}

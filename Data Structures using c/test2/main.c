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
int Extended_Euclidian(int key)
{
    int a=n,b=key,q,r,t1=0,t2=1,t;
    while(b>0)
    {
        q=a/b;
    r=a-q*b;
    a=b;b=r;
    t=t1-q*t2;
    t1=t2;t2=t;
    }
     if(a==1)
  {
    if(t1<0)
      t1+=n;
    return t1;
  }
}

int main()
{ int key;
    printf("Enter value of n and key:\n");
    scanf("%d%d",&n,&key);
    int inv_val;
    inv_val=Extended_Euclidian(key);
    printf("Inv_val=%d",inv_val);
    return 0;
}

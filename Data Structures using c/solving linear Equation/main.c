#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
{ int a=0,b=0,len,i;
char str[1000];
printf("Enter your equation in ax=b(mod n) form.\n");
scanf("%s",&str);
len=strlen(str);
for(i=0;i<len;i++)
{
    if(str[i]>=48&&str[i]<=57&&a==0)
        {a=(int)str[i]-48;
          i++;
          if(str[i]>=48&&str[i]<=57&&a!=0)
            a=a*10+(int)str[i]-48;
            }
   else if(str[i]>=48&&str[i]<=57&&a!=0&&b==0)
        {b=(int)str[i]-48;
        i++;
         if(str[i]>=48&&str[i]<=57&&a!=0&&b!=0)
            b=b*10+(int)str[i]-48;
        }
        else if(str[i]>=48&&str[i]<=57&&a!=0&&b!=0&&n==0)
                {n=str[i]-48;
                i++;
                if(str[i]>=48&&str[i]<=57&&a!=0&&b!=0&&n!=0)
                    n=n*10+str[i]-48;
                    }
}
int gcd_val,no_of_sol;
gcd_val=gcd(a,n);
printf(" GCD=%d ",gcd_val);
if(a%2==0&&b%2==0&&n%2==0)
{
    a=a/2; b=b/2; n=n/2;
}
if(a%3==0&&b%3==0&&n%3==0)
{
    a=a/3; b=b/3; n=n/3;
}
if(a%5==0&&b%5==0&&n%5==0)
{
    a=a/5; b=b/5; n=n/5;
}
printf("a=%d ,b=%d, n=%d ",a,b,n);
if(gcd_val%b==0||b%gcd_val==0)
    no_of_sol=gcd_val;
else no_of_sol=0;
if(no_of_sol>0)
    printf("\nNumber of solutions found is %d\n",gcd_val);
else {printf("\nNo solution found for this equation\n");
         exit(0);}
int inv_key,x0=0;
  inv_key=Extended_Euclidian(a);
  printf("\tInverse of a=%d",inv_key);
  printf("\nSolutions are: ");
  for(i=0;i<no_of_sol;i++)
  { if(x0==0)
      x0=(b*inv_key)%n;
      else x0=x0+n;
      printf("%d ",x0);
  }
    return 0;
}

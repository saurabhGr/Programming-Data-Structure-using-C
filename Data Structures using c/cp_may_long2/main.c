#include <stdio.h>
#include <stdlib.h>
int gcd(long long int a,long long int b)
{
    long long int q,r;
	while(b>0)
	{
		q=a/b; r=a-q*b;
		a=b; b=r;
	}
	return a;
}
int main()
{  long long int t,k,sum=0,i,j,a,b;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&k);
        for(j=1;j<=(2*k)+1;)
        {
            a=k+j*j;
            j++;
            if(j<=(2*k)+1)
            {b=k+j*j;
             sum=sum+gcd(a,b);
            }
        }
           printf("%d\n",sum);
    }
    return 0;
}

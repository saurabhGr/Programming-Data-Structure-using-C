#include<stdio.h>
int mod(int x,int y)
{
	int a,b;
	a=x/y;
	b=x-a*y;
	return b;
}
int gcd(int a,int b)
{
     int q,r;
	while(b>0)
	{
		q=a/b; r=a-q*b;
		a=b; b=r;
	}
	return a;
}

int inv(int x, int y)
{
    int i;
    for(i=0;i<y;i++)
        if((x*i)%y==1)
        break;
    return i;
}
double pow(int m,int e)
{
	double n=m;
	while(e--!=1)
		n=n*m;
	return n;
}
int primecheck(int a)
{ int i=2,ch=1,flag=1;
    while(i!=a&&ch==1)
	{
	  if(mod(a,i)==0)
	   {flag=0;
         ch==0;
          i++;
       }
	  else
	    i++;
    }
    return flag;
}
int chineseRemainderTheorem()
{
    int n,i,k,y=0,s;
    printf("Enter number of congruent equations\n");
    scanf("%d",&n);
    int a[n],m[n],M=1,Mk[n],Mkl[n];
    printf("Enter values of a,m\n");
    for(i=0;i<n;i++)
    {  k=i+1;
        printf("a%d mod m%d ",k,k);
        scanf("%d%d",&a[i],&m[i]);
    }
    for(i=0;i<n;i++)
        M=M*m[i];
        printf("M=%d\n",M);
    for(i=0;i<n;i++)
        {Mk[i]=M/m[i];
         k=i+1;
        printf("M%d=%d\t",k,Mk[i]);
        }
    for(i=0;i<n;i++)
    {
        Mkl[i]=inv(Mk[i],m[i]);
        k=i+1;
        printf("M%dinv=%d\t",k,Mkl[i]);
    }
    for(i=0;i<n;i++)
        y=y+a[i]*Mk[i]*Mkl[i];
        printf("y=%d\n",y);
    s=mod(y,M);
    printf("your solution x:= %d\n",s);
    return 0;
}
int publickey(int n)
{
    int e,y;
	printf("Enter the public key:");
	scanf("%d",&e);
	y=gcd(e,n);
	if(e<1||e>n||y>1)
	  printf("you entered wrong public key\n");
	else
	 return e;
}
int rsa()
{
    int pn,p,q,n,ch1,ch2,ch;
    int M,e,d;
    double b,c;
	printf("enter two large prime numbers :");
	scanf("%d%d",&p,&q);
	ch1=primecheck(p);
	ch2=primecheck(q);
	if(ch1==0||ch2==0)
		printf("number not prime");
	else
	{
	if(p==q)
	printf("Numbers should be different");
	else
	{
	n=p*q;
	pn=(p-1)*(q-1);
    e=publickey(pn);
    b=inv(pn,e);
	d=mod(b,pn);
	printf("Public key is ::(%d,%d)\n",e,n);
	printf("Private key is ::(%d,%d)\n",d,n);
	printf ("Enter message (M)::");
	scanf("%d",&M);
	printf("Enter 1.Encrypt\t2.Decrypt: ");
	scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		b=pow(M,e);
    		c=mod(b,n);
    		printf("\nCipher text is: %lf",c);
    	case 2:
		    b=pow(M,d);
    		c=mod(b,n);
    		printf("\nCipher text is: %lf",c);
		    break;
		default:
		printf("wrong choice");
	}
	}
    }
}
int main()
{  int ch;
    do
    {
        printf("\nEnter Your choice\n");
        printf("Press 1 for chinese remainder theorem\n");
        printf("Press 2 for RSA\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: chineseRemainderTheorem();
                         break;
            case 2: rsa();
                         break;
        }
    } while(ch<3);
	return 0;
}

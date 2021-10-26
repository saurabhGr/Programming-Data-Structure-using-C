#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int expmod(int a,int b,int n)
  {
         long long x=1,y=a;
         while(b>0)
            {
               if(b%2==1)
                  x=(x*y)%n;
                  y=(y*y)%n;
                  b=b/2;
              }
return x%n;
  }
int mi(int a,int m)
    { int x;
        a=fmod(a, m);
        for(x=1;x<m;x++)
           {
              if(fmod(a*x,m)==1)
                return x;
              }
      }
int primitiveroot(int e1,int p)
  {
     int i,j,temp,arr[p];
     for(i=1;i<p;i++)
        arr[i] = expmod(e1, i, p);
     for(i=0;i<p;i++)
       {
          temp = arr[i];
          for(j=i+1;j<p;j++)
                if(arr[j]==temp)
                    return 0;
          }
      return 1;
  }
void encryption(int e1,int e2,int p)
  {
     int r,plaintext,c1,c2;
     printf("Enter your Plain Text : ");
     scanf("%d",&plaintext);
     printf("Enter value of r used for Encryption : ");
     scanf("%d",&r);
     while(mi(p,r)>=p)
        {printf("Invalid Value of r\nEnter a Valid value : ");
         scanf("%d",&r);}
     c1=expmod(e1,r,p);
     c2=plaintext*expmod(e2,r,p);
     printf("Ciphertext is:\nC1=%d\nC2=%d",c1,c2);
     }
void decryption(int d,int p)
    {
       int c1, c2, cy;
        printf("Enter Ciphertext to Decrypt:\n");
        printf("C1=");
        scanf("%d",&c1);
        printf("C2=");
        scanf("%d",&c2);
        c1=pow(c1,d);
        c1=mi(c1,p);
        cy=c2*c1;
        cy=fmod(cy,p);
        printf("The Decrypted PlainText is : %d",cy);
    }
    void ElGammel()
    {
         int p,d,e1,e2,ch;
     printf("Enter the Prime No. To be used for key Generation : ");
     scanf("%d",&p);
     printf("Enter a value of d (1 to %d) : ",p-2);
     scanf("%d",&d);
     while(mi(p,d)>=p)
       {
           printf("Invalid Value of d\nEnter a Valid value : ");
           scanf("%d", &d);
           }
     printf("Enter a value for e1 :");
     scanf("%d",&e1);
     while(primitiveroot(e1,p)!=1)
        {
            printf("Invalid Value of e1\nEnter a valid Value :");
            scanf("%d",&e1);
           }
      e2=expmod(e1,d,p);
      printf("Public Key Is : (%d, %d, %d)\n",e1,e2,p);
      printf("Private Key Is : %d\n",d);
     while(1)
       {
          printf("Enter your choice:\n1. Encryption\n2. Decryption\n 3.EXIT\n");
          scanf("%d", &ch);
          switch (ch)
             {
               case 1: encryption(e1, e2, p);
                            printf("\n");
                            break;
               case 2: decryption(d, p);
                            printf("\n");
                            break;
               case 3: exit(0);
               }
         }
    }
int primiroot(double alpha,double p)
   {
      int i,j,temp;
      double arr[(int)p];
      for(i=1;i<p;i++)
         arr[i]=expmod((int)alpha, (int)i, (int)p);
      for(i=0;i<p;i++)
        {
           temp=arr[i];
      for(j=i+1;j<p;j++)
           if(arr[j]==temp)
              return 0;
        }
     return 1;
    }
void deffiHellmann()
{
    double p,alpha,x1,x2,y1,y2,k1,k2;
     printf("Enter Prime Number used for Key Generation: ");
     scanf("%lf",&p);
     printf("Enter Value of alpha: ");
     scanf("%lf",&alpha);
     while(primiroot(alpha,p)!=1)
         {
            printf("Invalid Value of alpha\nEnter a valid Value: ");
            scanf("%lf",&alpha);
          }
     printf("\nKey Generation For User 1\n");
     printf("Enter a Random Integer Less than alpha(%d): ",(int)alpha);
     scanf("%lf",&x1);
     y1=expmod(alpha,x1,p);
     printf("\nKey Generation For User 2\n\n");
     printf("Enter a Random Integer Less than alpha(%d): ",(int)alpha);
     scanf("%lf",&x2);
     y2=expmod(alpha,x2,p);
     printf("\nUser 1 has %d private key and  %d Public key.\n",(int)x1,(int)y1);
     k2=expmod(y1,x2,p);
     printf("User 2 has %d private key and  %d Public key.\n",(int)x2,(int) y2);
     k1=expmod(y2,x1,p);
     printf("User 1 calculates the Key as : %d\n",(int)k1);
     printf("User 2 calculates the Key as : %d\n",(int)k2);
   }
void main()
  { int ch;
   do
    {printf("Enter your choice\n");
      printf("Press 1 for ElGammel\n");
      printf("Press 2 for DeffiHellmann Key Exchange\n");
      printf("Press 3 to Exit.\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: ElGammel();
                       break;
          case 2: deffiHellmann();
                       break;
          case 3: exit(0);
                      break;
      }
    }while(ch<4);
   }

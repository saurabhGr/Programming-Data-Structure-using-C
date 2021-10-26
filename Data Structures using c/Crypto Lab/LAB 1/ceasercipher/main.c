#include <stdio.h>
#include<string.h>
void ceaserEncryption(char ch[],int len)
{ int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)(ch[i]+3-97))%26+65);
      printf("\nEncrypted string: %s\n",ch);
}
void ceaserDecryption(char ch[],int len)
{
    int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)(ch[i]-3-65))%26+97);
      printf("\nDecrypted string: %s\n",ch);
}
void AddiEncryption(char ch[],int key,int len)
{ int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)(ch[i]+key-97))%26+65);
      printf("\nEncrypted string: %s\n",ch);
}
void AddiDecryption(char ch[],int key,int len)
{
    int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)(ch[i]-key-65))%26+97);
      printf("\nDecrypted string: %s\n",ch);
}
void MultiEncryption(char ch[],int key,int len)
{ int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)((ch[i]-97)*key)%26+65));
      printf("\nEncrypted string: %s\n",ch);
}
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

int check(int key,int mulKey[])
{ int i;
    for(i=0;i<26;i++)
        {
            mulKey[i]=coprime(i,26);
        }
    for(i=0;i<26;i++)
    {
        if(key==mulKey[i])
            return 1;
    }
    return 0;
}
int Extended_Euclidian(int key)
{
    int a=26,b=key,q,r,t1=0,t2=1,t;
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
      t1+=26;
    return t1;
  }
}
void MultiDecryption(char ch[],int temp,int len)
{ int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)((ch[i]-65)*temp)%26+97));
      printf("\nDecrypted string: %s\n",ch);
}
int main()
{
   int x,len,key,temp=0,mulKey[26],i;
   char str[1000];
   printf("\nEnter a string:\t");
   gets(str);
   len=strlen(str);
   do{
            printf("\n..||Menu||..\n");
            printf("Press 1 to Ceaser cipher Encrypt the string.\n");
            printf("Press 2 to Ceaser cipher Decrypt the string.\n");
            printf("Press 3 to Additive Encrypt the string.\n");
            printf("Press 4 to Additive Decrypt the string.\n");
            printf("Press 5 to Multiplicative Encrypt the string.\n");
            printf("Press 6 to Multiplicative Decrypt the String.\n");
            printf("Press 7 to Exit\n");
            scanf("%d", &x);
            switch(x)
               {case 1: ceaserEncryption(str,len);
                               break;
                 case 2: ceaserDecryption(str,len);
                               break;
                 case 3:  printf("Enter Key\n");
                               scanf("%d",&key);
                               AddiEncryption(str,key,len);
                               break;
                 case 4: AddiDecryption(str,key,len);
                               break;
                case 5:   printf("Enter Key\n");
                               scanf("%d",&key);
                              if(check(key,mulKey))
                              MultiEncryption(str,key,len);
                              else printf("Key is not coprime");
                              break;

                case 6: temp=Extended_Euclidian(key);
                             MultiDecryption(str,temp,len);
                break;
               }
   }while(x<7);
   return 0;
}

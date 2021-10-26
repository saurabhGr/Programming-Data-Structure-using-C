#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
char cipher[1000];
char vigciph[1000],keygen[100],keycopy[1000];
char key[5][5],keyminus[25],keystr[10],str[25]={0};
char alpa[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int t=0;
void AffineEncryption(char ch[],int key1,int key2,int len)
{ int i;
      for(i = 0; i<len; i++)
        ch[i] = (char)(((int)(((ch[i]-97)*key1)+key2))%26+65);
      printf("\nEncrypted string: %s\n",ch);
}
void AffineDecryption(char ch[],int temp,int key2,int len)
{ int i,x,y;
      for(i = 0; i<len; i++)
        if(((int)((ch[i]-65)-key2))<0)
      {
          x=((ch[i]-65)-key2);
          y=26+x;
          ch[i] = (char)(((int)(y*temp)%26+97));
      }
       else ch[i] = (char)(((int)(((ch[i]-65)-key2)*temp)%26+97));
      printf("\nDecrypted string: %s\n",ch);
}

void Encryptionplayfair(char ch1,char ch2, char key[5][5])
{
 int i,j,w,x,y,z;
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
   if(ch1==key[i][j])
   {
    w=i;
    x=j;
   }
   else if(ch2==key[i][j])
   {
    y=i;
    z=j;
   }
  }
 }
 if(w==y)
 {
  x=(x+1)%5;
  z=(z+1)%5;
  printf(" %c%c ",key[w][x],key[y][z]);
  cipher[t++]=key[w][x];
  cipher[t++]=key[y][z];
 }
 else if(x==z)
 {
  w=(w+1)%5;
  y=(y+1)%5;
  printf(" %c%c ",key[w][x],key[y][z]);
  cipher[t++]=key[w][x];
  cipher[t++]=key[y][z];
 }
 else
 {
  printf(" %c%c ",key[w][z],key[y][x]);
  cipher[t++]=key[w][z];
  cipher[t++]=key[y][x];
  }
}

void Decryptionplayfair(char ch1,char ch2, char key[5][5])
{
 int i,j,w,x,y,z;
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
   if(ch1==key[i][j])
   {
    w=i;
    x=j;
   }
   else if(ch2==key[i][j])
   {
    y=i;
    z=j;
   }
  }
 }
 if(w==y)
 {
  x=(x-1)%5;
  if(x==-1)
    x=4;
  z=(z-1)%5;
  if(z==-1)
    z=4;
  printf("%c%c ",key[w][x],key[y][z]);
 }
 else if(x==z)
 {
  w=(w-1)%5;
  if(w==-1)
    w=4;
  y=(y-1)%5;
  if(y==-1)
    y=4;
  printf(" %c%c ",key[w][x],key[y][z]);
 }
 else
 {
  printf(" %c%c ",key[w][z],key[y][x]);
  }
}

void VignereEncryption(char strin[],char keycopy[])
{ int i;
    for(i=0;i<strlen(strin);i++)
        vigciph[i]=(char)(((int)(strin[i]+keycopy[i]))%26+65);
        printf("%s",vigciph);
}
void VignereDecryption(char strin[],char keycopy[])
{
    int i,x,y;
    for(i=0;i<strlen(strin);i++)
    {
        if((strin[i]-keycopy[i])<0)
           {
               x=strin[i]-keycopy[i];
               y=26+x;
               vigciph[i]=(char)(((int)(y))%26+65);
           }
        else vigciph[i]=(char)(((int)(strin[i]-keycopy[i]))%26+65);
}
printf("%s",vigciph);
}
void createVignere(char strin[])
{
int lenstrin,lenkey,i;
printf("Enter Key to Encrypt or Decrypt\n");
scanf("%s",keygen);
lenstrin=strlen(strin);
for(i=0;i<lenstrin;i++)
    strin[i]=toupper(strin[i]);
lenkey=strlen(keygen);
for(i=0;i<lenkey;i++)
    keygen[i]=toupper(keygen[i]);
for(i=0;i<lenstrin;i++)
    keycopy[i]=keygen[i%lenkey];
}

void Matrixcreation(char strin[])
{
     int i,j,k=0,m=0,n;
  n=strlen(keystr);

  for (i=0; i<n; i++)
   {
    if(keystr[i]=='j')
        keystr[i]='i';
    else if(keystr[i]=='J')
                keystr[i]='I';
    keystr[i]=toupper(keystr[i]);
   }

  for (i=0; i<strlen(strin); i++)
   {
    if(strin[i]=='j')
        strin[i]='i';
    else if(strin[i]=='J')
    strin[i]='I';
    strin[i] = toupper(strin[i]);
   }
  j=0;
  for(i=0;i<26;i++)
  {
   for(k=0;k<n;k++)
   {
    if(keystr[k]==alpa[i])
    break;
    else if(alpa[i]=='J')
    break;
   }
   if(k==n)
   {
    keyminus[j]=alpa[i];
    j++;
   }
  }
  k=0;
  for(i=0;i<5;i++)
  {
   for(j=0;j<5;j++)
    {
     if(k<n)
     {
     key[i][j]=keystr[k];
     k++;}
     else
     {
      key[i][j]=keyminus[m];
      m++;
      }
      printf("%c ",key[i][j]);
    }
    printf("\n");
  }

  printf("\nEntered text :%s\nCipher Text :",strin);
  for(i=0;i<strlen(strin);i++)
  {
   if(strin[i]=='J')
    strin[i]='I';
   if(strin[i+1]=='\0')
    Encryptionplayfair(strin[i],'X',key);
   else
   {
    if(strin[i+1]=='J')
        strin[i+1]='I';
    if(strin[i]==strin[i+1])
     Encryptionplayfair(strin[i],'X',key);
    else
    {
     Encryptionplayfair(strin[i],strin[i+1],key);
     i++;
    }
   }
  }
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

int main()
{
   int x,len,key1,key2,temp=0,mulKey[26],ci=0;
   char strin[1000];
   printf("\nEnter a string  to Encrypt or Decrypt:\t");
   gets(strin);
   do{
            printf("\n..||Menu||..\n");
            printf("Press 1 to Encrypt the string using Affine cipher.\n");
            printf("Press 2 to Decrypt the string using Affine cipher.\n");
            printf("Press 3 to Encrypt the string using PlayFair cipher \n");
            printf("Press 4 to Decrypt the string using PlayFair cipher \n");
            printf("Press 5 to Encrypt the string using Vigenere cipher \n");
            printf("Press 6 to Decrypt the string using Vigenere cipher \n");
            printf("Press 7 to Encrypt the string using Hill cipher \n");
            printf("Press 8 to Decrypt the string using Hill cipher \n");
            printf("Press 9 to Exit\n");
            scanf("%d", &x);
            switch(x)
               {
                 case 1: len=strlen(strin);
                               printf("Enter Keys\n");
                               scanf("%d%d",&key1,&key2);
                               if(check(key1,mulKey))
                               AffineEncryption(strin,key1,key2,len);
                               else  printf("Key is not coprime");
                               break;
                case 2:   len=strlen(strin);
                               printf("Enter Keys\n");
                               scanf("%d%d",&key1,&key2);
                              if(check(key1,mulKey))
                              {
                                  temp=Extended_Euclidian(key1);
                                  printf("%d",temp);
                                  AffineDecryption(strin,temp,key2,len);}
                             else  printf("Key is not coprime");
                             break;
               case 3:  printf("\nEnter the Key:");
                            scanf("%s",keystr);
                            Matrixcreation(strin);
                            break;
               case 4: for(ci=0;ci<strlen(cipher);ci++)
                               {
                                    Decryptionplayfair(cipher[ci],cipher[ci+1],key);
                                     ci++;
                                }
                                break;
               case 5:  createVignere(strin);
                             VignereEncryption(strin,keycopy);
                               break;
               case 6:  createVignere(strin);
                             VignereDecryption(strin,keycopy);
                             break;
               case 7:
                           break;
               case 8:
                           break;
               }
   }while(x<9);
   return 0;
}

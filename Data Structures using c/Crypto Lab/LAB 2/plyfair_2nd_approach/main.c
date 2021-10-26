#include<stdio.h>
#include<string.h>
#include<ctype.h>
char cipher[1000];
int t=0;
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
  printf("%c%c",key[w][x],key[y][z]);
 }
 else if(x==z)
 {
  w=(w-1)%5;
  if(w==-1)
    w=4;
  y=(y-1)%5;
  if(y==-1)
    y=4;
  printf("%c%c",key[w][x],key[y][z]);
 }
 else
 {
  printf("%c%c",key[w][z],key[y][x]);
  }
}
void main()
 {
  int i,j,k=0,l,m=0,n,ci=0;
  char key[5][5],keyminus[25],keystr[10],str[25]={0};
char alpa[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  printf("\nEnter key:");
   gets(keystr);
  printf("\nEnter the plain text:");
    gets(str);
  n=strlen(keystr);

  for (i=0; i<n; i++)
   {
    if(keystr[i]=='j')
        keystr[i]='i';
    else if(keystr[i]=='J')
                keystr[i]='I';
    keystr[i]=toupper(keystr[i]);
   }

  for (i=0; i<strlen(str); i++)
   {
    if(str[i]=='j')
        str[i]='i';
    else if(str[i]=='J')
    str[i]='I';
    str[i] = toupper(str[i]);
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

  printf("\nEntered text :%s\nCipher Text :",str);
  for(i=0;i<strlen(str);i++)
  {
   if(str[i]=='J')
    str[i]='I';
   if(str[i+1]=='\0')
    Encryptionplayfair(str[i],'X',key);
   else
   {
    if(str[i+1]=='J')
        str[i+1]='I';
    if(str[i]==str[i+1])
     Encryptionplayfair(str[i],'X',key);
    else
    {
     Encryptionplayfair(str[i],str[i+1],key);
     i++;
    }
   }
  }
  printf("\nDecrypted Plaintext is:");
  for(ci=0;ci<strlen(cipher);ci++)
  {
     Decryptionplayfair(cipher[ci],cipher[ci+1],key);
     ci++;
   }
 }

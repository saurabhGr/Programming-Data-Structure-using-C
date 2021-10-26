#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
char vigciph[1000];
void VignereEncryption(char strin[],char keycopy[],int n)
{ int i;
    for(i=0;i<n;i++)
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
int main()
{char strin[1000],keygen[100],keycopy[1000];
int lenstrin,lenkey,i;
printf("Enter String to Encrypt or Decrypt\n");
scanf("%s",strin);
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
VignereEncryption(strin,keycopy,lenstrin);
printf("\n");
VignereDecryption(vigciph,keycopy);
return 0;
}

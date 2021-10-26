#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
char plaintext[1000],ciphertext[1000],temp1[500],temp2[500],keyedstr[1000],keyedEnc[1000],comstr[1000];
char combinedcrypted[1000],combinedPlaintext[1000],mid[1000];
int len,len1,len2,len3,len4;
void RailFenceEncryptionRbyR()
         {
             int i,j,k;
             for(i=1,j=0;i<len;i+=2,j++)
                temp1[j]=plaintext[i];
             for(i=0,j=0;i<len;i+=2,j++)
                temp2[j]=plaintext[i];
                len1=strlen(temp1);
                len2=strlen(temp2);
             for(i=0,k=0;i<len1;i++)
                 ciphertext[k++]=temp2[i];
             for(i=len1,j=0;i<len;i++)
                 ciphertext[k++]=temp1[j++];
         }
void RailFenceDecryption()
{int x,y,len3,i,j,k;
  len3=strlen(ciphertext);
  y=len3;
  if(len3%2==0)
    x=len3/2;
  else x=(len3/2)+1;
  for(i=0,k=0;i<x;i++)
  temp1[i]=ciphertext[k++];
  for(i=x,j=0;i<y;i++)
  temp2[j++]=ciphertext[k++];
  for(i=0,j=0,k=0;i<len3;)
  {
      plaintext[i++]=temp1[j++];
      plaintext[i++]=temp2[k++];
  }
}
void encryptMsg(char msg[], int key)
{
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];

    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for(i = 0; i < msgLen; ++i)
        {
        railMatrix[row][col++] = msg[i];
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
        }
    printf("\nEncrypted Message: ");
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] != '\n')
                printf("%c", railMatrix[i][j]);
}

void decryptMsg(char enMsg[], int key)
{
    int msgLen = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
    for(i = 0; i < msgLen; ++i)
        {
        railMatrix[row][col++] = '*';
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];
    row = col = 0;
    k = -1;
    printf("\nDecrypted Message: ");
    for(i = 0; i < msgLen; ++i){
        printf("%c", railMatrix[row][col++]);
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
}
void keyedEncry(char keyedstr[],int keysize,int key[])
{  int t;
    for(t=0;t<strlen(keyedstr);t++)
        keyedstr[t]=toupper(keyedstr[t]);
    char temp[keysize];
    len3=strlen(keyedstr);
    int time=len3%keysize;
    if(time==0)
        time=len3/keysize;
    else time=(len3/keysize)+1;
    int i,j=0,k=0;
    while(time-->0)
    {
        for(i=0;i<keysize;i++)
        {  if(j>=len3)
                temp[i]='Z';
            else temp[i]=keyedstr[j++];
        }
        for(i=0;i<keysize;i++)
            keyedEnc[k++]=temp[key[i]];
    }
}
void keyedDec(int keysize,int key[])
{
    char temp[keysize];
    len4=strlen(keyedEnc);
    int time=len4%keysize;
    if(time==0)
        time=len4/keysize;
    else time=(len4/keysize)+1;
    int i,j=0,k=0;
        while(time-->0)
    {
        for(i=0;i<keysize;i++)
        { temp[i]=keyedEnc[j++];
           printf("%c",temp[i]);
        }
        printf("\n");
        for(i=0;i<keysize;i++)
            keyedstr[key[i]+k]=temp[i];
            k=k+keysize;
    }
}
void combinedEncr()
{
    int t;
   char msg[1000];
    int msgLen,i,k=0,j,keysize,height,count=0;
   if(strlen(mid)==0)
   { printf("Enter Your Message to Encrypt:");
       scanf("%s",msg);
   msgLen=strlen(msg);
   for(t=0;t<msgLen;t++)
        msg[t]=toupper(msg[t]);
   }
   else{
      for(t=0;t<strlen(mid);t++)
      {msg[t]=mid[t];
        msgLen=strlen(msg);}
   }
    printf("Enter Size of Key\n");
    scanf("%d",&keysize);
    char temp1[keysize];
    printf("Enter Block of keys\n");
    int val,keyed[keysize];
    for(i=0;i<keysize;i++)
            {scanf("%d",&val);
            keyed[i]=val-1;
            }
    height=msgLen%keysize;
    if(height==0)
        height=msgLen/keysize;
    else height=(msgLen/keysize)+1;
    char railMatrix[height][keysize];
    for(i = 0;i<height;++i)
        for(j = 0;j <keysize; ++j)
            { if(count>=msgLen)
                   railMatrix[i][j] ='Z' ;
                else railMatrix[i][j] =msg[k++];
                count++;}
   for(i = 0;i<height;++i)
        {
            for(j = 0;j <keysize; ++j)
            temp1[j]=railMatrix[i][j];
            keyedEncry(temp1,keysize,keyed);
            for(j = 0;j <keysize;++j)
                railMatrix[i][j]=keyedEnc[j];
        }
     printf("Your Intermediate state is:\n");
    for(i = 0;i<height;++i)
        {for(j = 0;j<keysize;++j)
        printf("%c ",railMatrix[i][j]);
        printf("\n");}
        k=0;
    for(j=0;j<keysize;++j)
        {for(i=0;i<height;++i)
        combinedcrypted[k++]=railMatrix[i][j];
        }
}
void combinedDecr(int keysize,int key[])
{
 int i,j,height,len,k=0;
    char temp1[keysize];
    len=strlen(combinedcrypted);
    height=len%keysize;
    if(height==0)
        height=len/keysize;
    else height=(len/keysize)+1;
    char railMatrix[height][keysize];
    for(j=0;j<keysize;++j)
        {for(i=0;i<height;++i)
        railMatrix[i][j]=combinedcrypted[k++];
        }
        printf("\nYour Intermediate state is:\n");
        k=0;
   for(i=0;i<height;++i)
        {
            for(j = 0;j <keysize; ++j)
            {
              temp1[j]=railMatrix[i][j];
              keyedEnc[j]=temp1[j];
              }
              keyedDec(keysize,key);
              for(j=0;j<keysize;++j)
                      combinedPlaintext[j+k]=keyedstr[j];
                  k=k+keysize;
            }
}
void DoubleTrasEncryption()
{     int i;
         combinedEncr();
          printf("\nYour Encrypted String is: ");
          printf("%s",combinedcrypted);
          for(i=0;i<strlen(combinedcrypted);i++)
           mid[i]=combinedcrypted[i];
           for(i=0;i<strlen(combinedcrypted);i++)
            combinedcrypted[i]='\0';
          combinedEncr();
            printf("%s",combinedcrypted);
}
int main()
{
int i,ch,ch1,ch2,ch3,ch4,ch5,keysized,val1;
int keyed[100];
    printf("Plz.Enter Plaintext in small and ciphertext in capital\n");
    do
    {
        printf("\nPress 1 for Rail Fence cipher\n");
        printf("Press 2 for Keyed Transposition Cipher\n");
        printf("Press 3 for Combining Two approaches\n");
        printf("Press 4 for Double Transposition Cipher\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: do
                       {
                           printf("Press 1 for Rail Fence cipher using Row by Row\n");
                           printf("Press 2 for Rail Fence Cipher using Column by Column\n");
                           printf("Press 3 to go to Previous section\n");
                           scanf("%d",&ch1);
                           switch(ch1)
                           {
                               case 1: do
                                           {
                                               printf("press 1 for Encryption\n");
                                               printf("Press 2 for Decryption\n");
                                               printf("Press 3 to go to previous section\n");
                                               scanf("%d",&ch2);
                                               switch(ch2)
                                               {
                                                   case 1: printf("Enter plaintext in lowercase to be Encrypted: ");
                                                                scanf("%s",plaintext);
                                                                len=strlen(plaintext);
                                                                for(i=0;i<len;i++)
                                                                    plaintext[i]=toupper(plaintext[i]);
                                                                    RailFenceEncryptionRbyR();
                                                              for(i=0;i<len/2;i++)
                                                              {
                                                                  printf("%c ",temp2[i]);
                                                              }
                                                              printf("\n");
                                                              for(i=0;i<len/2;i++)
                                                              {
                                                                  printf("%c ",temp1[i]);
                                                              }
                                                              printf("\n");
                                                                    printf("Generated cipher Text is: %s\n",ciphertext);
                                                                    break;
                                                  case 2: if(strlen(ciphertext)==0)
                                                               {printf("Enter Ciphertext in uppercase to Decrypt:  ");
                                                               scanf("%s",ciphertext);
                                                               RailFenceDecryption();
                                                               printf("Generated Plaintext  is: %s\n",plaintext);}
                                                               else
                                                               {RailFenceDecryption();
                                                               printf("Generated Plaintext  is: %s\n",plaintext);}
                                                               break;
                                               }
                                           }while(ch2<3);
                         }
                       }while(ch1<3);
        case 2: printf("You choose Keyed cipher\n");
                     do
                     {
                         printf("\nPress 1 for Keyed Encryption ");
                         printf("\nPress 2 for Keyed Decryption ");
                         printf("\nPress 3 to go back to Previous Menu ");
                         scanf("%d",&ch3);
                         switch(ch3)
                         {
                             case 1:printf("Enter your Message to Encrypt\n");
                                         scanf("%s",keyedstr);
                                         printf("Enter Key size\n");
                                          int keysize;
                                          scanf("%d",&keysize);
                                           printf("Enter Keys block\n");
                                        int val;
                                         for(i=0;i<keysize;i++)
                                            {scanf("%d",&val);
                                               keyed[i]=val-1;
                                                }
                                         keyedEncry(keyedstr,keysize,keyed);
                                         printf("\nYour cipher Text is: ");
                                         for(i=0;i<=len3;i++)
                                            printf("%c",keyedEnc[i]);
                                         break;
                            case 2:if(strlen(keyedEnc)==0)
                                         {printf("Enter ciphertext in capital to Decrypt\n");
                                         scanf("%s",keyedEnc);
                                         printf("Enter Key size\n");
                                         scanf("%d",&keysized);
                                          printf("Enter Keys block\n");
                                         for(i=0;i<keysized;i++)
                                            {scanf("%d",&val1);
                                               keyed[i]=val1-1;
                                                }
                                         keyedDec(keysized,keyed);
                                         printf("\nYour Plaintext is: ");
                                         for(i=0;i<=len4;i++)
                                            printf("%c",keyedstr[i]);
                                         }
                                         else{printf("Enter Key size\n");
                                                scanf("%d",&keysized);
                                                printf("Enter Keys block\n");
                                                 for(i=0;i<keysized;i++)
                                                     {scanf("%d",&val1);
                                                       keyed[i]=val1-1;
                                                       }
                                                keyedDec(keysized,keyed);
                                                printf("\nYour Plaintext is: ");
                                                 printf("%s",keyedstr);}
                                       break;
                         }
                     }while(ch3<3);
                case 3: printf("You choose combining Two Approach cipher\n");
                     do
                     {
                         printf("\nPress 1 for Combined Encryption ");
                         printf("\nPress 2 for Combined Decryption ");
                         printf("\nPress 3 to go back to Previous Menu ");
                         scanf("%d",&ch4);
                         switch(ch4)
                         {
                             case 1: combinedEncr();
                                         printf("\nYour Encrypted String is: ");
                                         printf("%s",combinedcrypted);
                                          break;
                            case 2: if(strlen(combinedcrypted)==0)
                                         {
                                         printf("Enter Your ciphertext to Decrypt\n");
                                         scanf("%s",combinedcrypted);
                                          }
                                          printf("Enter Key size\n");
                                          scanf("%d",&keysized);
                                          printf("Enter Keys block\n");
                                                 for(i=0;i<keysized;i++)
                                                     {scanf("%d",&val1);
                                                       keyed[i]=val1-1;
                                                       }
                                          combinedDecr(keysized,keyed);
                                          printf("\nYour converted Plaintext is: ");
                                          for(i=0;i<strlen(combinedPlaintext);i++)
                                                printf("%c",combinedPlaintext[i]);
                                      break;
                            }
                             }while(ch4<3);
                    case 4: printf("You choose Double Transposition cipher\n");
                     do
                     {
                         printf("\nPress 1 for Double Encryption ");
                         printf("\nPress 2 for Double Decryption ");
                         printf("\nPress 3 to go back to Previous Menu ");
                         scanf("%d",&ch5);
                         switch(ch5)
                         { case 1: DoubleTrasEncryption();
                                        break;
                            case 2: break;
                         }
                     }while(ch5<3);
        }
    }while(ch<5);
    return 0;
}

#include <stdio.h>
#include <string.h>
#define SIZE 100
void columnmajor_dec(char[]);
void columnmajor_enc(char str[])
{
    int i, j, k, m, n;
    char enc[SIZE];
    printf("Enter no. of rows : ");
    scanf("%d", &m);
    if(strlen(str)%m==0)
        n=strlen(str)/m;
    else
        n=strlen(str)/m+1;
    char msg[m][n];
    k = 0;
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            msg[i][j]=str[k];
            k++;
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%c ", msg[i][j]);
        }
        printf("\n");
    }
    k = 0;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            enc[k] = msg[i][j];
            k++;
        }
    }
    printf("Encrypted message : %s\n", enc);
    printf("Press 0 to decrypt it back, any other integer to continue : ");
    scanf("%d", &k);
    if(k==0)
        columnmajor_dec(enc);
}

void columnmajor_dec(char str[])
{
    int i, j, k, m, n;
    char dec[SIZE];
    printf("Enter no. of rows : ");
    scanf("%d", &m);
    if(strlen(str)%m==0)
        n=strlen(str)/m;
    else
        n=strlen(str)/m+1;
    char msg[m][n];
    k = 0;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            msg[i][j]=str[k];
            k++;
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%c ", msg[i][j]);
        }
        printf("\n");
    }
    k = 0;
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            dec[k] = msg[i][j];
            k++;
        }
    }
    printf("Decrypted message : %s\n", dec);
    printf("Press 0 to encrypt it back, any other integer to continue : ");
    scanf("%d", &k);
    if(k==0)
        columnmajor_enc(dec);
}
int main()
{
    int o,choice,ch = 1;
    char str[SIZE];
    while(ch){
        printf("1. Keyless Transposition\n");
        printf("Enter option no. : ");
        scanf("%d", &o);
        switch(o){
            case 1:
                printf("Enter the message(max 100 characters) : ");
                scanf("%s", str);
                printf("Enter your choice \n1. Row Major Encryption \n2. Row Major Decryption \n3. Column Major Encryption \n4. Column Major Decryption \nChoice no. : ");
                scanf("%d", &choice);
                if (choice==1)
                {
                    columnmajor_enc(str);
                }
                else if (choice==2)
                {
                    columnmajor_dec(str);
                }
        }
        printf("Press 0 to exit, any other integer to choose another algorithm : ");
        scanf("%d", &ch);
    }
    return 0;
}

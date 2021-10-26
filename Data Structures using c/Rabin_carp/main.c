#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_CHARS 256

void RabinKarpSearch(char *pat, char *txt, int prime)
{
    int pLen = strlen(pat);
    int tLen = strlen(txt);
    int tIndex, pIndex, hPat = 0, hTxt = 0, hash = 1;

    for(pIndex = 0; pIndex < pLen - 1; pIndex++)
        hash = (hash * NO_OF_CHARS) % prime;

    for(pIndex = 0; pIndex < pLen; pIndex++)
    {
        hPat = (NO_OF_CHARS * hPat + pat[pIndex]) % prime;
        hTxt = (NO_OF_CHARS * hTxt + txt[pIndex]) % prime;
    }

    for(tIndex = 0; tIndex <= tLen - pLen; tIndex++)
    {
        if( hPat == hTxt )
        {
            for(pIndex = 0; pIndex < pLen; pIndex++)
            {
                if(txt[tIndex + pIndex] != pat[pIndex])
                    break;
            }
            if(pIndex == pLen)
                printf("Pattern found at index %d \n", tIndex);
        }

        if ( tIndex < tLen - pLen )
        {
            hTxt = (NO_OF_CHARS * (hPat - txt[tIndex] * hash) +
                txt[tIndex + pLen]) % prime;
            if (hTxt < 0)
                hTxt = (hTxt + prime);
        }
    }
}


int main()
{
    char txt[100], pat[100];
    int prime;
    printf("Enter text string\n");
    scanf("%s", txt);
    printf("Enter pattern string\n");
    scanf("%s", pat);
    printf("Enter Prime Number\n");
    scanf("%d", &prime);
    RabinKarpSearch(pat, txt, prime);
    return 0;
}

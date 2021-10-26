#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPS(char *pat, int pLen, int *lps)
{
    int index = 1, len = 0;
    lps[0] = 0;
    while(index < pLen)
    {
        if(pat[index] == pat[len])
        {
            len++;
            lps[index++] = len;
        }
        else
        {
            if(len)
                len = lps[len-1];
            else
                lps[index++] = 0;
        }
    }
}

void PatternSearch(char *pat, char *txt)
{
    int pLen = strlen(pat);
    int tLen = strlen(txt);
    int lps[pLen], tIndex, pIndex;
    computeLPS(pat, pLen, lps);
    for(tIndex = 0, pIndex = 0; tIndex < tLen;)
    {
        if(pat[pIndex] == txt[tIndex])
        {
            pIndex++;
            tIndex++;
        }

        if(pIndex == pLen)
        {
            printf("Pattern Found at index %d \n", tIndex - pIndex);
            pIndex = lps[pIndex - 1];
        }
        else if(tIndex < tLen && pat[pIndex] != txt[tIndex])
        {
            if(pIndex)
                pIndex = lps[pIndex - 1];
            else
                tIndex += 1;
        }
    }
}

int main()
{
    char txt[100], pat[100];
    printf("Enter text string\n");
    scanf("%s", txt);
    printf("Enter pattern string\n");
    scanf("%s", pat);
    PatternSearch(pat, txt);
    return 0;
}

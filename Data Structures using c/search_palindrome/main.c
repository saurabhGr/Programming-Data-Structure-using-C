#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char str[1000];
    int i,j,k,len,flag,maxlen=1;
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            flag=1;
            for(k=0;k<(j-i+1)/2;k++)
            {
                if(str[i+k]!=str[j-k])
                    flag=0;
            }
            if(flag>0 && (j-i+1)>maxlen)
                maxlen=j-i+1;
        }
    }
    printf("%d",maxlen);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{  int l1=0,l2=0,i,j,count=0;
    char str1[1000],str2[10];
    gets(str1);
    gets(str2);
    l1=strlen(str1);
    l2=strlen(str2);
    for(i=0;i<=l1-l2;i++)
    {
        for(j=0;j<l2;j++)
            if(str1[i+j]!=str2[j])
                break;
        if(j==l2)
            count++;
    }
    printf("%d",count);
    return 0;
}

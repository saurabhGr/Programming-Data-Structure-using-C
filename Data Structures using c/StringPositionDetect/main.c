#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{  int l1=0,l2=0,i,k;
    char str1[1000],str2[10];
    gets(str1);
    gets(str2);
    l1=strlen(str1);
    l2=strlen(str2);
    k=l2-1;
    int index[l2];
    for(i=l1-1;i>=0;i--)
    {
        if(str2[k]==str1[i])
        {
            index[k]=i;
            k--;
        }
        if(k==-1)
           break;
    }
    if(k==-1)
    {
             for(i=0;i<l2;i++)
              printf("%d\t",index[i]);
    }
    return 0;
}

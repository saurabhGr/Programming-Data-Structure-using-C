#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void stringDifference(char *s1,char *s2,int l1,int l2)
{  int i,j,k;
    for(i=0;i<l2;i++)
    {
        for(j=0;j<l1;j++)
        {
            if(s2[i]==s1[j])
            {
                for(k=j;k<l1;k++)
                    s1[k]=s1[k+1];
                        l1--;
            }
        }
    }
}
void Display(int *s1)
{
        printf("%s",s1);
}
int main()
{
    int s1[10000],s2[10000],l1,l2;
    printf("Enter Strings to compare\nString One & String Two\n");
    gets(s1);
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    stringDifference(s1,s2,l1,l2);
    Display(s1);
    return 0;
}

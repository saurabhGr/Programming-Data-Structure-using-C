#include <stdio.h>
#include <string.h>
char result[1000];
void compress(char *str)
{ int i,j=0,times=1;
    for(i=0;i<strlen(str);)
    {
        while(str[i]==str[i+1])
           {times++;
               i++;}
        result[j++]=str[i++];
        if(times>1)
        result[j++]=times+48;
        times=1;
    }
}
int main()
{   char str[1000];
    printf("Enter Your String to Compress: ");
    scanf("%s",str);
    compress(str);
    printf("%s",result);
    return 0;
}

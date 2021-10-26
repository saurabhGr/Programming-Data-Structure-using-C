#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char ch[1000];
    int i,len;
    scanf("%s",&ch);
    len=strlen(ch);
    for(i=0;i<len;i+=2)
        printf("%c",ch[i]);
        printf("  ");
    for(i=1;i<len;i+=2)
        printf("%c",ch[i]);
    return 0;
}

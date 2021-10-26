#include<stdio.h>
int n=16;
int mod(int key)
{
    if(key<0)
    {while(key<0)
        key=key+n;
        return key;}
    else if(key>n)
    {
        while(key>=n)
            key=key-n;
        return key;
    }
     else if(key<n&&key>0)
        return key;
}
int main()
{ int key;
scanf("%d",&n);
    while(1)
    {printf("Enter mod and key\n");
    scanf("%d",&key);
    printf("%d",mod(key));}
    return 0;
}

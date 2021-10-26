#include <stdio.h>
#include <stdlib.h>
struct array
{
int key;
int count;
};
int linearSearch(int key,int n,struct array arr[])
{ int i;
    for(i=0;i<n;i++)
    {
        if(key==arr[i].key)
            return i;
    }
    return -1;
}
int findmax(struct array arr[],int n)
{ int i,max;
max=arr[0].count;
    for(i=0;i<n;i++)
    {
        if(max<arr[i].count)
            max=arr[i].count;
    }
    return max;
}
int main()
{  int n,key,i;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    struct array arr[n];
    int temp;
    printf("Enter keys in your array.\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&key);
        if(linearSearch(key,i,arr)>=0)
        { temp=linearSearch(key,i,arr);
            arr[temp].count=arr[temp].count+1;
            arr[i].key=-1;
            arr[i].count=0;
        }
        else {
            arr[i].key=key;
            arr[i].count=1;
        }
    }
    printf("Maximum frequent numbers are:\n");
    for(i=0;i<n;i++)
    { if(arr[i].count>1)
        printf("key=%d\t count=%d\n",arr[i].key,arr[i].count);
    }
    return 0;
}

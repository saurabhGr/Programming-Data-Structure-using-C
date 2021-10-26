#include <stdio.h>
#include <stdlib.h>
int key,arr[100][100];
int search(int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
          for(j=0;j<n;j++)
    {
        if(key==arr[i][j])
            {printf("%d found at %d col %d row\n",key,i,j);
                   }
        else if(key<arr[i][j])
                break;
    }
}
void Display(int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
        printf("%d ",arr[i][j]);
        printf("\n");
        }
}
int main()
{ int m,n,i,j;
printf("Enter size of 2D array\nEnter m and n value: ");
scanf("%d%d",&m,&n);
for(i=0;i<m;i++)
    for(j=0;j<n;j++)
         scanf("%d",&arr[i][j]);
    printf("Enter Element to search: ");
    scanf("%d",&key);
         search(m,n);
         Display(m,n);
    return 0;
}

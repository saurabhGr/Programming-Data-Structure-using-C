#include <stdio.h>
#include <stdlib.h>
int main()
{int i,j,row,col,count=0;
int arr[10][10];
printf("Enter size of Rows and column in your Matrix\n ");
scanf("%d%d",&row,&col);
printf("Enter elements of your matrix coloumn wise\n");
for(i=0;i<row;i++)
{
    for(j=0;j<col;j++)
    {
        scanf("%d",&arr[i][j]);
        if(arr[i][j]==0)
            count++;
    }
}
    if(count>(row*col)/2)
        printf("\n This is a Sparse Matrix\n");
    else printf("\n Not a Sparse Matrix");
return 0;
}

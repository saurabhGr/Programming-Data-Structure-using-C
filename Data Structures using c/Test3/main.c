#include<stdio.h>
int n;
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
int Extended_Euclidian(int key)
{
    int a=n,b=key,q,r,t1=0,t2=1,t;
    while(b>0)
    {
        q=a/b;
    r=a-q*b;
    a=b;b=r;
    t=t1-q*t2;
    t1=t2;t2=t;
    }
     if(a==1)
  {
    if(t1<0)
      t1+=n;
    return t1;
  }
}
int main()
{
  int a[3][3],i,j,b[3][3],c[3][3];
  int determinant=0;
  printf("Enter the 9 elements of matrix: ");
  for(i=0;i<3;i++)
      for(j=0;j<3;j++)
           scanf("%d",&a[i][j]);
  printf("\nThe matrix is\n");
  for(i=0;i<3;i++){
      printf("\n");
      for(j=0;j<3;j++)
           printf("%d ",a[i][j]);
  }

  for(i=0;i<3;i++)
      determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
 printf("\n Determinent of matrix is %d",determinant);
 printf("\nEnter value of mod\n");
scanf("%d",&n);
int modu_det=mod(determinant);
int modu_det_inv;
printf("\nModular Determinent of matrix is %d",modu_det);
modu_det_inv=Extended_Euclidian(modu_det);
printf("\nInverse of Determinent is %d",modu_det_inv);
   printf("\nInverse of matrix is: \n\n");
   for(i=0;i<3;i++)
      for(j=0;j<3;j++)
           b[i][j]=mod(modu_det_inv*((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3])));
    printf("Inverse Matrix of Matrix is:\n");
    for(j=0;j<3;j++)
      for(i=0;i<3;i++)
        c[j][i]=b[i][j];
      for(i=0;i<3;i++)
      {for(j=0;j<3;j++)
        printf("%d ",c[i][j]);
        printf("\n");}
   return 0;
}

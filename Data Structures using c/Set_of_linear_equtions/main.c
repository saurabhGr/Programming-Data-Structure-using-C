#include <stdio.h>
#include <stdlib.h>
int a[3][3],b[3][3],c[3][3],n,F[3][1];
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
int inverse()
{  int determinant=0;
    int i, j;
    for(i=0;i<3;i++)
      determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
    if ( determinant == 0)
    {printf("\nMatrix is NOT invertible\n");
     return 0;}
    else{
  printf("The matrix is\n");
  for(i=0;i<3;i++)
    {
      printf("\n");
      for(j=0;j<3;j++)
           printf("%d ",a[i][j]);}
 printf("\nDeterminent of matrix is %d",determinant);
int modu_det=mod(determinant);
int modu_det_inv;
printf("\nModular Determinent of matrix is %d",modu_det);
modu_det_inv=Extended_Euclidian(modu_det);
printf("\nInverse of Determinent is %d",modu_det_inv);
   printf("\nInverse of matrix is: \n");
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
    return 1;}
}
int main()
{ int i,j,m[3][1];
    printf("It is for set of 3 Linear Equations\n");
    printf("Enter Value of mod n: ");
    scanf("%d",&n);
    printf("Enter values of a1,b1,c1,a2,b2,c2,a3,b3,c3: ");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
              {scanf("%d",&a[i][j]);
                 c[i][j] = a[i][j];}
    printf("\nEnter Values of m1,m2,m3: ");
    for(i=0;i<3;i++)
        for(j=0;j<1;j++)
              scanf("%d",&m[i][j]);
    for(i=0;i<3;i++)
       {
           for(j=0;j<3;j++)
            printf("%d ",a[i][j] );
            printf("\n");
       }
        inverse();
      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
      {
          F[i][0]=F[i][0]+m[j][0]*c[i][j];
      }
      printf("Values of x,y,z is:\n");
      for(i=0;i<3;i++)
       {
           for(j=0;j<1;j++)
              {   F[i][j]=mod(F[i][j]);
                  if(i==0)
                     printf("x=%dmod%d",F[i][j],n);
                  else if(i==1)
                    printf("y=%dmod%d",F[i][j],n);
                  else if(i==2)
                    printf("z=%dmod%d",F[i][j],n);
              }
              printf("\n");
       }
    return 0;
}

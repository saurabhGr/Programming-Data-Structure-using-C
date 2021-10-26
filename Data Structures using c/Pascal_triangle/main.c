#include <stdio.h>
#include <stdlib.h>
pascal(int i , int j){
  if(i<0||j<0) return 0;
  if(i==0 &&j==0) return 1;
  if(i==0 && j!=0) return 0;
  return pascal(i-1,j-1)+pascal(i-1,j);
}
int main()
{   int i,j;
    printf("Input ith and jth index to know pascal traingle value: ");
    scanf("%d%d",&i,&j);
    printf("\n%dth row and %dth col value is %d.",i,j,pascal(i,j));
    return 0;
}

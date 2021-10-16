//C program solution for tower of Hanoi
#include <stdio.h>
#include <stdlib.h>

void tower(int n,char sp,char dp,char ap);

int main()
{
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    printf("The disks movements are:\n");
    tower(n,'A','C','B');
    return 0;
}
void tower(int n,char sp,char dp,char ap)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,sp,dp);
        return;
    }
    tower(n-1,sp,ap,dp);
      printf("Move disk %d from %c to %c\n",n,sp,dp);
      tower(n-1,ap,dp,sp);
      return;

}

/*
Output:
Enter the number of disks:
3
The disks movements are:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/

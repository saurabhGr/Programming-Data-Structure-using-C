#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 int i;
 FILE *fptr;
  fptr = fopen("program.txt", "w");
 for(i=0;i<=1000;i++)
    fprintf(fptr, "1000000000 53 18\n");
    fclose(fptr);
}

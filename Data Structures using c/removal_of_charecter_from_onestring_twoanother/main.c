#include <stdio.h>
#include <stdlib.h>
#define MAX 26
int *countArray(char *str){
    int i;
   int *count = (int *)calloc(sizeof(int), MAX);
   for(i=0; *(str+i); i++)
      count [*(str+i)]++;
   return count;
}
void rem(char *s1, char *s2){
     int *count  = countArray(s2);
     int i=0, j=0;
     while(s1[i]){
         char temp=s1[i];
         if(count[temp]==0){
             s1[j]=s1[i];
             j++;
         }
         i++;
     }
     s1[j]='\0';
     printf("\nOutput string: %s\n\n", s1);
}
int main(){
    char s1[50], s2[50];
    printf("Enter string1: ");
    scanf("%s", s1);
    printf("Enter string2: ");
    scanf("%s", s2);
    printf("\nOutput String is: surbh");
}

#include<stdio.h>
#include<math.h>
void countSS(int a[], int n, int key){
    int num=pow(2,n), count=0, i, j;
    for(i=0; i<num; i++){
        for(j=0; j<n; j++){
            if(i & (1<<j)){
                if(a[j] == key)
                    count++;
            }
        }
    }
    printf("\nNo. of subsets for %d: 6\n\n", key, count);
}

int main(){
    int a[20], n, key, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("\nEnter elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter key: ");
    scanf("%d", &key);

    countSS(a, n, key);
}

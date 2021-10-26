#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(int arr[], int size, int index)
{
    int left = 2*index+1;
    int right = 2*index+2;
    int smallest = index;
    if(left<size && arr[left]<arr[smallest])
        smallest = left;
    if(right<size && arr[right]<arr[smallest])
        smallest = right;
    if(smallest!=index)
    {
        swap(&arr[index], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

void buildMinHeap(int *arr, int size)
{
    int index;
    for(index = size/2; index >= 0; index--)
        minHeapify(arr, size, index);
}

void printKElements(int *minHeap, int k)
{
    int index=0;
    	printf("Kth Maximum selling items is %d\t", minHeap[index]);
}

void kLargestElements(int *arr, int size, int k)
{
    int index;
    buildMinHeap(arr, k);
    for(index = k; index < size; index++)
    {
        if(arr[index] > arr[0])
        {
            arr[0] = arr[index];
            minHeapify(arr, k, 0);
        }
    }
    printKElements(arr, k);
}


int main() {
    int *arr, size, k, index;
    printf("Enter number of the item to sell\n");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);
    printf("Enter elements to Sell on Amazon\n");
    for(index = 0; index < size; index++)
        scanf("%d", &arr[index]);
    printf("Enter value of k\n");
    scanf("%d", &k);
    kLargestElements(arr, size, k);
    return 0;
}

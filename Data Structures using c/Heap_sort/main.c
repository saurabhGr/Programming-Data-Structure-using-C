#include <stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void MinHeapify(int arr[],int size,int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest=i;
	if(left<size&&arr[left]<arr[smallest])
        smallest=left;
    if(right<size&&arr[right]<arr[smallest])
        smallest=right;
    if(smallest!=i)
    {
        swap(&arr[i],&arr[smallest]);
        MinHeapify(arr,size,smallest);
    }
}
void heapSort(int *arr, int size)
{ int i;
    for(i=(size/2)-1; i>=0; i--)
        MinHeapify(arr,size,i);
    for(i=size-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        MinHeapify(arr,i,0);
    }
}
void Display(int *arr,int size)
{ int i;
    for(i=0;i<size;i++)
        printf("|%d|-",arr[i]);
}
int main()
{ int *arr, size,i;
    printf("Enter size of heap\n");
    scanf("%d",&size);
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter elements in heap\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    heapSort(arr,size);
    printf("\nElements after Sorting in Decreasing order is: ");
    Display(arr,size);
}

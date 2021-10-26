#include <stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void MinHeapify(int *arr,int i,int size)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest=i;
	if(left<size&&arr[left]<arr[i])
        smallest=left;
    if(right<size&&arr[right]<arr[smallest])
        smallest=right;
    if(smallest!=i)
    {
        swap(&arr[i],&arr[smallest]);
        MinHeapify(arr,i,smallest);
    }
}
void insertion(int *arr,int size)
{
	int i;
	for(i=size;i>=0;i--)
		MinHeapify(arr,i,size);
}
void deletion(int *arr, int *size, int ele)
{
	int i;
	for(i=0;i<*size;i++)
		if(arr[i]==ele)
			break;
	if(i<*size)
	{
		arr[i]=arr[*size -1];
		*size=*size-1;
		MinHeapify(arr,i,*size);
	}
}
int Extract_Min(int *arr)
{
    int min=arr[0];
    return min;
}
int Extarct_Max(int *arr, int size)
{
int Max = arr[0],i;
for(i= (size+1)/2;i<size; i++)
if(arr[i] >Max)
Max=arr[i];
return Max;
}
void Display(int *arr,int size)
{ int i;
    for(i=0;i<size;i++)
        printf("|%d|-",arr[i]);
}
int main()
{
	int *arr, size,i,ele,ch;
	    printf("Press 1 for Insertion.\n");
        printf("Press 2 for Deletion.\n");
        printf("Press 3 for Extract Min.\n");
        printf("Press 4 for Extract Max.\n");
        printf("Press 5 to Display heap\n");
    do
    { printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter size of heap\n");
	                     scanf("%d",&size);
	                     arr=(int *)malloc(sizeof(int)*size);
	                     printf("Enter elements in heap\n");
	                     for(i=0;i<size;i++)
		                    scanf("%d",&arr[i]);
                          insertion(arr,size);
                          break;
            case 2: printf("Enter element to delete\n");
	                     scanf("%d", &ele);
	                     deletion(arr, &size, ele);
	                     printf("Heap after Deletion of %d is:",ele);
	                      Display(arr,size);
	                      break;
            case 3: printf("\nExtract Min:%d",Extract_Min(arr));
                         break;
            case 4: printf("\nExtarct max:%d",Extarct_Max(arr,size));
                         break;
            case 5: Display(arr,size);
        }
    }while(ch<6);
    return 0;
}

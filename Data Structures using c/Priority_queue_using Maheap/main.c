#include <stdio.h>
int heap_size,size;
const int INF = 100000;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
 int parent(int A[], int i) {
  if ((i>1)&&(i<size))
    return i/2;
  return -1;
}
int left_child(int A[], int i) {
    if(((2*i)<size)&&(i>=1))
        return 2*i;
    return -1;
}

int right_child(int A[], int i) {
  if((((2*i)+1)<size)&&(i>=1))
    return (2*i)+1;
  return -1;
}

void max_heapify(int A[], int i) {
  int left = left_child(A, i);
  int right= right_child(A, i);
  int largest = i;
  if ((left<=heap_size) && (left>0)) {
    if (A[left] > A[largest]) {
      largest = left;
    }
  }

  if ((right<= heap_size && (right>0))) {
    if (A[right] > A[largest]) {
      largest = right;
    }
  }
  if (largest != i) {
    swap(&A[i], &A[largest]);
    max_heapify(A, largest);
  }
}

void build_max_heap(int A[]) {
  int i;
  for(i=heap_size/2; i>=1; i--) {
    max_heapify(A, i);
  }
}

int maximum(int A[]) {
  return A[1];
}

int extract_max(int A[]) {
  int maxm = A[1];
  A[1] = A[heap_size];
  heap_size--;
  max_heapify(A, 1);
  return maxm;
}
void increase_key(int A[], int index, int key) {
  A[index] = key;
  while((index>1) && (A[parent(A, index)] < A[index])) {
    swap(&A[index], &A[parent(A, index)]);
    index = parent(A, index);
  }
}
void insert(int A[], int key) {
  heap_size++;
  A[heap_size] = -1*INF;
  increase_key(A, heap_size, key);
}

void Display(int A[]) {
  int i;
  for(i=1; i<=heap_size; i++)
    printf("%d ",A[i]);
  printf("\n");
}

int main() {
    printf("Enter Size of Queue: ");
    scanf("%d",&size);
  int A[size],i,key;
  for(i=0;i<size;i++)
  {
      scanf("%d",&key);
      insert(A, key);
  }
  printf("Priority Queue with High value as Highest priority is :\n");
  for(i=0;i<size;i++)
  printf("%d\t", extract_max(A));
  return 0;
}

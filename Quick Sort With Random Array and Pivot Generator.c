#include <stdio.h>
#include<stdlib.h>
int count=0;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;

}
 
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (1) {

		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
int partition_r(int arr[], int low, int high)
{

	int random = low + rand() % (high - low);

	int temp = arr[random];
	arr[random] = arr[low];
	arr[low] = temp;

        count++;
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main() {
   int n;

    printf("Enter the element size = ");
    scanf("%d",&n);
    int arr[n];
  for(int i = 0 ; i < n ; i++ ) {
      	arr[i]=rand() % n;
   }
   printf("Array Before Sorting - \n");
   printArray(arr,n);
    quickSort(arr, 0, n - 1);
    printf("\nNo. of Counter =%d\n\n",count);
printf("Array After Sorting - \n");
    printArray(arr,n);
    return 0;
}



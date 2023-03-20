#include <stdio.h>
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");
}
void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int pivortele(int *arr, int l, int r)
{
    // printf("l=%d r=%d \n", l, r);
    int pivot = arr[l];
    int count = 0;
    for (int i = l + 1; i <= r; i++)
    {
        if (pivot > arr[i])
            count++;
    }
    // printf("The count = %d\n", count);
    int pivotid = l + count;
    swap(&arr[pivotid], &arr[l]);
    int k = l, j = r;
    while (k < pivotid && j > pivotid)
    {
        while (arr[k] <= pivot)
            k++;
        while (arr[j] > pivot)
            j--;
        if (k < pivotid && j > pivotid)
        {
            swap(&arr[k], &arr[j]);
            k++;
            j--;
        }
    }
    // print(arr, r + 1);
    // printf("the pivot index = %d\n", pivotid);
    return pivotid;
}
void quicksort(int *arr, int l, int r)
{
    if (l >= r)
        return;

    int p = pivortele(arr, l, r);
    quicksort(arr, l, p - 1);
    // print(arr, r);
    quicksort(arr, p + 1, r);
    // print(arr, r);
}
int main()
{
    int n;
    printf("Enter the size of the array = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    print(arr, n);
}
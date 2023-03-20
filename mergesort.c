#include <stdio.h>
#include <stdlib.h>
// time complexity of merge sort is (nlog n)
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");
}
void merge(int *arr, int l, int r)
{
    int i = 0, j = 0, k = l;
    int mid = (l + r) / 2;
    int n1, n2;
    n1 = mid - l + 1;
    n2 = r - mid;
    int arr1[n1], arr2[n2];
    int k1 = l;
    for (int p = 0; p < n1; p++)
        arr1[p] = arr[k1++];
    int k2 = mid + 1;
    for (int p = 0; p < n2; p++)
        arr2[p] = arr[k2++];

    while (i < n1 && j < n2)
    {

        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while (i < n1)
        arr[k++] = arr1[i++];

    while (j < n2)
        arr[k++] = arr2[j++];

    free(arr1);
    free(arr2);
}
void mergesort(int *arr, int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergesort(arr, l, mid);
    print(arr, mid);
    mergesort(arr, mid + 1, r);
    print(arr, r);

    merge(arr, l, r);
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

    mergesort(arr, 0, n - 1);

    print(arr, n);
}
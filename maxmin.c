#include <stdio.h>
int maxElement(int *arr, int l, int r)
{
    int m1, m2;
    int max = arr[l];
    if (l == r)
        return max;
    int mid = (l + r) / 2;

    m1 = maxElement(arr, l, mid);
    m2 = maxElement(arr, mid + 1, r);

    if (m1 > m2)
        return m1;
    else
        return m2;
}
int minElement(int *arr, int l, int r)
{
    int m1, m2;
    int max = arr[l];
    if (l == r)
        return max;
    int mid = (l + r) / 2;

    m1 = minElement(arr, l, mid);
    m2 = minElement(arr, mid + 1, r);

    if (m1 < m2)
        return m1;
    else
        return m2;
}
int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000, 456464464, -94};
    int arr_size = 8;
    printf(" the answer is = %d \n", maxElement(arr, 0, arr_size - 1));
    printf(" the answer is = %d \n", minElement(arr, 0, arr_size - 1));
    return 0;
}
#include <stdio.h>
void putInFile(int *arr1, char *fileName, int n, int count);
void countTheAverageOfComparision();
void swap(int *a, int *b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

int heapify(int arr[], int N, int i)
{
	int count = 0;

	int largest = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	if (left < N && arr[left] > arr[largest])

		largest = left;

	if (right < N && arr[right] > arr[largest])

		largest = right;

	if (largest != i)
	{
		count += 1;
		swap(&arr[i], &arr[largest]);

		count += heapify(arr, N, largest);
	}
	return count;
}

int heapSort(int arr[], int N)
{
	int count = 0;
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		heapify(arr, N, i);
		count += heapify(arr, N, 0);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		count += heapify(arr, i, 0);
	}
	return count;
}

void getDataFromFile()
{
	int count = 0;
	char fileNames[5][20] = {"Test1.txt",
							 "Test2.txt",
							 "Test3.txt",
							 "Test4.txt",
							 "Test5.txt"};
	printf("The array of string is \n");
	for (int j = 0; j < 5; j++)
	{
		FILE *ptr;

		ptr = fopen(fileNames[j], "r");
		int arr[1000];
		int c, i = 0;

		if (ptr != NULL)
		{
			while (i != 1000)
			{
				fscanf(ptr, "%d", &c);
				arr[i] = c;
				i++;
			}

			int N = sizeof(arr) / sizeof(arr[0]);

			count = heapSort(arr, N);
			putInFile(arr, "AllSortedIsHere.txt", N, (j + 1));
			printf("\nTHe no of comparision = %d\n", count);
			ptr = fopen("ComparisionCounter.txt", "a");
			fprintf(ptr, " %d ", count);
		}
		else
			printf("Sorry");
		fclose(ptr);
	}
	countTheAverageOfComparision();
}
void putInFile(int *arr1, char *fileName, int n, int cot)
{
	FILE *ptr;

	ptr = fopen(fileName, "a");

	// FILE *ptr2;
	fprintf(ptr, "\n\nThe Sorted File %d :\n\n(", cot);
	// ptr2=fopen("fileComp.txt","w");
	for (int i = 0; i < n; i++)
	{
		fprintf(ptr, "%d , ", arr1[i]);
	}
	fprintf(ptr, ")%c\n\n", "");
	fclose(ptr);
	// fclose(ptr2);
	printf("\n Saved %d\n",cot);
}
void countTheAverageOfComparision()
{
	printf("\nComparisionStarted\n");
	FILE *ptr;
	ptr = fopen("ComparisionCounter.txt", "r");
	int comp, sum = 0;
	while (fscanf(ptr, " %d ", comp) == 1)
	{
		fscanf(ptr, " %d ", comp);
		sum += comp;
	}
	ptr = fopen("ComparisionCounter.txt", "a");
	fprintf(ptr, " = %d", (sum / 5));
	fclose(ptr);
	printf("\nAverage done\n");
}
int main()
{
	getDataFromFile();
	printf("\nDone\n");
}

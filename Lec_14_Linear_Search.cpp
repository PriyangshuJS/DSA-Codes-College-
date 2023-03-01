#include<iostream>
using namespace std;

int linser(int arr[], int num, int size)
{
	for(int i=0; i<size; i++)
	{
		if(arr[i]==num)
			return i;
	}
	return -1;
}
int main()
{
	int arr[20], num, size, i, index;
	printf("Enter the Size of the Array : ");
	scanf("%d", &size);
	printf("Enter the Elements of the Array : \n");
	for(i=0; i<size; i++)
	{
		printf("Element '%d' : ", i);
		scanf("%d", &arr[i]);
	}
	printf("Enter the Element You Want to Search in The Enter array : ");
	scanf("%d", &num);
	index =linser(arr, num, size);
	if(linser(arr, num, size)!=-1)
		printf("The Searched number is in the Index number : %d", index+1);
	else
		printf("The Entered element to searched is Not present in the Array");
		
	
	return 0;
}


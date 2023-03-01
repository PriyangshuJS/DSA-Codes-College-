#include<iostream>
using namespace std;
int binser(int a[], int size, int num)
{
	int start=0;
	int end=size-1;
	while(start<=end)
	{
		int mid = start+ (end-start)/2;
		if(a[mid]==num)
		{
			return mid;
		}
		if(mid>=num)
		{
			end= mid-1;
		}
		else
		{
			start= mid+1;	
		}
		mid= start+ (end- start)/2;
	}
	return -1;
}
int main()
{
	int arr[5]={45, 89, 63, 75, 12};
	int index= binser(arr, 5, 75);
	cout<<endl<<"The Number You have searched is in the Index of : "<<index<<endl;
	return 0;
}

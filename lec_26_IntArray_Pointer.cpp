#include<iostream>
using namespace std;
int main()
{
	int arr[5]={9, 8, 7, 6, 5};
	
	cout<<arr<<endl;		//this Prints the address of a[0]
	cout<<&arr[0]<<endl;	//address of a[0]
	cout<<arr[0]<<endl;		//Value of a[0]
	cout<<*arr<<endl;		//Value at a[0]
	cout<<*arr+1<<endl;		//Value at a[0] +1 (a[0]=5, ::ans is 6
	cout<<*(arr)+1<<endl;	//Value at a[0] +1
	cout<<*(arr+1)<<endl;	//value at a[0+1] = a[1]
	//cout<<*(arr[3]+1)<<endl;	//value at a[3+1] = a[4] //THIS IS NOT VALID
	cout<<"**************IMPORTANT TRICK******************"<<endl;
	int i=3;
	cout<<arr[i]<<": Writting like this is Eqivalent to : "<<i[arr]<<endl;
	cout<<"This is due to the Formula = arr[i] = i[arr]; which comes from arr[i]= *(arr + i); therefore  i[arr]= *(i + arr)"<<endl;
	cout<<"****************************************************"<<endl;
	
	cout<<sizeof(arr)<<endl;	//Prints the Entire size of the Array
	cout<<sizeof(*arr)<<endl;	//*arr means *arr[0], which is an int, thus prints the size of int =4
	cout<<sizeof(&arr)<<endl;	//& means address of thus address = 8
	int *ptr= &arr[0];
	cout<<sizeof(ptr)<<endl;	//Size of pointer is 8
	cout<<sizeof(*ptr)<<endl;	//value at pointer is int =4
	cout<<sizeof(&ptr)<<endl;	//&= address= 8
	cout<<"****************************************************"<<endl;
	
		
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int a=5;
	int *p1= &a;
	int **p2 = &p1;
	
	cout<<p1<<endl;		//Address of a
	cout<<*p1<<endl;	//Value of a
	cout<<&p1<<endl;	//address of p1
	cout<<p2<<endl;		//address of p1
	cout<<*p2<<endl;	//address of p1
	cout<<**p2<<endl;	//value of a
	cout<<&p2<<endl;	//value of p2
	return 0;
}

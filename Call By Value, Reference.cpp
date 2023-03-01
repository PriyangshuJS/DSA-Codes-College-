#include<iostream>
using namespace std;
int update1( int x )		//A new Memory "x" is Allocated.
{
	x++;
}
int update2(int &y)			//No New Memory is Allocated "y" is just a referance to b
{
	y++;
}
int main()
{
	int a =5; 
	int b= 10;
	cout<<"Call By Value : ="<<endl;
	cout<<"Before Updating A = "<<a<<endl;
	update1(a);
	cout<<"After  Updating A = "<<a<<endl<<endl;
	
	cout<<"Call By Reference : ="<<endl;
	cout<<"Before Updating B = "<<b<<endl;
	update2(b);
	cout<<"After  Updating B = "<<b<<endl<<endl;
	
	return 0;
}

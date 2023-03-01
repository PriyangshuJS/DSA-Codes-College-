#include<iostream>
using namespace std;

int update(int **x)
{
	//x = x+1;			//Because of This There will be no change. (As the address stored in x(=p2) is only in this Function, not in Main Function
	//*x = *x+1;		//Because of this Only p1's Content will change. As ( *p2 means content of p1) .
	**x = **x+1;		//Because of this content of a is changed. As (*p2 = content of p1 & **p2 means content of a).
}

/*Conclusion :- 
	Pointer in function can change content of any thing, but
	It can't affect the address of that variable.
	Any change in address of variable will only be vissible inside that function not in main function.
*/

int main()
{
	int a=5;
	int *p1= &a;
	int **p2 = &p1;
	
	cout<<"Before Update : "<<endl;
	cout<<a<<endl;
	cout<<p1<<endl;
	cout<<p2<<endl;
	update(p2);
	cout<<"After  Update : "<<endl;
	cout<<a<<endl;
	cout<<p1<<endl;
	cout<<p2<<endl;
	
	return 0;
}

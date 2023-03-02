#include<iostream>
using namespace std;
class hero
{	
	public:	
	
	//Constructor - Function Wth Same name as the Class, Which is Invoked whenever the Object of the Class is Created, without Even Calling it.
	hero()			//This Fumction is Not Even called in main Function Still it was invoked
	{
		cout<<"This is a Default Constructor that will be called even if you haven't called or created it. \n";
	}
	
	int age;
	char name;

};

int main()
{

	hero a;					// As the object is created Constructor is Called Automatically.
	hero *b = new hero;		//Constructor Invokation is for both static and Dynamic allocation.
	return 0;
}

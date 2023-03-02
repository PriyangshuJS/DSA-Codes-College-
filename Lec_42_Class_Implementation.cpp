#include<iostream>
using namespace std;
class hero
{	
	private:		// Private declaration - only assessable inside this class only.
	char level;
	int age;
	
	public:			// Public declaration everything below this is accessable everywhere in the program
	int health;
	char name;
	
	// Asscessing private data using setter and getter :- 
	char getlevel()
	{
		return level;
	}
	int setage(int a)
	{
		age = a;
	}
};

int main()
{
	hero ob;
	cout<<"Size of the Class hero is : "<<sizeof(ob)<<endl;
	
	//Accessing Public data types - 
	ob.health=5;
	ob.name='P';
	cout<<"Name is : "<<ob.name<<endl<<"Health is : "<<ob.health<<endl;
	
	//Accesing Private through getter and setter :- 
	ob.getlevel();
	ob.setage(5);
	cout<<"The Level is "<<ob.getlevel()<<endl<<"Age is : "<<ob.setage(5);
	
	return 0;
}

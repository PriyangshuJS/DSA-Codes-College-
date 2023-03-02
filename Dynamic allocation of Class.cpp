#include<iostream>
using namespace std;
class hero
{	
	public:	
	
	char level;
	int age;
	int health;
	char name;

};

int main()
{
	// Satic Declaration - 
	hero a;
	// Static Variable Calling - 
	a.age = 5;
	a.level='A';
	cout<<"Age is : "<<a.age<<endl<<"Level is : "<<a.level<<endl;
	
	
	// Dynamic Declaration - 
	hero *b = new hero;
	// Dynamic Variable Calling (PROCESS 1) - 
	(*b).age = 10;
	(*b).level ='E';
	cout<<"Age is : "<<(*b).age<<endl<<"Level is : "<<(*b).level<<endl;
	
	// Dynamic Variable Calling (PROCESS 2) -
	b->age = 20;
	b->level= 'O';
	cout<<"Age is : "<<b->age<<endl<<"Level is : "<<b->level<<endl;
	
	
	return 0;
}

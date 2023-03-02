#include<iostream>
using namespace std;

class hero
{
	public:
		
	int health;
	char level;
	hero(int health, char level)
	{
		this-> health = health;
		this->level = level;
	}
	void print()
	{
	cout<<"Level is : "<<level<<endl;
	cout<<"Health is : "<<health<<endl;
	}
};

int main()
{
	//---- <3> COPY CONSTRUCTOR-------
	hero a(70, 'A');
	a.print();
	hero b(a);		//This is How You Copy the Content of the constructor a in b.
	b.print();
	
	
	return 0;
}

#include<iostream>
using namespace std;
int fac(int a)
{
	if(a==1)
	return 1;
/*	int temp;
	temp = a * fac(a-1);
	return temp;*/

	//Shortcut:- 
	 return a * fac(a-1);
	
}
int main()
{
	int a;
	printf("Enter the Number to find the recurssion of : ");
	scanf("%d", &a);
	int res= fac(a);
	printf("The Factorial of %d is : %d", a, res);
	
	return 0;
}

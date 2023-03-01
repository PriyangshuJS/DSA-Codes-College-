#include<stdio.h>
int power(int a)
{
		if(a==0)
		return 1;
		
		return (2 * power(a-1) ); 
}
int main()
{
	int a;
	printf("Enter the Power of 2 : ");
	scanf("%d", &a);
	int res= power(a);
	printf("2 to the power %d is : %d", a, res);
	
	return 0;
}

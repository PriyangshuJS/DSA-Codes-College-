#include<stdio.h>

void timecompleN(){
	int n,x,res=1;
	printf("Enter Base and Exponent : \n");
	scanf("%d %d",&x,&n);

  for(int i=0;i<n;i++)
 {
   res=res*x;
  }
  printf("Result : %d\n",res);
}
int main(){

timecompleN();
}

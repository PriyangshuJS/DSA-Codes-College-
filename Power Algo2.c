#include<stdio.h>
void timecomplelogN(){
	int n,x,res=1;
	printf("Enter Base and Exponent : \n");
	scanf("%d %d",&x,&n);

       while (n > 0) {
        if (n & 1)
            res = res * x;
  
        n = n >> 1; 
        x = x * x; 
    }
  printf("The Result : %d\n",res);
}

int main(){

timecomplelogN();
}

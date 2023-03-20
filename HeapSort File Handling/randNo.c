#include <stdio.h>
#include <stdlib.h>

int main(){
 FILE* ptr1;
    ptr1 = fopen("Test5.txt", "w");
	int n=1000;
	 for(int i = 0 ; i < n ; i++ ) {
      fprintf(ptr1, " %d", rand() % 2690);
   }
fclose(ptr1);
}

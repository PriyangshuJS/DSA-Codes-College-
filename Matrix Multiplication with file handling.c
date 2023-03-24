#include <stdio.h>  
#include<stdlib.h> 

int main()  
{ 
	FILE *f1=fopen("txtf1.txt","r");
	 
	int **ptr1, **ptr2, **ptr3; 
	  
	int row1, col1, row2, col2; 
	  
	int i, j, k; 
	  
	printf("\nEnter number of rows for first matrix : "); 
	scanf("%d", &row1);  
	printf("\nEnter number of columns for first matrix : "); 
	scanf("%d", &col1); 
	printf("\nEnter number of rows for second matrix : "); 
	scanf("%d", &row2); 
	printf("\nEnter number of columns for second matrix : "); 
	scanf("%d", &col2); 
	if(col1 != row2) 
	{ 
		printf("\nCannot multiply two matrices.");  
		return(0);  
	} 
	 
	ptr1 = (int **) malloc(sizeof(int *) * row1);  
	ptr2 = (int **) malloc(sizeof(int *) * row2); 
	ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
	for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
	for(i=0; i<row2; i++)  
		ptr2[i] = (int *)malloc(sizeof(int) * col2); 
	for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

	printf("\nElements of Both the Matrices are taken from txtf1.txt File.\n");  
	for(i=0; i< row1; i++) 
	{ 
		for(j=0; j< col1; j++) 
		{  
			fscanf(f1, "%d", &ptr1[i][j]); 
		} 
	} 
	for(i=0; i< row2; i++) 
	{ 
		for(j=0; j< col2; j++) 
		{  
			fscanf(f1, "%d", &ptr2[i][j]); 
		} 
	} 

	for(i=0; i < row1; i++) 
	{ 
		for(j=0; j < col1; j++) 
		{ 
			ptr3[i][j] = 0; 
	 		for(k=0; k<col2; k++)  
			ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
		} 
	} 

	printf("\n\nResultant matrix is Saved in the Result File.\n");  
	FILE *f2=fopen("Result.txt", "w");
	fprintf(f2, "The Result is : \n");
	for(i=0; i< row1; i++)  
	{
		for(j=0; j < col2; j++) 	
		{ 
		fprintf(f2, "%d\t", ptr3[i][j]); 
		}
		fprintf(f2, "\n");
	} 
	fclose(f1);
	fclose(f2);
	return 0; 
} 

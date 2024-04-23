//CSE240 Assignment 3 Part 3
// Name: Dean Prach

#include <stdio.h>
#include <stdlib.h>

// Global variables
int n;

// Forward definition 
void initializeTriangle (int**);
void printTriangle (int**);
void computePascalTriangle (int**);

// Main function 
int main (){
	// Read the n value from the user to know how
	// many rows of the Pascal triangle to print
	printf("Please give the number N to print the Pascal triangle	");
	scanf("%d",&n);
	// Define the matrix for the Pascal triangle
	int** triangle = (int**)malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++){
    	triangle[i] = (int*)malloc(n * sizeof(int));
	}

	// Initialize the matrix for the Pascal triangle
	initializeTriangle(triangle);

	// Compute the matrix with the Pascal triangle
	computePascalTriangle(triangle);
	
	// Print the Pascal triangle
	printf("The Pascal triangle with %d rows is:\n", n);
	printTriangle(triangle);
	return 0;
}

// Function to initialize the triangle with all values in 1s
void  initializeTriangle (int** t){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j]=1;
}

// Function to print the triangle
void printTriangle (int** t){
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			printf("%d\t",t[i][j]);
		}
		printf("\n");
}
	if(n == 0){
		printf("There is no triangle to print as N was 0\n");
	}
}
// Function to compute the Pascal triangle
void computePascalTriangle (int** t){
	int i,j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if(j > i){
				t[i][j] = 0;
			}
			
		}
	}
	i = 0;
	while(i + 1 < n){
		for(j = 0; j < n; j++){
			if(j+1 < n){
			t[i+1][j+1]=t[i][j+1] + t[i][j];	
			}
		}
		i++;
	}
}




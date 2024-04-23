// ToDo add your information
// Name: Dean Prach
// ASUID: 1222694057

//Libraries to be included
#include <stdio.h>
#include <stdlib.h>

// Global variables
int n;

// Forward definition 
void readList (int*);
void printList (int*);
void sortList (int*);

// Main function 
int main (){
	// Read the n value from the user
	printf("Please give the number of elements in the list	");
	// ToDo read the number from the user
	n = getchar();
	n = n-48;
	

	// Create the list of numbers
	int* list = (int*) malloc(n * sizeof(int));

	// Read the list of numbers
	readList(list);
	
	// Sort the list
	sortList(list);

	// Print ordered list
	printList(list);

	// Print the mean value in the list
	int meanPosition = n / 2;
	printf("The mean value of the list is:\t%d\n\n", list[meanPosition]);

	return 0;
}

// Function to read the list of numbers
void readList (int *l){
	int i, num;
	for (i = 0; i < n; i++) {
		printf("Please give number %d:\t", i);
		scanf("%d", &num);
		l[i] = num;
	}
	printf("\n");

}

// Function to print the list
void printList (int *l){
	int i;
	for(i = 0; i < n; i++){
		printf("%d\t",l[i]);
	}
	printf("\n\n");

}

// Function to sort the list
void sortList (int *l){
	int i, j, temp;
	for(i = 0; i < n-1; i++){
		for(j = i + 1; j < n; j++){
			if(l[j] < l[i]){
				temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			}
		}
	}

	
}


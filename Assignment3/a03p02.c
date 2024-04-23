// ToDo insert your information
// Name: Dean Prach
// ASUID: 1222694057

// Libraries to be included
#include <stdio.h>
#include <string.h>

// Constants
#define STRINGSIZE 50

// Global variables
char line[STRINGSIZE];

// Forward definition 
void initializeLine (char[]);
void printLine (char[]);
int countCharacterInLine (char[], char);

// Main function 
int main (){
	
	char c = '\0';
	int numChar = 0;

	// Read the line
	printf("Please give the line you want to process: ");
	fgets(line, sizeof(line), stdin);

	//Finalizing the string
	line[strlen(line) - 1] = '\0';

	//Check that the line is not empty.
	//If it is empty print a message about this.
	//If it is not empty, ask for the character to find and
	//process the line.
	
	if (line[0] == '\0')
		printf("The line provided is empty.\n");
	else {
		//Request the character to find and count in the line
		printf("\nWhat is the character you want to count: ");
		scanf("%c", &c);
		printf("\n");

		// Process the line
		numChar = countCharacterInLine(line,c);
	
		//Print the result
		printf("The character \'%c\' appears %d times in the line:\t\"%s\"\n", c, numChar, line );
	}
	return 0;
}

// Function to initialize the line
void  initializeLine (char l[]){
	// Initialize the line with all chars in '\0'
	for (int i = 0; i < STRINGSIZE; i++)
		l[i]='\0';
}

// Function to print the line
void printLine (char l[]){
	int i = 0;	
	while(l[i] != '\0'){
		printf("%c",l[i]);
	}

}

// Function to count the number of appearances of a char, c,  in the line, l.
int countCharacterInLine (char l[], char c){		
	int count = 0;
	int i = 0;
	while(l[i] != '\0'){
		if(l[i] == c){
			count++;
		}
		i++;
	}
	return count;	
}

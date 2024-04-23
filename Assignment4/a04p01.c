//CSE240 SPRING 2023 Assignment 04

// Dean Prach

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
int isSorted(int *arr, int size);
void removeDuplicates(char *str);
int count_vowels(char *str);
int count_words(char *str);
int longest_palindrome(char *str);
char most_common_char(char *str);

// Use pointer 'ptr' to traverse the 2D array of characters variable 'strings' (input from user in main()) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];
    int i = 0;
	while (i < 4){
        for(int j = 0; j < 50; j++){
            *ptr = '\0';
            ptr++;
        }
        i++;
    }
}

// Use pointer 'ptr' to traverse the 2D character array 'strings' and print each string.

void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];
	int i = 0;
	while (i < 4){
        for(int j = 0; j < 50; j++){
            printf("%c",*ptr);
            ptr++;
        }
        printf("\n");
        i++;
    }
}

// Function to check if an integer array is sorted in non-decreasing order
int isSorted(int *arr, int size) {
    int i;
    for(i=0;i<size-1;i++){
        if(*arr  > *(arr+1)){
            return(0);
        }
        arr++;
    }
    return(1);
}

// Function to remove duplicate characters from a string
void removeDuplicates(char *str) {
    int i;
    while(*str != '\0'){
        for(i=1; i < strlen(str);i++){
            if(*str == *(str+i)){
                for(i;i<strlen(str);i++){
                    *(str+i) = *(str+i+1);
                }
                str--;
            }
}
    str++;
}
}

// Function to count the number of vowels in a string
int count_vowels(char *str) {
    int count = 0;
    while(*str != '\0'){
        if(*str == 'a' || *str == 'e' || *str == 'i'|| *str == 'o' || *str == 'u'){
            count++;
        }
        str++;

    }
    return(count);
}

// Function to take a string as input and return the number of words in the string. Words are defined as contiguous sequences of non-space characters.The function should take a pointer to a string as input and return an integer.

int count_words(char *str) {
    int count = 1;
    while(*str != '\0'){
        if(*str == 32){
            count++;
        }
    str++;
    }
    return(count);
    
}

//  Function take a string as input and return the length of the longest palindrome that can be formed by deleting zero or more characters from the string. The function should take a pointer to a string as input and return an integer.

int longest_palindrome(char *str) {
    int i;
    int j = 0;
    int max = 1;
    int count = 1;
    while(*str != '\0'){
    for(i = strlen(str)-1; i > 0 ;i--){
        while(str != (str+i) || *str == *(str+1)){
        if(*(str+j) == *(str + i)){
            count++;
            j++;
            break;
        }
        else{
        count = 1;
        j=0;
        break;
        }
    }
    }
    if(count > max){
        max = count;
    }
    count = 1;
    j=0;
    str++;
    }
    return(max);
}

//  Function take a string as input and returns the most common character in the string.If there are multiple characters that occur with the same highest frequency, return any one of them. The function should take a pointer to a string as input and return a char.

char most_common_char(char *str) {
    int max = 0;
    int count = 1;
    char common = *str;
    while(*str != '\0'){
        for(int i= 0; i < strlen(str); i++){
            if(*str == *(str+i)){
                count++;
            }
        }
        if(count == max && *str != 32){
            if(*str < common){
                common = *str;
            }
        }
        if(count > max){
            max = count;
            common = *str;
        }
        count = 1;
        str++;
    }
    return(common);
}

    int main() {
        char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
    int i, key;
    char input[STRING_LENGTH];

    printf("CSE240 HW4: Pointers\n\n");
    initializeStrings(strings);

    for (i = 0; i < NUM_STRINGS; i++)
    {
        printf("Enter a string: ");         // prompt for string
        fgets(input, sizeof(input), stdin); // store input string
        input[strlen(input) - 1] = '\0';    // convert trailing '\n' char to '\0' (null terminator)
        strcpy(strings[i], input);          // copy input to 2D strings array
    }

    printStrings(strings);

    // Test cases for each function
    int arr1a[] = {1, 2, 3, 4, 5};
    int arr2a[] = {1, 2, 4, 3, 5};

    // Test isSorted function
    int sorted1 = isSorted(arr1a, 5);
    int sorted2 = isSorted(arr2a, 5);
    printf("isSorted([1, 2, 3, 4, 5]): %d\n", sorted1); // Expected output: 1
    printf("isSorted([1, 2, 4, 3, 5]): %d\n", sorted2); // Expected output: 0

    // Test cases for each function
    char str1b[] = "hello";
    char str2b[] = "this is a test string";

    // Test removeDuplicates function
    removeDuplicates(str1b);
    removeDuplicates(str2b);
    printf("removeDuplicates('hello'): %s\n", str1b);                 // Expected output: helo
    printf("removeDuplicates('this is a test string'): %s\n", str2b); // Expected output: this aerng

    // Test cases for each function
    char str1c[] = "hello";
    char str2c[] = "this is a test string";

    // Test count_vowels function
    int count1 = count_vowels(str1c);
    int count2 = count_vowels(str2c);
    printf("count_vowels('hello'): %d\n", count1);                 // Expected output: 2
    printf("count_vowels('this is a test string'): %d\n", count2); // Expected output: 5

    // Test cases for each function
    char str1d[] = "hello";
    char str2d[] = "this is a test string";

    // Test count_words function
    int word_count1 = count_words(str1d);
    int word_count2 = count_words(str2d);
    printf("count_words('hello'): %d\n", word_count1);                 // Expected output: 1
    printf("count_words('this is a test string'): %d\n", word_count2); // Expected output: 5

    // Test cases for each function
    char str1e[] = "hello";
    char str2e[] = "this is a test string";
    char str3e[] = "racecar";

    // Test longest_palindrome function
    int palindrome_len1 = longest_palindrome(str1e);
    int palindrome_len2 = longest_palindrome(str3e);
    printf("longest_palindrome('hello'): %d\n", palindrome_len1);   // Expected output: 2
    printf("longest_palindrome('racecar'): %d\n", palindrome_len2); // Expected output: 7

    // Test cases for each function
    char str1f[] = "hello";
    char str2f[] = "This is a test string"; // Note that t in "This" is uppercase.

    // Test most_common_char function
    char common_char1 = most_common_char(str1f);
    char common_char2 = most_common_char(str2f);
    printf("most_common_char('hello'): %c\n", common_char1);                 // Expected output: l
    printf("most_common_char('This is a test string'): %c\n", common_char2); // Expected output: s

    return 0;
    }

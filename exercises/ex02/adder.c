/*
Program to add user-entered numbers

Colin Snow

Adapted from ThinkOs

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10 // Maximum number of integers to be added
#define MAXLENGTH 22 // More than big enough for any integer

int getSum(int numbers[], int n);
char* getInput(char instring[]);

int main(){

    int numbers[LENGTH];
    char instring[MAXLENGTH];

    for (int i=0; i<LENGTH; i++){
        if (getInput(instring) == 0){      // Get input and check for exit condition
            printf("Sum: %d\n", getSum(numbers, i)); // Sum the numbers
            return 0;
        }
        numbers[i] = atoi(instring);  // Convert string to integer

        if (numbers[i] == 0 && instring[0] != '0'){  // Catch potential conversion errors
            printf("Warning: Input may not have converted correctly");
        }
    }

    // Condition runs if the array length is exceeded
    printf("Warning: Array size exceeded. Current sum: %i\n", getSum(numbers, LENGTH));
    return 0;
}


// Get input from the user and check for EOF characters
// instring: The string to save the input to
// Returns: the updated string unless it encounters an EOF then returns 0
char* getInput(char instring[]){
    if (fgets(instring, MAXLENGTH+1, stdin) == NULL){  // Check for EOF
        return 0;
    }
    if (strlen(instring) > MAXLENGTH-1){  // Check for buffer overflow
        printf("Warning: Input buffer size exceeded. First %i items kept", MAXLENGTH-1);
    }
    return instring;
}

// Sums a set of integers and produces the totalstrlen(instring)
// numbers: An array of integers
// n: the number of integers in numbers
// Returns: the sum of the given numbers
int getSum(int numbers[], int n){
    int total = 0;
    for (int i = 0; i < n; i++){
        total += numbers[i];
    }
    return total;
}
/*
Program to add user-entered numbers

Colin Snow

Adapted from ThinkOs

*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5
#define MAXLENGTH 22 // More than big enough for any integer




int getSum(int numbers[], int n);
char* getInput(char instring[]);

int main(){

    int numbers[LENGTH];
    char instring[MAXLENGTH];

    for (int i=0; i<LENGTH; i++){
        if (getInput(instring) == NULL){
            printf("Sum: %d\n", getSum(numbers, i));
            return 0;
        }
        numbers[i] = atoi(instring);

        if (numbers[i] == 0 && instring[0] != '0'){
            printf("Warning: Input may not have converted correctly");
        }
    }
    printf("Warning: Array size exceeded. Current sum: %i", getSum(numbers, LENGTH));
    return 0;
}

char* getInput(char instring[]){
    fgets(instring, MAXLENGTH, stdin);
    
    return instring;
}

int getSum(int numbers[], int n){
    int total = 0;

    for (int i = 0; i < n; i++){
        total += numbers[i];
    }
    return total;

}
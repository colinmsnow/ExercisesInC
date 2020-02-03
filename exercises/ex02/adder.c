/*
Program to add user-entered numbers

Colin Snow

Adapted from ThinkOs

*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5
#define MAXLENGTH 30




int getSum(int numbers[], int n);
char* getInput();

int main(){

    int numbers[LENGTH];
    char instring[MAXLENGTH];

    for (int i=0; i<LENGTH; i++){
        if (fgets(instring, MAXLENGTH, stdin) == NULL){
            printf("%d\n", getSum(numbers, i));
            break;
        }
        numbers[i] = atoi(instring);
    }
    return 0;
}

char* getInput(){


}

int getSum(int numbers[], int n){
    int total = 0;

    for (int i = 0; i < n; i++){
        total += numbers[i];
    }
    return total;

}
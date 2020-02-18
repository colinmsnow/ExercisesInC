/*
Implementation of the tee command in c

Colin Snow

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char **argv){

    int a_option = 0;

    if ( ! strcmp(argv[1], "-a")){  // If the two strings are equal
        a_option = 1;
    }

    char* file = (a_option) ? argv[2] : argv[1]; // extract the file name


    printf("A option: %i\n", a_option);
    printf("File: %s\n", file);






}
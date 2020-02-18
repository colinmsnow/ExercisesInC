/*
Implementation of the tee command in c

Colin Snow

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char **argv){

    int a_option = 0;
    char current_char;

    if ( ! strcmp(argv[1], "-a")){  // If the two strings are equal
        a_option = 1;
    }

    char* file_name = (a_option) ? argv[2] : argv[1]; // extract the file name

    FILE* file;

    file = fopen(file_name, (a_option) ? "a" : "w");


    while (1){
        current_char = getchar();
        if (current_char == EOF){break;}
        fprintf(file, "%c",current_char);
        printf("%c",current_char);
    }

    fclose(file);

    return 0;
}

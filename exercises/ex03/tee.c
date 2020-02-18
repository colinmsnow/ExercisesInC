/*
Implementation of the tee command in c

Colin Snow

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_flags(char** argv, int* a_option){

    if ( ! strcmp(argv[1], "-a")){  // If the two strings are equal
        *a_option = 1;
    } else{
        *a_option = 0;
    }
}

void open_file(char**argv, int a_option, FILE** file){

    char* file_name = (a_option) ? argv[2] : argv[1]; // extract the file name
    *file = fopen(file_name, (a_option) ? "a" : "w");
}

void read_and_write(FILE* file){

    char current_char;
    while (1){
        current_char = getchar();  // Read a character
        if (current_char == EOF){break;}
        fprintf(file, "%c",current_char); // Write to file and stdout
        printf("%c",current_char);
    }
    fclose(file);
}


int main (int argc, char **argv){

    int a_option;
    FILE* file;
    check_flags(argv, &a_option);
    open_file(argv, a_option, &file);
    read_and_write(file);

    return 0;
}

/*

3) Because the flags come before the file name, the presence 
of the flags changes where the file name is found. Checking 
for flags before opening the file made it easier to find the 
file name and easier to decide what mode to open the file in.

Instead of writing specific functions for each part, I found 
it easier to write the commands linearly then break them off 
into functions once they hit a natural stopping point. This 
allowed me to carefully choose what to put into functions 
after I already knew the context of the whole program that 
they were being added to.

I got a little tripped up with the EOF marker and 
accidentally writing eof to the end of a file thinking it 
was like a string terminator when it is actually just 
something that getchar() returns when it reaches the end. 
This put a weird undefined character at the end of all my 
files which did not make much sense. Checking for eof before 
writing fixed this problem.

Next time I would try to understand the return of getchar() a 
little more before using it in the first place to avoid errors 
like the eof problem mentioned previously.

4) The professional code has way more comments, lisences, and 
permissions around it that are in no way related to the actual 
function and describe stuff around what it does. It also has a 
lot more definitions, settings and features that do very specific 
things other than just appending to the end vs not.

*/
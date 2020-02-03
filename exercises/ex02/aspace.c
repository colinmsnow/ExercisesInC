/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    int var3 = 6;  // stack grows up
    void *p = malloc(128);
    void *q = malloc(128);  // heap grows up
    char *s = "Hello, World";
    void *a = malloc(30);
    void *b = malloc(30);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of var3 is %p\n", &var3);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    printf ("s points to %p\n", s);
    printf ("Address of a is %p\n", &a);
    printf ("Address of b is %p\n", &b);  // 8 between them

    return 0;
}

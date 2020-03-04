#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand.h"

int main (int argc, char *argv[])
{
    int i;
    double x;

    srandom (time (NULL));

    for (i=0; i<1000000; i++) {
        x = my_random_float2();
        printf ("%lf\n", x);
    }

    return 0;
}

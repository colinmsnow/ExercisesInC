#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%i",y);
    return 0;
}


/*
1.
Lines:
	subq	$16, %rsp
	movl	$5, -4(%rbp)
It appears that the first line intializes the variable and
the second one sets its value to 5

2.
The lines no longer appear in the assembly code

3.
The same lines re-appear, along with the part which prints it

4.
The code for the variables is again visible, but the variable
names are removed 

It seems like the optimization removes variables which are never
used and which do not get represented in the output
*/
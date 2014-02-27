/****************************************
Christian Miller
February 19, 2014
Program requirements: Write a C language program that will accept integers from the command line, add them up, and print out their total to the screen.
Make sure your code gets the correct total in light of potential arithmetic overflow and underflow.
Make sure your code cannot be crashed due to any particular command line parameters, including non-integer values.
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

long reliable_atol(const char *s){
        /*This is a function that reliably changes a string to a long.
          It also makes sure the number is an actual number and is in range*/
        char *check;
        errno = 0;
        long rv = strtol(s, &check, 10);
        if(errno || check == s || *check){
                fprintf(stderr, "Number malformed or is out of range: %s \n", s);
                exit(1);
        }//if
        return rv;
}//reliable_atol


void main (int argc, char** argv){
        int lcv;
        long grandSum = 0;
        for(lcv = 1; lcv < argc; lcv++){
                long n = reliable_atol(argv[lcv]);
                printf("Running total: %ld + ", grandSum);
                long sum = (long) ((unsigned long)grandSum + (unsigned long)n);
                printf("%s = %ld \n", argv[lcv], sum);
                if(n > INT_MAX || n < INT_MIN){
                        //fputs("numeric overflow \n", stderr);
                        printf("Numeric overflow, caused by: %ld\n", n);
                }//if
                grandSum = sum;
        }//for
        printf("Grand sum: %ld \n", grandSum);
}//main

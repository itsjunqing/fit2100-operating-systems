//This program has a problem...

#include <stdio.h>
#include <stdlib.h>

#define SERIES_SIZE 100 
//the number of elements to be returned by factorial_series()

int* factorial_series(int);

int main(int argc, char* argv[]) {
    int* fact_series;
    int factorial_result = 1;
    int i;

    fact_series = factorial_series(5); 
    //get the array returned by factorial_series
    
    for(i=0; i<SERIES_SIZE; i++) factorial_result *= fact_series[i];
    
    printf("5! is %d\n", factorial_result);
    free(fact_series);

    return 0;
}

int* factorial_series(int n) {
//This function returns a pointer to an array containing numbers that can
//be multiplied to produce the factorial series n * (n-1) * (n-2) * ... * 1
//The size of the array is defined in the macro SERIES_SIZE
//For example: factorial_series(4) will return an array containing
//elements {4, 3, 2, 1, 1, 1, ...}.

    // static int series[SERIES_SIZE];
    // int series[SERIES_SIZE];
    int *series = (int *) malloc(n * sizeof(int));

    int index = 0;
    for(index = 0; index<SERIES_SIZE; index++) {
        *(series+index) = n;
        // series[index] = n;

        if(n>1) n--;
        //once n is already 1, just fill each remaining element with a 1
        //since this will not affect the result of the multiplication.
    }

    return series;
}
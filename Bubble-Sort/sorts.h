#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"



// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    //first outer loop to go through array size number of times
    for(unsigned int outer = 0; outer < size - 1; outer++) {
      int swap_counter = 0;
        //inner loop that should go through size-1 times since we compare the next value
        for(unsigned int inner = 0; inner < size - 1; inner++) {
            
            //printf("Value of a = %d and b = %d before call to swap\n", *(array+inner),*(array+inner+1));
            if(*(array+inner) > *(array+inner+1)) {
                swap_counter++;
                swap((array+inner),(array+inner+1));
            }
            //printf("Value of a = %d and b = %d after call to swap\n", *(array+inner),*(array+inner+1));
        }

        //print array after each outer pass
        if(print) {
          printf("Pass %u: ", outer + 1);
          printIntArray(array, size);
        }
        if(swap_counter == 0) {
          break;
    }
  }
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif
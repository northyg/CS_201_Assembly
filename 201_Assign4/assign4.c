
/* Giselle Northy
 *  Assignment 4 
 *  Summer 2020
 *  PLEASE FOLLOW DIRECTIONS WITHIN
 *  THE COMMENTS
 */

#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES         200000
#define ARRAY_SIZE       100000

int main(void)
{
    long *array = calloc(ARRAY_SIZE, sizeof(long));
    long sum = 0;
    long i=0;
    long value=1;

    // putting some values in the array
    // Do NOT modify this for loop
    for(i=0; i<ARRAY_SIZE; i++,value++)
         array[i] = value;

     // You can add variables between this comment ...



     // ... and this one.

     // do NOT modify the following line
     for (i = 0; i < N_TIMES; i++) {
                sum = 0;

                // You can change anything between this comment ...

        long j;
        int arraySize = ARRAY_SIZE; // I added this
        // I added this
        long sum1 = 0;
        long sum2 = 0;
        long sum3 = 0;
        long sum4 = 0;
        long sum5 = 0;

        for (j = 0; j < arraySize - 10; j += 11) // put in arraySize instead of ARRAY_SIZE. it was 5 and 6
        {
            sum1 += array[j];
            // add and change stuff
            sum2 += array[j+1];
            sum3 += array[j+2];
            sum4 += array[j+3];
            sum5 += array[j+4];
            sum1 += array[j+5];
            sum2 += array[j+6];
            sum3 += array[j+7];
            sum4 += array[j+8];
            sum5 += array[j+9];
            sum1 += array[j+10];
        }

        // ... and this one. But your inner loop must do the same
        // number of additions as this one does. All array 
        // elements should be accessed at least once.
        // I added this
        for(; j < arraySize; j++)
        {
            sum1 += array[j];
        }
        sum = sum1 + sum2 + sum3 + sum4 + sum5;
    }
        // You can add some final code between this comment ...

        // ... and this one.

    // these sum values need to match!
    printf("sum is %ld\n",sum);
    printf("sum should be 5000050000\n");
    return 0;
}
                                                                                                                                                                                                                                                                                                                                        
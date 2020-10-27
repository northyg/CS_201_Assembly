/*  Giselle Northy
 *  You can put answers to 
 *  questions here or
 *  in a separate text file.
 *  
 * In this file is a function called 'equals' that doesn't quite work with floating point values due to round off errors.
 *  There are two examples, one of which doesn't work. Do the following:
 * 
 * 1. Why is the first example not working?
 * 
 * ANSWER: Because there are round off errors and the comparison in 'equals' is checking if the value's exactly match.
 * Because they don't exactly match, it doesn't work.
 * 
 * 2. Fix the function 'equals' so that it works for both examples. 
 * We want the two numbers to be considered equal if they are equal in the first 3 decimals after the decimal point.
 * 
 * NOTE: There are several ways to do this. 
 * You can take the absolute value of the difference between a and b and compare it to a tolerance value. 
 * In other words, if
 * |a-b| < tol
 * is true, then we can say the values are 'equal'. 
 * The tolerance value should be just small enough to act as a 'cutoff' point for equality but no smaller.
 * 
 */ 


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int equals(float a, float b)
{
	if(fabs(a-b) < .0001)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void example1()
{
	
    float a=100.6;
	float b=100.0;
	
	for(int i=0; i < 6; i++)
	{
		a = a - .1;
	}
	printf("Example 1: these should equal each other\n\n");
   	if(equals(a, b))
   	{
		printf("%f and %f are equal.\n", a, b);
	}
	else
	{
		printf("%f and %f are NOT equal. \n", a, b);
	}
		
}

void example2()
{
	float a=100.006;
	float b=100.0;
	
	for(int i=0; i < 7; i++)
	{
		a = a - .001;
	}
	printf("Example 2: these should NOT equal each other\n"); // I changed txt Example 1: to 2
   	if(equals(a, b))
   	{
		printf("%f and %f are equal.\n", a, b);
	}
	else
	{
		printf("%f and %f are NOT equal. \n", a, b);
	}
		
	
}



int main()
{
    example1();
    example2();
    return 0;
}

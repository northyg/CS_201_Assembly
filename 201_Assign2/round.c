/*  Giselle Northy
 * Assignment 2
 * Part A: rounding floating point(20 points)
 *  
In the given file round.c, write four functions that take a float and round this value according to one of the four floating point rounding modes. 
The float can be either positive or negative. 
You can use the fabs and floor function in your code but no other math functions.

The floor() function takes a single argument and returns the value in type double.
The floor() function calculates the nearest integer less than the argument passed.

The fabs() function returns the absolute value of a number.
 */ 


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

float round_even(float number)
{
	double floorNum = floor(number);
   
   if((int)floorNum % 2 == 0)
   {
      //printf("Part A modulus 2 even do nothing\n");
   }
   else
   {
      //printf("part A it was odd add 1 \n ");
      floorNum = floorNum + 1;
   }
   return floorNum;
}

float round_minus_inf(float number)
{
   double floorNum = floor(number);
   //printf("part B stuff %f\n", floorNum);
   return floorNum;
}

float round_plus_inf(float number)
{
	double roundPlus = floor(number); 
   roundPlus = roundPlus + 1;
   return roundPlus;
}

// positive number round down towards zero
// negative number round up towards zero
float round_zero(float number)
{
	double roundZero = floor(number);
   if (roundZero > 0)
   {
      roundZero = roundZero;
   }
   else if (roundZero < 0)
   {
      roundZero = roundZero + 1;
   }
   return roundZero;
}


int main()
{
   float number = 0.0;
   
   printf("Enter float number: \n");
   scanf("%f", &number);
   
   float even = round_even(number);
   float minus = round_minus_inf(number);
   float plus = round_plus_inf(number);
   float zero = round_zero(number);
   
   printf("Round to nearest even: %f \n",even);
   printf("Round to minus infinity: %f \n",minus);
   printf("Round to plus infinity: %f \n",plus);
   printf("Round toward zero: %f \n",zero);
   
   return 0;
}   

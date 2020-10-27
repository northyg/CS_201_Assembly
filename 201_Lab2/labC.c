/*  Giselle Northy
 * Write a function that will multiple(multiply?) two numbers together without the use of the multiplication operator (*). 
 * Note that the second number is guaranteed to be a power of two.
 * NOTE: You can use a math function for getting the exponent from the second number. 
 * Or you can use a while loop to determine it.
 * 
 * NOTE: I'm using the pow() function to get the second number. This requires compiling with the math library option '-lm':
 * //http://www.cplusplus.com/reference/cmath/log2/
 * gcc -lm labC.c -o prog
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

//PUT YOUR CODE HERE

int multiply(int a, int b)
{
   int num=  ;
   int i = log2(b); 	

   num = a << i;

   //num = a;
   //for (int i = b; i > 1; i = i >> 1)
   //{
//	   num = num << 1;
  // }
   return num;
}


int main()
{
   	int num=0;
   	int e=0;

	printf("Enter an integer: ");
	scanf("%d", &num);

	printf("Enter a power of 2 for the second number: ");
	scanf("%d", &e);

	int num2 = (int) pow(2,e);
	printf("the second number is: %d\n", num2);

	int prod = multiply(num, num2);
	printf("the product from return: %d\n", prod);

	// checking result of multiply. Needs to be same return value as above  
	int rprod = num*num2;
	printf("the product is: %d\n", rprod);
	
    return 0;
}

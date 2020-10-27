/*  Assignment 1 - part A, B and C
 *  Please read the instructions
 *  for assignment 1 for details on
 *  what to code for each part.
 * 
 *  I will be copying your functions
 *  from this file to another file.
 *  Please put your code between
 *  the comments or they will
 *  not be copied correctly.
 * 
 *  Giselle Northy
 *  gcc -o assign1.cout assign1.c
 */

#include <stdio.h>

#define MAX_STR 100

/*
In the given file assign1.c, write a function that takes a 4 digit hexadecimal number as a string of 0-9 or A-F values and prints
out the binary digits. Assume the user will type in all capitals for letters.
HINT: the ASCII code for 0-9 starts at 48 and ends at 57. The ASCII code for A - F starts at 65 and ends at 70. 
Anything else is not a valid hex digit; if you encounter a invalid hex digit print an error message and return.
*/

//Part A - DO NOT CHANGE OR REMOVE THIS COMMENT
void hex_to_binary(char* hex)
{
	int i;
	
	for (int i =  0; hex[i] != '\0'; ++i)
	{
		//	char hex = 'a';
		// int ia = (int)a;
		char newHex = hex[i];
		int convertedHex = (int)newHex;

		if (convertedHex >= 65 && convertedHex <= 70)
		{
			// this is 65 to 70 for A-F
			//printf("Range [65, 70]\n");
			// Print out binary
			switch(convertedHex) 
			{
      			case 65 :
        			printf("1010");
         			break;
      			case 66 :
        			printf("1011");
         			break;
				case 67 :
        			printf("1100");
         			break;
				case 68 :
        			printf("1101");
         			break;
				case 69 :
        			printf("1110");
         			break;
				case 70 :
        			printf("1111");
         			break;
			}
		}


		else if (convertedHex >= 48 && convertedHex <= 57)
		{
			// ASCII values between 48 - 57
			// printf("Range [48, 57]\n");
			// Print out binary
			switch(convertedHex) 
			{
      			case 48 :
        			printf("0000");
         			break;
      			case 49 :
        			printf("0001");
         			break;
				case 50 :
        			printf("0010");
         			break;
				case 51 :
        			printf("0011");
         			break;
				case 52 :
        			printf("0100");
         			break;
				case 53 :
        			printf("0101");
         			break;
				case 54 :
        			printf("0110");
         			break;
				case 55 :
        			printf("0111");
         			break;
				case 56 :
        			printf("1000");
         			break;
				case 57 :
        			printf("1001");
         			break;
			}
 		}		

		else
		{
			// error message
			printf("\nError invalid digit! ");
			//printf("you typed %d\n\n", convertedHex);
			printf("%c Stopping Now!\n\n", newHex);
			return;
		}
	}
	printf("\nEnd Part A.\n");	
}

//End Part A - DO NOT CHANGE OR REMOVE THIS COMMENT

/*
Write a function that takes an unsigned integer num (note this is always positive or zero) and an int position pos (0..31) and returns the value 
of the (pos)th bit as an integer (this will be either 1, 0 or -1 for error). Check for pos being between 0 and 31 and if it's not return a -1.
*/

//Part B -DO NOT CHANGE OR REMOVE THIS COMMENT

int bit_value(unsigned number, int pos)
{
	if (pos >= 0 && pos <= 31)
	{
		int findBit = (number >> pos ) & 1;
		//printf("Findbit value!%d\n\n", findBit);
		return findBit;
	}
	else
	{
		//printf("Position not between 0 - 31!%d\n\n", pos);
		return -1;
	}
}
//End Part B - DO NOT CHANGE OR REMOVE THIS COMMENT

/*Write a function that takes two int numbers. 
It then returns a TRUE if there is an overflow (both positive and negative) of the sum of the two numbers.
HINT: For testing purposes, the largest positive int value before overflow is 2147483647. 
The largest negative value is -2147483648. 
When testing, make sure the two numbers aren't overflows themselves or you're function wont work. 
Get two numbers whose magnitude is less than 2147483647 for positive (negative: 2147483648) but the sum's 
magnitude is greater than 2147483647 for positive (negative: 2147483648). A positive and a negative number's
sum won't overflow if neither number is an overflow itself.
*/

//Part C - DO NOT CHANGE OR REMOVE THIS COMMENT
int overflow_check(int a, int b)
{
	// if A OR B is less than -214748364 or greater than 214748364
	// then there is overflow	
	if (a < -2147483648 || a > 2147483647)
	{
		//printf("1st part A%d\n\n", a);
		return 1;
	}
	else if (b < -2147483648 || b > 2147483647)
	{
		//printf("1st part B%d\n\n", b);
		return 1;
	}
	// 	2147483647. The largest negative value is -2147483648.
	else
	{
		int result = a + b;// if numbers are positive and sum is negative then overflow
		
		if (a > 0 && b > 0 && result < 0)
		{
			//printf("2nd part sums %d\n\n", result);
			return 1;
		}

		// if numbers are negative and sum is positive then overflow
		if (a < 0 && b < 0 && result > 0)
		{
			//printf("3rd part sums %d\n\n", result);
			return 1;
		}

		else
		{
			//printf("No overflow part %d\n\n", result);
			return 0;
		}
	}
}
//End Part C - DO NOT CHANGE OR REMOVE THIS COMMENT

int main()
{
	// These are here so you can test your
	// code. You can change them for
	// debugging your code but...
	// MAKE SURE YOUR CODE WORKS WITH
	// THE ORIGINAL CODE IN THIS FUNCTION OR
	// YOU WILL GET POINTS OFF!
	
	// Part A
	char hex[MAX_STR];
	printf("enter hex digits: ");
	scanf("%s",hex);
	hex_to_binary(hex);
	
	//Part B
	int num, pos, value;
	printf("enter number: ");
	scanf("%d",&num);
	printf("enter position (0 to 31): ");
	scanf("%d",&pos);
	value = bit_value(num, pos);
	printf("value is %d\n", value);
	
	//Part C
	int a, b;
	printf("enter two numbers to add: ");
	scanf("%d %d",&a, &b);
	printf("%d %d\n", a, b);
	if(overflow_check(a,b))
	{
		printf("there has been overflow\n");
	}
	else
	{
		printf("the sum is okay\n");
	}
	
	return 0;
}

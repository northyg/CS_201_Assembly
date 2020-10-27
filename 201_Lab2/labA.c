/* Giselle Northy
 * gcc -o labA.cout labA.c
 * Explain the output of the following
 * values: 20, -20, 200, -200
 * Then fix the function to work correctly.
 * NOTE: ONLY change the function.
 * 
 * #1 Explain why these values work or don't work:
 * 20 a (20) <= b (100)
 * -20 a (-20) > b (100)
 * 200 a (200) > b (100)
 * -200 a (-200) > b (100)
 * 
 * ANSWER: The reason why values -20 and -200 do not work is because the function b(the value holding the int
 * to compare with) was unsigned. Unsigned integer types can only represent positive and zero values, therefore
 * when comparing with the input, the result wasn't 'correct'.  
 * 
 * #2 Then change the function to work the way it should. Note that you should get a <= printout if the number is negative.
 * NOTE: Change the function ONLY. Don't touch the rest of the program. And don't change the types. Also, put your explanations inside comments in the file.
 * 
 * ANSWER: I changed unsigned b = 100 to signed b = 100. The reason is because signed integer types can represent positive, zero and negative values.
 * Therefore, the new outputs are 'correct':
 * 20 a (20) <= b (100)
 * -20 a (-20) <= b (100)
 * 200 a (200) > b (100)
 * -200 a (-200) <= b (100)
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

void compare(int a)
{
	/* Change this function so it works correctly
	 * test it with both positive, negative and zero
	 * values. You don't need to worry about overflow.
	 */ 
	 
	// an unsigned is an unsigned int type
	signed b = 100; // changed this from signed to unsigned

// if(a > (int) b)

	if(a > b)
	{
		printf("a (%d) > b (%d)\n", a, b);
	}
	else
	{
		printf("a (%d) <= b (%d)", a, b);
	}
}



int main()
{
	int num=0;
	printf("Enter an integer: ");
	scanf("%d", &num);
	compare(num);
	
    return 0;
}

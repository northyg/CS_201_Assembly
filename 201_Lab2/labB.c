/*  Giselle Northy
 *  gcc -o labB.cout labB.c
 *  The program inputs into a function a int type and then typecasts this number to various sizes and 
 * 		unsigned types.
 *  Explain the output for the following values: 1000, -1000, 100, -100. 
 *  Think about unsigned/signed encoding and overflow in your answer. 
 * 
 * Why do some numbers end up negative when the value was positive?
 * 
 * ANSWER: Some numbers end up negative when the value was positive because if the signed type most significant bit is 1, then it flips
 * to a negative number. This happens because the range for signed is half the size of unsigned. If the number is larger than TMAX then 
 * overflow happens and the number will be negative. Addiitionally, this can cause overflow which will ignore
 * the leftmost bits and result in a smaller number.
 * 
 * Why do some small numbers end up with a hugh(sp) magnitude when typecast to unsigned?
 * 
 * ANSWER:
 * 
 * Some small numbers end up with huge magnitude when typecast to unsigned because if the signed number is negative,
 * the end result is a very large positive number. Another reason is because when going from smaller 
 * to larger, in signed numbers, the left most bits will be filled in with what the left-most bit of the smaller
 * number was. 
 * 
 * Enter an integer: 1000
 
 1000 : 
 ->unsigned int: 1000
 ->unsigned char (as decimal) 232
 ->char (as decimal) -24
 ->unsigned long: 1000
 ->long: 1000

 Enter an integer: -1000
 -1000 : 
 ->unsigned int: 4294966296
 ->unsigned char (as decimal) 24
 ->char (as decimal) 24
 ->unsigned long: 18446744073709550616
 ->long: -1000

 Enter an integer: 100
 100 : 
 ->unsigned int: 100
 ->unsigned char (as decimal) 100
 ->char (as decimal) 100
 ->unsigned long: 100
 ->long: 100

 Enter an integer: -100
 -100 : 
 ->unsigned int: 4294967196
 ->unsigned char (as decimal) 156
 ->char (as decimal) -100
 ->unsigned long: 18446744073709551516
 ->long: -100
 */ 


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


void typecast(int a)
{
	unsigned b = (unsigned) a;
	unsigned char c = (unsigned char) a;
	char d = (char) a;
	unsigned long e = (unsigned long) a;
	long f = (long) a;
	
	// this illustrates some 
	printf(" %d : \n",a);
	printf(" ->unsigned int: %u\n",b);
	printf(" ->unsigned char (as decimal) %u\n",c);
	printf(" ->char (as decimal) %d\n",d);
	printf(" ->unsigned long: %lu\n",e);
	printf(" ->long: %ld\n",f);
	
}


int main()
{
   	int num=0;
	printf("Enter an integer: ");
	scanf("%d", &num);
	typecast(num);
	
    return 0;
}

/*  Giselle Northy
 *  Assignment 2 Part B + Extra Credit
 * 
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

/* Part B: 20 points
 * See instructions on how to do this part.
 * See the web site:
 *  http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#s4
 * for information on how to write gcc inline 
 * assembly.
 */
int regular_pay_asm(int payrate, int hours)
{
	// remember to put any register names
	// you are directly using in the
	// clobber list.
	// gpay - %0  hours - %1  payrate - %2
	int gpay=0;
    asm(" cmpl  $40, %1\n" // compare long less than 40
        " jle thingOne\n" // if less than 40 then jump to pay_rate = hours * pay_rate thingOne;
        " movl  $40, %1\n" // setting hours to 40
        "thingOne:  \n" // pay_rate =  hours * pay_rate
        " imull %1, %2\n" // multiply hours * payrate
        " movl %2, %0\n" // move source, destination

    : "=r"(gpay) /* output */
    : "r"(hours), "r"(payrate)/* input */
    :             /* clobbered register */
    );
	
	return gpay;
}


int regular_pay_c(int pay_rate, int hours)
{
	if(hours > 40)
  {
    hours = 40;
    pay_rate = hours * pay_rate;
  }
  else
  {
    pay_rate = hours * pay_rate;
  }
  
	return pay_rate;
}

/* EXTRA CREDIT: 15 points
 * calculate overtime pay
 * See instructions on how to do this part
 */
// gpay - %0  hours - %1  payrate - %2
int overtime_pay_asm(int payrate, int hours)
{
	// remember to put any register names
	// you are directly using in your asm
	int gpay;
    asm(" cmpl  $40, %1\n " // compare long less than 40
        " jg greaterFourty\n" // jmp if greater than
        " movl $0, %1\n" // put 0 into hours
        " jmp theEnd\n" // then jump to the end
        "greaterFourty:   \n"
        " subl $40, %1\n" // subtract 40 from hours
        " imull %1, %2\n" // multiply hours by payrate
        " movl  %2, %0\n" // move hours into gpay
        "theEnd:  \n" // end
        
    : "=r"(gpay) /* output */
    : "r"(hours), "r"(payrate)/* input */
    :    /* clobbered register */
    );
	
	return gpay;
}


// extra credit
int overtime_pay_c(int pay_rate, int hours)
{	 
	if (hours <= 40)
  {
    hours = 0;
  }
  else
  {
    hours = hours - 40;
  }
  pay_rate = hours * pay_rate;
  
  return pay_rate;
}

int main()
{
   int pay_rate = 15;
   int hours = 30;
   
   printf("enter pay rate: ");
   scanf("%d",&pay_rate);
   printf("enter hours: ");
   scanf("%d",&hours);
   
   int rpay_c = regular_pay_c(pay_rate, hours);
   int rpay_asm = regular_pay_asm(pay_rate, hours);
   printf("regular pay (C) is: %d \n",rpay_c);
   printf("regular pay (asm) is: %d \n", rpay_asm);
   
   // UNCOMMENT THIS CODE IF WANT TO DO THE
   // EXTRA CREDIT PART  
  int opay_c = overtime_pay_c(pay_rate, hours);
   int opay_asm = overtime_pay_asm(pay_rate, hours);
   printf("overtime pay (C) is: %d \n",opay_c);
   printf("overtime pay (asm) is: %d \n", opay_asm);
   
   printf("total gross pay: %d\n", (rpay_c+opay_c));
 
   
   return 0;
}

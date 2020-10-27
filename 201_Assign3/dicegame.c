
/**
 * Name: Giselle Northy
 * C201 - Assignment 3
 * Summer 2020
 * Requirements:
 * 
 * Need to use fork() to create 4 child processes. 
 * Each child process will roll two dice randomly using rand() function.
 * The parent needs to use waitpid() to reap each child and determine a win/loss/draw. 
 * Have each child prints out it's pid number and the two rolls of the dice before returning. 
 * Have the parent also print out the child pid and the sum so we can verify that the correct values were gotten
 * from the right child. 
 *  
 * The parent will print out the sum, determine and print out whether the child had a win/lose/draw, don't print 
 * this in the child process's code.
 * 
 * Note that you will need to do this inside the code for each child separately.
 * Now, you can use the rand() function to get a value from 0 to MAX_INT. This is
 * way too big so to cut it down, use a modulo (%) 6 and add 1 to get a value between 1 and 6:
**/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()
#include <time.h>           //for time()


int main()
{
   int pid = 0;
   
   for(int i = 1; i <= 4; i++)
   {
	   int dice1;
       int dice2;
       int sumDice;
       pid_t cpid = fork();
	   if(cpid == 0) // this is a child
	   {
		  srand((unsigned)time(0)*i); // seed random number, use time as part of it because time changes. Get unique number
          // the child processes are going to randomly roll two dice and the send back via the return value to the parent process the sum of the two dice. 
          dice1 = (rand() % 6) + 1; 
          dice2 = (rand() % 6) + 1;

          

          pid = getpid();
          printf("Child %d rolls a %d and a %d\n",pid, dice1, dice2);

          sumDice = dice1 + dice2;
          return sumDice;
	   }
   }
   
   // only parent gets this far
   int status;
   while ((pid = waitpid(-1, &status, 0)) > 0) 
   {
	  if (WIFEXITED(status))
      {
        printf("child %d gets a %d\n", pid, WEXITSTATUS(status));
         // The child won if the sum is either 7 or 11. The child lost if the sum is either 2, 3 or 12.
         // Any other value is a 'draw'. 
        if (WEXITSTATUS(status) == 7 || WEXITSTATUS(status) == 11)
        {
            printf("child %d has won!\n", pid);
        } 
        else if (WEXITSTATUS(status) == 2 || WEXITSTATUS(status) == 3 || WEXITSTATUS(status) == 12)
        {
            printf("child %d has lost!\n", pid);
        }
        else
        {
            printf("child %d gets a draw!\n", pid);
        }
      }           
   }
   return 0;
} 
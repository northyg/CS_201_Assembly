
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

int global = 10;

int main()
{
   pid_t pid, cpid1;
   int number = 1;
   
   // up to this point only the parent is running
   // global is 10 and number is 1.
   cpid1 = fork();
   // after this point BOTH parent and child
   // are running. The child inherits the 
   // variables declared before the fork
   // with their current values. However,
   // the 'number' variable is DIFFERENT
   // in each process.
   
   if(cpid1 < 0)
   {
	  // only parent exists if this happens
     printf("ERROR in forking\n");
     return 0;
   }
   // these lines are run by BOTH processes in their own flow
   pid = getpid(); // gets either the child or parent pid
   printf("BEFORE: pid %d number is %d global is %d\n",pid, number, global);
   if(cpid1 == 0)  // this is the child
   {
	   number = -100;
	   global = -100;
   }
   else // pid > 0 so this is the parent
   {
	   number = 200;
	   global = 200;
   }
   sleep(1); // pause for 1 second so both processes are done running.
   
   // NOTE: this will print TWICE because two different
   // processes are going to print it.
   printf("AFTER: pid: %d number is %d global is %d\n", pid, number, global);
   
   return 0;
}

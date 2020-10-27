
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

int main()
{
   pid_t pid, ppid1, ppid2, cpid1, cpid2;
   int number = 1;
   
   pid = getpid(); // gets parent id
   // up to this point only the parent is running
   cpid1 = fork();
   
   // after this point BOTH parent and child
   // are running the SAME code below
   // However, the cpid1 number is DIFFERENT
   // in the parent and the child.
   
   if(cpid1 < 0) //error condition
   {
	  // only parent exists if this happens
     printf("ERROR in forking\n");
   }
   else if(cpid1 == 0)  // this is the child
   {
	   // This code will be run by the child
	   // ONLY as the parent's cpid1 will not
	   // be 0.
	   pid_t cpid2 = getpid(); // child's pid
	   pid_t ppid2 = getppid();// parent's pid
	   printf("CHILD: child's pid is %d\n",cpid2);
	   printf("CHILD: parent's pid is %d\n", ppid2);
   }
   else // pid > 0 so this is the parent
        // the pid is the child's
   {
	   // This code will be run by the parent
	   // ONLY as it will have non-zero returned
	   pid_t ppid1 = getpid(); // parent's pid
	   printf("PARENT: child's pid is %d\n", cpid1);
	   printf("PARENT: parent's pid is %d\n", ppid1);
   }
   
   return 0;
}

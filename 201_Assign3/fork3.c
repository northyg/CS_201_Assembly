
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

int main()
{
   pid_t cpid1, pid;
   
   cpid1 = fork();
   
   if(cpid1 < 0)
   {
	  // only parent exists if this happens
     printf("ERROR in forking\n");
     return 0;
   }
   
   if(cpid1 == 0)  // this is the child
   {
	   printf("CHILD's pid is %d\n", getpid());
	   return 100;
   }
   

    // child has exited  so this is the parent
    printf("PARENT's pid is %d\n", getpid());
	int status;
	pid_t wpid = waitpid(-1, &status, 0); // taking defaults
	if(WIFEXITED(status)) {
	   int chstat = WEXITSTATUS(status);
	   printf("PARENT: child %d exited with a status of %d\n", wpid, chstat); 
   }  
   return 0; // ONLY parent returns here
}

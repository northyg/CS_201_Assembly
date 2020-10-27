
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

int main()
{
   int pid = 0;
   
   for(int i=1; i<=4; i++)
   {
	   pid_t cpid = fork();
	   if(cpid == 0) // this is a child
	   {
		  pid = getpid();
          printf("the %d child (pid %d) has been launched\n",i,pid);
	      return i;
	   }
   }
   
   // only parent gets this far
   int status;
   while ((pid = waitpid(-1, &status, 0)) > 0) {
	  if (WIFEXITED(status))
        printf("child %d terminated normally with exit status=%d\n",
                  pid, WEXITSTATUS(status));
      else
        printf("child %d terminated abnormally\n", pid);
   }
   return 0;
}

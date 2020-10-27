/*  This just shows how to use a global
 *  flag to get info back to the main 
 *  program.
 */
#include <unistd.h> // for sleep and write functions
#include <stdio.h>  // for printf
#include <signal.h>  // needed for the signal handling
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

// you can make this longer or shorter (it's in seconds)
#define MAX 5
#define STDOUT 1

volatile sig_atomic_t flag;

void signal_handler(int signum)
{
	flag = 1;
}

pid_t doFork()
{
    pid_t pid;
  
    pid = fork();
   
    if(pid < 0) //error condition
    {
	  // only parent exists if this happens
       printf("ERROR in forking\n");
       return -1;
    }
    
    if(pid == 0)  // this is the child
    {
	   pid_t cpid = getpid();
	   printf("CHILD %d is running\n", cpid);
    }
    
    return pid;
}

void waitOnChild()
{
	int status;
	// wait for child to end.
	pid_t wpid = waitpid(-1, &status, 0);
}

void busyWork(int parent)
{
	 // do some busy work
    int i = 0;
    while(i < MAX)
    {
		if(flag != 0)
		{
			if(parent)
			{
			    printf("parent %d got signal\n", getpid());
			}
			else
			{
				printf("child %d got signal\n", getpid());
				kill(getppid(), SIGINT);
		    }
			flag = 0;
		}
		sleep(1);
		i++;
    }
}

int main()
{
	flag = 0;
	//install signal handler for SIGINT
    signal(SIGINT, signal_handler);	
    
    pid_t cpid = fork();
   
	if(cpid > 0)
	{
		sleep(1);
		kill(cpid, SIGINT);
		busyWork(1);
        waitOnChild();		
	}
	else if(cpid == 0)
	{
		sleep(1);
		busyWork(0);
	}

    return 0;
}

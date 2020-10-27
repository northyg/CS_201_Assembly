/**
 * Giselle Northy
 * CS 201 - Lab 7 "Family Feud" Shootout with Signals
 * Summer 2020
 * 
 **/

#include <unistd.h> // for sleep and write functions
#include <stdio.h>  // for printf
#include <stdlib.h> // for rand
#include <signal.h>  // needed for the signal handling
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()
#include <time.h>           //for time()
#include <stdbool.h>    // for bool

// you can make this longer or shorter (it's in seconds)
#define MAX 5
//#define STDOUT 1

volatile sig_atomic_t flag;

void signal_handler(int signum)
{
	flag = (rand() % 49) + 1; // random 1-49, flags is the dmg
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

    // true means keep going
    // false means stop
bool busyWork(int parent)
{

    static int childDamage = 0;
    static int parentDamage = 0; 

     // do some busy work
    int i = 0;
    while(i < MAX)
    {
		if(flag != 0)
		{
            // get in here when other process sends us a signal
            // need to process it here:
            //   - DONE block new signals incoming "See sigblock.c on how to block a signal"
            //   - calculate and take damage "To process a hit, keep track in each process how much 
            //     damage has been done (this can be a local variable outside of the loop). "
            //   - check if taken full damage "If a process exceeds a maximum damage (I used 200) 
            //     then they have 'died'. Have them either quit using _exit or just break out of the 
            //     loop (the parent should break out and then wait for the child to end so it can be 'reaped')."
            //   - set flag back to 0
            //   - unblock new signals   sigprocmask(SIG_SETMASK,&prev_mask,&mask);

            // block signal
            //block SIGINT
            sigset_t mask, prev_mask;
            sigemptyset(&mask); // create an empty mask
            sigaddset(&mask, SIGINT);
            sigprocmask(SIG_BLOCK, &mask, &prev_mask);

            // calculate and take damage
            // check if taken full damage and explode

			if(parent)
			{
                parentDamage = parentDamage + flag;
                printf("parent %d got hit with + %d. damage is now %d!\n", getpid(), flag, parentDamage);
                if(parentDamage >= 200)
                {
                    printf("parent has died!\n");
                    return false;
                }
			}
			else
			{
			    childDamage = childDamage + flag;
                printf("child %d got hit with + %d. damage is now %d!\n", getpid(), flag, childDamage);
                if(childDamage >= 200)
                {
                    printf("child has died!\n");
                    return false;
                }
			}          
			flag = 0;
            
            // unblock signal
            sigprocmask(SIG_SETMASK,&prev_mask,&mask);
		}
		sleep(1);
		i++;
    }
    return true;
}

int main()
{
	srand(time(NULL));
    flag = 0;
	//install signal handler for SIGINT
    signal(SIGINT, signal_handler);	// when process gets SIGINT, call signal_handler function
    
    
    pid_t cpid = fork();

   for (int i = 0; i < 10; ++i)
   {
       	if(cpid > 0)  // this is the parent
	    {
            int randomTime = (rand() % 3) + 1; // random 1-3
            sleep(randomTime); // random

            kill(cpid, SIGINT); // parent send the signal SIGINT to child process
            bool keepGoing = busyWork(1);
            
            if(keepGoing == 0)
            {
                break;
            }
            if (i >= 9)
            {
                printf("parent has survived!\n");
            }
	    }
        else if(cpid == 0)   // this is the child
        {
            pid_t ppid = getppid();
            srand(time(NULL) % ppid); // different random seed for child process
            //sleep(1);
            int randomTime = (rand() % 3) + 1; // random 1-3
            sleep(randomTime); // random
            kill(ppid, SIGINT); // child sending parent a signal
            bool keepGoing = busyWork(0);
            
            if(keepGoing == 0)
            {
                break;
            }
            if (i >= 9)
            {
                printf("child has survived!\n");
            }
        }
   }
   // parent waiting to reap the child
   if(cpid > 0)
   {
        waitOnChild();
   }
    return 0;
}

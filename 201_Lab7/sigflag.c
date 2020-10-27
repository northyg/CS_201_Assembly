/*  This just shows how to use a global
 *  flag to get info back to the main 
 *  program.
 */
#include <unistd.h> // for sleep and write functions
#include <stdio.h>  // for printf
#include <signal.h>  // needed for the signal handling

// you can make this longer or shorter (it's in seconds)
#define MAX 10
#define STDOUT 1

volatile sig_atomic_t flag;

void signal_handler(int signum)
{
	if(signum == SIGINT)
	    flag = 1;
	else // assume SIGTSTP
	    flag = 2;
}

int main()
{
	//install signal handler for SIGINT
    signal(SIGINT, signal_handler);	
    signal(SIGTSTP, signal_handler);
    // Since we don't know when the
    // signal is coming, we will 
    // use a while loop to keep checking for
    // it to come. This is called 'polling'.
    flag = 0;
    while(1) // infinite loop (we'll break out of it when SIGINT)
    {
		sleep(1);
		if(flag == 1)
		{
			printf("Got a SIGINT! We'll quit now!\n");
			sleep(1); // needed to get printf to print before quitting
			break;
		}
		else if(flag == 2)
		{
			printf("Got a SIGTSTP! Not quitting\n");
			flag = 0; // re-set flag
		}
	}
	
    return 0;
}

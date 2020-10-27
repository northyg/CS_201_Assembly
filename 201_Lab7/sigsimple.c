/*  If you want to see the effects of handling the
 *  SIGINT signal, run this at a terminal and hit
 *  <ctrl> C to send the SIGINT signal to
 *  the program.
 */
#include <unistd.h> // for sleep and write functions
#include <stdio.h>  // for printf
#include <signal.h>  // needed for the signal handling

// you can make this longer or shorter (it's in seconds)
#define MAX 10
#define STDOUT 1

void sigint_handler(int signum)
{
	char mess[100] = "\nOuch!\n";
	
	// note that I'm using write
	// in the signal handler because
	// it is async-signal-safe
	write(STDOUT, mess, 7);
}

int main()
{
	int signum = SIGINT;
	
	//install signal handler for SIGINT
    signal(signum, sigint_handler);	
    
    // do some busy work
    int i =0;
    while(i < MAX)
    {
		sleep(1);
		i++;
    }
    printf("I've had enough! Goodbye!\n");
    return 0;
}

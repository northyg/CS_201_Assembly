/*  If you want to see the effects of blocking
 *  and non-blocking, hit either <ctrl> c or 
 * <ctrl> z.  Note this also shows how to have one
 * handler shared between the two signals.
 */
#include <unistd.h> // for sleep and write functions
#include <stdio.h>  // for printf
#include <signal.h>  // needed for the signal handling

// you can make this longer or shorter (it's in seconds)
#define MAX 10
#define STDOUT 1

void signal_handler(int signum)
{
	char mess_int[200] = "SIGINT signal was caught";
	char mess_tstp[200] = "SIGTSTP signal was caught";
	if(signum == SIGINT)
	    write(STDOUT, mess_int, sizeof(mess_int));
	else
	   write(STDOUT, mess_tstp, sizeof(mess_tstp));
}

void busyWork()
{
	 // do some busy work
    int i = 0;
    while(i < MAX)
    {
		sleep(1);
		i++;
    }
}

int main()
{
	
	//install signal handler for SIGINT
    signal(SIGINT, signal_handler);	
    signal(SIGTSTP, signal_handler);
    
    printf("Signals NOT blocked.....\n");
    busyWork();
    //block SIGINT AND SIGTSTP
    sigset_t mask, prev_mask;
    sigemptyset(&mask); // create an empty mask
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGTSTP);
    sigprocmask(SIG_BLOCK, &mask, &prev_mask);    
    printf("Blocking Signals...\n");
    busyWork();    
    return 0;
}

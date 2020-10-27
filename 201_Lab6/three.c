#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Note that before any fork call, only the parent is running. 
After fork is called, there are two processes running the same code.
 The return value for fork is one of three things:

pid < 0 - This is an error where the fork couldn't be done. Assume only the parent is running at this point.
pid == 0 - This is what is passed back in the child process. You can use an if statement to process any code that the child needs to run.
pid > 0 - This is what is passed back in the parent process. In fact, the pid is the child's pid. Again, you can use an if statement to run any code that only the parent needs to run.
Note that the child's pid is available to the parent but child itself will need to call getpid() to get it's own pid.
*/

void doWork()
{
    int size = 10000;
    int x;
    for (int i=0;i<size;i++)
	for (int j=0;j<size;j++)
	{
	    x = i * j;  
	    x = x;
	}
}

int main()
{
	printf("\n");
    int pid = fork(); // original process spawns a child

    if (pid == 0)
    {
	doWork();
	printf("red\n");
	fork(); // fork make new child ?
	doWork();
	printf("yellow\n");
    }
    else
    {
	doWork();
	printf("blue\n");
	fork(); // it would do the same code... 
	doWork();
	printf("green\n");
	wait(NULL);
    }



    return(0);
}

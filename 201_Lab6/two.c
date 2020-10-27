#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
    int pid = fork();

    if (pid == 0)
    {
	doWork(); // child process
	printf("red\n");
	doWork(); // do work again?
	printf("yellow\n");
    }
    else // parent processes ??
    {
	doWork();
	printf("blue\n");
	doWork();
	printf("green\n");
	wait(NULL);
    }




    return(0);
}

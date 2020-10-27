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
	    x = i * j;  
}

int main()
{
	printf("\n");
    int pid = fork();

    if (pid == 0)
    {
	doWork();
	printf("red\n");
    }
    else
    {
	doWork();
	printf("blue\n");
	wait(NULL);
    }



    return(0);
}

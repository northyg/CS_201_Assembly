/*  This is lab 8 part A.
 */
#include <stdlib.h> // for rand and srand
#include <string.h> // for strlen
#include <stdio.h>  // for printf
#include <time.h>   // for time

// PLEASE DON'T CHANGE THIS DEFINE!
#define NUMOFLINES 3000

int isVowel(char letter)
{
	if(letter == 'a' ||
	   letter == 'e' ||
	   letter == 'i' ||
	   letter == 'o' ||
	   letter == 'u')
	{
		return 1;
	}
		
	return 0;
}

int countAllVowels(char* lines[])
{
	int count = 0;
	for(int i=0; i<NUMOFLINES; i++)
	{
		for(int j=0; j < strlen(lines[i]); j++)
		{
			char letter = lines[i][j];
			if( isVowel(letter) ) count++;
		}
	}
	
	return count;
}

/*
void printLines(char* lines[])
{
	for(int i=0; i < NUMOFLINES; i++)
	{
		printf("%s\n", lines[i]);
	}
}
*/
// PLEASE DON'T CHANGE THIS FUNCTION!
void createLines(char* lines[])
{
	for(int i=0; i<NUMOFLINES; i++)
	{
	    int size = (rand() % 10000) + 1;
	    lines[i] = (char*) malloc(sizeof(char)*size+1);
        for(int j=0; j < size; j++)
        {
	        char letter = (char) (rand() % 26) + 97;
	        lines[i][j] = letter;
	    }
	    lines[i][size]='\0';
	}	
}

int main()
{
	char* lines[NUMOFLINES];
	
	srand((unsigned int)time(0));
	
	createLines(lines);
	//printLines(lines);
	int count = countAllVowels(lines);
	printf("count of vowels is %d\n", count);

    return 0;
}

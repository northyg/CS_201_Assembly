// Giselle Northy
// CS201 Lab1 Summer 2020
// Part A: Convert C++ to C (5 points)
// File lab1a.c
// gcc -o lab1a.out lab1a.c
// 10.2f where 10 is how wide to make the number and 2 is how many digits after the decimal point

#include <stdio.h>

#define SIZE = 100

struct Employee {
	char last_name[SIZE];
	double pay_rate;
};

void printPayroll(struct Employee list[], int count)
{
	printf("*** PAYROLL ***\n");
	int i;
	for(int i=0; i<count; i++)
	{
		printf("Last Name: %s,\n", list[i].last_name);
		printf("Pay Rate: %10.2f\n", list[i].pay_rate);
	}
}

void createPayroll(struct Employee list[], int *count)
{
	printf("how many employees? \n");
	scanf("%d", count);

	int i;
	for(int i=0; i<*count; i++)
	{
		char tname[100];
		printf("For employee %d\n", i + 1);
		printf("last name? \n");
		scanf("%s", list[i].last_name); // this needs check
		printf("pay rate?\n");
		scanf("%lf", &list[i].pay_rate); // check 
	}
}

int main()
{
    struct Employee list[SIZE];
    int count = 0;
    
    createPayroll(list, &count);
    
    printPayroll(list, count);
      
    return 0;
}

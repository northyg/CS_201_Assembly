
#include <stdio.h>
#include <stdlib.h>

double afunct(double ad, int count, double bd)
{
	double sd = ad*bd;
	double res = sd*count;
	return res;
}

double comparefp(double ad, int count, double bd)
{
	if(ad < bd)
	{
		return ad;
	}
	return bd;
	
}

void inputValues(double* ad, double* bd)
{
	printf("Enter two floats: ");
	scanf("%lf",ad);
	scanf("%lf",bd);
}

int main()
{
	double ad = 0.0;
	double bd = 0.0;
	int count = 8;
	
	inputValues(&ad, &bd);
	
	double res = afunct(ad, count, bd);
	printf("product is %6.4lf\n", res);
	
   return 0;	
}

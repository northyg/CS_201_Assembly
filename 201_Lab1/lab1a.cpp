#include <iostream>

using namespace std;

const int SIZE = 100;

struct Employee {
	char last_name[SIZE];
	double pay_rate;
};

void printPayroll(Employee list[], int count)
{
	cout << "*** PAYROLL ***" << endl;
	
	for(int i=0; i<count; i++)
	{
		cout << "Last Name: " << list[i].last_name << endl;
		cout << "Pay Rate: " << list[i].pay_rate << endl;
	}
}

void createPayroll(Employee list[], int &count)
{
	cout << "how many employees? " << endl;
	cin >> count;
	
	for(int i=0; i<count; i++)
	{
		char tname[100];
		cout << "For employee" << i+1 << endl;
		cout << "last name? ";
		cin >> list[i].last_name;
		cout << "pay rate?";
		cin >> list[i].pay_rate;
	}
	
}

int main()
{
    Employee list[SIZE];
    int count = 0;
    
    createPayroll(list, count);
    
    printPayroll(list, count);
      
    return 0;
}

/*This is a currency converter program.*/
/*Please note that the conversions are done keeping in mind the latest conversion tables.*/
#include "pch.h"//the necessary header files are included
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
double amount;//the necessary identifiers are declared
double rupees, paise, pounds, pence, dollars, cents;
int ch;
struct Input//structure with input types are declared
{
	 double rupees;
	 double pounds;
	 double dollars;
};
Input i1;
void menu()//menu for the user to choose from
{
	cout << "Press 0 to exit." << endl;
	cout << "Press 1 to convert from rupees to pounds and pence." << endl;
	cout << "Press 2 to convert from pounds to rupees and paise." << endl;
	cout << "Press 3 to convert from rupees to dollars and cents." << endl;
	cout << "Press 4 to convert from dollars to rupees and paise." << endl;
	cout << "Press 5 to convert from pounds to dollars and cents." << endl;
	cout << "Press 6 to convert from dollars to pounds and pence." << endl;
}
void take_input()//the amount is to be taken input by the user
{
	cout << "Enter the choice:";
	cin >> ch;
	while (ch > 6 || ch < 0 || (!cin >> ch))
	{
		cout << "Enter the choice:";
		cin.clear();
		cin.ignore();
		cin >> ch;
	}
}
void take_amount()
{
	cout << "Enter the amount to be converted:";
	cin >> amount;
	while (cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
	{
		cout << "Enter the amount to be converted:";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> amount;
	}
}
//various conversion using functions
void rupees_pounds()
{
	if (ch == 1)
	{
		i1.rupees = amount;
		pounds = i1.rupees / 86.63;
		pence = abs(100-pounds);
		cout << i1.rupees << "Rupees=" << int(pounds) << "Pounds and " << pence << " pence" << endl;
	}
}
void pounds_rupees()
{
	if (ch == 2)
	{
		i1.pounds = amount;
		rupees = i1.pounds*86.63;
		paise = abs(100-rupees);
		cout << i1.pounds << "Pounds=" << int(rupees) << "Rupees and " << paise << " paise" << endl;
	}
}
void rupees_dollars()
{
	if (ch == 3)
	{
		i1.rupees = amount;
		dollars = i1.rupees / 71.42;
		cents = abs(100-dollars);
		cout << i1.rupees << "Rupees=" << int(dollars) << "Dollars and " << cents << " cents" << endl;
	}
}
void dollars_rupees()
{
	if (ch == 4)
	{
		i1.dollars = amount;
		rupees = i1.dollars*71.42;
		paise = abs(100-rupees);
		cout << i1.dollars << "Dollars=" << int(rupees) << "Rupees and " << paise << " paise" << endl;
	}
}
void pounds_dollars()
{
	if (ch == 5)
	{
		i1.pounds = amount;
		dollars = i1.pounds*1.21;
		cents = abs(100-dollars);
		cout << i1.pounds << "Pounds=" << int(dollars) << "Dollars and " << cents << " cents" << endl;
	}
}
void dollars_pounds()
{
	if (ch == 6)
	{
		i1.dollars = amount;
		pounds = dollars * 0.83;
		pence = abs(pounds-0.100);
		cout << i1.dollars << " Dollars=" << int(pounds) << "Pounds and " << pence << " pence" << endl;
	}
}
int main()//start of main
{
	while(1)
	{
		menu();
		take_input();
		if (ch == 0)
			break;
		take_amount();
		rupees_pounds();
		pounds_rupees();
		rupees_dollars();
		dollars_rupees();
		pounds_dollars();
		dollars_pounds();
	}
	return 0;
}//end of main
#include "pch.h"
#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
using namespace std;
double bill;
int n;
double pay;
int rupee, paise;
void take_input()
{
	cout << "Enter the total amount of bill generated:";
	cin >> bill;
	while (cin.fail()||(cin.peek()!='\r' && cin.peek()!='\n'))
	{
		cout << "Enter the total amount of bill generated:";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> bill;
	}
	cout << "Enter the total number of people in your squad:";
	cin >> n;
	while (!cin >> n)
	{
		cout << "Enter the total number of people in your squad:";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
}
void split_bill()
{
	pay = bill / n;
	pay *= 100;
	rupee = pay / 100;
	paise = int(pay) % 100;
	cout<< rupee <<"Rupees and "<< paise << "paise" << endl;
}
int main()
{
	take_input();
	split_bill();
	return 0;
}
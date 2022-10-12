#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


int length(double n)
{
	if (n >= 10)
	{
		int d = log10(n);
		return d + d / 3 + 4;
	}
	else
		return 4;
}


void commaNumber(ofstream& o, double x)
{
	int wholeNumbers, decimals, length;
	//if (x == 0)
	//{

		//o << "0.00";
		//exit(0);
	//}

	wholeNumbers = x;
	decimals = (x * 100) - (wholeNumbers * 100);

	if (x == 0 && decimals < 10)
	{
		o << "0.0" << decimals;
		return;
	}
	else if (x == 0 && decimals > 10)
	{
		o << "0." << decimals;
		return;
	}
	length = log10(wholeNumbers) + 1;
	const int MAXLENGTH = length;

	for (; 2 <= length; --length)
	{
		bool start = true;
		int singleValue;
		int  power = 0;
		while (start)
		{
			++power;
			singleValue = wholeNumbers / pow(10, power);
			if (singleValue >= 10)
				continue;
			if (length % 3 == 0 && length != MAXLENGTH)
				o << ",";
			cout << singleValue; 
			wholeNumbers -= singleValue * pow(10, length - 1); 
			if (length == 2)
			{
				if (decimals < 10)
				{
					o << wholeNumbers;
					o << ".0" << decimals;
					//length = 0;
				}
				else if (decimals > 10)
				{
					o << wholeNumbers;
					o << "." << decimals;
					//length = 0;
				}
			}
			start = false;
		}
	}

}


void blanks(ofstream& o, int n)
{
	for (int i = 1; i <= n; i++)
		o << " ";
}


void printDollarNumber(ofstream& o, double x, int s, int c)
{
	int b = s - length(x);
	int h = b / 2;

	switch (c)
	{
	case 1:
		commaNumber(o, x);
		blanks(o, b);
		break;
	case 2:
		blanks(o, h);
		commaNumber(o, x);
		blanks(o, b - h);
		break;
	case 3:
		blanks(o, b);
		commaNumber(o, x);
		break;
	default:
		cout << "Wrong code" << endl;
		break;
	}
}


int main()
{
	const int SPACE = 12;
	double loanAmount, intRate, addtlPrincipal;
	int years;

	do
	{
		cout << "Enter Loan amount (0-9999999), for example 300000.90: ";
		cin >> loanAmount;
	} while ((loanAmount <= 0) || (loanAmount > 9999999));

	do
	{
		cout << "Enter annual interest rate(0-50), for example 4.25 meaning 4.25%: ";
		cin >> intRate;
	} while ((intRate <= 0) || (intRate > 50));

	do
	{
		cout << "Enter no. of years as integer(1-50), for example 30: ";
		cin >> years;
	} while ((years < 1) || (years > 50));

	do
	{
		cout << "Enter additional principal per month (0-9999999), for example 300: ";
		cin >> addtlPrincipal;
	} while ((addtlPrincipal < 0) || (addtlPrincipal > 9999999));

	string fileName;

	cout << "Send the mortgage amortization table to a file (enter file name): ";
	cin >> fileName; 

	ofstream outFile(fileName);

	double monIntRate = intRate / 1200;

	double mthlyPymt = loanAmount * monIntRate / (1 - 1 / pow(1 + monIntRate, years * 12));

	double actPymt = mthlyPymt + addtlPrincipal;
	double balance = loanAmount;
	double interest;
	double principal;

	outFile << endl << endl;
	outFile << "\n\t MORTGAGE AMORTIZATION TABLE" << endl;
	outFile << "\nAmount:\t\t\t" << "$";
	printDollarNumber(outFile, loanAmount, SPACE, 3);
	outFile << endl;
	outFile << "Interest Rate:\t\t" << intRate << "%" << endl;
	outFile << "Term(Years):\t\t" << years << endl;
	outFile << "Monthly Payment:\t" << "$";
	printDollarNumber(outFile, mthlyPymt, SPACE, 3);
	outFile << endl;
	outFile << "Additonal Principal:\t" << "$";
	printDollarNumber(outFile, addtlPrincipal, SPACE, 3);
	outFile << endl;
	outFile << "Actual Payment:\t\t" << "$";
	printDollarNumber(outFile, actPymt, SPACE, 3);
	outFile << endl << endl;
	outFile << "\t"; 
	blanks(outFile, SPACE - 9);
	outFile << "Principal\t"; 
	blanks(outFile, SPACE - 8);
	outFile << "Interest\t"; 
	blanks(outFile, SPACE - 7);
	outFile << "Balance" << endl;


	for (int term = 1; balance > 0; term++)
	{
		actPymt = mthlyPymt + addtlPrincipal;
		interest = balance * monIntRate;
		principal = actPymt - interest;
		//outFile << term << "\t";
		if (balance < actPymt)
		{
			principal = balance;
			balance = 0.00;
			blanks(outFile, SPACE - 9);
			printDollarNumber(outFile, principal, SPACE, 1);
			printDollarNumber(outFile, interest, SPACE, 2);
			printDollarNumber(outFile, balance, SPACE, 3);
		}
		balance -= principal;

		for (int choice = 1; choice <= 3; choice++)
		{
			/*if (term == 1)
			{
				outFile << "$";
			}*/
			double number;
			if (choice == 1)
				number = principal;
			else if (choice == 2)
				number = interest;
			else if (choice == 3)
				number = balance;
			blanks(outFile, SPACE - 9);
			printDollarNumber(outFile, number, SPACE, choice);
		}
		outFile << endl;
	}
	outFile.close();

	system("pause");
	return 0;



}

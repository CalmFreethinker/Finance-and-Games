/*Mortgage amortization table*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double loan_amount, interest_rate, monthly_payment,
		actual_payment, principal, current_balance,
		additional_principal, number_of_years,
		interest, factor;

	cout << "Please enter loan amount: ";
	cin >> loan_amount;
	if (loan_amount <= 0 || loan_amount > 9999999)
	{
		cout << "Invalid: You need to enter an amount greater than $0.00 and less than $10,000,000.00: ";
		cin >> loan_amount;
	}
	cout << "Please enter the annual interest rate: ";
	cin >> interest_rate;
	if (interest_rate < 0.001 || interest_rate > 99.999)
	{
		cout << "Invalid: You need to enter a rate equal to or between 0.001 and 99.999: ";
		cin >> interest_rate;
	}
	cout << "Please enter the term or number of years: ";
	cin >> number_of_years;
	if (number_of_years <= 0 || number_of_years > 65)
	{
		cout << "Invalid: Please enter any number from 1 to 65 only: ";
		cin >> number_of_years;
	}
	cout << "Additional principal payment per month: ";
	cin >> additional_principal;
	if (additional_principal < 0 || additional_principal > loan_amount)
	{
		cout << "Invalid: You need to enter an amount greater than $0.00 and less than $" << loan_amount << ": ";
		cin >> additional_principal;
	}

	cout << endl << setw(47) << "MORTGAGE AMORTIZATION TABLE\n";
	cout << "\nAmount " << setw(21) << " $   " << setprecision(2) << fixed << loan_amount;
	cout << "\nInterest Rate " << setw(24) << setprecision(3) << fixed << interest_rate << "%\n";

	interest_rate = (interest_rate / 100) / 12;
	factor = interest_rate * (1 / (1 - pow(1 + interest_rate, -(number_of_years * 12))));
	monthly_payment = loan_amount * factor;
	actual_payment = monthly_payment + additional_principal;

	cout << setprecision(0) << fixed << "Term (Years)" << setw(22) << number_of_years;
	cout << "\nMonthly Payment " << setprecision(2) << fixed << setw(10) << " $ " << setw(11) << monthly_payment;
	cout << "\nAdditional Principal " << setw(16) << additional_principal;
	cout << "\nActual Payment " << setw(22) << actual_payment << endl;
	cout << "\nTerm " << setw(14) << " Principal " << setw(16);
	cout << " Interest " << setw(19) << " Balance\n";
	current_balance = loan_amount;
	
	for (int term=1; current_balance > 0; term++)
	{
		actual_payment = monthly_payment + additional_principal;
		interest = current_balance * interest_rate;
		principal = actual_payment - interest;
		if (current_balance < actual_payment)
		{
			principal = current_balance;
			cout << term << setw(14) << principal
				<< setw(17) << interest << setw(18)
				<< setw(17) << "0" << endl;
		}
		current_balance -= principal;

		if (term == 1)
			cout << term << setw(4) << "$ " << setw(12) << principal
			<< setw(9) << " $ " << setw(8) << interest << setw(9)
			<< " $ " << setw(11) << current_balance << endl;

		else if (!(current_balance <= 0))
			if (term > 1 && term <= 9)
			{
				cout << term << setw(16) << principal << setw(17);
				cout << interest << setw(20) << current_balance << endl;
			}
			else if (term >=10 && term < 100)
			{
				cout << term << setw(15) << principal << setw(17);
				cout << interest << setw(20) << current_balance << endl;
			}
			else if (term >= 100 && term < 1000)
			{
				cout << term << setw(14) << principal << setw(17)
					<< interest << setw(20) << current_balance << endl;
			}
	}
	return 0;
}
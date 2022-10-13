#include <iostream>
using namespace std;

int main()
{
	int blank, number, count, i;

	cout << "Enter an integer: ";
	cin >> number;
	while (number == 0)
	{
		cout << "Error: Enter a value that is greater than 0: ";
		cin >> number;
	}
	for (count = 1, i = 0; count <= number; ++count, i = 0)
	{
		for (blank = 1; (number - count) >= blank; ++blank)
		{
			cout << "X";
		}
		while (i != (2 * count - 1))
		{
			cout << "* ";
			++i;
		}
		cout << endl;
	}
	return 0;
}
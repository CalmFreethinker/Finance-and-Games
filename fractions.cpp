#include <iostream> 
#include <cmath>
using namespace std;

int gcf(int a, int b)
{
	int d;
	if (abs(a) > abs(b))
		d = abs(b);
	else
		d = abs(a);
	while (((a%d != 0) || (b%d != 0)) && (d > 1))
		d--;
	return d;
}

class Rational
{
public:
	Rational();
	Rational(int, int);
	Rational(const Rational&); // copy constructor
	void setNumerator(int);
	void setDenominator(int);
	int getNumerator() const;
	int getDenominator() const;
	const Rational& operator=(const Rational&);
	Rational operator+(const Rational&) const;
	Rational operator-(const Rational&) const;
	Rational operator*(const Rational&) const;
	Rational operator/(const Rational&) const;
	Rational operator++(); // prefix ++
	Rational operator++(int); // postfix ++
	bool operator==(const Rational&) const;
	bool operator>(const Rational&) const;
	bool operator<(const Rational&) const;
	operator int() const; // object conversion 
	operator double() const; //object conversion 
	~Rational(); // destructor 
private: 
	double fraction;
	int numerator;
	int denominator;
	int objectID;
	static int objectCount;
	friend istream& operator>>(istream& i, Rational & r);
	friend ostream& operator<<(ostream& o, const Rational& r);
};

int Rational::objectCount = 0;


Rational::Rational()
{
	fraction = 0.0;
	numerator = 0;
	denominator = 1;
	objectID = ++objectCount;
	cout << "Constructor of object " << objectID << " : " << numerator << "/" << denominator << endl;

}

Rational::Rational(int numer, int denom)
{
	numerator = numer;
	denominator = denom;
	objectID = ++objectCount;
	cout << "Constructor of object " << objectID << " : " << numerator << "/" << denominator << endl;
}

Rational::Rational(const Rational& obj)
{
	numerator = obj.numerator;
	denominator = obj.denominator;
	objectID = ++objectCount;
	cout << "Copy Constructor of object " << objectID << " from object 5" << endl;
}


void Rational::setNumerator(int numer)
{
	numerator = numer;
}

void Rational::setDenominator(int denom)
{
	denominator = denom;
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}


const Rational& Rational::operator=(const Rational& right)
{
	if (this != &right)
	{
		numerator = right.numerator;
		denominator = right.denominator;
		objectID = ++objectCount;
		cout << "Assignment from object " << objectID << " to " << "object 5" << endl;
	}
	return *this;
}

Rational Rational::operator+(const Rational&right) const
{
	Rational temp;
	if (denominator == right.denominator)
		temp.numerator = numerator + right.numerator;
	else
	{
		temp.denominator = denominator * right.denominator;
		temp.numerator = (right.numerator * denominator) + (numerator * right.denominator);
	}
	return temp;
}


Rational Rational::operator-(const Rational& right) const
{
	Rational temp;
	if (denominator == right.denominator)
		temp.numerator = numerator - right.numerator;
	else
	{
		temp.denominator = denominator * right.denominator;
		temp.numerator = (right.numerator * denominator) - (numerator * right.denominator);
	}
	return temp;
}

Rational Rational::operator*(const Rational&right) const
{
	Rational temp;
	temp.numerator = numerator * right.numerator;
	temp.denominator = denominator * right.denominator;
	return temp;
}

Rational Rational::operator/(const Rational& right) const
{
	Rational temp;
	temp.numerator = numerator * right.denominator;
	temp.denominator = denominator * right.numerator;
	return temp;
}

Rational Rational::operator++()
{
	numerator = denominator * 1 + numerator;
	return *this;
}

Rational Rational::operator++(int)
{
   Rational temp(numerator, denominator);
   numerator = denominator * 1 + numerator;
   return temp;
}

bool Rational::operator==(const Rational& right) const
{
	bool status;
	if (denominator == right.denominator)
	{
		if (numerator == right.numerator)
			status = true;
		else
			status = false;
	}
	else
	{
		int commonDenominator = denominator * right.denominator;
		int top = numerator * commonDenominator;
		int top2 = right.numerator * commonDenominator;
		if (top == top2)
			status = true;
		else
			status = false;
	}
	return status;
}

bool Rational::operator>(const Rational& right) const
{
	bool status;
	if (denominator == right.denominator)
	{
		if (numerator > right.numerator)
			status = true;
		else
			status = false;
	}
	else
	{
		int commonDenominator = denominator * right.denominator;
		int top = numerator * commonDenominator;
		int top2 = right.numerator * commonDenominator;
		if (top > top2)
			status = true;
		else
			status = false;
	}
	return status;
}

bool Rational::operator<(const Rational& right) const
{
	bool status;
	if (denominator == right.denominator)
	{
		if (numerator < right.numerator)
			status = true;
		else
			status = false;
	}
	else
	{
		int commonDenominator = denominator * right.denominator;
		int top = numerator * commonDenominator;
		int top2 = right.numerator * commonDenominator;
		if (top < top2)
			status = true;
		else
			status = false;
	}
	return status;
}

Rational::operator int() const
{
	int temp = numerator / denominator;
	return temp;
}

Rational::operator double() const
{
	double temp = (numerator / 1.0) / denominator;
	return temp;
}


istream& operator>>(istream& i, Rational& r)
{
	i >> r.fraction >> r.fraction >> r.fraction >> r.fraction;
	return i;
}


Rational:: ~Rational()
{
	
	cout << "Destructor of object " << objectID << endl;
}

ostream& operator<<(ostream& o, const Rational& r)
{
	o << r.numerator << " / " << r.denominator << endl;
    return o;
}

int main()
{
	Rational r1, r2, r3, r4, r5, r6, r7;
	cout << "Please enter 4 rational numbers: ";
	cin >> r1 >> r2 >> r3 >> r4;
	if (r1 > r2) 
		r5 = r3 + r4;
	else
		r5 = r3 - r4;
	if (r3 == r4) 
		r6 = r1 * r2;
	else
		r6 = r1 / r2;
	cout << "r5 = " << r5 << endl;
	cout << "r6 = " << r6 << endl;

	r7 = ++r5;
	cout << "r5 = " << r5 << endl;
	cout << "r7 = " << r7 << endl;

	r7 = r6++;
	cout << "r6 = " << r6 << endl;
	cout << "r7 = " << r7 << endl;

	r7 = r6 = r5;
	cout << "r7 = " << r7 << endl;
	return 0;
}

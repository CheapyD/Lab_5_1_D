#include "FuzzyNumber.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

FuzzyNumber makeFuzzyNumber(FuzzyNumber c)
{
	return c;
}

void Call_Bad() throw(int)
{
	throw 'x';
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	double x, l, r;
	do
	{
		cout << "x = "; cin >> x;
		cout << "l = "; cin >> l;
		cout << "r = "; cin >> r;
	} while (!(x > (x - l) && (x + r) > x));

	FuzzyNumber A(x, l, r);
	cout << A << endl;
	cout << "Size of class: " << sizeof(A) << endl;

	FuzzyNumber B(5, 1, 7);
	cout << B << endl;

	FuzzyNumber C = A + B;
	cout << "C: " << endl;
	cout << C << endl;

	FuzzyNumber D = A * B;
	cout << "D: " << endl;
	cout << D << endl;

	FuzzyNumber L = makeFuzzyNumber(D);
	cout << L << endl;
	try
	{
		A--;
	}
	catch (MyDerivedException a)
	{
		cerr << a.What() << endl << endl;
	}
	catch (MyDerivedException* a)
	{
		cerr << a->What() << endl << endl;
	}

	do
	{
		cout << "x = "; cin >> x;
		cout << "l = "; cin >> l;
		cout << "r = "; cin >> r;
	} while (!(x > (x - l) && (x + r) > x));

	FuzzyNumber N(x, l, r);

	try
	{
		N++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Triad K;
		cin >> K;
		cout << "K:" << endl;
		cout << K << endl;

		Triad M(-4.5, 3.8, 9.2);
		cout << "M:" << endl;
		cout << M << endl;

		if (K == M)
			cout << "triads are equal" << endl;
		else
			cout << "triads are not equal" << endl;

		if (K != M)
			cout << "triads are not equal" << endl;
		else
			cout << "triads are equal" << endl;

		if (K > M)
			cout << "Triad A is bigger than Triad B" << endl;
		else
			cout << "Triad A is smaller than Triad B" << endl;

		if (K < M)
			cout << "Triad A is smaller than Triad B" << endl;
		else
			cout << "Triad A is bigger than Triad B" << endl;

		if (K >= M)
			cout << "Triad A is bigger than/equal to Triad B" << endl;
		else
			cout << "Triad A is smaller than/equal to Triad B" << endl;

		if (K <= M)
			cout << "Triad A is smaller than/equal to Triad B" << endl;
		else
			cout << "Triad A is bigger than/equal to Triad B" << endl;
	}
	catch (MyException a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (out_of_range& a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}

}
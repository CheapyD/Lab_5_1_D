#include "Triad.h"

Triad::Triad()
	: x(0), l(0), r(0)
{}

Triad::Triad(double x, double l, double r) throw (out_of_range)
{
	if (!((x > -10 && x < 10) || (l > -10 && l < 10) || (r > -10 && r < 10)))
		throw out_of_range("Numbers must belong to [-10;10]");
	
	this->x = x;
	this->l = l;
	this->r = r;
}

Triad::Triad(const Triad& A)
{
	SetX(A.GetX());
	SetL(A.GetL());
	SetR(A.GetR());
}

Triad& Triad::operator =(const Triad& n)
{
	SetX(n.GetX());
	SetL(n.GetL());
	SetR(n.GetR());
	return *this;
}

bool operator == (const Triad& A, const Triad& B)
{
	return (A.GetX() == B.GetX() && A.GetL() == B.GetL() && A.GetR() == B.GetR());
}

bool operator != (const Triad& A, const Triad& B)
{
	return !(A == B);
}

bool operator > (const Triad& A, const Triad& B)
{
	return ((A.GetX() > B.GetX()) || (A.GetX() == B.GetX() && A.GetL() > B.GetL()) ||
		(A.GetX() == B.GetX() && A.GetL() == B.GetL() && A.GetR() > B.GetR()));
}

bool operator < (const Triad& A, const Triad& B)
{
	return ((A.GetX() < B.GetX()) || (A.GetX() == B.GetX() && A.GetL() < B.GetL()) ||
		(A.GetX() == B.GetX() && A.GetL() == B.GetL() && A.GetR() < B.GetR()));
}

bool operator >= (const Triad& A, const Triad& B)
{
	return !(A < B);
}

bool operator <= (const Triad& A, const Triad& B)
{
	return !(A > B);
}

Triad::operator string() const
{
	stringstream ss;
	ss << "x = " << x << endl;
	ss << "l = " << l << endl;
	ss << "r = " << r << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Triad& A)
{
	out << string(A);
	return out;
}

istream& operator >> (istream& in, Triad& A) throw(MyException)
{
	double x, l, r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;

	if (!((x > -10 && x < 10) || (l > -10 && l < 10) || (r > -10 && r < 10)))
		throw MyException("Numbers must belong to [-10;10]");

	A.SetX(x); A.SetL(l); A.SetR(r);
	return in;
}
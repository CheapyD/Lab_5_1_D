#pragma once
#pragma pack(1)
#include "MyException.h"
#include "MyDerivedException.h"

class Triad
{
private:
	double x, l, r;

public:
	Triad();
	Triad(double x, double l, double r) throw(out_of_range);
	Triad(const Triad& a);

	double GetX() const { return x; }
	double GetL() const { return l; }
	double GetR() const { return r; }

	void SetX(double value) { x = value; }
	void SetL(double value) { l = value; }
	void SetR(double value) { r = value; }

	Triad& operator =(const Triad& n);
	operator string() const;

	friend bool operator == (const Triad& l, const Triad& r);
	friend bool operator != (const Triad& l, const Triad& r);
	friend bool operator > (const Triad& l, const Triad& r);
	friend bool operator < (const Triad& l, const Triad& r);
	friend bool operator >= (const Triad& l, const Triad& r);
	friend bool operator <= (const Triad& l, const Triad& r);

	friend ostream& operator << (ostream& out, const Triad& a);
	friend istream& operator >> (istream& in, Triad& a) throw(MyException);
};


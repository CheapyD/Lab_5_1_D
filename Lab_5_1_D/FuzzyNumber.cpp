#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	: Triad()
{}

FuzzyNumber::FuzzyNumber(double X, double L, double R) throw(logic_error)
{
	if (!(X > (X - L) && (X + R) > X))
		throw logic_error("Condition is not met");

	this->SetX(X);
	this->SetL(X - L);
	this->SetR(X + R);
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	: Triad(v)
{}

FuzzyNumber& FuzzyNumber::operator --() throw(MyDerivedException)
{
	this->SetL(this->GetL() - 1);
	if (this->GetL() < 0)
		throw new MyDerivedException();
	return *this;
}

FuzzyNumber& FuzzyNumber::operator ++() throw(MyException)
{
	this->SetR(this->GetR() + 1);
	if (this->GetR() > 10)
		throw MyException("Right coordinate bigger than 10");
	return *this;
}

FuzzyNumber FuzzyNumber::operator --(int) throw(MyDerivedException)
{
	FuzzyNumber a(*this);
	this->SetL(this->GetL() - 1);
	if (this->GetL() < 0)
		throw MyDerivedException();
	return a;
}

FuzzyNumber FuzzyNumber::operator ++(int) throw(logic_error)
{
	FuzzyNumber a(*this);
	this->SetR(this->GetR() + 1);
	if (this->GetR() > 10)
		throw logic_error("Right coordinate bigger than 10");
	return a;
}

FuzzyNumber operator + (const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber T;
	T.SetX(a.GetX() + b.GetX());
	T.SetL(a.GetX() + b.GetX() - a.GetL() - b.GetL());
	T.SetR(a.GetX() + b.GetX() + a.GetR() + b.GetR());
	return T;
}

FuzzyNumber operator * (const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber N;
	N.SetX(a.GetX() * b.GetX());
	N.SetL(a.GetX() * b.GetX() - b.GetX() * a.GetL() - a.GetX() * b.GetL() - a.GetL() * b.GetL());
	N.SetR(a.GetX() * b.GetX() + b.GetX() * a.GetR() + a.GetX() * b.GetR() + a.GetR() * b.GetR());
	return N;
}
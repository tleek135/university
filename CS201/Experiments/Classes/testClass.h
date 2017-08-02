#pragma once

class Fraction
{

private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator);
	int getNumerator() const;
	int getDenominator() const;
	void setNumerator(int numerator);
	void setDenominator(int denominator);
	bool isImproper() const;
	void simplify();

};

#include "testClass.h"

Fraction::Fraction(int numerator, int denominator){
	this->numerator = numerator;
	this->denominator = denominator;
}

int Fraction::getNumerator() const {
	return numerator;
}

int Fraction::getDenominator() const {
	return denominator;
}

void Fraction::setNumerator(int numerator) {
	this->numerator = numerator;
}

void Fraction::setDenominator(int denominator) {
	this->denominator = denominator;
}

bool Fraction::isImproper() const {
	if (numerator > denominator)
		return true;
	else
		return false;
}

void Fraction::simplify() {
	for(int divisor = 2; divisor <= numerator && divisor <= denominator; divisor++){
		if (numerator % divisor == 0 && denominator % divisor == 0){
			numerator /= divisor;
			denominator /= divisor;
			divisor = 1;
		}
	}
}

#include <iostream>
#include <cassert>
#include "testClass.h"

using namespace std;

int main(){
	Fraction sample(9, 8);
	assert(sample.getNumerator() == 9);
	assert(sample.getDenominator() == 8);
	assert(sample.isImproper());

	sample.setNumerator(4);
	assert(sample.getNumerator() != 9);
	assert(sample.getNumerator() == 4);
	assert(!sample.isImproper());

	sample.simplify();
	assert(sample.getNumerator() == 1);
	assert(sample.getDenominator() == 2);

	sample.setNumerator(24);
	sample.setDenominator(36);
	sample.simplify();
	assert(sample.getNumerator() == 2);
	assert(sample.getDenominator() == 3);
	assert(!sample.isImproper());

	cout << "All tests passed.\n";

}


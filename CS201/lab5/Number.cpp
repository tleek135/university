//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 1

#include "Number.h"

Number::Number(int n){
	this->n = n;
}

bool Number::isPrime(){
	for (int Tester = 2; Tester <= n; Tester++){
		if (n == 2 || (n % Tester != 0 && Tester == n - 1))
			return true;
		else if (n % Tester == 0)
			return false;
	}
}

bool Number::isDivisibleBy(int divisor){
	if (n % divisor == 0)
		return true;
	else
		return false;
}

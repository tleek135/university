//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 1

/*
+----------------------------------+

		Number
+----------------------------------+

- n : int

+----------------------------------+

+ Number(n : int)
+ isPrime() : bool
+ isDivisibleBy(divisor : int) : bool

+----------------------------------+
*/
#pragma once

class Number
{

public:
	Number(int n);
	bool isPrime();
	bool isDivisibleBy(int divisor);

private:
	int n;

};



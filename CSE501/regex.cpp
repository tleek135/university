/*
	Name: Kyle Lee
	Date: March 13, 2017
	Class: CSE 501
	Term: Winter 2017
	Assignment: Convert finite automaton from Problem 1.21b on
	page 86 of the book to its corresponding regular expression.
*/

#include <string>
#include <iostream>
using namespace std;

string regex(int p, int q, int k) 
{
	if (k == 0) {
		if (p == 1 and q == 1)
			return "e";
		else if (p == 1 and q == 2)
			return "a + b";
		else if (p == 1 and q == 3)
			return "null";
		else if (p == 2 and q == 1)
			return "null";
		else if (p == 2 and q == 2)
			return "a + e";
		else if (p == 2 and q == 3)
			return "b";
		else if (p == 3 and q == 1)
			return "a";
		else if (p == 3 and q == 2)
			return "b"; 
		else if (p == 3 and q == 3)
			return "e";
	}
	else {
		return "(" + regex(p, q, k-1) + ")U" + "(" +
		regex(p, k, k-1) + ")" + "(" + regex(k, k, k-1)
		+ ")*" + "(" + regex(k, q, k-1) + ")";
	}
}

int main()
{
	cout << regex(1, 1, 3) + " + " + regex(1, 3, 3) << endl;
}
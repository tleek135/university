/********************************************************************
 * Kyle Lee
 * palindrome.cpp
 * May 20, 2015
 * CSE 202 (Wednesday lab)
 * Description: Write a function to see whether or not a string is
   a palindrome (spelled the same forwards and backwards). 
 * Solution: Use a recursive function to repeatedly trim down the 
   string until either two non-matching letters are found (not a 
   palindrome) or all of the characters were checked successfully
   (is a palindrome).
 * Percent complete: 100%
********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Tests whether or not a character is a letter
bool is_letter(char c)
{
	if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z'))
		return true;
	
	return false;
}

//Converts an upper-case letter to a lower-case letter
char to_lower(char c)
{
	if (c >= 'A' and c <= 'Z')
		return c + 32;

	return c;
}

//Tests whether or not a string is a palindrome
bool is_palindrome(string s)
{

	if (s.length() <= 1)
		return true;

	char first = s[0];
	char last = s[s.length()-1];

	if (!is_letter(first)) {
		string shorter = s.substr(1, s.length()-1);
		return is_palindrome(shorter);
	}

	if (!is_letter(last)) {
		string shorter = s.substr(0, s.length()-1);
		return is_palindrome(shorter);
	}

	if (to_lower(first) == to_lower(last)) {
		string shorter = s.substr(1, s.length()-2);
		return is_palindrome(shorter);
	}
	
	return false;
}

//Prompts user for test input
main()
{
	cout << "Enter a string: ";
	string input;
	getline(cin, input);
	cout << "\'" << input << "\' is ";
	if (!is_palindrome(input))
		cout << "not ";
	cout << "a palindrome.\n";
}

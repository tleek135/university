// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Lab 6
// Title: Sieve of Eratosthenes

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void listSieve(list<int> & numbers, int maxNum)
{
	list<int>::iterator iter = numbers.begin();
	int prime;

	while (iter != numbers.end()) {

		if (*iter == 1)
			numbers.erase(iter++);

		prime = *iter;

		while (*iter < maxNum) {
		iter += prime;
		numbers.erase(iter);
		}

		
		
			
		

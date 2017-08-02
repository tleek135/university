// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Homework 2, Chapter 9, #28

//Chapter 9, #28
/*Implement a function countValue() that counts the number of
times an item occurs in a linked list.

template <typename T>
int countValue(node<T> *front, const T& item);

Generate 20 random numbers in the range from 0 to 4, and insert
each number at the front of a linked list. Output the list 
by using writeLinkedList() (in d_nodel.h header file). In a loop,
call the function countValue(), and display the number of occurrences
of each value from 0 to 4 in the list. */

#include <iostream>
#include <cstdlib> //for random number functions 
#include <ctime> //for time function
#include "d_node.h" //includes declaration of node class
#include "d_nodel.h" //includes writeLinkedList() function

using namespace std;

//Counts number of occurrences of an item in a linked list
template <typename T>
int countValue(node<T> *front, const T& item)
{
	//Use pointer to traverse linked list
	node<T> *iter = front;
	int counter = 0; //to count number of occurrences

	//loop for traversing linked list
	for ( ; iter != NULL; iter = iter->next) {
		if (iter->nodeValue == item)
			counter++; //increase count when desired value is encountered
	}

	return counter;
}

int main()
{
	srand(time(0)); //seed random number generator

	node<int> *front = NULL;

	//Generates random # between 0 and 4, and pushes this
	//value to front of linked list. Values are pushed
	//20 times to make a linked list of 20 random numbers
	//from 0 to 4. 
	for (int i = 0; i < 20; i++) {
		front = new node<int> (rand() % 5, front);
	}

	//Use function to display contents of linked list
	writeLinkedList(front, " ");
	cout << endl;

	//call countValue() to display the number of occurrences for 
	//each number
	for (int i = 0; i < 5; i++) {
		cout << "The number " << i << " appears in the linked list "
			 << countValue(front, i) << " times." << endl;
	}

	node<int> *curr;
	//Deallocate memory after operation is complete
	while (front != NULL) {
		curr = front;
		front = front->next;
		delete curr;
	}
		
	return 0;
}

		



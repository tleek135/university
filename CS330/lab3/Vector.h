// Class: CSE 330
// Term: Fall 2015
// Instructor: George M. Georgiou
// Name: Kyle Lee
// Lab 3
// Title: Vector


#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
// Vector.h

using namespace std;

template <class T>
class Vector
{
public:

   typedef T * iterator;				  		// defines iterator as an alias of a pointer to type T

   Vector();							  		// Default constructor
   Vector(unsigned int size);		      		// Constructor that creates vector of specified size
   Vector(unsigned int size, const T & initial);// Creates vector of size and initializes all elements to initial
   Vector(const Vector<T> & v);           		// copy constructor
   ~Vector();									// Destructor

   unsigned int capacity() const;         // return capacity of vector (in elements)
   unsigned int size() const;             // return the number of elements in the vector
   bool empty() const;					  // checks whether or not vector is empty

   iterator begin();                      // return an iterator pointing to the first element
   iterator end();                        // return an iterator pointing to one past the last element
   T & front();                           // return a reference to the first element
   T & back();                            // return a reference to the last element
   void push_back(const T & value);       // add a new element
   void pop_back();                       // remove the last element

   void reserve(unsigned int capacity);   // adjust capacity
   void resize(unsigned int size);        // adjust size

   T & operator[](unsigned int index);    	// return reference to numbered element
   Vector<T> & operator=(const Vector<T> &);// assign one vector to another

private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};

template <class T>
Vector<T>::Vector()
{
	my_size = 0;
	my_capacity = 0;
	buffer = 0;
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
	my_size = size;
	my_capacity = size;
	buffer = new T[size];

	//Initializes vector to default value of T
	for (int i = 0; i < size; i++)
		buffer[i] = T();
}
	
template <class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
	my_size = size;
	my_capacity = size;
	buffer = new T[size];

	//Initializes elements of vector to initial value
	for (int i = 0; i < size; i++)
		buffer[i] = initial;

}

template <class T>
Vector<T>::Vector(const Vector<T> & v)
{
	my_size = v.size();
	my_capacity = v.capacity();
	buffer = new T[my_capacity];

	//Copies values from v to new vector
	for (int i = 0; i < my_size; i++) 
		buffer[i] = v.buffer[i];
}

template <class T>
Vector<T>::~Vector()
{
	//Deallocates memory after program finishes
	if (buffer != 0)
		delete[] buffer;
}

template <class T>
unsigned int Vector<T>::capacity() const
{
	return my_capacity;
}

template <class T>
unsigned int Vector<T>::size() const
{
	return my_size;
}

template <class T>
bool Vector<T>::empty() const
{
	//Checks whether or not vector has any elements
	if (my_size == 0)
		return true;
	else
		return false;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	//Returns pointer to beginning of vector
	return buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
	//Returns pointer to one past the last element
	return begin() + my_size;
}

template <class T>
T & Vector<T>::front()
{
	return *(begin());
}

template <class T>
T & Vector<T>::back()
{
	return *(end() - 1);
}

template <class T>
void Vector<T>::push_back(const T & value)
{
	//If size is greater than or equal to current
	//capacity, expand capacity by 5 first
	if (my_size >= my_capacity) {
		reserve(my_capacity + 5);
	}

	//Puts value at end of vector and adjusts size
	//accordingly
	buffer[size()] = value;
	resize(size()+1);
}

template <class T>
void Vector<T>::pop_back() 
{
	//Do not pop back if vector is empty
	if (empty())
		return;
	
	//Re-adjust size of vector to remove last element
	resize(size() - 1);
}

template <class T>
void Vector<T>::reserve(unsigned int capacity)
{
	//Do not allow reserve if desired capacity 
	//is less than current size
	if (capacity < my_size)
		return;

	my_capacity = capacity;

	//Allocate space for new vector
	T * tempBuffer = new T[my_capacity];
	iterator i;
	int k;

	//Copy values to this new vector
	for (i = begin(), k = 0; i < end(); i++, k++) 
		tempBuffer[k] = *i;

	//Deallocate space from old vector, then point to
	//new vector
	delete[] buffer;
	buffer = tempBuffer;
}

template <class T>
void Vector<T>::resize(unsigned int size)
{
	//if size exceeds capacity, increases capacity to match size
	if (size > my_capacity)
		reserve(size);

	my_size = size;

	//Allocate space for new vector
	T * tempBuffer = new T[my_capacity];
	iterator i;
	int k;

	//Copy values to this new vector
	for (i = begin(), k = 0; k < my_size; i++, k++) 
		tempBuffer[k] = *i;

	//Deallocate space from old vector, then point to
	//new vector
	delete[] buffer;
	buffer = tempBuffer;
}

template <class T>
T & Vector<T>::operator[](unsigned int index)
{
	//Make sure index is within range
	assert(index < my_size);

	return buffer[index];
}

template <class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & rightVector)
{
	//Check capacity to see if vector can hold all elements from
	//the vector to the right of the =.
	//If not, reserve more space.
	if (capacity() < rightVector.size())
		reserve(rightVector.size());

	//Change size of vector to match the right-hand-side vector
	my_size = rightVector.size();

	//Copy elements from right-hand-side vector to current vector.
	for (int i = 0; i < my_size; i++)
		buffer[i] = rightVector[i];
	
}

#endif
	
	


		



/***************************************************************
 * Kyle Lee
 * vector_function_tests.cpp
 * April 15, 2015
 * Problem description: appending, merging, and sorting vectors
 * Solution: create a new vector, and use loops to determine 
   what will be added to this new vector
 * Percent completed: 66% (merge_sorted not working)
***************************************************************/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Displays the contents of a vector
void print_vector(const vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";

	cout << endl;
}

//Appends one vector to another using for loops
vector<int> append(vector<int> a, vector<int> b)
{
	int n = a.size();
	int m = b.size();
	vector<int> c(n + m);
	int i;

	for (i = 0; i < n; i++)
		c[i] = a[i];

	for (i = 0; i < m; i++)
		c[n + i] = b[i];

	return c;
}

//Creates a new vector by alternating terms of two different vectors
vector<int> merge(vector<int> a, vector<int> b)
{
	vector<int> c;
	int n = a.size();
	int m = b.size();
	int smaller = ((n < m)? n : m);
	int larger = ((smaller == n)? m : n);
	int i;
	
	for (i = 0; i < smaller; i++){
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	
	for (; i < larger; i++){
		if (a.size() == b.size())
			break;
		else if (larger == n)
			c.push_back(a[i]);
		else if (larger == m)
			c.push_back(b[i]);
	}

	return c;
}

//Merges two sorted vectors into a new sorted vector
vector<int> merge_sorted(vector<int> a, vector<int> b)
{
	vector<int> c;
	int n = a.size();
	int m = b.size();
	int smaller = ((n < m)? n : m);
	int larger = ((smaller == n)? m : n);
	int i, j;

	for (i = 0, j = 0; ;){
		if (a[i] < b[j]){
			c.push_back(a[i]);
			i++;
		}
		else if (b[j] < a[i]){
			c.push_back(b[j]);
			j++;
		} else {
			c.push_back(a[i]);
			c.push_back(b[j]);
			i++, j++;
		}
		
	
main()
{
	vector<int> one, two, three;
	int i;
	int input = 0;
	cout << "Please enter positive integer values for vector one, "
		<< "then type -1 when finished: ";
	cin >> input;

	while (input != -1){
		one.push_back(input);
		cout << "Enter another number: ";
		cin >> input;
	}

	cout << "Enter positive integers for vector two, then type "
         << "-1 when finshed: ";
	cin >> input;

	while (input != -1){
		two.push_back(input);
		cout << "Enter another number: ";
		cin >> input;
	}

	three = append(one, two);
	cout << "Your appended vector is: ";
	print_vector(three);

	three.clear();
	three = merge(one, two);
	cout << "Your merged (unsorted) vector is: ";
	print_vector(three);

	three.clear();
	sort(one.begin(), one.end());
	sort(two.begin(), two.end());
	three = merge_sorted(one, two);
	cout << "Your merged (sorted) vector is: ";
	print_vector(three);
}

		




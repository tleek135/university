// Class: CSE 455
// Term: Winter 2016
// Instructor: Dr. Concepcion
// Name: Kyle Lee
// PSP Assignment #7
// Title: Building and sorting singly-linked list

#include <iostream>

using namespace std;

class Node
{
private:
	double xValue;
	double yValue;
	Node * nextNode;

public:
	Node(): xValue(0), yValue(0), nextNode(NULL) {}
	Node(double x, double y)
	{
		xValue = x;
		yValue = y;
		nextNode = NULL;
	}

	void setX(double x) {xValue = x;}
	void setY(double y) {yValue = y;}
	void setBoth(double x, double y) {xValue = x; yValue = y;}

	double getX() {return xValue;}
	double getY() {return yValue;}

	void setPtr(Node * ptr) {nextNode = ptr;}
	Node* getPtr() {return nextNode;}
};

class singlyLinkedList
{
private: 
	Node * start;
	Node * end;
	int size;

public:
	//Constructor
	singlyLinkedList(): start(NULL), end(NULL), size(0) {}

	//Adds node to linked list
	void add(double x, double y)
	{
		if (start == NULL) {
			start = new Node(x, y);
			end = start;
			size++;
			return;
		}

		Node * iter = new Node(x, y);
		end->setPtr(iter);
		end = iter;
		size++;
	}

	//Removes specified node from linked list
	void remove(double x, double y)
	{
		if (size == 0)
			return;

		Node * pass = start;
		while ((pass->getX() != x or pass->getY() != y) and pass->getPtr() != NULL) {
			pass = pass->getPtr();
		}

		//If node not found, exit function
		if (pass->getPtr() == NULL)
			return;
		
		//Otherwise, remove node and modify pointers
		if (size == 1) {
			delete pass;
			start = end = NULL;
		}
		else if (pass == start) {
			start = pass->getPtr();
			delete pass;
		}
		else if (pass == end) {
			Node * beforeEnd = start;
			while (beforeEnd->getPtr() != end)
				beforeEnd = beforeEnd->getPtr();

			delete pass;
			end = beforeEnd;
			end->setPtr(NULL);
		}
		else {
			if (pass->getPtr() == end)
				end = pass;

			pass->setBoth((pass->getPtr())->getX(), (pass->getPtr())->getY());
			delete pass->getPtr();
		}

		size--;
	}

	//Prints out contents of all nodes
	void print()
	{
		for (Node * i = start; i != NULL; i = i->getPtr())
			cout << "(" << i->getX() << ", " << i->getY() << ")" << endl;
	}

	//Swaps two nodes
	void swapNode(Node * a, Node * b)
	{
		double tempX = a->getX();
		double tempY = a->getY();

		a->setBoth(b->getX(), b->getY());
		b->setBoth(tempX, tempY);
	}

	//Sorts linked list 
	//Sorts by x value if sortByX == true; otherwise, sorts by y value
	void sortXorY(bool sortByX)
	{
		for (Node * i = start; i != end; i = i->getPtr()) {
			for (Node * j = i->getPtr(); j != NULL; j = j->getPtr()) {
				if (sortByX) {
					if (i->getX() > j->getX())
						swapNode(i, j);
				}
				else {
					if (i->getY() > j->getY())
						swapNode(i, j);
				}
			}
		}
	}

	//Destructor that deallocates memory from nodes
	~singlyLinkedList()
	{
		Node * temp = NULL;
		for (Node * i = start; i != NULL; i = temp) {
			temp = i->getPtr();
			delete i;
		}
	}
	
};

main()
{
	double x, y;
	singlyLinkedList list;

	cout << "Enter ten pairs of x and y values, separated by a space: " << endl;

	for (int i = 0; i < 10; i++) {
		cin >> x >> y;
		list.add(x, y);
	}

	cout << "List sorted by x values: " << endl;
	list.sortXorY(true);
	list.print();

	cout << endl;
	cout << "List sorted by y values: " << endl;
	list.sortXorY(false);
	list.print();

}


#include "matrix.h"

int main()
{
	int rows, cols;
	cout << "Enter the # of rows and cols for first matrix, separated by a space: ";
	cin >> rows >> cols;
	Matrix first(rows, cols);
	first.fill();
	first.print();
	cout << "------------------------\n";

	cout << "Enter the # of cols for the second matrix: ";
	cin >> rows;
	Matrix second(cols, rows);
	second.fill();
	second.print();
	cout << "------------------------\n";

	second = first;
	cout << "The first matrix has now been assigned to the second.\n";
	second.print();
}
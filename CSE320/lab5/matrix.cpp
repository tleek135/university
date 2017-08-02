#include "matrix.h"

using namespace std;

Matrix::Matrix() : matrix(0) {}

Matrix::Matrix(int rows, int cols) : matrix(rows)
{
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(cols);
	}
}

Matrix::Matrix(const Matrix & m) : matrix(m.matrix) {}

void Matrix::fill()
{
	srand(time(0));
	//uniform_int_distribution<int> values(1, 100);
	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			matrix[row][col] = (rand()%100)+1;
		}
	}
}

void Matrix::operator=(Matrix m)
{
	matrix.swap(m.matrix);
}

Matrix Matrix::operator*(const Matrix & m)
{
	
}

void Matrix::print()
{
	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			 cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}

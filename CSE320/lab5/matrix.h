#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;
#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
private:
	vector<vector<int>> matrix;

public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix &);

	void fill();
	void operator=(Matrix);
	Matrix operator*(const Matrix &);
	void print();
};
#endif
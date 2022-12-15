#pragma once
#include "Vector.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
class Matrix {
	Vector data;
	int rows;
	int cols;
	void write(std::string filename);

	
public:
	Matrix();
	Matrix(int _r, int _cols);
	~Matrix();

	int K0(int i);
	int KN(int i);

	Vector solution();

	void read(std::string filename);

	Vector getData();
	int getCols();
	int getRows();

	void setData(Vector _data);
	void setCols(int _cols);
	void setRows(int _rows);

	Matrix operator+(Matrix A);
	Matrix operator-(Matrix A);
	Matrix operator=(Matrix& A);

	double& operator()(int i, int j);
	double& operator()(int i, int j) const;
	friend std::ostream& operator<<(std::ostream& out, Matrix &M);
};


/*
TODO:
1. read(file)
2. write(file)

*/


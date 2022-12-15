#include "Matrix.h"


Matrix::Matrix() {
	rows = 0; 
	cols = 0;
}

Matrix::Matrix(int _rows, int _cols) {
	rows = _rows;
	cols = _cols;
	Vector temp((_rows+1) * ( cols+1));
	data = temp;
}

Matrix::~Matrix() {
	
}


int Matrix::K0(int i) {
	return i <= cols ? 1 : i-cols+1;
}

int Matrix::KN(int i) {
	return i <= rows - cols ? i + cols-1 : rows;
}

Vector Matrix::solution()
{
	Matrix Q(rows, cols);
	double S;
	Matrix P(1, 1);
	P = *this;
	cout << cols << "\n";
	for (int i = 1; i <= rows; i++) {
		S = P(i, cols);
		cout << "\n========\n i = " << i << " \n========\n s = ";
		cout << S << "\n";
		for (int k = K0(i); k <= i - 1; k++) {
			S = S - Q(k, i-k+1)*Q(k, i - k + 1);
		}
		
		Q(i, 1) =sqrt(S);
		cout << "\t i = " << i << " K0 = " << KN(i)  << "\n\n\n";
		for (int j = i + 1; j <= KN(i); j++) {
			S = P(j, i - j + cols);
			for (int k = K0(i); k < i - 1; k++) {
				//if ();
				S = S - Q(k, i - k + 1) * Q(k, j - k + 1);
			}
			
			Q(i, j - i + 1) = S / Q(i, 1);
	//		cout << "\n========\n i = " << i << "\t j = " << j << " \n========\n s = " << S << "\tQ(k, i - k + 1) = " << Q(K0(i), i - K0(i) + 1)  
		//		<< "\tQ(k, i - k + 1) = " << Q(K0(i), j - K0(i) + 1) << "\t Q = " << Q(i, cols) << "\n\n" << Q << "\n\n\n";
		}
	}

	std::cout << Q;
	return (data);
}

void Matrix::read(std::string path) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		int t = 0;
		fin >> rows >> cols;

		Matrix T(rows, cols);

		for (int i = 1; i <= rows; i++)
			for (int j = 1; j <= cols; j++)
				fin >> T(i, j);

		//Выведем матрицу


		*this = T;
	}

};

void Matrix::setData(Vector _data) {
	Vector data = _data;
}

Matrix Matrix::operator=(Matrix& A) {
	rows = A.getRows();
	cols = A.getCols();
	Vector temp((rows + 1) * (cols + 1));
	data = temp;
	
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++)
			data[i * cols + j] = A(i, j);

	}
	return *this;
};

void Matrix::setCols(int _cols){
	cols = _cols;
}

void Matrix::setRows(int _rows) {
	rows = _rows;
}

Vector Matrix::getData() {
	return data;
}

int Matrix::getCols() {
	return cols;
}

int Matrix::getRows() {
	return rows;
}

Matrix Matrix::operator+(Matrix A) {
	Matrix temp(this->rows, this->cols);
	temp.data = data + A.data;
	return temp;
}

Matrix Matrix::operator-(Matrix A) {
	Matrix temp(this->rows, this->cols);
	temp.data = data - A.data;
	return temp;
}


double& Matrix::operator()(int i, int j) {
	return data[i*cols+j];
}

double& Matrix::operator()(int i, int j) const {
	return data[i*cols + j];
}



std::ostream& operator<<(std::ostream& out, Matrix& a) {
	for (int i = 1; i <= a.rows; i++) {
		for (int j = 1; j <= a.cols; j++)
			out << a.data[i * a.cols + j] << "\t\t";
			out << "\n";
	}
	return out;
}
// ?????
//Vector Matrix::solution()
//{
//	Matrix Q(rows, cols);
//	double S;
//	Matrix P(1, 1);
//	P = *this;
//	cout << cols << "\n";
//	for (int i = 1; i <= rows; i++) {
//		S = P(i, cols);
//		for (int k = K0(i); k <= i - 1; k++) {
//			S = S - Q(k, i - k + cols) * Q(k, i - k + cols);
//		}
//
//		Q(i, cols) = sqrt(S);
//		cout << "\t i = " << i << " KN = " << KN(i) << "\n\n\n";
//		for (int j = i + 1; j <= KN(i); j++) {
//			S = P(i, j - i + cols);
//			for (int k = K0(i); k <= i - 1; k++) {
//				S = S - Q(k, i - k + cols) * Q(k, j - k + cols);
//			}
//
//			Q(i, j - i + cols) = S / Q(i, cols);
//			cout << "\n========\n i = " << i << "\t j = " << j << " \n========\n s = " << S << "\tP = " << P(i, j - i + cols) << "\t Q = " << Q(i, cols) << "\n\n" << Q << "\n\n\n";
//		}
//	}
//
//	std::cout << Q;
//	return (data);
//}

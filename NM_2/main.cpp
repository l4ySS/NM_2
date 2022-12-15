#include "Matrix.h"

 
#include <iomanip>
using namespace std;
void main() {
	setprecision(3);
	Matrix M(4, 2);
	M.read("input.txt");
	cout << setprecision(3)<<  M << "\n\n";
	cout << M(1, 6);
	M.solution();
}

















//Matrix M(4, 2);
//Matrix N(2, 1);
//double n = 5;
//double m = 3;
//std::cout << M << "\n\n\n";
//for (int i = 1; i <= 4; i++)
//for (int j = 1; j <= 2; j++) {
//	std::cout << "i = " << i * 2 + j << "\n";
//
//	M(i, j) = m / n;
//}
//
//
//std::cout << M << "\n\n\n";
//N = M;
//std::cout << N << "\n\n\n"; */
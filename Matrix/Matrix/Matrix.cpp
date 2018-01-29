#include "Matrix.hpp"
#include <iostream>

using namespace std;

Matrix::Matrix(int n = 1) : size(n) {
	
	isValidSize();

}


//Check wheter entered size is valid
//PRE	: size should be an integer
//POST	: terminate the program if it is not valid
void Matrix::isValidSize() {
	
	int root(round(sqrt(size)));
	if (size != root * root) {
		cout << "Invalid input" << endl;
		cout << "Program terminated" << endl;
		exit(1);
	}
}
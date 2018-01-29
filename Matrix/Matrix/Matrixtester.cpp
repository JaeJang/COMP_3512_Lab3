#include "Matrix.hpp"
#include <iostream>

int main() {
	Matrix a;
	std::cout << a << endl;

	Matrix b(3);
	std::cout << b << endl;

	int[] wrong_size = { 1, 2, 3 };
	Matrix c(wrong_size);

	b.set_value(0, 0, -1);
	b.get_value(0, 0);
	b.clear();

	Matrix identity = a.identity(5);

	Matrix d;
	Matrix e;
	if (d == e) { cout << "equal" << endl; }
	if (d >= e) { cout << "c is greater than d" << endl; }

	Matrix f = d + e;

	Matrix d += a;
}
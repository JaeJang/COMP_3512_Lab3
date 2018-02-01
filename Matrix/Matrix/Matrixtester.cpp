#include "Matrix.hpp"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	Matrix a;
	cout << a << endl << endl;

	Matrix b(3);
	cout << b << endl << endl;

	int wrong_size[] = { 1, 2, 3 };
	Matrix c(wrong_size);

	b.set_value(0, 0, -1);
	b.get_value(0, 0);
	b.clear();
	cout << b << endl << endl;

	Matrix identity = a.identity();
	cout << identity << endl << endl;

	Matrix d;
	Matrix e;
	if (d == e) { cout << "equal" << endl; }
	if (d >= e) { cout << "c is greater than d" << endl; }

	Matrix f = d + e;
	cout << f << endl << endl;

	Matrix g;
	g += a;
	cout << g << endl << endl;

	cout << "Press any button to exit";
	_getche();
	return 0;
}
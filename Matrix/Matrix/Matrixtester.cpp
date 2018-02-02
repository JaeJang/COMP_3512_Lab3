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
	//Since the wrong size passed, c is initialized with 1 X 1 Matrix
	Matrix c(wrong_size, 3);

	b.clear();
	cout << "Matrix b is now set to 1 for all the elements" << endl;
	for (int i = 0; i < sqrt(b.get_Arraysize()); ++i) {
		for (int j = 0; j < sqrt(b.get_Arraysize()); ++j) {
			b.set_value(i, j, 1);
		}
	}
	cout << b << endl << endl;
	
	cout << "Identity Matrix for b is created" << endl;
	Matrix identity(b.identity(), b.get_Arraysize());
	cout << identity << endl << endl;

	//Matrix b is copied, which fills up with 1
	Matrix d(b);
	
	if (d == b) { cout << "equal" << endl; }
	if (d >= b) { cout << "d is greater than or equal to b" << endl; }
	if (d > c) { cout << "d is greater than c" << endl; }
	if (c < d) { cout << "c is less than d" << endl; }
	if (c != d) { cout << "c and d have different size" << endl; }

	//Expected output is filling up with 2
	Matrix &&e = d + b;
	cout << e << endl << endl;
	cout << d << endl << endl;

	//Expected output is filling up with 3
	e += b;
	cout << e << endl << endl;

	//Expected output is filling up with 2
	e -= b;
	cout << e << endl << endl;
	cout << d << endl << endl;
	//Expected output is filling up with 1
	Matrix f = e - d;
	cout << f << endl << endl;
	cout << "Press any button to exit";
	_getche();
	return 0;
}
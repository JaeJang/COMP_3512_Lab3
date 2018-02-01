#pragma once
#include <iostream>
class Matrix {

public:
	Matrix();
	Matrix(int);
	Matrix(int*);
	~Matrix();

	void set_value(const int, const int, const int);
	int get_value(const int, const int);
	void clear();
	int* identity();
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);
	bool operator>(const Matrix&);
	bool operator<(const Matrix&);
	bool operator<=(const Matrix&);
	bool operator>=(const Matrix&);



private:
	int size;
	int *array;

};
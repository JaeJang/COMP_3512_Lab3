#pragma once
#include <iostream>
class Matrix {

public:
	Matrix();
	Matrix(int);
	Matrix(int*);
	Matrix(const Matrix&);
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
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	friend void swap(Matrix &, Matrix &);
	Matrix& operator=(Matrix);
	Matrix& operator+=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix & operator-=(const Matrix&);
	Matrix operator-(const Matrix&);

private:
	int size;
	int *array;

};
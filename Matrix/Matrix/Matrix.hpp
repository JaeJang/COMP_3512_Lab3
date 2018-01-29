#pragma once


class Matrix {

public:
	Matrix(int = 1);
	

private:
	int size;
	int *array;

	void isValidSize();

};
#include "Matrix.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

Matrix::Matrix() : size(1) {
	array = new int[size * size];
;}

Matrix::Matrix(int n) : size(n) { 
	array = new int[size * size];
}

//PRE	: The size of passed array must have an integer
//		  square root
Matrix::Matrix(int *array) {
	//this->array = array;
}

//Copy constructor
Matrix::Matrix(const Matrix &rhs) {
	size = rhs.size;
	memcpy_s(array, sizeof(array), rhs.array, sizeof(array));
}

Matrix::~Matrix() {
	delete[] array;
}


//Put the value into the specific index
//PRE	: All parameters need to be integers
//PRE	: The index must not be out of bound
//POST	: the value is assigned to the index
void Matrix::set_value(const int row, const int col, const int value) {
	array[row * size + col] = value;
}

//Get value for the index
//PRE	: The index must not be out of bound
//RETURN: an integer for the index
int Matrix::get_value(const int row, const int col) {
	return array[row*size + col];
}

//Reset the array
//PRE	: The array exists
//POST	: All values in the array set to 0
void Matrix::clear() {
	memset(array, 0, sizeof(array));
}


//Create ideneity matrix
//PRE	: Aimed array needs to be existed
//POST	: Create identity matrix whose size is tha same as the array
//RETURN: Identity matrix created
int* Matrix::identity() {
	int *identityArray = (int*)calloc(sizeof(array), sizeof(int));
	
	if (identityArray == nullptr) {
		cout << "fail to allocate" << endl;
		return nullptr;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				identityArray[i*size + j] = 1;
			}
		}
	}
	return identityArray;
}

	
//overloaded insertion operator
//PRE    : (ostream) << (Matrix object)
//POST   : when compiler sees above, it will implement the definition
//RETURN : ostream
ostream& operator<<(ostream& os, const Matrix& obj) {
	for (int i = 0; i < obj.size; i++) {
		for (int j = 0; j < obj.size; j++) {
			os << obj.array[i * obj.size + j];
		}
	}
	return os;
}

//Overloaded equal comparison
bool Matrix::operator==(const Matrix &com)
{
	return size == com.size ? true : false;
}

//Overloaded not equal comparison
bool Matrix::operator!=(const Matrix &com)
{
	return size != com.size ? true : false;
}

//Overloaded greater than comparison
bool Matrix::operator>(const Matrix &com)
{
	return size > com.size ? true: false;
}

//Overloaded less than comparison
bool Matrix::operator<(const Matrix &com)
{
	return size < com.size ? true : false;
}

//Overloaded less than or equal to comparison
bool Matrix::operator<=(const Matrix &com)
{
	return size <= com.size ? true : false;
}

//Overloaded greater than or equal to comparison
bool Matrix::operator>=(const Matrix &com)
{	
	return size >= com.size ? true : false;
}

//Overloaed increment operator(prefix)
Matrix & Matrix::operator++()
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			array[i * size + j]++;
		}
	}

	return *this;
}

//Overloaed increment operator(postfix)
Matrix Matrix::operator++(int)
{	
	Matrix temp(*this);
	operator++();
	return temp;
}

//Overloaded decrement operator(prefix)
Matrix & Matrix::operator--()
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			array[i * size + j]++;
		}
	}

	return *this;
}

//Overloaded decrement operator(postfix)
Matrix Matrix::operator--(int)
{
	Matrix temp(*this);
	operator--();
	return temp;
}



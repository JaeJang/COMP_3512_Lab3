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

//POST: if a passed array doesn't have an integer square root,
//		initialize the array with size 1
//		otherwise copy the passed array 
Matrix::Matrix(int *_array, const int arraySize) {
	if ((int)sqrt(arraySize) * (int)sqrt(arraySize) == arraySize) {

		//arraySize is full array size(n * n) 
		//ans size is just n
		size = (int) sqrt(arraySize);
		array = new int[arraySize];
		memcpy_s(array, arraySize * sizeof(int), _array, arraySize * sizeof(int));
		
	}
	else {
		Matrix();
	}
}

//Copy constructor
Matrix::Matrix(const Matrix &rhs) {
	size = rhs.size;
	array = new int[size * size];
	memcpy(array, rhs.array, sizeof(int) * size * size);
	//memcpy_s(array, sizeof(int) * size * size, rhs.array, sizeof(int) * size * size);
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
	memset(array, 0, sizeof(int) * get_Arraysize());
}


//Create ideneity matrix
//PRE	: Aimed array needs to be existed
//POST	: Create identity matrix whose size is tha same as the array
//RETURN: Identity matrix created
int* Matrix::identity() {
	int* temp = (int*) calloc(get_Arraysize(), sizeof(int));
	if (temp == nullptr) {
		cout << "fail to allocate" << endl;
		return nullptr;
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				temp[i * size + j] = 1;
			}
		}
	}
	return temp;
}

	
//overloaded insertion operator
//PRE    : (ostream) << (Matrix object)
//POST   : when compiler sees above, it will implement the definition
//RETURN : ostream
ostream& operator<<(ostream& os, const Matrix& obj) {
	for (int i = 0; i < obj.size; i++) {
		for (int j = 0; j < obj.size; j++) {
			os << obj.array[i * obj.size + j] << "\t";
		}
		os << endl;
	}
	return os;
}

//Overloaded equal comparison
//PRE	: both matrixs have size
//RETURN: return true if they have same size
bool Matrix::operator==(const Matrix &com)
{
	return size == com.size ? true : false;
}

//Overloaded not equal comparison
//PRE	: both matrixs have size
//RETURN: return true if they have different size
bool Matrix::operator!=(const Matrix &com)
{
	return size != com.size ? true : false;
}

//Overloaded greater than comparison
//PRE	: both matrixs have size
//RETURN: return true if lhs is bigger
bool Matrix::operator>(const Matrix &com)
{
	return size > com.size ? true : false;
}

//Overloaded less than comparison
//PRE	: both matrixs have size
//RETURN: return true if lhs is less
bool Matrix::operator<(const Matrix &com)
{
	return size < com.size ? true : false;
}

//Overloaded less than or equal to comparison
//PRE	: both matrixs have size
//RETURN: return true if lhs is less than or equal to rhs
bool Matrix::operator<=(const Matrix &com)
{
	return size <= com.size ? true : false;
}

//Overloaded greater than or equal to comparison
//PRE	: both matrixs have size
//RETURN: return true if lhs is greater than or equal to rhs
bool Matrix::operator>=(const Matrix &com)
{	
	return size >= com.size ? true : false;
}

//Overloaed increment operator(prefix)
//PRE	: Matrix initialized
//POST	: increment of each element
//RETURN: reference of this object
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
//PRE	: Matrix initialized
//POST	: increment of each element
//RETURN: reference of this object
Matrix Matrix::operator++(int)
{	
	Matrix temp(*this);
	operator++();
	return temp;
}

//Overloaded decrement operator(prefix)
//PRE	: Matrix initialized
//POST	: decrement of each element
//RETURN: reference of this object
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
//PRE	: Matrix initialized
//POST	: decrement of each element
//RETURN: reference of this object
Matrix Matrix::operator--(int)
{
	Matrix temp(*this);
	operator--();
	return temp;
}


//Swap values between two objects
//PRE	: both are Matrix object
//POST	: swap each other
void swap(Matrix &first, Matrix &second)
{
	std::swap(first.size, second.size);
	std::swap(first.array, second.array);
}

//Overloaded assignment operator
//PRE	: both are Matrix object
//POST	: lhs is overrided with rhs
Matrix & Matrix::operator=(Matrix other)
{
	swap(*this, other);
	return *this;
}

//Overloaded += operator
//PRE	: both Matrix have to have the same size
//POST	: rhs matrix is added to lhs matrix
Matrix & Matrix::operator+=(const Matrix &rhs)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			this->array[i * size + j] += rhs.array[i * rhs.size + j];
		}
	}

	return *this;
}

//Overloaded + operator
//PRE	: both Matrix have to have the same size
//POST	: rhs matrix is added to lhs matrix
//RETURN: current Matrix object
Matrix operator+(Matrix lhs, const Matrix& rhs)
{
	//Matrix temp(size);

	lhs += rhs;
	return lhs;
}

//Overloaded -= operator
//PRE	: both Matrix have to have the same size
//POST	: lhs maxtrix is subtracted by rhs
//RETURN: reference of current Matrix object
Matrix & Matrix::operator-=(const Matrix &rhs)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			this->array[i * size + j] -= rhs.array[i * rhs.size + j];
		}
	}

	return *this;
}

//Overloaded - operator
//PRE	: both Matrix have to have the same size
//POST	: lhs maxtrix is subtracted by rhs
//RETURN: current Matrix object
Matrix operator-(Matrix lhs, const Matrix &rhs)
{
	lhs -= rhs;
	return lhs;
}

//Get the matrix size
//RETURN: the size of matrix
int Matrix::get_Arraysize()
{
	return size * size;
}

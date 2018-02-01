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


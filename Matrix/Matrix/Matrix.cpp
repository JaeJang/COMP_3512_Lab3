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






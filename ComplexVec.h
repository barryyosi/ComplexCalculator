/* Assignment C++: 2
   Author: Barry Yosilevich, ID: 208725218
   */
#include <vector>
#include <iostream>
#include "Complex.h"
#pragma once
using namespace std;

class ComplexVec
{
	vector<Complex> Vector;
	int vectorSize = 0;                       // initialize Complex vector size

public:
	
	ComplexVec();
	
	/* Print vector elements*/
	void printElements() const;					
	
	/* */
	void insert(const Complex& argComplex);
	Complex operator[](const int index) const;
	virtual ~ComplexVec();
	int getSize() const;
};


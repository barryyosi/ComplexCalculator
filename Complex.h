/* Assignment C++: 2
   Author: Barry Yosilevich, ID: 208725218
   */
#pragma once
#include <iostream>
using namespace std;

	class Complex
	{
		float realVal, imaginaryVal;
		float radius, phase;
		void calculateRad();
		void calculatePhase();

	public:
		Complex(float argReal = 0, float argImaginary = 0);
		float getRad() const;
		float getPhase() const;
		Complex operator+(const Complex& argComplex) const;
		Complex operator-(const Complex& argComplex) const;
		Complex operator*(const Complex& argComplex) const;
		Complex operator/(const Complex& argComplex) const;
		bool operator==(const Complex& argComplex) const;
		Complex operator~() const;
		friend ostream& operator<<(ostream& output, const Complex& argComplex);
		virtual ~Complex();
		

	};
	
	





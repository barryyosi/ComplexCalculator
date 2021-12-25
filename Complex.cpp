/* Assignment C++: 2
   Author: Barry Yosilevich, ID: 208725218
   */
#include "Complex.h"
#include <cmath>
#include <iostream>
#define PI 3.141592653

using namespace std;
/* Constructor */
Complex::Complex(float argReal, float argImaginary) {
	realVal = argReal;
	imaginaryVal = argImaginary;
	calculatePhase();
	calculateRad();
	}

/* privte calculating complex number's polar coordinates: radius and phase */
void Complex::calculateRad()
{
	radius = sqrt(realVal * realVal + imaginaryVal * imaginaryVal);
}

void Complex::calculatePhase()
{
	if (realVal == 0)
	{
		if (imaginaryVal == 0)
			phase = 0;
		else if (imaginaryVal > 0)
			phase = 90;
		else
			phase = 270;
	}
	else 
	{
		//int quadrant;

		if (imaginaryVal >= 0)
			phase = atan2(imaginaryVal, realVal) * 180 / PI;
		else
			phase = 360 + atan2(imaginaryVal, realVal) * 180 / PI;
	}
}

/* public getters for copmlex number's polar coorinates: */
float Complex::getRad() const {
	return this->radius;
}

float Complex::getPhase() const {
	return this->phase;
}

/*Operators overloading: Complex ddition */
Complex Complex::operator+(const Complex& argComplex) const {
	Complex result;
	result.realVal = realVal + argComplex.realVal;
	result.imaginaryVal = imaginaryVal + argComplex.imaginaryVal;
	return result;
}

/* Complex substraction */
Complex Complex::operator-(const Complex& argComplex) const {
	Complex result;
	result.realVal = realVal - argComplex.realVal;
	result.imaginaryVal = imaginaryVal - argComplex.imaginaryVal;
	return result;

}

/* Complex multiplication */
Complex Complex::operator*(const Complex& argComplex) const {
	Complex result;
	result.realVal = realVal * argComplex.realVal - imaginaryVal * argComplex.imaginaryVal;
	result.imaginaryVal = imaginaryVal * argComplex.realVal + realVal * argComplex.imaginaryVal;
	return result;

}

/* Complex division using conjugate multiplication method*/
Complex Complex::operator/(const Complex& argComplex) const {
	
	if (argComplex.getRad() == 0){
		cout << "Zero-devision is not allowed!" << endl;
	return *this;
}
	else {
		Complex argConjugate(argComplex.realVal, -argComplex.imaginaryVal);     		// Initing argument conjugate to multiply numerator and denominator with
		Complex numerator = *this * argConjugate;						// Numerator multiplication result: complex number
		Complex denominator = argComplex * argConjugate;					// Denominator multiplication result - real number
		Complex result;
		result.realVal = numerator.realVal / denominator.realVal;				// Dividing numerator real and imaginary part with the real denominator
		result.imaginaryVal = numerator.imaginaryVal / denominator.realVal;
		return result;
	}
}

/*Complex equallity operator - comparing real parts and imaginary parts of 2 complex parameters */
bool Complex::operator==(const Complex& argComplex) const {
	return realVal == argComplex.realVal && imaginaryVal == argComplex.imaginaryVal;
}

/* Conjucgate operator*/
Complex Complex::operator~() const { return Complex(realVal, -imaginaryVal); }

/* cout << operator implementaation */
ostream& operator<<(ostream& output, const Complex& argComplex) {
	if (argComplex.imaginaryVal < 0 )
		return output << argComplex.realVal << " - " << abs(argComplex.imaginaryVal) << 'i';
		
	//else imaginaryVal >= 0
	return output << argComplex.realVal << " + " << abs(argComplex.imaginaryVal) << 'i';
		
}

/* Distructor */
Complex::~Complex() {};

/* Assignment C++: 2
   Author: Barry Yosilevich, ID: 208725218
   */
#include "ComplexVec.h"
#include <vector>

using namespace std;

/* Constructor, intializes vector size = 0 */
ComplexVec::ComplexVec(){
	vectorSize = 0;
}

/* Printing Complex vector's elements */
void ComplexVec::printElements() const {
	
	int iter = 0;						    // iter is used to index vector's elements
	if (vectorSize == 0)
		cout << "Vector is empty!" << endl;
	else
	{
		cout << "\nComplex vector elements:\n " << endl;
		for (Complex i : Vector) {
			cout << iter << ": " << i << endl;
			iter++;

		}
	}
	}

/* Appending to complex vector */
void ComplexVec::insert(const Complex& argComplex){
	Vector.push_back(argComplex);                       // Append at the end
	vectorSize++;									    // Increase vector size
}

/* Vecotr  index acces using [] implementation*/
Complex ComplexVec::operator[](const int index) const
{
	return Vector[index];
}

/* Vector size getter */
int ComplexVec::getSize() const
{
	return vectorSize;
}

/* Distructor - frees vector's allocated space */
ComplexVec::~ComplexVec() {
	Vector.~vector();
}



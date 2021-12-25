/* Assignment C++: 2
   Author: Barry Yosilevich, ID: 208725218
   */
#include "ComplexVec.h"
#include "Complex.h"
#include <stdlib.h>
#include <iostream>
#pragma once
class Menu 
{
	ComplexVec ComplexVec;
	void getInput( int& idx, const char* param, const int vecSize);
public:
	Menu();
	void mainMenu();
};


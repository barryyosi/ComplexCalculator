/* Assignment C++: 2
   Author: Barry Yosilevich, ID: 208725218
   */
#include "Menu.h"
#include "ComplexVec.h"
#include "Complex.h"

using namespace std;
/* Constructor */
Menu::Menu() {}

/* Input validation method */
void Menu::getInput( int& idx, const char* param, const int vecSize) {
	
	bool validIdx = 0;												// validIdx = 0 if not valid, 1 if valid
	
	cout << "Index range: 0.." << vecSize-1 << endl;				// Printing avaiable indexes range

	while (!validIdx) {												// Get index input from user until validIdx is 1
		cout << "Insert index of " << param << " number: "; // Desired index input
		cin >> idx;
		cout << "\n";
		if (idx >= vecSize || idx < 0)								// Validity condition, if inputed index is in range of vector size
			cout << "Index not in range, try again." << endl;
		else
			validIdx = 1;											// Terminate loop
	
	}
}

void Menu::mainMenu() {
	
	bool runMenu = 1;									// Menu loop running-flag
	int choice;											// holds user menu choice
	int firstIdx, secondIdx;							// hold vector accesing parameters
	
	while (runMenu) {
		cout
			<< "=======================================\n"
			<< "<1> add a new complex number\n"
			<< "<2> print all numbers\n"
			<< "<3> +\n"
			<< "<4> -\n"
			<< "<5> /\n"
			<< "<6> *\n"
			<< "<7> ~\n"
			<< "<8> polar coordinate\n"
			<< "<9> exit\n" 
			<< "=======================================" << endl;
		cin >> choice;
		
		switch (choice) {
		case 1:
		{	// Insert new complex number to ComplexVec from user input
			float real, image;
			cout << "Please insert a copmlex number:" << endl;
			cout << "Real:";
			cin >> real;
			cout << "Imaginary:";
			cin >> image;
			cout << "\n";

			Complex newComplex(real, image);			// New copmlex number with inputed parameters (real, imaginary valuess)
			ComplexVec.insert(newComplex);				// Appended to ComplexVec
			cout << newComplex << " appended to the complex vector." << endl;
			break;
		}
		case 2:
		{	
			ComplexVec.printElements();
			break; 
		}
		case 3:
		{	// If vector is not empty, get element indexes from user input in-order to conduct ADDITION(+) calculation
			int vecSize = ComplexVec.getSize();
			if (vecSize == 0)
				cout << "Vector is empty, please insert new numbers" << endl;
			else {
				getInput(firstIdx, "first", vecSize);
				getInput(secondIdx, "second", vecSize);

				cout << '(' << ComplexVec[firstIdx] << ')' << " + " << '(' << ComplexVec[secondIdx] << ')' << " = "
					 << ComplexVec[firstIdx] + ComplexVec[secondIdx] << endl;
			}
			break;
		}
		case 4:
		{	// If vector is not empty, get element indexes from user input in-order to conduct SUBSTRACTION(-) calculation
			int vecSize = ComplexVec.getSize();
			if (vecSize == 0)
				cout << "Vector is empty, please insert new numbers" << endl;
			else {
				getInput(firstIdx, "first", vecSize);
				getInput(secondIdx, "second", vecSize);

				cout << '(' << ComplexVec[firstIdx] << ')' << " - " << '(' << ComplexVec[secondIdx] << ')' << " = "
					 << ComplexVec[firstIdx] - ComplexVec[secondIdx] << endl;
			}
			break;
		}
		case 5:
		{	// If vector is not empty, get element indexes from user input in-order to conduct DIVISIONO(/) calculation
			int vecSize = ComplexVec.getSize();
			if (vecSize == 0)
				cout << "Vector is empty, please insert new numbers" << endl;
			else {
				getInput(firstIdx, "first", vecSize);

				cout << "\nBeware, zero-division is not allowed! \n\n";		// Zero division warning, force index re-input if 0 is placed in inputed index 
				do {
					getInput(secondIdx, "second", vecSize);
					cout << ((ComplexVec[secondIdx].getRad() == 0) ? "Zero-division is not allowed!" : "") << endl;
				} while (ComplexVec[secondIdx].getRad() == 0);

				cout << '(' << ComplexVec[firstIdx] << ')' << " / " << '(' << ComplexVec[secondIdx] << ')' << " = "
				     << ComplexVec[firstIdx] / ComplexVec[secondIdx] << endl;
			}
			break;
		}
		case 6:
		{	// If vector is not empty, get element indexes from user input in-order to conduct MULTIPLICATION(*) calculation
			int vecSize = ComplexVec.getSize();
			if (vecSize == 0)
				cout << "Vector is empty, please insert new numbers" << endl;
			else {
				getInput(firstIdx, "first", vecSize);
				getInput(secondIdx, "second", vecSize);

				cout << '(' << ComplexVec[firstIdx] << ')' << " * " << '(' << ComplexVec[secondIdx] << ')' << " = "
					<< ComplexVec[firstIdx] * ComplexVec[secondIdx] << endl;
			}
			break;
		}
		case 7:
		{	// If vector is not empty, get element indexes from user input in-order to conduct CONJUGATE(~) calculation
			int vecSize = ComplexVec.getSize();
			if (vecSize == 0)
				cout << "Vector is empty, please insert new numbers" << endl;
			else {
				getInput(firstIdx, "complex", vecSize);
				cout << "The conjugate of " << ComplexVec[firstIdx] << " is: " << ~ComplexVec[firstIdx] << endl;
			}
			break;
		}
		case 8:
		{	// If vector is not empty, get element indexes from user input in-order to conduct get the number's radius and phase
			int vecSize = ComplexVec.getSize();
			if (vecSize == 0)
				cout << "Vector is empty, please insert new numbers" << endl;
			else {
				getInput(firstIdx, "complex", vecSize);
				cout << "Polar coordinates for " << ComplexVec[firstIdx] << endl;
				cout << "Phase (degree): " << ComplexVec[firstIdx].getPhase() << "\370" << endl;
				cout << "Radius: " << ComplexVec[firstIdx].getRad() << endl;
			}
			break;
		}

		case 9:
			runMenu = 0;	// Turn off menu loop running flag
			break;
		
		default:			// If invalid choice has been made:
			cout << "Invalid input, try again." << endl;
			break;

}
	}
}
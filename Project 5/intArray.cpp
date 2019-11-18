/* intArray.cpp
CS320 Fall 2019, program #5
Nam Tran
This program overloads several operators for the purpose of 
 array manipulation and custom indices.
*/

#include <iostream>
#include <iomanip>
#include "string.h"         // warnings issued whether this or <string>
#include <fstream>          // necessary for external file ptr
#include <stdlib.h>
#include "intArray.h"

using namespace std;
using std::ostream;


// Constructors

/* Default constructor:
	No argument constructor creates a default array
	 of 10 elements with indices 0 to 9.
*/
IntArray::IntArray(){
	size = 10;
	lo = 0;
	hi = 9;
	pA = new int[10];
	
	//Creating space for the array
	for (int i = 0; i < size; i++){
		pA[i] = 0;
	}
}

/* Constructor of array with given size:
	This constructor creates an array of a custom
	 size with lower index 0, and upper index size - 1.
*/
IntArray::IntArray(int size){
	this ->size = size;
	lo = 0;
	hi = size - 1;
	pA = new int[size];
	
	//Creating space for the array
	for (int i = 0; i < size; i++){
		pA[i] = 0;
	}
}

/* Constructor with given lower and upper indices:
	This constructor creates an array with a custom
	 lower and upper index. Throws and error and 
	 simulates a halt if invalid limits.
*/
IntArray::IntArray(int lowerIndex, int upperIndex){
	lo = lowerIndex;
	hi = upperIndex;
	if (lowerIndex > upperIndex){
		cout << "Error: lowerIndex > upperIndex"<<endl;
		cout << "---Simulating halt---" << endl;
		return;
	}
	size = hi - lo + 1;
	pA = new int[size];
	
	//Creating space for the array
	for (int i = 0; i < size; i++){
		pA[i] = 0;
	}
}	

/* Copy constructor:
	This constructor copies another array, with entries
	 and index range duplicated.
*/
IntArray::IntArray(const IntArray& copyArr){
	size = copyArr.size;
	pA = new int[size];

	//Creating space for the array
	for (int i = 0; i < size; i++){
		pA[i] = copyArr.pA[i];
	}
}

// Destructor 
IntArray::~IntArray(){
	delete [] pA;
}

//Operator overloading

/* The overloaded == operator:
	Tests if two IntArray objects have equal elements
	 at equal indices.
	 return 0 - not equal
	 return 1 - equal
*/
int IntArray:: operator==(const IntArray& rightHand) {
	int holdingIndex = rightHand.lo;
	//Comparing sizes
	if (size != rightHand.size){
		return 0;
	}
	else{
		//Testing every element
		for (int i = 0; i < size; i++){
			if( pA[i] != rightHand.pA[i]){
				return 0;
			}
			holdingIndex++;
		}
	}
	return 1;
}

/* The overloaded != operator:
	Tests if two IntArray objects are not equal using
	 the overloaded == operator.
	return 0 - equal
	return 1 - not equal
*/
int IntArray:: operator!=(const IntArray& rightHand) {
	if(*this == rightHand){
		return 0;
	}
	return 1;
}

/* The overloaded [] operator:
	Tests the index range, and simulates a halt if
	 user tries to access out of bounds of the array
	return pA[0] - out of bound
	return pA[index - lo] - normal operation
*/
int& IntArray:: operator[](int index){
	if ((index < lo) || (index > hi)){
		cout << "Error: Index is out of bounds: arr[" << index << 
"]" << endl;
		cout << "---Simulating halt---" << endl;
		return pA[0];
	}
	return pA[index - lo];
	
}

/* The overloaded = operator:
	Assigns one IntArray object to another. Simulates a 
	 halt if the sizes of both arrays are not matching.
*/
IntArray& IntArray::operator=(const IntArray& rightHand){
	if(&rightHand != this){
		if (size != rightHand.size){
			cout << "Error: Sizes of arrays are not matching." << endl;
			cout << "---Simulating halt---" << endl;
			return *this;
		}
		for (int i = 0; i < size; i++){
			pA[i] = rightHand.pA[i];
		}
	}
	return *this;
}

/* The overloaded + operator:
	Assigns the sum of two arrays to be assigned to
	 a third array. Simulates a halt if the sizes of
	 both arrays are not matching.
*/
IntArray IntArray::operator+(const IntArray& rightHand){
	if(size != rightHand.size){
		cout << "Error: Sizes of arrays are not matching." << endl;
		cout << "---Simulating halt---" << endl;
		size = rightHand.size;
	}
	for (int i = 0; i < size; i++){
		pA[i] = pA[i] + rightHand.pA[i];
	}
	return *this;
}

/* The overloaded += operator:
	Assigns the sum of two arrays to the first array.
	 Simulates a halt if the sizes of both arrays are not
	 matching.
*/
IntArray& IntArray::operator+=(const IntArray& rightHand){
	if(size != rightHand.size){
		cout << "Error: Sizes of arrays are not matching." << endl;
		cout << "---Simulating halt---" << endl;
		size = rightHand.size;
	}
	for (int i = 0; i < size; i++){
		pA[i] = pA[i] + rightHand.pA[i];
	}
	return *this;
}

/* The overloaded << operator:
	Prints the elements of the array in the following form:
	 name[index] = value \n
*/
ostream& operator<<(ostream &output, const IntArray& arr){
	for (int i = 0; i < arr.size; i++){
		output << arr.name[0] << "[" << (i+arr.lo) << "] = " << arr.pA[i] << endl;
	}
	return output;
}

//Helper Functions

void IntArray::setName(const char *name){
	this->name = name;
}

void IntArray::getName(){
	std::cout << name;
}

int IntArray::high(){
	return hi;
}

int IntArray::low(){
	return lo;
}

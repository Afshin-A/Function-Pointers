// source: https://youtu.be/Laiv_E2q_nQ

#include <iostream>
#include <vector>
#include <algorithm> // used for std::swap()

/*
* For testing purposes
*/
int getNumber() {
	return 5;
}

/*
* For testing purposes
*/
int add(int a, int b) {
	return a + b;
}

/*
* Checks if the first argument is greater than the second argument
*/
template <typename T>
bool ascendingCheck(T a, T b) {
	return a > b;
}

/*
* Checks if the first argument is less than the second argument
*/
template <typename T>
bool descendingCheck(T a, T b) {
	return a < b;
}

/*
* Swaps two elements in a vector
*/
template <typename T>
void swap(std::vector<T>& vector, size_t i, size_t j) {
	T temp = vector[i];
	vector[i] = vector[j];
	vector[j] = temp;
}

/**
* Prints the elements of a vector
*/
template <typename T>
void printVector(std::vector<T>& vector) {
	// When the compiler is parsing the template, it doesn't know if  std::vector<T>::iterator  is a type or a variable.
	// So we use the keyword  typename  to explicitly tell the compiler this is a type.
	// We can also use  auto  to allow the compiler to automatically deduce the type and make things simpler.
	for (typename std::vector<T>::iterator iter = vector.begin(); iter != vector.end(); ++iter) {
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;
}

/*
* Just a simple (and inefficient), sorting algorithm to demonstrate the use of function pointers.
* This method uses function pointers as argument, which determines the direction of the sort (ascending or descending).
* Without the use of the function pointers, we would have to write this function twice and implement the comparison checks differently, twice.
*/
template <typename T>
void sort(std::vector<T>& vector, bool(*sortingOrder)(T, T)) {
	// Note that the  &  means vector is passed by reference, not copied. i.e. function performs operations on original vector, not a copy.
	for (size_t i = 0; i < vector.size(); i++) {
		for (size_t j = i + 1; j < vector.size(); j++) {
			if (sortingOrder(vector[i], vector[j])) {
				swap(vector, i, j);
			}
		}
	}
}

int main(int argc, char** argv) {
	// general syntax of function pointers: returnType(*pointerName)(parameter types)
	//int(*funcPtr1)() = getNumber;
	//std::cout << funcPtr1() << std::endl;

	//int(*funcPtr2)(int, int) = add;
	//std::cout << add(2, 3) << std::endl;
	//std::cout << funcPtr2(2, 3) << std::endl;
	
	
	// pass functions as arguments to optimize code by reusability. See 
	std::vector<int> testVector {1, 8, 5, 0};


	bool(*ascendingFuncPtr)(int, int) = ascendingCheck;
	bool(*descendingFuncPtr)(int, int) = descendingCheck;

	//printVector(testVector);
	//sort<int>(testVector, greaterFuncPtr);
	//printVector(testVector);

	// This function eliminates the need to write a separate swap method.
	std::swap(testVector[0], testVector[1]);
	printVector(testVector);

	//sort in ascending order
	sort(testVector, ascendingFuncPtr);
	printVector(testVector);

	// sort in descending order
	sort(testVector, descendingFuncPtr);
	printVector(testVector);

	// system("pause>nul");
	return 0;
}
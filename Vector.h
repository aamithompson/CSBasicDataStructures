//==============================================================================
// Filename: Vector.h
// Author: Aaron Thompson
// Date Created: 11/1/2021
// Date Last Modified: 10/1/2021
// Description: Implementation of a vector (dynamic array).
//==============================================================================
#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iterator>
#include "Array.h"
//------------------------------------------------------------------------------
namespace ds {
template <class T>
class Vector {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return _length; }
		const int& capacity() { return _capacity; }
	private:
		T * data;
		int _length;
		int _capacity;
//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Vector<T>() {

		}

		Vector<T>(std::initializer_list<T> list) {

		}

		Vector<T>(T arr[], int n) {

		}

		Vector<T>(Array<T> arr) {

		}

		~Vector<T>() {

		}
//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Utility Function(s)
		T * ToArray() {
			T * arr = new T[_length];
			return arr;
		}

		Array<T> ToArray() {
			Array<T> arr = Array<T>(data, _length);
			return arr;
		}

		void CopyTo(T arr[], int n=-1) {
			n = (n == -1) ? _length : std::min(_length, n);
		}

		void CopyTo(Array<T> arr) {
			int n = std::min(_length, arr._length());
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //END namespace VECTOR_H
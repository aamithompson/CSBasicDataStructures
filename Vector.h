//==============================================================================
// Filename: Vector.h
// Author: Aaron Thompson
// Date Created: 11/1/2021
// Date Last Modified: 11/2/2021
// Description: Implementation of a vector (dynamic array).
// https://en.wikipedia.org/wiki/Dynamic_array
//==============================================================================
#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iterator>
#include <cmath>
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
		const bool& empty() { return _length == 0; }
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
		//Data Manipulation Function(s)
		void SetValue(T e, int index) {
			data[index] = e;
		}

		void Fill(T e) {
			for(int i = 0; i < _length; i++) {
				data[i] = e;
			}
		}

		void Fill(T e, int start, int end) {
			for(int i = start; i < _length; i++){
				data[i] = e;
			}
		}

		void Reserve(int n) {
			if(n < _capacity) {
				return;
			}

			capacity = n;
			T * temp = data;
			data = new T[capacity];
			for(int i = 0; i < _length; i++) {
				data[i] = temp[i];
			}

			delete[] temp;
		}

		void Add(T e) {
			//Expanding vector capacity by powers of 2
			if(length == _capacity) {
				int n = (_capacity == 0) ? 0 : (int)std::floor(std::log2(_capacity)) + 1;
				_capacity = (int)std::pow(2, n);

				Reserve(_capacity);
			}

			data[_length] = e;
			_length++;
		}

		void AddRange(T arr[], int n) {
			for(int i = 0; i < n; i++) {
				Add(arr[i]);
			}
		}

		//Data Retrieval Function(s)
		T GetValue(int index) {
			return data[index];
		}

		T& operator[] (int index){
			return data[index];
		}

		//Search Function(s)
		bool Contains(T e) {
			for(int i = 0; i < _length; i++) {
				if(data[i] == e) {
					return true;
				}
			}

			return false;
		}

		T& Find(T e) {
			for(int i = 0; i < _length; i++) {
				if(data[i] = e) {
					return data[i];
				}
			}

			T* ptr = NULL;
			return *ptr;
		}

		Array<T&> FindAll(T[], int n) {
			int numOfElements = 0;
			for(int i = 0; i < n; i++) {
				if(Contains(T[i])) {
					numOfElements++;
				}
			}

			if (numOfElements > 0) {
				Array<T&> arr = Array<T&>(n);
			}

			return Array<T&>();
		}

		int IndexOf(T e) {
			for(int i = 0; i < _length; i++) {
				if(data[i] == e) {
					return i;
				}
			}

			return -1;
		}

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

			for(int i = 0; i < n; i++) {
				arr[i] = data[i];
			}
		}

		void CopyTo(Array<T> arr) {
			int n = std::min(_length, arr._length());

			for (int i = 0; i < n; i++) {
				arr[i] = data[i];
			}
		}

		void CopyTo(Vector<T> v) {
			int n = std::min(_length, v._length());

			for (int i = 0; i < n; i++) {
				v[i] = data[i];
			}
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //END namespace VECTOR_H
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

//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		void Reserve(int n) {
			if (n < _capacity) {
				return;
			}

			_capacity = n;
			T* temp = data;
			data = new T[_capacity];
			for (int i = 0; i < _length; i++) {
				data[i] = temp[i];
			}

			delete[] temp;
		}

//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Vector<T>() {
			data = new T[];
			_length = 0;
			_capacity = 0;
		}

		Vector<T>(int n) {
			data = new T[n];
			_length = 0;
			_capacity = n;
		}

		Vector<T>(std::initializer_list<T> list) {
			Reserve(list.size());
			for (int i = 0; i < list.size(); i++) {
				data[i] = list.begin()[i];
			}
		}

		Vector<T>(T arr[], int n) {
			Reserve(n);
			for(int i = 0; i < n; i++) {
				data[i] = arr[i];
			}
		}

		Vector<T>(Array<T> arr) {
			Reserve(arr.length());
			for(int i = 0; i < arr.length(); i++) {
				data[i] = arr[i];
			}
		}

		~Vector<T>() {
			delete[] data;
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

		void Remove(int index) {
			for(int i = index; i < _length - 1; i++) {
				data[i] = data[i + 1];
			}

			length--;
		}

		void Clear() {
			delete[] data;
			data = new T[];
			_length = 0;
			_capacity = 0;

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

		Array<T&> FindAll(Array<T> arr) {
			int numOfElements = 0;
			for (int i = 0; i < arr.length(); i++) {
				if (Contains(arr[i])) {
					numOfElements++;
				}
			}

			if (numOfElements > 0) {
				Array<T&> result = Array<T&>(numOfElements);
				int index = 0;
				for(int i = 0; i < arr.length(); i++) {
					T& e = Find(arr[i]);
					if(*e != NULL) {
						result[index] = e;
						index++;
					}

					if(index > numOfElements) {
						break;
					}
				}

				return result;
			}

			return Array<T&>();
		}

		Array<T&> FindAll(T arr[], int n) {
			Array<T> temp = new Array<T>(arr, n);
			return FindAll(temp);
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
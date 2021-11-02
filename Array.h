//==============================================================================
// Filename: Array.h
// Author: Aaron Thompson
// Date Created: 10/19/2021
// Date Last Modified: 11/2/2021
// Description: Array data type
//==============================================================================
#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <iterator>
//------------------------------------------------------------------------------
namespace ds {
template <class T>
class Array {
	//VARIABLE(s)
	//------------------------------------------------------------------------------
public:
	const int& length() { return _length; }
	const bool& empty() { return _length == 0; }
private:
	T* data;
	int _length;


	//CONSTRUCTOR(s)/DESTRUCTOR(s)
	//------------------------------------------------------------------------------
public:
	Array<T>() {
		data = new T[];
		_length = 0;
	}

	Array<T>(std::initializer_list<T> list) {
		data = new T[list.size()];
		_length = list.size();

		for (int i = 0; i < _length; i++) {
			data[i] = list.begin()[i];
		}
	}

	Array<T>(int n) {
		data = new T[n];
		_length = n;
	}

	Array<T>(T arr[], int n) {
		data = new T[n];
		_length = n;

		for (int i = 0; i < n; i++) {
			data[i] = arr[i];
		}
	}

	~Array<T>() {
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
		for (int i = 0; i < _length; i++) {
			data[i] = e;
		}
	}

	void Fill(T e, int start, int end) {
		for (int i = start; i < _length; i++) {
			data[i] = e;
		}
	}

	//Data Retrieval Function(s)
	T GetValue(int index) {
		return data[index];
	}

	T& operator[] (int index) {
		return data[index];
	}

	//Search Function(s)
	bool Contains(T e) {
		for (int i = 0; i < _length; i++) {
			if (data[i] == e) {
				return true;
			}
		}

		return false;
	}

	T& Find(T e) {
		for (int i = 0; i < _length; i++) {
			if (data[i] = e) {
				return data[i];
			}
		}

		T * ptr = NULL;
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
			T arr[] = new T[_length];
			for(int i = 0; i < _length; i++) {
				arr[i] = data[i];
			}

			return arr;
		}

		void Copy(Array<T> arr) {
			int n = std::min(_length, arr.length);
			for(int i = 0; i < n; i++) {
				data[i] = arr[i];
			}
		}

		void Copy(T arr[], int n) {
			n = (n == -1) ? _length : std::min(_length, n);
			for(int i = 0; i < n; i++) {
				data[i] = arr[i];
			}
		}

		void CopyTo(Array<T> arr) {
			int n = std::min(_length, arr.length);
			for(int i = 0; i < n; i++) {
				arr[i] = data[i];
			}
		}

		void CopyTo(T arr[], int n = -1) {
			n = (n == -1) ? _length : std::min(_length, n);
			for(int i = 0; i < n; i++) {
				arr[i] = data[i];
			}
		}

		void ForEach(typedef void (*f)(T&)) {
			for (int i = 0; i < _length; i++) {
				f(data[i]);
			}
		}

		void ForEach(typedef T (*f)(T)) {
			for (int i = 0; i < _length; i++) {
				data[i] = f(data[i]);
			}
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //ARRAY_H
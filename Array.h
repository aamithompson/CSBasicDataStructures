//==============================================================================
// Filename: Array.h
// Author: Aaron Thompson
// Date Created: 10/19/2021
// Date Last Modified: 10/21/2021
// Description:
//==============================================================================
#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <iterator>
#include <string>
//------------------------------------------------------------------------------
namespace ds {
template <class T>
class Array {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return _length; }
		const int& rank() { return _rank;  }
	private:
		T * data;
		int * dimensions;
		int _length;
		int _rank;


//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Array<T>() {
			data = new T[];
			dimensions = { 0 };
			_length = 0;
			_rank = 1;
		}

		Array<T>(int n) {
			data = new T[n];
			dimensions = new T[1];
			_length = n;
			_rank = 1;

			dimensions[0] = n;
		}

		Array<T>(T arr[], int n) {
			data = new T[n];
			dimensions = new T[1];
			_length = n;
			_rank = 1;

			for(int i = 0; i < n; i++) {
				data[i] = arr[i];
			}

			dimensions[0] = n;
		}

		Array<T>(T arr[], int n[], int rank){
			int size = 1;
			for(int i = 0; i < rank; i++) {
				size *= n[i];
			}

			data = new T[size];
			dimensions = new T[rank];
			_length = n;
			_rank = rank;

			for(int i = 0; i < size; i++) {
				data[i] = arr[i];
			}

			for(int i = 0; i < rank; i++) {
				dimensions[i] = n[i];
			}
		}

		~Array<T>() {
			delete[] data;
			delete[] dimensions;
		}
//FUNCTION(s)
//------------------------------------------------------------------------------
	private:
		int CoordToIndex(int indices[]) {
			for(int i = 0; i < _rank; i++) {
				if(indices[i] < 0) {
					indices[i] = dimensions[i] + indices[i];
				}
			}

			int index = indices[rank - 1];
			for(int i = 0; i <= rank - 2; i++) {
				int product = indices[i];

				for(int j = 1 + i; j <= rank - 1; j++) {
					product *= dimensions[j];
				}

				index += product;
			}

			return index;
		}

	public:
		//Data Manipulation Function(s)
		void SetValue(T e, int index) {
			data[index] = e;
		}

		void SetValue(T e, int indices[]) {
			data[CoordToIndex(indices)] = e;
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

		void Fill(T e, int start[], int end[]) {
			int coord[] = new int[_rank];

		}

		//Data Retrieval Function(s)
		T GetValue(int index) {
			return data[index];
		}

		T GetValue(int indices[]) {
			return data[CoordToIndex(indices)];
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
		T* ToArray() {
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
#endif //LINKED_LIST_H
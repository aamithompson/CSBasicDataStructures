//==============================================================================
// Filename: Stack.h
// Author: Aaron Thompson
// Date Created: 10/30/2021
// Date Last Modified: 11/1/2021
// Description: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
//==============================================================================
#ifndef  STACK_H
#define STACK_H

#include <algorithm>
#include <iterator>
#include "Array.h"
#include "SList.h"
//------------------------------------------------------------------------------
namespace ds{
template <class T>
class Stack {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return data.length(); }
		const bool& empty() { return data.empty(); }
	private:
		SList<T> data;
//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Data Manipulation Function(s)
		void Push(T e) {
			data.Insert(0, e);
		}

		void Clear() {
			data.Clear();
		}

		//Data Retrieval Function(s)
		T Peek() {
			return data[0];
		}

		T Pop() {
			T e = data[0];
			data.RemoveAt(0);
			return e;
		}

//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Stack<T>() {
			data = SList<T>();
		}

		Stack<T>(T arr[], int n) {
			data = SList<T>();
			for(int i = 0; i < n; i++){
				Push(arr[i]);
			}
		}

		Stack<T>(Array<T> arr) {
			data = SList<T>();
			for(int i = 0; i < arr.length(); i++) {
				Push(arr[i]);
			}
		}
//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Search Function(s)
		bool Contains(T e) {
			return data.Contains(e);
		}

		//Utility Function(s)
		void CopyTo(T arr[], int n=-1) {
			data.CopyTo(arr, n);
		}

		T * ToArray() {
			return data.ToArray();
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //STACK_H
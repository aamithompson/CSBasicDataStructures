//==============================================================================
// Filename: SList.h
// Author: Aaron Thompson
// Date Created: 10/18/2021
// Date Last Modified: 10/30/2021
// Description: https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
//==============================================================================
#ifndef QUEUE_H
#define QUEUE_H
//------------------------------------------------------------------------------
namespace ds {
template <class T>
class Queue {
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
		void Enqueue(T e) {
			data.Add(e);
		}

		//Data Retrieval Function(s)
		T Peek() {
			return data[0];
		}

		T Dequeue() {
			T e = data[0];
			data.RemoveAt(0);
			return e;
		}

//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Queue<T>() {
			data = SList<T>();
		}

		Queue<T>(T arr[], int n) {
			data = SList<T>();
			data.AddRange(arr, n);
		}

		Queue<T>(Array<T> arr) {
			data = SList<T>();
			T* temp = arr.ToArray();
			data.AddRange(temp, arr.length());
			delete[] temp;
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
#endif
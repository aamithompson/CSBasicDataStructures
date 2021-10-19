//==============================================================================
// Filename: Array.h
// Author: Aaron Thompson
// Date Created: 10/19/2021
// Date Last Modified: 10/19/2021
// Description:
//==============================================================================
#ifndef ARRAY_H
#define ARRAY_H

namespace ds {
template <class T>
class Array {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return _length; }
		const int& rank() { return _rank;  }
	private:
		T[] data;
		int[] dimensions;
		int _length;
		int _rank;


//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Array<T>();
		Array<T>(T[], int n);
		Array<T>(T[], int[] n);
		~Array<T>();
//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Data Manipulation Function(s)
		void SetValue(T, int index);
		void SetValue(T, int[] indices);
		void Fill(T e);
		void Fill(T e, int start, int end);
		void Fill(T e, int[] start, int[] end);

		//Data Retrieval Function(s)
		T GetValue(int index);
		T GetValue(int[] indices);

		//Search Function(s)
		bool Contains();
		T Find(T e); //TODO decide if reference
		Array<T> FindAll(T[], int n); //TODO decide if references
		int IndexOf(T)

		//Utility Function(s)
		T[] ToArray();
		void Copy(Array<T> arr)
		void Copy(T[] arr, int n);
		void CopyTo(T[] arr, int n = -1);
		void ForEach(typedef void (*f)(T));
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //LINKED_LIST_H
//==============================================================================
// Filename: LinkedList.h
// Author: Aaron Thompson
// Date Created: 10/18/2021
// Date Last Modified: 10/19/2021
// Description:
//==============================================================================
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
//------------------------------------------------------------------------------
namespace ds {
template <class T>
class SList {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return _length; }
	private:
		T[] data;
		int _length;

/*
//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		SList<T>();
		SList<T>(T[], int n);
		~SList<T>();
//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//TODO write T[] as an array class that can be inherited
		//Data Manipulation Function(s)
		void Add(T e);
		void AddRange(T[] data, int n);
		void Insert(int index, T e);
		void InsertRange(int index, T[] e);
		void Remove(T e);
		void RemoveAll(T[], int n);
		void RemoveAt(int index);
		void RemoveRange(int start, int end);
		void Clear();
		void Reverse();

		//Data Retrieval Function(s)
		T GetValue(int index);
		SList<T> GetRange(int start, int end);

		//Search Function(s)
		bool Contains();
		T Find(T e); //TODO decide if reference
		SList<T> FindAll(T[], int n); //TODO decide if references
		int IndexOf(T)

		//Utility Function(s)
		T[] ToArray();
		void CopyTo(T[], int n = -1);
		//void ForEach(Action<T> action);
		*/
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //LINKED_LIST_H

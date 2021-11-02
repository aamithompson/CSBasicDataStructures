//==============================================================================
// Filename: SList.h
// Author: Aaron Thompson
// Date Created: 10/18/2021
// Date Last Modified: 11/2/2021
// Description: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list
//==============================================================================
#ifndef S_LIST_H
#define S_LIST_H

#include <algorithm>
#include <iterator>
#include "Array.h"
//------------------------------------------------------------------------------
namespace ds {
template <class T>
struct SNode {
	public:
		T value;
		SNode<T> * next;
};

template <class T>
class SList {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return _length; }
		const bool& empty() { return head == NULL; }
	private:
		SNode<T> * head;
		SNode<T> * tail;
		int _length;

//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Search Function(s)
		bool Contains(T e) {
			SNode<T>* node = head;
			for (int i = 0; i < _length; i++) {
				if (e == node->value) {
					return true;
				}
				node = node->next;
			}

			return false;
		}

		T& Find(T e) {
			SNode<T> * node = head;
			for (int i = 0; i < _length; i++) {
				if (e == node->value) {
					return node->value;
				}
				node = node->next;
			}

			T * ptr = NULL;
			return *ptr;
		}

		SList<T&> FindAll(T arr[], int n) {
			SList<T&> list = SList<T&>();
			SNode<T> * node;
			for(int i = 0; i < n; i++) {
				node = head;
				for(int j = 0; j < _length; j++) {
					if (arr[i] == node->value) {
						list.Add(node->value);
						break;
					}

					node = node->next;
				}
			}

			return list;
		}

		int IndexOf(T e) {
			SNode<T>* node = head;
			for (int i = 0; i < _length; i++) {
				if (e == node->value) {
					return i;
				}
				node = node->next;
			}

			return -1;
		}
		
		//Data Manipulation Function(s)
		void Add(T e) {
			SNode<T> * node = new SNode<T>;
			node->value = e;

			if(empty()) {
				head = node;
				tail = node;
			} else {
				tail->next = node;
				tail = tail->next;
			}

			_length++;
		}

		void AddRange(T arr[], int n) {
			for(int i = 0; i < n; i++) {
				Add(arr[i]);
			}
		}

		void Insert(int index, T e){
			SNode<T> * node = new SNode<T>;
			node->value = e;
			if(index == 0) {
				node->next = (_length > 0) ? head : NULL;
				head = node;
			} else {
				SNode<T> * temp = head;
				for(int i = 0; i < index - 1; i++) {
					temp = temp->next;
				}

				node->next = temp->next;
				temp->next = node;
			}
		}

		void InsertRange(int index, T arr[], int n) {
			for(int i = n - 1; i >= 0; i--) {
				Insert(index, arr[i]);
			}
		}

		void RemoveAt(int index) {
			if(empty()) {
				return;
			}

			if(index == 0) {
				SNode<T> * temp = head;
				head = head->next;
				if(empty()) {
					tail = NULL;
				}

				delete temp;
			} else if(index == _length - 1) {
				SNode<T> * temp = tail;
				tail = head;
				for (int i = 0; i < _length - 2; i++) {
					tail = tail->next;
				}
				
				delete temp;
			} else {
				SNode<T> * tempA = head;
				SNode<T> * tempB;
				for (int i = 0; i < index - 2; i++) {
					tempA = tempA->next;
				}
				tempB = tempA->next;

				tempA->next = tempB->next;
				delete tempB;
			}

			_length--;
		}

		void RemoveRange(int start, int end) {
			for(int i = start; i <= end; i++) {
				RemoveAt(i);
			}
		}

		void Remove(T e){
			int index = Find(e);
			if (index != -1) {
				RemoveAt(index);
			}
		}

		void RemoveAll(T arr[], int n) {
			for(int i = 0; i < n; i++) {
				Remove(arr[i]);
			}
		}

		void Clear() {
			while(!empty()) {
				RemoveAt(0);
			}
		}

		//void Reverse();

		//Data Retrieval Function(s)
		T GetValue(int index) {
			SNode<T> * node = head;
			for(int i = 0; i < index; i++) {
				node = node->next;
			}

			return node->value;
		}

		T& operator[](int index) {
			SNode<T>* node = head;
			for (int i = 0; i < index; i++) {
				node = node->next;
			}

			return node->value;
		}

//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		SList<T>() {
			head = NULL;
			tail = NULL;
			_length = 0;
		}

		SList<T>(std::initializer_list<T> list) {
			head = NULL;
			tail = NULL;
			_length = 0;

			T* arr = new T[list.size()];
			for(int i = 0; i < list.size(); i++){
				arr[i] = list.begin()[i];
			}

			AddRange(arr, list.size());
		}

		SList<T>(T arr[], int n) {
			head = NULL;
			tail = NULL;
			_length = 0;

			AddRange(arr, n);
		}

		SList<T>(Array<T> arr) {
			head = NULL;
			tail = NULL;
			_length = 0;

			T * temp = arr.ToArray();
			AddRange(temp, arr.length());
			delete[] temp;
		}

		~SList<T>() {
			SNode<T> * current = head;
			for (int i = 0; i < _length - 1; i++) {
				SNode<T> * next =  current->next;
				delete current;
				current = next;
			}
		}

//FUNCTION(s) (Continued)
//------------------------------------------------------------------------------
	public:
		//Data Retrieval Function(s)
		SList<T> GetRange(int start, int end) {
			SList<T> list = SList<T>();
			for(int i = start; i <= end; i++) {
				list.Add(GetValue(i));
			}

			return list;
		}

		//Utility Function(s)
		T * ToArray() {
			T arr[] = new T[_length];
			SNode<T> * node = head;
			for(int i = 0; i < _length; i++) {
				arr[i] = node->value;
				node = node->next;
			}
		}

		void CopyTo(T arr[], int n = -1) {
			n = (n == -1) ? _length : std::min(_length, n);
			SNode<T> * node = head;
			for (int i = 0; i < n; i++) {
				arr[i] = node->value;
				node = node->value;
			}
		}

		//void ForEach(Action<T> action);
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //S_LIST_H
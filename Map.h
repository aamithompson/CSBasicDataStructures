//==============================================================================
// Filename: Map.h
// Author: Aaron Thompson
// Date Created: 11/1/2021
// Date Last Modified: 11/2/2021
// Description: https://en.wikipedia.org/wiki/Associative_array
//==============================================================================
#ifndef MAP_H
#define MAP_H

#include "Vector.h"
//------------------------------------------------------------------------------
namespace ds {
template <class K, class T>
struct Pair{
	K key;
	T value;
};

template <class K, class T>
class Map {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& length() { return data.length(); }
		const bool& empty() { return data.empty(); }
	private:
		Vector<Pair<K, T>> data;

//FUNCTION(s)
//------------------------------------------------------------------------------
	private:
		//Search Function(s)
		int Find(K key) {
			for(int i = 0; i < data.length(); i++) {
				if(data[i].key == key) {
					return i;
				}
			}

			return -1;
		}

	public:
		//Data Manipulation Function(s)
		void Add(K key, T value) {
			int index = Find(key);
			if (index != -1) {
				data[index].value = value;
			} else {
				Pair<K, T> e = { key, value };
				data.Add(e);
			}
		}

		void Remove(K key) {
			int index = Find(key);
			data.Remove(index);
		}

		void Clear() {
			data.Clear();
		}

		//Data Retrieval Function(s)
		T GetValue(K key) {
			int index = Find(key);
			if (index != -1) {
				return data[key];
			}

			T * ptr = NULL;
			return *ptr;
		}

		T Pop(K key) {
			int index = Find(key);
			T value = data[index];
			data.Remove(key);

			return value;
		}

//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:
		Map<K, T>() {

		}

		Map<K, T>(K * keys, T * values, int n) {

		}

		Map<K, T>(Array<K> keys, Array<T> values) {

		}

//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Search Function(s)
		bool Contains(K key) {
			return false;
		}

		bool Contains(T value) {
			return false;
		}

		bool Contains(K key, T value) {

		}

		//Utility Function(s)
		K * Keys() {
			return NULL;
		}

		Array<K> Keys() {
			return Array<K>();
		}

		T * Values() {
			return NULL;
		}

		Array<T> Values() {
			return Array<T>();
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //END namespace MAP_H
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
			data = Vector<Pair<K, T>>();
		}

		Map<K, T>(K * keys, T * values, int n) {
			data = Vector<Pair<K, T>>();
			for(int i = 0; i < n; i++) {
				Add(keys[i], values[i]);
			}
		}

		Map<K, T>(Array<K> keys, Array<T> values) {
			data = Vector<Pair<K, T>>();
			int n = std::min(keys.length(), values.length());
			for (int i = 0; i < n; i++) {
				Add(keys[i], values[i]);
			}
		}

//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Search Function(s)
		bool Contains(K key) {
			return (Find(key) != -1);
		}

		bool Contains(T value) {
			for (int i = 0; i < data.length(); i++) {
				if(data[i].value == value) {
					return true;
				}
			}

			return false;
		}

		bool Contains(K key, T value) {
			int index = Find(key);
			if(index != -1) {
				return (data[index].value == value);
			}

			return false;
		}

		//Utility Function(s)
		K * Keys() {
			K keys[] = new K[data.length()];
			for(int i = 0; i < data.length(); i++) {
				keys[i] = data[i].key;
			}

			return keys;
		}

		Array<K> Keys() {
			K arr[] = Keys();
			Array<K> keys = Array<K>(arr, data.length());
			delete[] arr;

			return keys;
		}

		T * Values() {
			T values[] = new T[data.length()];
			for (int i = 0; i < data.length(); i++) {
				values[i] = data[i].value;
			}

			return values;
		}

		Array<T> Values() {
			T arr[] = Values();
			Array<T> values = Array<T>(arr, data.length());
			delete[] arr;

			return values;
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //END namespace MAP_H
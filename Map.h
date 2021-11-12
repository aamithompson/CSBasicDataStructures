//==============================================================================
// Filename: Map.h
// Author: Aaron Thompson
// Date Created: 11/1/2021
// Date Last Modified: 11/5/2021
// Description: https://en.wikipedia.org/wiki/Associative_array
// https://en.wikipedia.org/wiki/Hash_table 
// https://www.cs.cornell.edu/courses/cs312/2008sp/lectures/lec21.html
//==============================================================================
#ifndef MAP_H
#define MAP_H

#define HASHMAP_DEFAULT_CAPACITY 16
#define HASHMAP_DEFAULY_LOADFACTOR 0.75f

#include "Vector.h"
//------------------------------------------------------------------------------
namespace ds {
template <class K, class T>
struct Pair{
	K key;
	T value;
};

template <class K, class T>
class MapInterface {
	public:
		virtual const int& count() { return 0; }
		virtual const int& capacity() { return 0; }
		virtual const bool& empty() { return true; }
	protected:
		virtual int GetIndex(K key) { return 0; }
		virtual int Find(K key) { return 0; }
	public:
		virtual void Add(){};
		virtual void Remove(K key){};
		virtual void Clear(){};
		virtual T GetValue(K key) { T* ptr = NULL; return ptr; }
		virtual T Pop(K key) { T* ptr = NULL; return ptr; }
		virtual K* Keys() { return NULL; }
		virtual Array<K> Keys() { return Array<K>(); }
		virtual T* Values() { return NULL; }
		virtual Array<T> Values() { return Array<T>(); }
		virtual Pair<K, T>* ToArray() { return NULL; }
		virtual Array<Pair<K, T>> ToArray() { return Array<Pair<K, T>>(); }
};

template <class K, class T>
class Map : MapInterface<K, T> {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& count() { return data.length(); }
		const int& capacity() { return data.capacity(); }
		const bool& empty() { return data.empty(); }
	protected:
		Vector<Pair<K, T>> data;

//FUNCTION(s)
//------------------------------------------------------------------------------
	protected:
		//Search Function(s)
		/*int GetIndex(K key) {
			for (int i = 0; i < data.length(); i++) {
				if (data[i].key == key) {
					return i;
				}
			}

			return -1;
		}*/

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

		Pair<K, T> * ToArray() {
			Pair<K, T> arr[] = new Pair<K, T>[data.length()];
			K keys[] = Keys();
			T values[] = Values();

			return arr;
		}

		Array<Pair<K, T>> ToArray() {
			Pair<K, T> arr[] = ToArray();
			Array<T> pairs = Array<T>(arr, data.length());
			delete[] arr;

			return pairs;
		}
};

//------------------------------------------------------------------------------
template <class K, class T>
class HashMap : public MapInterface<K, T> {
	public:
		const int& count() { return _count; }
		const int& capacity() { return _capacity; }
		const bool& empty() { return _count > 0;  }
	private:
		Pair<K, T> * data;
		bool * occupied;
		int _count;
		int _capacity;
		float loadFactor;
		unsigned int (*pHash)(K);
	protected:
		//Search Function(s)
		int GetIndex(K key) {
			int index = pHash(key);
			for (int i = 0; i < _capacity; i++) {
				if(occupied[i]) {
					if (data[(index + i) % _capacity].key == key) {
						return (index + i) % _capacity;
					}
				} else {
					return i;
				}
			}

			return -1;
		}

		int Find(K key) {
			int index = pHash(key);
			for(int i = 0; i < _capacity; i++) {
				if(occupied[i]) {
					if(data[(index + i) % _capacity].key == key) {
						return (index + i) % _capacity;
					}
				}
			}

			return -1;
		}

	private:
		//Data Manipulation Function(s)
		void Reserve(int n) {
			if (n < _capacity) {
				return;
			}

			int tempC = _capacity;
			Pair<K, T> * tempD = data;
			bool * tempO = occupied;
			_capacity = n;
			data = new Pair<K, T>[n];
			occupied = new bool[n];
			for (int i = 0; i < tempC; i++) {
				occupied[i] = false;
				if(tempO[i]) {
					int index = GetIndex(tempD[i].key);
					data[index] = tempD[i];
					occupied[index] = true;
				}
			}

			delete[] tempD;
			delete[] tempO;
		}

	public:
		void Add(K key, T value) {
			if(_count > std::ceil(_capacity * loadFactor)) {
				int n = (_capacity == 0) ? 0 : (int)std::floor(std::log2(_capacity)) + 1;
				n = (int)std::pow(2, n);

				Reserve(n);
			}

			int index = GetIndex(key);
			Pair<K, T> pair = { key, value };
			data[index] = pair;
			occupied[index] = true;

			count++;
		}

		void Remove(K key) {
			int index = GetIndex(key);
			occupied[index] = false
		}

		void Clear() {
			for(int i = 0; i < _capacity; i++) {
				occuplied[i] = false;
			}
		}

		//Data Retrieval Function(s)
		T GetValue(K key) {
			int index = Find(key);
			if (index != -1) {
				return data[index].value;
			}

			T* ptr = NULL;
			return ptr;
		}

		T Pop(K key) {
			T value = GetValue(key);
			Remove(key);
			return value;
		}

		HashMap<K, T>() {
			data = new Pair<K, T>[HASHMAP_DEFAULT_CAPACITY];
			occupied = new bool[HASHMAP_DEFAULT_CAPACITY];
			for(int i = 0; i < HASHMAP_DEFAULT_CAPACITY; i++) {
				occupied[i] = false;
			}
		}

		HashMap<K, T>(int n) {
			n = std::max(HASHMAP_DEFAULT_CAPACITY, n);
			data = new Pair<K, T>[n];
			occupied = new bool[n];
			for (int i = 0; i < n; i++) {
				occupied[i] = false;
			}
		}

		HashMap<K, T>(K * keys, T * values, int n) {
			int maxCap = std::max(HASHMAP_DEFAULT_CAPACITY, n);
			data = new Pair<K, T>[n];
			occupied = new bool[n];
			for (int i = 0; i < maxCap; i++) {
				occupied[n] = false;
			}

			for(int i = 0; i < n; i++) {
				Add(keys[i], values[i]);
			}
		}

		HashMap<K, T>(Array<K> keys, Array<T> values) {
			int n = std::min(keys.length(), values.length());
			int maxCap = std::max(HASHMAP_DEFAULT_CAPACITY, n);
			data = new Pair<K, T>[n];
			occupied = new bool[n];
			for (int i = 0; i < maxCap; i++) {
				occupied[n] = false;
			}

			for(int i = 0; i < n; i++) {
				Add(keys[i], values[i]);
			}
		}
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //END namespace MAP_H
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
struct pair{
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
		Vector<pair<K, T>> data;
//FUNCTION(s)
//------------------------------------------------------------------------------
	public:

//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------
	public:

//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
};
} //END namespace ds
//------------------------------------------------------------------------------
#endif //END namespace MAP_H
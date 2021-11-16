//==============================================================================
// Filename: HashFunctions.cpp
// Author: Aaron Thompson
// Date Created: 11/16/2021
// Date Last Modified: 11/16/2021
// Description: Implementations of various hash functions, i.e. for some object
// x, the hash function h(x) = i where i is an integer. i is meant to be an
// index value for an array;
// https://en.wikipedia.org/wiki/Hash_function
// https://en.wikipedia.org/wiki/Cryptographic_hash_function
// SHA-2: https://en.wikipedia.org/wiki/SHA-2
// MD5: https://en.wikipedia.org/wiki/MD5
//==============================================================================
#include "HashFunctions.h"
//------------------------------------------------------------------------------
namespace hash {
	unsigned int SHA_256(const uint8_t key[], int n) {
		//FORMAT:
		//[Key[0]] [Key[1]] . . . [Key[n-1]] [1000 000] [0000 0000]. . . [0000 0000] [n]
		uint8_t * data = new uint8_t[BLOCK256_SIZE];
		for(int i = 0; i < KEY256_SIZE; i++) {
			if(i >= n) {
				data[i] = 0;
			} else {
				data[i] = key[i];
			}
		}

		data[KEY256_SIZE] = 0x80; //1000 0000

		for(int i = KEY256_SIZE + 1; i < BLOCK256_SIZE - 1; i++) {
			data[i] = 0;
		}

		data[BLOCK256_SIZE - 1] = n * 8; //key size;

		for (int i = 0; i < BLOCK256_SIZE; i++) {
			if (i % 8 == 0) {
				std::cout << std::endl;
			}

			std::cout << data[i] << " ";
		}

		delete[] data;
		return 0;
	}

	unsigned int SHA_256(const std::string &key) {
		return SHA_256(reinterpret_cast<const uint8_t*>(key.c_str()), key.size());
	}
} //END namespace hash
//------------------------------------------------------------------------------
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
	//Bit Functions
	uint32_t LeftRotate(uint32_t x, int n) {
		return (x << n) | (x >> (INT32_BITS - n));
	}

	uint32_t RightRotate(uint32_t x, int n) {
		return (x >> n) | (x << (INT32_BITS - n));
	}
	
	//SHA-256
	uint8_t * SHA_256(const uint8_t key[], int n) {
		//Pre-Processing
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

		data[std::min(n, KEY256_SIZE)] = 0x80; //1000 0000

		for(int i = std::min(n, KEY256_SIZE) + 1; i < BLOCK256_SIZE - 1; i++) {
			data[i] = 0;
		}

		data[BLOCK256_SIZE - 1] = n * 8; //key size;

		//Message Schedule
		uint32_t * datadw = new uint32_t[BLOCK256_SIZE];
		for (int i = 0; i < BLOCK256_SIZE / 4; i++) {
			uint32_t dword = 0;
			for(int j = 0; j < 4; j++){
				dword = dword | ((uint32_t)data[(i*4)+j] << (8 * (3-j)));
			}
			datadw[i] = dword;
		}

		for(int i = BLOCK256_SIZE / 4; i < BLOCK256_SIZE; i++) {
			datadw[i] = 0;
		}

		//Modification: First Rotations
		for(int i = 16; i < BLOCK256_SIZE; i++) {
			uint32_t s0 = RightRotate(datadw[i - 15], 7) ^ RightRotate(datadw[i - 15], 18) ^ (datadw[i - 15] >> 3);
			uint32_t s1 = RightRotate(datadw[i - 2], 17) ^ RightRotate(datadw[i - 2], 19) ^ (datadw[i - 2] >> 10);
			datadw[i] = datadw[i - 16] + s0 + datadw[i - 7] + s1;
		}

		//Modification: Compression
		uint32_t * hsh = new uint32_t[8];
		for (int i = 0; i < 8; i++) {
			hsh[i] = h256[i];
		}

		uint32_t a = h256[0];
		uint32_t b = h256[1];
		uint32_t c = h256[2];
		uint32_t d = h256[3];
		uint32_t e = h256[4];
		uint32_t f = h256[5];
		uint32_t g = h256[6];
		uint32_t h = h256[7];

		for(int i = 0; i < BLOCK256_SIZE; i++) {
			uint32_t s0 = RightRotate(a, 2) ^ RightRotate(a, 13) ^ RightRotate(a, 22);
			uint32_t s1 = RightRotate(e, 6) ^ RightRotate(e, 11) ^ RightRotate(e, 25);
			uint32_t ch = (e & f) ^ (~e & g);
			uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
			uint32_t tempA = h + s1 + ch + k256[i] + datadw[i];
			uint32_t tempB = s0 + maj;
			
			h = g;
			g = f;
			f = e;
			e = d + tempA;
			d = c;
			c = b;
			b = a;
			a = tempA + tempB;
		}

		hsh[0] += a;
		hsh[1] += b;
		hsh[2] += c;
		hsh[3] += d;
		hsh[4] += e;
		hsh[5] += f;
		hsh[6] += g;
		hsh[7] += h;

		uint8_t * digest = new uint8_t[32];
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 4; j++) {
				digest[(i * 4) + j] = hsh[i] >> (24 - (j * 8));
			}
		}


		delete[] data;
		delete[] datadw;
		delete[] hsh;
		return digest;
	}

	uint8_t * SHA_256(const std::string &key) {
		return SHA_256(reinterpret_cast<const uint8_t*>(key.c_str()), key.size());
	}

	unsigned int SHA_256_UInt(const uint8_t key[], int n) {
		uint8_t * digest = SHA_256(key, n);
		uint32_t hsh = 0;
		for (int i = 0; i < 4; i++) {
			hsh = hsh | ((uint32_t)digest[i] << (8 * (3 - i)));
		}

		return hsh;
	}

	unsigned int SHA_256_UInt(const std::string& key) {
		return SHA_256_UInt(reinterpret_cast<const uint8_t*>(key.c_str()), key.size());
	}
} //END namespace hash
//------------------------------------------------------------------------------
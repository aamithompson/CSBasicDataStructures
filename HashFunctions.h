//==============================================================================
// Filename: HashFunctions.h
// Author: Aaron Thompson
// Date Created: 11/16/2021
// Date Last Modified: 11/17/2021
// Description: Implementations of various hash functions, i.e. for some object
// x, the hash function h(x) = i where i is an integer. i is meant to be an
// index value for an array;
// https://en.wikipedia.org/wiki/Hash_function
// https://en.wikipedia.org/wiki/Cryptographic_hash_function
// SHA-2: https://en.wikipedia.org/wiki/SHA-2
// MD5: https://en.wikipedia.org/wiki/MD5
//==============================================================================
#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <bitset>
#include <string>
#include <iostream>
//------------------------------------------------------------------------------
namespace hash {
//Bit Functions
	constexpr int INT32_BITS = 32;

	uint32_t LeftRotate(uint32_t value, int n);
	uint32_t RightRotate(uint32_t value, int n);

//SHA-256
	constexpr int KEY256_SIZE = 32;
	constexpr int BLOCK256_SIZE = 64;
	constexpr int H256_SIZE = 8;
	constexpr int K256_SIZE = 64;

	//hash values
	const uint32_t h256[] = { 
								0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
								0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
							};

	//round constants
	const uint32_t k256[] = { 
								0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
								0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
								0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
								0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
								0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
								0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
								0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
								0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
								0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
								0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
								0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
								0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
								0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
								0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
								0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
								0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 
							};

	uint8_t * SHA_256(const uint8_t key[], int n);
	uint8_t * SHA_256(const std::string &key);
	unsigned int SHA_256_UInt(const uint8_t key[], int n);
	unsigned int SHA_256_UInt(const std::string& key);
} //END namespace hash
//------------------------------------------------------------------------------
#endif //HASH_FUNCTIONS_H
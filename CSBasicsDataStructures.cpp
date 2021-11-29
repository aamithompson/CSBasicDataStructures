#include <iostream>
#include <iomanip>
#include "DataStructures.h"
#include "HashFunctions.h"

int main() {
	int arr[] = { 1, 2, 3 };
	ds::Array<int> a = ds::Array<int>(arr, 3);

	a[2] = 5;
	for (int i = 0; i < 3; i++) {
		std::cout << a[i];
	}

	ds::Array<int> b = { 7, 8, 9 };
	for (int i = 0; i < 3; i++) {
		std::cout << b[i];
	}

	ds::SList<int> c = { 3, 4, 3 };
	for (int i = 0; i < 3; i++) {
		std::cout << c.GetValue(i);
	}

	for (int i = 2; i >= 0; i--) {
		c.RemoveAt(i);
	}
	std::cout << std::endl << c.length();
	std::cout << std::endl << c.empty();

	for (int i = 0; i < 10; i++) {
		c.Insert(i, i);
		std::cout << c.GetValue(i);
	}

	c.InsertRange(9, arr, 3);
	std::cout << std::endl;
	for (int i = 0; i < 13; i++) {
		std::cout << c.GetValue(i);
	}

	std::cout << std::endl;
	uint8_t * lol = hash::SHA_256("hello world");
	for (int i = 0; i < 32; i++) {
		std::cout << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(lol[i]);
	}

	unsigned hashtag = hash::SHA_256_UInt("hello world");
	std::cout << std::endl << std::hex << hashtag%32;

	return 0;
}
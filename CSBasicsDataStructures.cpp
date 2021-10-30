#include <iostream>
#include "Array.h"
#include "SList.h"

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

	return 0;
}
#include "ScaleHeader.h"
#include <iostream>

matrix scale::create(float x, float y, float z) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[0] = x;
	arr[5] = y;
	arr[10] = z;
	arr[15] = 1;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from scale" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;

}

matrix scale::create(point const& p, float sX, float sY, float sZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[0] = sX * p.x;
	arr[5] = sY * p.y;
	arr[10] = sZ * p.z;
	arr[15] = 1;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from point scale" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;
}

matrix scale::create(vector const& v, float sX, float sY, float sZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[0] = sX * v.x;
	arr[5] = sY * v.y;
	arr[10] = sZ * v.z;
	arr[15] = 0;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from vector scale" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;
}
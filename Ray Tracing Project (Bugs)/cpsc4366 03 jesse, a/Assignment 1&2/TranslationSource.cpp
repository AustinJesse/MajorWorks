#include "TranslationHeader.h"
#include <string>
#include <iostream>

matrix translation::create(float x, float y, float z) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[3] = x;
	arr[7] = y;
	arr[11] = z;
	arr[15] = 1;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from translation" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;
}

matrix translation::create(point const& p, float tX, float tY, float tZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[3] = p.x + tX;
	arr[7] = p.y + tY;
	arr[11] = p.z + tZ;
	arr[15] = 1;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from point scale" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;
}

matrix translation::create(vector const& v, float tX, float tY, float tZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[3] = v.x;
	arr[7] = v.y;
	arr[11] = v.z;
	arr[15] = 0;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from vector scale" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;
}
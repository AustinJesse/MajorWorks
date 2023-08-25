#include "RotationHeader.h"
#include <iostream>
#include <cmath>

matrix rotation::create(float f, component c) {

	float cosNum = cos(f);
	float sinNum = sin(f);
	float arr[16];

	if (c == x) {
		arr[0] = 1;
		arr[1] = 0;
		arr[2] = 0;
		arr[3] = 0;
		arr[4] = 0;
		arr[5] = cosNum;
		arr[6] = -(sinNum);
		arr[7] = 0;
		arr[8] = 0;
		arr[9] = sinNum;
		arr[10] = cosNum;
		arr[11] = 0;
		arr[12] = 0;
		arr[13] = 0;
		arr[14] = 0;
		arr[15] = 1;
	}
	else if (c == y) {
		arr[0] = cosNum;
		arr[1] = 0;
		arr[2] = sinNum;
		arr[3] = 0;
		arr[4] = 0;
		arr[5] = 1;
		arr[6] = 0;
		arr[7] = 0;
		arr[8] = -(sinNum);
		arr[9] = 0;
		arr[10] = cosNum;
		arr[11] = 0;
		arr[12] = 0;
		arr[13] = 0;
		arr[14] = 0;
		arr[15] = 1;
	}
	else if (c == z) {
		arr[0] = cosNum;
		arr[1] = -(sinNum);
		arr[2] = 0;
		arr[3] = 0;
		arr[4] = sinNum;
		arr[5] = cosNum;
		arr[6] = 0;
		arr[7] = 0;
		arr[8] = 0;
		arr[9] = 0;
		arr[10] = 1;
		arr[11] = 0;
		arr[12] = 0;
		arr[13] = 0;
		arr[14] = 0;
		arr[15] = 1;
	}
	
	matrix returnMatrix(arr);
	cout << "Below is printed matrix from rotation" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;

}

matrix rotation::create(float x, float y, float z) {
	int xInt = x;
	int yInt = y;
	int zInt = z;
	
	int angleNum = atan2(yInt, xInt);
	int cosTheta = cos(angleNum);
	int sinTheta = sin(angleNum);

	float arr[16];

	arr[0] = cosTheta + (1 - cosTheta) * pow(xInt,2);
	arr[1] = (1 - cosTheta) * (xInt * yInt) - (zInt * sinTheta);
	arr[2] = (1 - cosTheta) * (xInt * zInt) + (yInt * sinTheta);
	arr[3] = 0;
	arr[4] = (1 - cosTheta) * (xInt * yInt) + (zInt * sinTheta);
	arr[5] = cosTheta + (1 - cosTheta) * pow(yInt, 2);
	arr[6] = (1 - cosTheta) * (yInt * zInt) - (xInt * sinTheta);
	arr[7] = 0;
	arr[8] = (1 - cosTheta) * (xInt * zInt) - (yInt * sinTheta);
	arr[9] = (1 - cosTheta) * (yInt * zInt) + (xInt * sinTheta);
	arr[10] = cosTheta + (1 - cosTheta) * pow(zInt, 2);
	arr[11] = 0;
	arr[12] = 0;
	arr[13] = 0;
	arr[14] = 0;
	arr[15] = 1;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from rotation overloaded" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;

}

matrix rotation::create(point p) {
	float arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	int xInt = p.x;
	int yInt = p.y;
	int zInt = p.z;

	int angleNum = atan2(yInt, xInt);
	int cosTheta = cos(angleNum);
	int sinTheta = sin(angleNum);

	arr[0] = 1;
	/*arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;*/
	arr[5] = cosTheta * yInt;
	arr[6] = -(sinTheta) * zInt;
	/*arr[7] = 0;
	arr[8] = 0;*/
	arr[9] = sinTheta * yInt;
	arr[10] = cosTheta * zInt;
	//arr[11] = 0;
	//arr[12] = 0;
	//arr[13] = 0;
	//arr[14] = 0;
	//arr[15] = 0;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from rotation point overloaded" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;

}

matrix rotation::create(vector v) {
	float arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	int xInt = v.x;
	int yInt = v.y;
	int zInt = v.z;

	int angleNum = atan2(yInt, xInt);
	int cosTheta = cos(angleNum);
	int sinTheta = sin(angleNum);

	arr[0] = 1;
	/*arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;*/
	arr[5] = cosTheta * yInt;
	arr[6] = -(sinTheta)*zInt;
	/*arr[7] = 0;
	arr[8] = 0;*/
	arr[9] = sinTheta * yInt;
	arr[10] = cosTheta * zInt;
	//arr[11] = 0;
	//arr[12] = 0;
	//arr[13] = 0;
	//arr[14] = 0;
	//arr[15] = 0;

	matrix returnMatrix(arr);
	cout << "Below is printed matrix from rotation point overloaded" << endl;
	returnMatrix.printMatrix(returnMatrix);

	return returnMatrix;

}
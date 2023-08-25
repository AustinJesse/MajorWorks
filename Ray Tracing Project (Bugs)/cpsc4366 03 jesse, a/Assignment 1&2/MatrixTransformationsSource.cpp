#include "MatrixTransformationsHeader.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265

matrix rotation::create(float f, component c) {

	float cosNum = cos(f * PI / 180.0);
	float sinNum = sin(f * PI / 180.0);
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

	return returnMatrix;

}

matrix rotation::create(float x, float y, float z) {
	int xInt = x;
	int yInt = y;
	int zInt = z;

	float angleNum = atan2(yInt, xInt);
	float cosTheta = cos(angleNum * PI / 180.0);
	float sinTheta = sin(angleNum * PI / 180.0);

	float arr[16];

	arr[0] = cosTheta + (1 - cosTheta) * pow(xInt, 2);
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

	return returnMatrix;

}

matrix rotation::create(point p) {
	float arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	float dataHolder[4];
	for (int i = 0; i < 4; i++) {
		dataHolder[i] = p.getElement(i);
	}

	float x = dataHolder[0];
	float y = dataHolder[1];
	float z = dataHolder[2];

	float angleNum = atan2(y, x);
	float cosTheta = cos(angleNum * PI / 180.0);
	float sinTheta = sin(angleNum * PI / 180.0);

	arr[0] = 1;
	/*arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;*/
	arr[5] = cosTheta * y;
	arr[6] = -(sinTheta)*z;
	/*arr[7] = 0;
	arr[8] = 0;*/
	arr[9] = sinTheta * y;
	arr[10] = cosTheta * z;
	//arr[11] = 0;
	//arr[12] = 0;
	//arr[13] = 0;
	//arr[14] = 0;
	//arr[15] = 0;

	matrix returnMatrix(arr);

	return returnMatrix;

}

matrix rotation::create(vector v) {
	float arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	float dataHolder[4];
	for (int i = 0; i < 4; i++) {
		dataHolder[i] = v.getElement(i);
	}

	float x = dataHolder[0];
	float y = dataHolder[1];
	float z = dataHolder[2];

	float angleNum = atan2(y, x);
	float cosTheta = cos(angleNum * PI / 180.0);
	float sinTheta = sin(angleNum * PI / 180.0);

	arr[0] = 1;
	/*arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;*/
	arr[5] = cosTheta * y;
	arr[6] = -(sinTheta)*z;
	/*arr[7] = 0;
	arr[8] = 0;*/
	arr[9] = sinTheta * y;
	arr[10] = cosTheta * z;
	//arr[11] = 0;
	//arr[12] = 0;
	//arr[13] = 0;
	//arr[14] = 0;
	//arr[15] = 0;

	matrix returnMatrix(arr);

	return returnMatrix;

}

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

	return returnMatrix;

}

matrix scale::create(point const p, float sX, float sY, float sZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	float dataHolder[4];
	for (int i = 0; i < 4; i++) {
		dataHolder[i] = p.getElement(i);
	}

	float x = dataHolder[0];
	float y = dataHolder[1];
	float z = dataHolder[2];

	arr[0] = sX * x;
	arr[5] = sY * y;
	arr[10] = sZ * z;
	arr[15] = 1;

	matrix returnMatrix(arr);

	return returnMatrix;
}

matrix scale::create(vector const v, float sX, float sY, float sZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	float dataHolder[4];
	for (int i = 0; i < 4; i++) {
		dataHolder[i] = v.getElement(i);
	}

	float x = dataHolder[0];
	float y = dataHolder[1];
	float z = dataHolder[2];

	arr[0] = sX * x;
	arr[5] = sY * y;
	arr[10] = sZ * z;
	arr[15] = 0;

	matrix returnMatrix(arr);

	return returnMatrix;
}

matrix translation::create(float x, float y, float z) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	arr[0] = 1;
	arr[3] = x;
	arr[5] = 1;
	arr[7] = y;
	arr[10] = 1;
	arr[11] = z;
	arr[15] = 1;

	matrix returnMatrix(arr);

	return returnMatrix;
}

matrix translation::create(point const& p, float tX, float tY, float tZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	float dataHolder[4];
	for (int i = 0; i < 4; i++) {
		dataHolder[i] = p.getElement(i);
	}

	float x = dataHolder[0];
	float y = dataHolder[1];
	float z = dataHolder[2];

	arr[0] = 1;
	arr[3] = x + tX;
	arr[5] = 1;
	arr[7] = y + tY;
	arr[10] = 1;
	arr[11] = z + tZ;
	arr[15] = 1;

	matrix returnMatrix(arr);

	return returnMatrix;
}

matrix translation::create(rc_vector const& v, float tX, float tY, float tZ) {
	float arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = 0;
	}

	float dataHolder[4];
	for (int i = 0; i < 4; i++) {
		dataHolder[i] = v.getElement(i);
	}

	float x = dataHolder[0];
	float y = dataHolder[1];
	float z = dataHolder[2];

	arr[0] = 1;
	arr[3] = x;
	arr[5] = 1;
	arr[7] = y;
	arr[10] = 1;
	arr[11] = z;
	arr[15] = 0;

	matrix returnMatrix(arr);

	return returnMatrix;
}

double conversion::deg2rad(double a) {
	return ((PI / 180.0) * a);
}

double conversion::rad2deg(double a) {
	return ((180.0 / PI) * a);
}
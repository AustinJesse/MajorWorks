#include "VectorHeader.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

rc_vector::rc_vector() {
	data_[0] = 0;
	data_[1] = 0;
	data_[2] = 0;
	data_[3] = 0;
}

rc_vector::rc_vector(float x, float y, float z) {
	data_[0] = x;
	data_[1] = y;
	data_[2] = z;
	data_[3] = 0;
}

rc_vector::rc_vector(point const& p1, point const& p2)
{
	data_[0] = p1.getElement(0) + p2.getElement(0);
	data_[1] = p1.getElement(1) + p2.getElement(1);
	data_[2] = p1.getElement(2) + p2.getElement(2);
}

void rc_vector::printVector(float x, float y, float z, float w) {
	cout << "   (" << endl;
	cout << "   " << data_[0] << endl;
	cout << "v= " << data_[1] << endl;
	cout << "   " << data_[2] << endl;
	cout << "   " << data_[3] << endl;
	cout << "   )" << endl;
}

float rc_vector::length(rc_vector vector) {
	float lengthNumber;
	lengthNumber = sqrt(pow(data_[0], 2) + pow(data_[1], 2) + pow(data_[2], 2));
	return lengthNumber;
}

rc_vector rc_vector::normalize(rc_vector thisVector) {
	float lengthNum = length(thisVector);
	data_[0] = data_[0] / lengthNum;
	data_[1] = data_[1] / lengthNum;
	data_[2] = data_[2] / lengthNum;
	//we dont change the w since its just 0 still, always 0 the slides say

	return (rc_vector::rc_vector(data_[0], data_[1], data_[2]));
}

rc_vector rc_vector::project(rc_vector const& vector1, rc_vector const& vector2) {
	float numerator;
	float denominator;

	rc_vector newVector;
	float newX;
	float newY;
	float newZ;
	float newW;

	numerator = (vector1.data_[0] * vector2.data_[0]) + (vector1.data_[1] * vector2.data_[1])
		+ (vector1.data_[2] * vector2.data_[2]) + (vector1.data_[3] * vector2.data_[3]);

	denominator = pow(sqrt(pow(vector2.data_[0], 2) + pow(vector2.data_[1], 2) + pow(vector2.data_[2], 2)),2);

	newX = numerator * vector2.data_[0];
	newY = numerator * vector2.data_[1];
	newZ = numerator * vector2.data_[2];
	newW = numerator * vector2.data_[3];

	/*newX = newX / denominator;*/
	newVector.data_[0] = newX / denominator;
	newVector.data_[1] = newY / denominator;
	newVector.data_[2] = newZ / denominator;
	newVector.data_[3] = newW / denominator;

	return newVector;
}

rc_vector rc_vector::reflect(rc_vector v) {
	rc_vector normalized;
	rc_vector vBefore;
	rc_vector result;
	rc_vector holder;

	vBefore = v;
	normalized = v.normalize(v);
	int i = 0;

	holder = cross(v, normalized);

	result.data_[0] = normalized.data_[0] * holder.data_[0] - vBefore.data_[0];
	result.data_[1] = vBefore.data_[1];
	result.data_[2] = normalized.data_[2] * holder.data_[2] - vBefore.data_[2];
	result.data_[3] = normalized.data_[3] * holder.data_[3] - vBefore.data_[3];
	
	return result;

}

float rc_vector::dot(rc_vector const& a, rc_vector const& b) {
	return (a.data_[0] * b.data_[0]) +
		(a.data_[1] * b.data_[1]) +
		(a.data_[2] * b.data_[2]);
}

rc_vector rc_vector::cross(rc_vector const& a, rc_vector const& b)
{
	float crossX;
	float crossY;
	float crossZ;
	float crossW;

	crossX = ((a.data_[1] * b.data_[2]) - (a.data_[2] * b.data_[1]));
	crossY = ((a.data_[2] * b.data_[0]) - (a.data_[0] * b.data_[2]));
	crossZ = ((a.data_[0] * b.data_[1]) - (a.data_[1] * b.data_[0]));
	crossW = 0;

	rc_vector crossedVector;
	crossedVector.data_[0] = crossX;
	crossedVector.data_[1] = crossY;
	crossedVector.data_[2] = crossZ;
	crossedVector.data_[3] = crossW;

	return crossedVector;

}

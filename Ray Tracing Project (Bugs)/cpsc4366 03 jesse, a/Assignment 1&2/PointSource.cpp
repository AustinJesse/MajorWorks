#include "PointHeader.h"
#include <iostream>
#include <cmath>

point::point() {
	data_[0] = 0;
	data_[1] = 0;
	data_[2] = 0;
	data_[3] = 1;
}

point::point(float x, float y, float z) {
	data_[0] = x;
	data_[1] = y;
	data_[2] = z;
	data_[3] = 1;
}

void point::printPoint(float x, float y, float z, float w) {
	cout << "   (" << endl;
	cout << "   " << data_[0] << endl;
	cout << "p= " << data_[1] << endl;
	cout << "   " << data_[2] << endl;
	cout << "   " << data_[3] << endl;
	cout << "   )" << endl;

}

float point::distance(point const& point1, point const& point2) {
	float distX = point1.data_[0] - point2.data_[0];
	float distY = point1.data_[1] - point2.data_[1];
	float distZ = point1.data_[2] - point2.data_[2];
	float distW = point1.data_[3] - point2.data_[3];

	float toSquare = pow(distX, 2) + pow(distY, 2) + pow(distZ, 2) + pow(distW, 2);

	toSquare = sqrt(toSquare);

	return toSquare;
}
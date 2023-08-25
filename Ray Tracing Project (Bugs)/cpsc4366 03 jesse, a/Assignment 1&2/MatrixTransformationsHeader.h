#include <string>
#include "MatrixHeader.h"
#include "PointHeader.h"
#include "VectorHeader.h"

#ifndef MATRIXTRANSFORMATIONSHEADER_H
#define MATRIXTRANSFORMATIONSHEADER_H

using namespace std;

class matrix;
class point;
class vector;

class rotation {
public:
	enum component { x = 0, y = 1, z = 2 };

	static matrix create(float, component);
	static matrix create(float, float, float);
	static matrix create(point);
	static matrix create(rc_vector);

};

class scale {
public:
	static matrix create(float, float, float);
	static matrix create(point const, float, float, float);
	static matrix create(rc_vector const, float, float, float);

};

class translation {
public:
	static matrix create(float, float, float);
	static matrix create(point const&, float, float, float);
	static matrix create(rc_vector const&, float, float, float);
};

class conversion {
public:
	double deg2rad(double);
	double rad2deg(double);
};


#endif
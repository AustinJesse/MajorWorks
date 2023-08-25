#include <string>
#include "MatrixHeader.h"
#include "PointHeader.h"
#include "VectorHeader.h"

#ifndef ROTATIONNHEADER_H
#define ROTATIONHEADER_H

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
	static matrix create(vector);

};

#endif
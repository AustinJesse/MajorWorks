#include <string>
#include "MatrixHeader.h"
#include "PointHeader.h"
#include "VectorHeader.h"

#ifndef SCALEHEADER_H
#define SCALEHEADER_H

using namespace std;

class matrix;
class point;
class vector;

class scale {
	static matrix create(float, float, float);
	static matrix create(point const&, float, float, float);
	static matrix create(vector const&, float, float, float);

};

#endif
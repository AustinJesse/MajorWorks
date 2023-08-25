#include <string>
#include "MatrixHeader.h"
#include "PointHeader.h"
#include "VectorHeader.h"

#ifndef TRANSLATIONHEADER_H
#define TRANSLATIONHEADER_H

using namespace std;

class matrix;
class point;
class vector;

class translation {
public:
	static matrix create(float, float, float);
	static matrix create(point const&, float, float, float);
	static matrix create(vector const&, float, float, float);
};

#endif
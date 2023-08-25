#include <string>
#include "PointHeader.h"
#include "VectorHeader.h"

#ifndef RAYHEADER_H
#define RAYHEADER_H

using namespace std;

class point;
class vector;

class ray {
public:
	point position_; //I assume this is the same as point origin_ but called different
	rc_vector direction_;

	ray(); // ([0,0,0], normalize([1,1,1]))

	ray(ray const&);
	ray(point const&, rc_vector const&);
	ray& operator=(ray const&);
};

#endif
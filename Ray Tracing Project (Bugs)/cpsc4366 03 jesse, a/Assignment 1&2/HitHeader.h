#include <string>
#include "MaterialHeader.h"
#include "PointHeader.h"
#include "RayHeader.h"

#ifndef HITHEADER_H
#define HITHEADER_H

using namespace std;

class point;
class vector;
class material;

class hit {
public:
	point point_;
	rc_vector normal_;
	material material_;

	hit();
	hit(point const&, rc_vector const&, material const&);
};

#endif // !HITHEADER_H


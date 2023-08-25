#include <string>
#include "MaterialHeader.h"
#include "PointHeader.h"
#include "RayHeader.h"
#include "HitHeader.h"
#include "VectorHeader.h"

#ifndef SHAPEHEADER_H
#define SHAPEHEADER_H

using namespace std;

class material;
class point;
class ray;
class vector;

class shape {
public:
	virtual bool intersect(ray const&, hit&) = 0;
	virtual double volume() const = 0;

protected:
	material material_;
};

bool intersect(ray const&, shape const&);

class box : public shape {
public:
	bool same(float, float, float);
	float epsilon = std::numeric_limits<float>::epsilon();
	bool intersect(ray const&, hit&);
	rc_vector get_normal(point const&);
	double volume() const;
	point extent_[2];
};

class sphere : public shape {
public:
	sphere(point, float);
	bool intersect(ray const&, hit&);
	double volume() const;

	point position_;
	float radius_;
};

#endif // !SHAPEHEADER_H

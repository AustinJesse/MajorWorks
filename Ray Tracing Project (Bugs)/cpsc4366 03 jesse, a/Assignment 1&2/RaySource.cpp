#include "RayHeader.h"
#include <iostream>

ray::ray() {
	point p;
	position_ = p;
	rc_vector v(1, 1, 1);
	v.normalize(v);
	direction_ = v;
}

ray::ray(ray const& r)
{
	position_ = r.position_;
	direction_ = r.direction_;
}

ray::ray(point const& p, rc_vector const& v)
{
	position_ = p;
	direction_ = v;
}

ray& ray::operator=(ray const& r)
{
	position_ = r.position_;
	direction_ = r.direction_;

	return *this;
}




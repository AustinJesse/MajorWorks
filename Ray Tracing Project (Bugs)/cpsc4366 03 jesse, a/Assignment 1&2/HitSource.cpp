#include "HitHeader.h"
#include <iostream>

hit::hit() {
	point p;
	rc_vector v;
	material m;

	point_ = p;
	normal_ = v.normalize(v);
	material_ = m;
}

hit::hit(point const& p, rc_vector const& v, material const& m) {
	rc_vector normalized;

	point_ = p;
	normal_ = normalized.normalize(v);
	material_ = m;
}
#include "ShapeHeader.h"
#include <iostream>
#include <cmath>

bool box::same(float a, float b, float e)
{
	return ((a <= (b + e)) && ( a >= (b - e)));
}

bool box::intersect(ray const& r, hit& h) {
	float holderX;
	float holderY;
	float holderZ;

	float xPoint = r.direction_.getElement(0);
	float yPoint = r.direction_.getElement(1);
	float zPoint = r.direction_.getElement(2);

	double const ddx(1.0 / xPoint);
	double const ddy(1.0 / yPoint);
	double tmin, tmax, tminy, tmaxy;

	if (ddx >= 0) {
		tmin = (extent_[0].getElement(0) - r.position_.getElement(0)) * ddx;
		tmax = (extent_[1].getElement(0) - r.position_.getElement(0)) * ddx;
	}
	else {
		tmin = (extent_[1].getElement(0) - r.position_.getElement(0)) * ddx;
		tmax = (extent_[0].getElement(0) - r.position_.getElement(0)) * ddx;
	}
	if (ddy >= 0) {
		tminy = (extent_[0].getElement(1) - r.position_.getElement(1)) * ddy;
		tmaxy = (extent_[1].getElement(1) - r.position_.getElement(1)) * ddy;
	}
	else {
		tminy = (extent_[1].getElement(1) - r.position_.getElement(1)) * ddy;
		tmaxy = (extent_[0].getElement(1) - r.position_.getElement(1)) * ddy;
	}
	if ((tmin > tmaxy) || (tminy > tmax)) {
		return false;
	}
	if (tminy > tmin) tmin = tminy;
	if (tmaxy < tmax) tmax = tmaxy;
	double const ddz(1.0 / zPoint);

	double tminz, tmaxz;
	if (ddz >= 0) {
		tminz = (extent_[0].getElement(2) - r.position_.getElement(2)) * ddz;
		tmaxz = (extent_[1].getElement(2) - r.position_.getElement(2)) * ddz;
	}
	else {
		tminz = (extent_[1].getElement(2) - r.position_.getElement(2)) * ddz;
		tmaxz = (extent_[0].getElement(2) - r.position_.getElement(2)) * ddz;
	}
	if ((tmin > tmaxz) || (tminz > tmax)) {
		return false;
	}

	if (tminz > tmin) tmin = tminz;
	if (tmaxz < tmax) tmax = tmaxz;
	if (tmax > epsilon) {
		//The below code seeks to perform the same function as:
		//h.position(r.origin() += r.direction * tmin);
		holderX = r.position_.getElement(0) + r.direction_.getElement(0) * tmin;
		holderY = r.position_.getElement(1) + r.direction_.getElement(1) * tmin;
		holderZ = r.position_.getElement(2) + r.direction_.getElement(2) * tmin;
		point holderPoint(holderX, holderY, holderZ);
		h.point_ = holderPoint;

		//The below code seeks to perform the same function as:
		//h.normal(get_normal(h.position()));
		h.normal_ = get_normal(h.point_);

		//The below code seeks to perform the same function as:
		//h.material(material_);
		h.material_ = material_;


		/*h.position(r.origin() += r.direction * tmin);
		h.normal(get_normal(h.position()));
		h.material(material_);*/
		return true;
	}

	return false;
};

rc_vector box :: get_normal(point const& p)
{
	float const eps(std::numeric_limits<float>::epsilon());

	float xPoint = p.getElement(0);
	float yPoint = p.getElement(1);
	float zPoint = p.getElement(2);
	rc_vector result;
	float resultX = result.getElement(0);
	float resultY = result.getElement(1);
	float resultZ = result.getElement(2);
	
	if (same(xPoint, extent_[0].getElement(0), eps)) resultX = -1.0;
	else if (same(xPoint, extent_[1].getElement(0), eps)) resultX = 1.0;
	else if (same(yPoint, extent_[0].getElement(1), eps)) resultY = -1.0;
	else if (same(yPoint, extent_[1].getElement(1), eps)) resultY = 1.0;
	else if (same(zPoint, extent_[0].getElement(2), eps)) resultZ = -1.0;
	else if (same(zPoint, extent_[1].getElement(2), eps)) resultZ = 1.0;
	rc_vector trueResult(resultX, resultY, resultZ);

	return trueResult;
}

double box::volume() const
{
	float length;
	float width;
	float height;

	length = extent_[1].getElement(0) - extent_[0].getElement(0);
	width = extent_[1].getElement(1) - extent_[0].getElement(1);
	height = extent_[1].getElement(2) - extent_[0].getElement(2);
	float volume = length * width * height;
	return fabs(volume);
}

bool sphere::intersect(ray const& r, hit& h) {
	float holderX;
	float holderY;
	float holderZ;
	rc_vector vTest;
	double const eps(std::numeric_limits<float>::epsilon());
	rc_vector const p(position_, r.position_);
	double const b = vTest.dot(p, r.direction_) * 2;
	double const c = vTest.dot(p, p) - radius_ * radius_;
	double const d = b * b - 4 * c;
	if (eps > d) {
		return false;
	}
	double rlen, t0, t1;
	if (eps < (t0 = 0.5 * (-b - std::sqrt(d)))) {
		rlen = t0;
	}
	else if (eps < (t1 = 0.5 * (-b + std::sqrt(d)))) {
		rlen = t1;
	}
	else {
		return false;
	}
	//The below code seeks to perform the same function as:
		//h.position(r.origin() += r.direction * rlen);
	holderX = r.position_.getElement(0) + r.direction_.getElement(0) * rlen;
	holderY = r.position_.getElement(1) + r.direction_.getElement(1) * rlen;
	holderZ = r.position_.getElement(2) + r.direction_.getElement(2) * rlen;
	point holderPoint(holderX, holderY, holderZ);
	h.point_ = holderPoint;

	//The below code seeks to perform the same function as:
	//h.normal (vector(position_, h.position()).normalize());
	rc_vector vectorHolder = rc_vector(position_, h.point_);
	h.normal_ = vectorHolder.normalize(vectorHolder);

	//The below code seeks to perform the same function as:
	//h.material(material_);
	h.material_ = material_;

	return true;
}

double sphere::volume() const
{
	double volume = (4 / 3)*(3.14)*(pow(radius_, 3));
	return volume;
}

sphere::sphere(point p, float r) {
	position_ = p;
	radius_ = r;
}

#include <string>
#include "PointHeader.h"

#ifndef VECTORHEADER_H
#define VECTORHEADER_H

using namespace std;

class rc_vector {
public:
	enum component { x = 0, y = 1, z = 2, w = 3 }; //this fills out the basic component
	rc_vector(); //sets vector slots to [0,0,0,0]
	rc_vector(float, float, float); //used to create a new vector
	rc_vector(point const&, point const& = point());

	void printVector(float, float, float, float); //prints out the vector

	float length(rc_vector); //gets the Magnitude aka the Euclidean length or L^2 norm
	rc_vector normalize(rc_vector); //creates a unit vector, aka normalization
	rc_vector project(rc_vector const& vector1, rc_vector const& vector2);
	rc_vector reflect(rc_vector /* normal */);
	float dot(rc_vector const&, rc_vector const&);
	const float* getArrayPointer() const { return data_; }
	const float& getElement(size_t ele) const { return data_[ele]; }
	rc_vector cross(rc_vector const&, rc_vector const&);

	float data_[4];
};

#endif

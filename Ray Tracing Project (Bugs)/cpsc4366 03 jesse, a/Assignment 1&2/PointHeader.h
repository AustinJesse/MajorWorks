#include <string>
#ifndef POINTHEADER_H
#define POINTHEADER_H

using namespace std;

class point {
public:
	enum component {x = 0, y = 1, z = 2, w = 3}; //this fills out the basic component
	point(); //should set component numbers to [0,0,0,1]
	point(float, float, float); //sets up xyz and sets w to 1

	const float* getArrayPointer() const { return data_; }
	const float& getElement(size_t ele) const { return data_[ele]; }

	void printPoint(float, float, float, float); //should print the 3D space point

	float distance(point const& point1, point const& point2); //returns the distance between two points, used for vector

private:
	float data_[4];

};

#endif

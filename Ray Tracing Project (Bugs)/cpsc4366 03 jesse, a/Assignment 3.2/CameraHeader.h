#include <string>
#include <iostream>
#include <functional>
#include "PointHeader.h"
#include "VectorHeader.h"
#include "OutputBaseHeader.h"
#include "RayHeader.h"

#ifndef CAMERAHEADER_H
#define CAMERAHEADER_H

using namespace std;

class point; 
class ray;
class vector;

class camera {
public:
	typedef std::function<color /* cb */(ray const&)> render_callback_type;
	typedef output_base render_output_type;
	point eye_;
	unsigned screen_[2];
	virtual void render(rc_vector, render_callback_type, render_output_type&) const;
};

#endif
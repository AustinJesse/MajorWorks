#include <string>
#include "ColorHeader.h"
#include "PointHeader.h"
#include "VectorHeader.h"

using namespace std;

class color;
class point;
class vector;

//Illumination 4 slide 7 may need to be included

class light {
public:
	bool enabled; // 0:true, false
	color ambient_; // w=0 dir, (0,0,0,1)
	color diffuse_; // 0:(1,1,1,1), (0,0,0,0)
	color specular_; // 0:(1,1,1,1), (0,0,0,0)
	float attenuation_[3]; // dflt:(c:1,l:0,q:0)

	color ambient();
	light direction(light*, color);
};

class directional_light : public light {
public:
	rc_vector direction_;
};

class point_light : public light {
public:
	rc_vector position_; // w=0 dir, (0,0,-1,0)
};

class spot_light : public directional_light, public point_light {
public:
	// spot = {cutoff, exponent}
	float spot_[2]; // [0]: 180deg (dflt)
					// xor [0,90]deg
					// [1]: [0,128]

	float spot_exponent; // [0,128]
};
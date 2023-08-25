#include <string>
#include "ColorHeader.h"

#ifndef MATERIALHEADER_H
#define MATERIALHEADER_H

using namespace std;

class color;

class material {
public:
	color emission_;
	color ambient_;
	color diffuse_;
	color specular_;
	float shininess_;

	color diffuse();
};

#endif

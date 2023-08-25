#include <string>

#ifndef COLORHEADER_H
#define COLORHEADER_H

using namespace std;

class color {
public:
	float red_;
	float green_;
	float blue_;
	float alpha_;

	color();
	color(color const&);
	color(float, float, float, float = 1.0);
	color& operator=(color const&);

	color& operator+=(color const&);
	color& operator-=(color const&);
	color& operator*=(float);

	void clamp(float = 0, float = 1);

	color clamp(color, float = 0, float = 1);
};

color const black(0, 0, 0, 1);
color const white(1, 1, 1, 1);
color const red(1, 0, 0, 1);
color const green(0, 1, 0, 1);
color const blue(0, 0, 1, 1);

inline color operator+(color const& a, color const& b) {
	return color(a) += b;
	}

inline color operator-(color const& a, color const& b) {
	return color(a) -= b;
}

inline color operator*(color const& rgba, float f) {
	return color(rgba) *= f;
}

#endif
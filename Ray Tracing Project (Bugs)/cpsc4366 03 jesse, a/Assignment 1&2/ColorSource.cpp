#include "ColorHeader.h"
#include <iostream>

color::color() {
	red_ = 0;
	green_ = 0;
	blue_ = 0;
	alpha_ = 0;
}

color::color(color const& rgba) {
	red_ = rgba.red_;
	green_ = rgba.green_;
	blue_ = rgba.blue_;
	alpha_ = rgba.alpha_;
}

color::color(float r, float g, float b, float a) {
	red_ = r;
	green_ = g;
	blue_ = b;
	alpha_ = a;
}

color& color::operator=(color const& rgba)
{
	red_ = rgba.red_;
	green_ = rgba.green_;
	blue_ = rgba.blue_;
	alpha_ = rgba.alpha_;

	clamp();

	return *this;
}

color& color::operator+=(color const& rgba) {
	red_ += rgba.red_;
	green_ += rgba.green_;
	blue_ += rgba.blue_;
	alpha_ += rgba.alpha_;

	clamp();

	return *this;
}

color& color::operator-=(color const& rgba) {
	red_ -= rgba.red_;
	blue_ -= rgba.blue_;
	green_ -= rgba.green_;
	alpha_ -= rgba.alpha_;

	clamp();

	return *this;
}

color& color::operator*=(float f) {
	red_ *= f;
	green_ *= f;
	blue_ *= f;
	alpha_ *= f;

	clamp();
	
	return *this;
}

void color::clamp(float a, float b) {
	red_ = std::max(a, std::min(b, red_));
	green_ = std::max(a, std::min(b, green_));
	blue_ = std::max(a, std::min(b, blue_));
	alpha_ = std::max(a, std::min(b, alpha_));
}

color color::clamp(color c, float a, float b) {
	c.red_ = std::max(a, std::min(b, c.red_));
	c.green_ = std::max(a, std::min(b, c.green_));
	c.blue_ = std::max(a, std::min(b, c.blue_));
	c.alpha_ = std::max(a, std::min(b, c.alpha_));
	return c;
};

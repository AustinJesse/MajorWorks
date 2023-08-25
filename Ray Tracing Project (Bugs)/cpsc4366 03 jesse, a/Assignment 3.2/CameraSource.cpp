#include "CameraHeader.h"
#include <iostream>

void camera::render(rc_vector v, render_callback_type rc, render_output_type& ro) const {
	point rayPoint;

	for (unsigned y = 0; y < screen_[1]; y++) {
		for (unsigned x = 0; x < screen_[0]; x++) {
			point p(x, y, 0);
			ray   r(eye_, rc_vector(eye_, p));
			ro.write(rc(r), { x, y });
		}
	}
	
}
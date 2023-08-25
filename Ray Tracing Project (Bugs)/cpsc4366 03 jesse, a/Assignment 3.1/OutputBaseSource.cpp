#include "OutputBaseHeader.h"
#include <iostream>
#include <fstream>
#include <valarray>

output_base::output_base() {
	index_type i;
	i[0] = 0;
	i[1] = 0;
	//vector for buffer type should be able to remain 0 as nothing passed in
}
ppm::ppm(string const& n, index_type const& i) {
	size_[0] = i[0];
	size_[1] = i[1];
	fname = n;
}

void ppm::flush() {
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	ofstr_.open(fname);
	if (ofstr_.is_open()) {
		ofstr_.seekp(0);
		ofstr_ << "P6" << '\n'
			<< "# output::ppm::write" << '\n'
			<< size_[0] << ' ' << size_[1] << '\n'
			<< "255" << '\n';

		for (unsigned y = 0; y < size_[1]; ++y) {
			for (unsigned x = 0; x < size_[0]; ++x) {
				color bufferColor(buffer_[x + (size_[1] - y) * size_[0]]);
				red = (unsigned char)(bufferColor.red_ * 255);
				green = (unsigned char)(bufferColor.green_ * 255);
				blue = (unsigned char)(bufferColor.blue_ * 255);

				ofstr_.put(red);
				ofstr_.put(green);
				ofstr_.put(blue);

				/*for (auto& channel : { red,
									  green,
									  blue }) {
					unsigned const char val = channel * 255;
					ofstr_.put(val);
				}*/
			}
		}
		ofstr_ << "\n# EOF";
	}
	ofstr_.flush();
}

void ppm::write(color const& c, index_type i) {
	unsigned idx = i[0] + (i[1] * size_[0]);

	buffer_[idx] = c;
}
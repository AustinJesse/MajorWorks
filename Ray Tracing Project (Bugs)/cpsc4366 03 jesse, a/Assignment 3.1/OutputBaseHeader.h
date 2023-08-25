#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <fstream>
#include <valarray>
#include "MaterialHeader.h"
#include "PointHeader.h"
#include "RayHeader.h"
#include "HitHeader.h"
#include "VectorHeader.h"

#ifndef OUTPUTBASEHEADER_H
#define OUTPUTBASEHEADER_H

using namespace std;

class output_base {
public:
	output_base();
	typedef std::vector<color> buffer_type;
	typedef std::array<unsigned, 2> index_type;
	virtual void flush() {
		cout << "ERROR 404: WRONG FLUSH REFERENCED!!!";
	}
	virtual void write(color const&,
		index_type const&) = 0;
protected:
	index_type size_;
	buffer_type buffer_;
	explicit output_base(index_type i/* w/h */) {
		i[0] = 0;
		i[1] = 0;
	}
};

class ppm : public output_base {
public:
	using output_base::index_type;
	explicit ppm(std::string const& /* fname */,
		index_type const& /* w/h */);
	virtual ~ppm();
	/* virtual */ void flush();
	/* virtual */ void write(color const&,
		index_type);
	string fname;
protected:
	ofstream ofstr_;
};


#endif

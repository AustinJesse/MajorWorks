#include <string>

#ifndef MATRIXHEADER_H
#define MATRIXHEADER_H

using namespace std;

class matrix {
public:
	enum cols { c0 = 0, c1 = 1, c2 = 2, c3 = 3 };
	enum rows { r0 = 0, r1 = 1, r2 = 2, r3 = 3 };
	// column major element ordering
	enum component {
		aa = 0, ba = 1, ca = 2, da = 3,
		ab = 4, bb = 5, cb = 6, db = 7,
		ac = 8, bc = 9, cc = 10, dc = 11,
		ad = 12, bd = 13, cd = 14, dd = 15
	};

	matrix();
	matrix(float const [16]);

	void printMatrix(matrix);

	bool invert(); //M=M^1
	void transpose(); // M=M^T

	float determinant();
	float trace() const;

	matrix inverse(matrix);
	matrix transpose(matrix);
	float determinant(matrix);
	float trace(matrix);
	inline float det3(float, float, float, float, float, float, float, float, float);

private:
	float data_[16];

};

#endif

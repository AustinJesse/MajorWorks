#include "MatrixHeader.h"
#include <iostream>

matrix::matrix() {
	for (int i = 0; i < 16; i++) {
		data_[i] = 0;
	}
}

matrix::matrix(float const input[16]) {
	for (int i = 0; i < 16; i++) {
		data_[i] = input[i];
	}
}

void matrix::printMatrix(matrix m) {
	cout << "|" << m.data_[0] << ", " << m.data_[1] << ", " << m.data_[2] << ", " << m.data_[3] << "|" << endl;
	cout << "|" << m.data_[4] << ", " << m.data_[5] << ", " << m.data_[6] << ", " << m.data_[7] << "|" << endl;
	cout << "|" << m.data_[8] << ", " << m.data_[9] << ", " << m.data_[10] << ", " << m.data_[11] << "|" << endl;
	cout << "|" << m.data_[12] << ", " << m.data_[13] << ", " << m.data_[14] << ", " << m.data_[15] << "|" << endl;
}

inline float matrix::det3(float a1, float a2, float a3,
	float b1, float b2, float b3,
	float c1, float c2, float c3)
{
	return ((a1 * b2 * c3) + (a2 * b3 * c1) +
		(a3 * b1 * c2) - (a1 * b3 * c2) -
		(a2 * b1 * c3) - (a3 * b2 * c1));
}

bool matrix::invert() {
	bool result(false);
	float const d(determinant());
	if (0.0 != d) {
		float const& a1(data_[0]), b1(data_[4]);
		float const& c1(data_[8]), d1(data_[12]);
		float const& a2(data_[1]), b2(data_[5]);
		float const& c2(data_[9]), d2(data_[13]);
		float const& a3(data_[2]), b3(data_[6]);
		float const& c3(data_[10]), d3(data_[14]);
		float const& a4(data_[3]), b4(data_[7]);
		float const& c4(data_[11]), d4(data_[15]);
		float const di(1.0 / d);
		matrix tmp;
		tmp.data_[0] = det3(b2, b3, b4, c2, c3, c4, d2, d3, d4) * di;
		tmp.data_[1] = -det3(a2, a3, a4, c2, c3, c4, d2, d3, d4) * di;
		tmp.data_[2] = det3(a2, a3, a4, b2, b3, b4, d2, d3, d4) * di;
		tmp.data_[3] = -det3(a2, a3, a4, b2, b3, b4, c2, c3, c4) * di;
		tmp.data_[4] = -det3(b1, b3, b4, c1, c3, c4, d1, d3, d4) * di;
		tmp.data_[5] = det3(a1, a3, a4, c1, c3, c4, d1, d3, d4) * di;
		tmp.data_[6] = -det3(a1, a3, a4, b1, b3, b4, d1, d3, d4) * di;
		tmp.data_[7] = det3(a1, a3, a4, b1, b3, b4, c1, c3, c4) * di;
		tmp.data_[8] = det3(b1, b2, b4, c1, c2, c4, d1, d2, d4) * di;
		tmp.data_[9] = -det3(a1, a2, a4, c1, c2, c4, d1, d2, d4) * di;
		tmp.data_[10] = det3(a1, a2, a4, b1, b2, b4, d1, d2, d4) * di;
		tmp.data_[11] = -det3(a1, a2, a4, b1, b2, b4, c1, c2, c4) * di;
		tmp.data_[12] = -det3(b1, b2, b3, c1, c2, c3, d1, d2, d3) * di;
		tmp.data_[13] = det3(a1, a2, a3, c1, c2, c3, d1, d2, d3) * di;
		tmp.data_[14] = -det3(a1, a2, a3, b1, b2, b3, d1, d2, d3) * di;
		tmp.data_[15] = det3(a1, a2, a3, b1, b2, b3, c1, c2, c3) * di;

		//have to switch the values so
		for (int i = 0; i < 16; i++) {
			data_[i] = tmp.data_[i];
		}
		result = true;
	}
	return result;
}

void matrix::transpose() {
	//IF TIME LEFT BEFORE SUNDAY FIGURE OUT A THEOREM!!!
	float arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = data_[i];
	}

	data_[0] = arr[0];
	data_[1] = arr[4];
	data_[2] = arr[8];
	data_[3] = arr[12];
	data_[4] = arr[2];
	data_[5] = arr[5];
	data_[6] = arr[9];
	data_[7] = arr[13];
	data_[8] = arr[2];
	data_[9] = arr[6];
	data_[10] = arr[10];
	data_[11] = arr[14];
	data_[12] = arr[3];
	data_[13] = arr[7];
	data_[14] = arr[11];
	data_[15] = arr[15];
}

float matrix::determinant() {
	float line1 = 0.0;
	float line2 = 0.0;
	float line3 = 0.0;
	float line4 = 0.0;

	float matrixOneResult;
	float matrixTwoResult;
	float matrixThreeResult;
	float matrixFourResult;

	matrixOneResult = det3(data_[5], data_[6], data_[7], data_[9], data_[10], data_[11], data_[13], data_[14], data_[15]);
	matrixTwoResult = det3(data_[4], data_[6], data_[7], data_[8], data_[10], data_[11], data_[12], data_[14], data_[15]);
	matrixThreeResult = det3(data_[4], data_[5], data_[7], data_[8], data_[9], data_[11], data_[12], data_[13], data_[15]);
	matrixFourResult = det3(data_[4], data_[5], data_[7], data_[8], data_[9], data_[11], data_[12], data_[13], data_[15]);

	line1 = data_[0] * matrixOneResult;
	line2 = -(data_[1] * matrixTwoResult);
	line3 = data_[2] * matrixThreeResult;
	line4 = -(data_[3] * matrixFourResult);

	float result = line1 + line2 + line3 + line4;

	return result;

	
}

float matrix::trace() const {
	return (data_[0] + data_[5] + data_[10] + data_[15]);
	//gets the diagonal of the matrix added up
}

matrix matrix::inverse(matrix m) {
	bool result(false);
	float const d(determinant());
	if (0.0 != d) {
		float const& a1(m.data_[0]), b1(m.data_[4]);
		float const& c1(m.data_[8]), d1(m.data_[12]);
		float const& a2(m.data_[1]), b2(m.data_[5]);
		float const& c2(m.data_[9]), d2(m.data_[13]);
		float const& a3(m.data_[2]), b3(m.data_[6]);
		float const& c3(m.data_[10]), d3(m.data_[14]);
		float const& a4(m.data_[3]), b4(m.data_[7]);
		float const& c4(m.data_[11]), d4(m.data_[15]);
		float const di(1.0 / d);
		matrix tmp;
		tmp.data_[0] = det3(b2, b3, b4, c2, c3, c4, d2, d3, d4) * di;
		tmp.data_[1] = -det3(a2, a3, a4, c2, c3, c4, d2, d3, d4) * di;
		tmp.data_[2] = det3(a2, a3, a4, b2, b3, b4, d2, d3, d4) * di;
		tmp.data_[3] = -det3(a2, a3, a4, b2, b3, b4, c2, c3, c4) * di;
		tmp.data_[4] = -det3(b1, b3, b4, c1, c3, c4, d1, d3, d4) * di;
		tmp.data_[5] = det3(a1, a3, a4, c1, c3, c4, d1, d3, d4) * di;
		tmp.data_[6] = -det3(a1, a3, a4, b1, b3, b4, d1, d3, d4) * di;
		tmp.data_[7] = det3(a1, a3, a4, b1, b3, b4, c1, c3, c4) * di;
		tmp.data_[8] = det3(b1, b2, b4, c1, c2, c4, d1, d2, d4) * di;
		tmp.data_[9] = -det3(a1, a2, a4, c1, c2, c4, d1, d2, d4) * di;
		tmp.data_[10] = det3(a1, a2, a4, b1, b2, b4, d1, d2, d4) * di;
		tmp.data_[11] = -det3(a1, a2, a4, b1, b2, b4, c1, c2, c4) * di;
		tmp.data_[12] = -det3(b1, b2, b3, c1, c2, c3, d1, d2, d3) * di;
		tmp.data_[13] = det3(a1, a2, a3, c1, c2, c3, d1, d2, d3) * di;
		tmp.data_[14] = -det3(a1, a2, a3, b1, b2, b3, d1, d2, d3) * di;
		tmp.data_[15] = det3(a1, a2, a3, b1, b2, b3, c1, c2, c3) * di;

		//have to switch the values so
		for (int i = 0; i < 16; i++) {
			m.data_[i] = tmp.data_[i];
		}
		result = true;
	}
	return m;
}

matrix matrix::transpose(matrix m) {
	float arr[16];
	for (int i = 0; i < 16; i++) {
		arr[i] = m.data_[i];
	}

	m.data_[0] = arr[0];
	m.data_[1] = arr[4];
	m.data_[2] = arr[8];
	m.data_[3] = arr[12];
	m.data_[4] = arr[2];
	m.data_[5] = arr[5];
	m.data_[6] = arr[9];
	m.data_[7] = arr[13];
	m.data_[8] = arr[2];
	m.data_[9] = arr[6];
	m.data_[10] = arr[10];
	m.data_[11] = arr[14];
	m.data_[12] = arr[3];
	m.data_[13] = arr[7];
	m.data_[14] = arr[11];
	m.data_[15] = arr[15];

	return m;
}

float matrix::determinant(matrix m) {
	float line1 = 0.0;
	float line2 = 0.0;
	float line3 = 0.0;
	float line4 = 0.0;

	float matrixOneResult;
	float matrixTwoResult;
	float matrixThreeResult;
	float matrixFourResult;

	matrixOneResult = det3(m.data_[5], m.data_[6], m.data_[7], m.data_[9], m.data_[10], m.data_[11], m.data_[13], m.data_[14], m.data_[15]);
	matrixTwoResult = det3(m.data_[4], m.data_[6], m.data_[7], m.data_[8], m.data_[10], m.data_[11], m.data_[12], m.data_[14], m.data_[15]);
	matrixThreeResult = det3(m.data_[4], m.data_[5], m.data_[7], m.data_[8], m.data_[9], m.data_[11], m.data_[12], m.data_[13], m.data_[15]);
	matrixFourResult = det3(m.data_[4], m.data_[5], m.data_[6], m.data_[8], m.data_[9], m.data_[10], m.data_[12], m.data_[13], m.data_[14]);

	line1 = m.data_[0] * matrixOneResult;
	line2 = m.data_[1] * matrixTwoResult;
	line3 = m.data_[2] * matrixThreeResult;
	line4 = m.data_[3] * matrixFourResult;

	float result = line1 - line2 + line3 + line4;

	return result;
}

float matrix::trace(matrix m) {
	return (m.data_[0] + m.data_[5] + m.data_[10] + m.data_[15]);
}



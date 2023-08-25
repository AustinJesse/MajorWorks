#include "PointHeader.h"
#include "VectorHeader.h"
#include "MatrixHeader.h"
#include "MatrixTransformationsHeader.h"
#include "ColorHeader.h"
#include "HitHeader.h"
#include "LightHeader.h"
#include "MaterialHeader.h"
#include "ShapeHeader.h"
#include "CameraHeader.h"
#include "OutputBaseHeader.h"
#include "RayHeader.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <Math3DHelper.h>
#include <math.h>
#include <list>

using namespace std;

color ray_cast_debug(ray const& r)
	{
		color result(0,0,0,1); //aka black
		result.red_ = r.direction_.data_[0];
		result.green_ = r.direction_.data_[1];
		result.blue_ = r.direction_.data_[2];
		return result;
	}

bool
cast_shadow_ray(point from, rc_vector to)
{
	bool result(false);
	ray const r(from, to.normalize(to));
	for (auto o : objects) {
		hit h;
		if (o->intersect(r, h)) {
			result = true; break;
		}
	}
	return result;
}

color const mtl_ambient = { 0.01, 0.01, 0.01, 1.0 };
color const mtl_diffuse_r = { 1.00, 0.00, 0.00, 1.0 };
color const mtl_diffuse_g = { 0.00, 1.00, 0.00, 1.0 };
color const mtl_diffuse_b = { 0.00, 0.00, 1.00, 1.0 };
std::vector<std::shared_ptr<material>> materials = {
std::make_shared<material>(mtl_ambient, mtl_diffuse_r),
std::make_shared<material>(mtl_ambient, mtl_diffuse_g),
std::make_shared<material>(mtl_ambient, mtl_diffuse_b),
};
std::vector<std::shared_ptr<shape>> objects = {
std::make_shared<sphere>(point(10, 0, -10), 5, materials[0]),
std::make_shared<box>(point(-5, -5, -5), point(5, 5, 5), materials[1]),
std::make_shared<sphere>(point(-10, 0, -10), 5, materials[2]),
};
color const lgt_amb = { 0.01, 0.01, 0.01, 1.0 };
color const lgt_diff = { 0.75, 0.75, 0.75, 1.0 };
color const lgt_spec = { 0.50, 0.50, 0.50, 1.0 };

conversion converter;
double fortyfive_deg = converter.deg2rad(45);


std::vector < std::shared_ptr<light> > lights = {
std::make_shared<directional_light>(rc_vector(0, 0, -1), lgt_amb, lgt_diff, lgt_spec),
std::make_shared<spot_light>(point(40, 40, 5),//replaced spot_source with spot_light
rc_vector(-1, -0.25, -1), lgt_amb, lgt_diff, lgt_spec, fortyfive_deg),
};

color ray_cast(ray const& r)
{
	material m;
	color result(0,0,0,1);
	std::vector<hit> hits;
	for (auto o : objects) {
		/*for (int i = 0; i < objects.size(); i++) {
			o->intersect(r, hits[i]);*/

		hit h;
		if (o->intersect(r, h)) {
			hits.push_back(h);
		}
		
		// collect all intersections in 'hits'
	}
	if (!hits.empty()) {
		for (auto l : lights) {
			result += l->ambient();
			
			// accumulate ambient contribution
			// in 'result'
		}
		// find nearest 'hit' wrt. ray origin
		// 
		// apply material diffuse contribution
		// to 'result'

		hit hit;
		point p;

		for (auto const& h : hits) {
			if (p.distance(h.point_, r.position_) <
				p.distance(hit.point_, r.position_)) {
				hit = h;
			}
		}

		result *= hit.material_->diffuse();

		for (auto l : lights) {
			if (!cast_shadow_ray(hit.point_,
				-light::direction(*l, hit.point_))) {
				result += shade(r, hit, *l);
			}
		}
	}
	return result;
}

std::list<shape> objects;
std::list<light> lights;

color ray_cast(ray);

int main() {
	float eyeCoords[3];
	cout << "Austin Jesse - Dr. Springer - CPSC 4366 Introduction to Computer Graphics" << endl << endl;
	cout << "Where is your eye located? Insert in XYZ format." << endl;
	cout << "X coord: ";
	cin >> eyeCoords[0];
	cout << endl;
	cout << "Y coord: ";
	cin >> eyeCoords[1];
	cout << endl;
	cout << "Z coord: ";
	cin >> eyeCoords[2];

	point const eye(eyeCoords[0], eyeCoords[1], eyeCoords[2]);
	unsigned const res[2] = { 100,100 };
	std::array<color, res[0] * res[1]> screen;

	float sphereCoords[3];
	cout << "Please insert the coords you wish to make your sphere at" << endl;
	cout << "X coord: ";
	cin >> sphereCoords[0];
	cout << endl;
	cout << "Y coord: ";
	cin >> sphereCoords[1];
	cout << endl;
	cout << "Z coord: ";
	cin >> sphereCoords[2];

	objects.push_back(sphere({ sphereCoords[0], sphereCoords[1], sphereCoords[2]}, 0.5));

	float boxCoords[6];
	cout << "Please insert the coords you wish to make your box at" << endl;
	cout << "first X coord: ";
	cin >> boxCoords[0];
	cout << endl;
	cout << "first Y coord: ";
	cin >> boxCoords[1];
	cout << endl;
	cout << "first Z coord: ";
	cin >> boxCoords[2];
	cout << "second X coord: ";
	cin >> boxCoords[3];
	cout << endl;
	cout << "second Y coord: ";
	cin >> boxCoords[4];
	cout << endl;
	cout << "second Z coord: ";
	cin >> boxCoords[5];

	objects.push_back(box({ boxCoords[0], boxCoords[1], boxCoords[2] },
		{ boxCoords[3], boxCoords[4], boxCoords[5] }));

	lights.push_back(light(directional_light));
	lights.push_back(light(spot_light));

	for (unsigned i = 0; i < res[0]; i++) {
		for (unsigned j = 0; j < res[1]; j++) {
			unsigned const index((i * res[0]) + j);
			ray const r(eye, point(i, j, 0));
			screen[index] = ray_cast(r);

		}
	}
	
return 0;
}
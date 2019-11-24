#ifndef __VERLETINTEGRATOR_H__
#define __VERLETINTEGRATOR_H__

#include "j1Module.h"
#include <iostream>

class object //sphere
{
public:
	void setX(double _x);

	void setY(double _y);

	void setVX(double _vx);

	void setVY(double _vy);

	void setAX(double _ax);

	void setAY(double _ay);

	void setRadius(double _radius);

	void setDensity(double _density);

	void enterData();

	double getX();

	double getY();

	double getVX();

	double getVY();

	double getAX();

	double getAY();

	double getRadius();

	double getArea();

	double getVolume();

	double getDensity();

	double getMass();

	double getFX();

	double getFY();

	double distanceTo(object _object);

	bool checkCollission(object _object);

	void update(double time, object _object, double CR);

private:
	//position
	double x = 0.0;
	double y = 0.0;

	//velocity
	double vx = 0.0;
	double vy = 0.0;

	//acceleration
	double ax = 0.0;
	double ay = 0.0;

	//object dimensions
	double radius = 1.0;
	double area = radius * radius * 3.14159265359;
	double volume = 4.0 / 3.0 * 3.14159265359 * radius * radius * radius;

	//mass
	double density = 1000.0;
	double mass = volume * density;

	//drag coefficient
	double CD = 0.47;

	//forces
	double fx = 0.0;
	double fy = 0.0;

	//updated data
	double new_x;
	double new_y;
	double new_vx;
	double new_vy;
	double new_ax;
	double new_ay;

};


class VerletIntegrator : public j1Module
{
public:
	//Constructor
	VerletIntegrator();

	// Destructor
	virtual ~VerletIntegrator();
};

#endif // __VERLETINTEGRATOR_H__
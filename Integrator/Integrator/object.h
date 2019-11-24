#pragma once
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

	void NewtonsLawsMRUA();

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

	//coefficient of friction
	double CF = 0.0;

	//forces
	double fx = 0.0;
	double fy = 0.0;

	//drag force
	double df = 0.0;

	//updated data
	double new_x = 0.0;
	double new_y = 0.0;
	double new_vx = 0.0;
	double new_vy = 0.0;
	double new_ax = 0.0;
	double new_ay = 0.0;

};

#include "object.h"
#include "globals.h"

//set

void object::setX(double _x)
{
	x = _x;
}

void object::setY(double _y)
{
	y = _y;
}

void object::setVX(double _vx)
{
	vx = _vx;
}

void object::setVY(double _vy)
{
	vy = _vy;
}

void object::setAX(double _ax)
{
	ax = _ax;
}

void object::setAY(double _ay)
{
	ay = _ay;
}

void object::setRadius(double _radius)
{
	radius = _radius;
}

void object::setDensity(double _density)
{
	density = _density;
}

void object::enterData()
{
	//x
	std::cout << "Enter a value for initial X position (m): ";
	std::cin >> x;
	std::cout << std::endl;

	//y
	std::cout << "Enter a value for initial Y position (m): ";
	std::cin >> y;
	std::cout << std::endl;


	//vx
	std::cout << "Enter a value for initial X velocity (m/s): ";
	std::cin >> vx;
	std::cout << std::endl;

	//vy
	std::cout << "Enter a value for initial Y velocity (m/s): ";
	std::cin >> vy;
	std::cout << std::endl;

	//ax
	std::cout << "Enter a value for initial X acceleration (m/s^2): ";
	std::cin >> ax;
	std::cout << std::endl;

	//ay
	std::cout << "Enter a value for initial Y acceleration (m/s^2): ";
	std::cin >> ay;
	std::cout << std::endl;

	//radius
	std::cout << "Enter a value for the sphere radius (m): ";
	std::cin >> radius;
	std::cout << std::endl;
	area = radius * radius * 3.14159265359;
	volume = 4.0 / 3.0 * 3.14159265359 * radius * radius * radius;

	//density
	std::cout << "Enter a value for the density of the object (kg/m^3): ";
	std::cin >> density;
	std::cout << std::endl;
	mass = volume * density;
}

//get

double object::getX()
{
	return x;
}

double object::getY()
{
	return y;
}

double object::getVX()
{
	return vx;
}

double object::getVY()
{
	return vy;
}

double object::getAX()
{
	return ax;
}

double object::getAY()
{
	return ay;
}

double object::getRadius()
{
	return radius;
}

double object::getArea()
{
	return area;
}

double object::getVolume()
{
	return volume;
}

double object::getDensity()
{
	return density;
}

double object::getMass()
{
	return mass;
}

double object::getFX()
{
	return fx;
}

double object::getFY()
{
	return fy;
}

double object::distanceTo(object _object)
{
	double distanceX = abs(x - _object.x);
	double distanceY = abs(y - _object.y);

	double distance = sqrt(distanceX * distanceX + distanceY * distanceY);

	return distance;
}

bool object::checkCollission(object _object)
{
	if (distanceTo(_object) <= radius + _object.radius)
		return true;
	else
		return false;
}

void object::update(double time, object _object, double CR)
{
	unsigned int second = 0;
	unsigned int frame = 0;
	unsigned int secondFrame = 0;

	for (double t = 0.0; t < time - 1.0 / 60.0; t = t + 1.0 / 60.0)
	{
		//X

		fx = 0.5 * AIR_DENSITY * new_vx * new_vx * area * CD;

		if (new_vx <= 0.0)
			new_ax = fx / mass;
		else
			new_ax = -fx / mass;

		new_x = x + new_vx * t + (new_ax / 2.0) * t * t;
		new_vx = vx + new_ax * t;


		//Y

		fy = 0.5 * AIR_DENSITY * new_vy * new_vy * area * CD;

		if (new_vy <= 0.0 && new_y > 0.0)
			new_ay = fy / mass + GRAVITY;
		else if (new_vy > 0.0 && new_y > 0.0)
			new_ay = -fy / mass + GRAVITY;
		else if (new_vy <= 0.0 && new_y <= 0.0)
			new_ay = fy / mass;
		else
			new_ay = -fy / mass;

		new_y = y + new_vy * t + (new_ay / 2.0) * t * t;
		new_vy = vy + new_ay * t;

		if (new_y < 0.0)
			new_y = 0.0;


		//Collision

		if (checkCollission(_object) == true)
		{
			std::cout << "Collision!" << std::endl;
			new_vx = (((CR * _object.mass * (_object.vx - new_vx)) + (mass * new_vx + _object.mass * _object.vx)) / (mass + _object.mass));
			new_vy = (((CR * _object.mass * (_object.vy - new_vy)) + (mass * new_vy + _object.mass * _object.vy)) / (mass + _object.mass));
		}

		//Results

		frame++;
		secondFrame++;
		if ((frame - 1) % 60 == 0)
			second++, secondFrame = 0;

		if (frame == 1)
		{
			std::cout << "Second: " << second - 1 << "   Frame: " << secondFrame + 1 << "   Total Frame: " << frame << std::endl;
			std::cout << "x: " << x << "  vx: " << vx << "  ax: " << ax << std::endl;
			std::cout << "y: " << y << "  vy: " << vy << "  ay: " << ay << std::endl << std::endl;
		}
		else
		{
			std::cout << "Second: " << second - 1 << "   Frame: " << secondFrame + 1 << "   Total Frame: " << frame << std::endl;
			std::cout << "x: " << new_x << "  vx: " << new_vx << "  ax: " << new_ax << std::endl;
			std::cout << "y: " << new_y << "  vy: " << new_vy << "  ay: " << new_ay << std::endl << std::endl;
		}
	}

}
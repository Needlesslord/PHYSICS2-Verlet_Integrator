#include "VerletIntegrator.h"
#include "j1App.h"
#include "Globals.h"
#include "j1Render.h"
#include "j1Scene.h"

//Constructor
VerletIntegrator::VerletIntegrator() : j1Module()
{
	name.create("physics");
	object ball;
}

// Destructor
VerletIntegrator::~VerletIntegrator()
{
}

// Object Functions ---------------------------------------------------------------------------------------------

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

void object::setFX(double _fx)
{
	fx = _fx;
}

void object::setFY(double _fy)
{
	fy = _fy;
}

void object::setCD(double _cd)
{
	CD = _cd;
}

void object::setSide(double _side)
{
	side = _side;
	area = side * side;
	volume = side * side * side;
}

void object::setDensity(double _density)
{
	density = _density;
	mass = volume * density;
}

void object::setElasticity(int _e)
{
	isElastic = _e;
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

double object::getSide()
{
	return side;
}

double object::getArea()
{
	return area;
}

double object::getVolume()
{
	return volume;
}

double object::getCD()
{
	return CD;
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

double object::getElasticity()
{
	return isElastic;
}

double object::distanceTo(object _object)
{
	double distanceX = abs(new_x - _object.x);
	double distanceY = abs(new_y - _object.y);

	double distance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

	return distance;
}

bool object::checkCollission(object _object)
{
	if (distanceTo(_object) <= side + _object.side)
		return true;
	else
		return false;
}

void object::update(double time, object _object, double CR)
{
	unsigned int second = 0;
	unsigned int frame = 0;
	unsigned int secondFrame = 0;
	bool checkCollisionAgain = true;

	new_x = x;
	new_y = y;
	new_vx = vx;
	new_vy = vy;

	for (frame = 0; frame < time * fps; frame++)
	{
		dt = 1.0 / fps;

		//X

		//Updating previous frame variables
		x = new_x;
		vx = new_vx;

		//Forces
		fx = 0.5 * AIR_DENSITY * new_vx * new_vx * area * CD;

		//Acceleration
		if (new_vx <= 0.0)
			new_ax = fx / mass;
		else
			new_ax = -fx / mass;

		//Velocity
		new_vx = vx + new_ax * dt;

		//Position
		new_x = x + vx * dt + (new_ax / 2.0) * dt * dt;


		//Y

		//Updating previous frame variables
		y = new_y;
		vy = new_vy;

		//Forces
		fy = 0.5 * AIR_DENSITY * new_vy * new_vy * area * CD;

		//Acceleration
		if (new_vy <= 0.0)
			new_ay = fy / mass + GRAVITY;
		else if (new_vy > 0.0)
			new_ay = -fy / mass + GRAVITY;

		//Velocity
		new_vy = vy + new_ay * dt;

		//Position
		new_y = y + vy * dt + (new_ay / 2.0) * dt * dt;



		//Solving ground collision
		if (new_y < side && !isElastic)
		{
			new_y = side;
			new_vy = 0.0;
		}
		else if (new_y < side && isElastic)
		{
			new_vy = -new_vy;
		}


		//Collision

		if (checkCollission(_object) == true && checkCollisionAgain == true)
		{
			new_vx = ((CR * _object.mass * (_object.vx - new_vx) + mass * new_vx + _object.mass * _object.vx) / (mass + _object.mass));
			new_vy = ((CR * _object.mass * (_object.vy - new_vy) + mass * new_vy + _object.mass * _object.vy) / (mass + _object.mass));

			checkCollisionAgain = false;
		}

		if (distanceTo(_object) > side + _object.side)
			checkCollisionAgain = true;

		//Results

		secondFrame++;
		if ((frame - 1) % (int)fps == 0)
			second++, secondFrame = 0;

		if (frame == 1)
		{
		}
		else
		{

		}

		//Drawing Object if it has to
		if (App->scene->draw)
		{
			App->scene->Draw(new_x, new_y);
		}
	}

	//Restart(); //Menu Restart al acabar la representacio
}

void object::NewtonsLawsMRUA() //Codi amb els calculs segons les lleis de Newton
{
	new_ax = fx / mass;

	new_vx = vx + new_ax * dt;

	new_x = x + vx * dt + (new_ax / 2.0) * dt * dt;

	new_ay = fy / mass;

	new_vy = vy + new_ay * dt;

	new_y = y + vy * dt + (new_ay / 2.0) * dt * dt;

	//Adaptar a la interface

	//Adaptar a la interface

	Restart();
}

void object::Restart()		//Funcio per acabar la representacio
{
	//int restart;
	//double time;
	//object _object;
	//draw = false;

	////Adaptar a la interface
	//

	//std::cin >> restart;		//rep valor de "restart"
	////Adaptar a la interface

	//if (restart == 1)			//Si es "1" aplicar newton
	//{
	//	NewtonsLawsMRUA();
	//}
	//else if (restart == 2)		//Si es "2" restart
	//{

	//	//enterData();

	//	//Adaptar a la interface
	//	std::cin >> time;
	//	//Adaptar a la interface

	//	update(time, _object, 1);
	//}
	//else						//Exit
	//{
	//	system("pause");
	//}
}
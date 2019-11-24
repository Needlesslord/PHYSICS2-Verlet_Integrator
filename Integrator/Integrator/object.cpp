#include "object.h"
#include "globals.h"

//////// VARIABLES LIST ////////
/*

dt = time between 2 frames

new_x = value of x in the current frame
x = initial x, when used in a formula x = previous frame x position

new_y = value of y in the current frame
y = initial y, when used in a formula y = previous frame y position

new_vx = value of vx in the current frame
vx = initial vx, when used in a formula vx = previous frame x velocity

new_vy = value of vy in the current frame
vy = initial vy, when used in a formula vy = previous frame y velocity

new_ax = value of ax in the current frame
ax = initial ax, when used in a formula ax = previous frame x acceleration

new_ay = value of ay in the current frame
ay = initial ay, when used in a formula ay = previous frame a acceleration

fx = resultant force on x axis
fy = resultant force on y axis

initial_fx= initial force on x axis
initial_fy= initial force on y axis

CF = coefficient of friction with the ground
ff = friction force of the object


bool checkCollision() compares two object positions, if their distance is less than the sum of their radius, returns true

*/



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

void object::setEdgeLength(double _edgeLength)
{
	edge_length = _edgeLength;
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
	std::cin >> edge_length;
	std::cout << std::endl;
	area = edge_length * edge_length;
	volume = edge_length * edge_length * edge_length;

	//density
	std::cout << "Enter a value for the density of the object (kg/m^3): ";
	std::cin >> density;
	std::cout << std::endl;
	mass = volume * density;

	//initial force
	std::cout << "Enter a value for the initial force of the object on the x axis (N): ";
	std::cin >> initial_fx;
	std::cout << std::endl;

	std::cout << "Enter a value for the initial force of the object on the y axis (N): ";
	std::cin >> initial_fy;
	std::cout << std::endl;

	//coefficient of friction
	int i = 0;
	while (i == 0) {
		std::cout << "Enter a value for the coefficient of friction(value should range between 0 and 1): ";
		std::cin >> CF;
		std::cout << std::endl;
		if (CF >= 0 && CF <= 1) {
			ff = CF * mass * GRAVITY;
			i = 1;

		}
		else {
			std::cout << "Wrong value introduced." << std::endl;
			std::cout << std::endl;
		}
	}
	
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
	return edge_length;
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
	double distanceX = abs(new_x - _object.x) - (edge_length / 2 - _object.edge_length / 2);
	double distanceY = abs(new_y - _object.y) - (edge_length / 2 - _object.edge_length / 2);

	double distance = sqrt(distanceX * distanceX + distanceY * distanceY);

	return distance;
}

bool object::checkCollission(object _object)
{
	double distanceX = abs(new_x - _object.x);
	double distanceY = abs(new_y - _object.y);

	if (distanceX <= 0.0 || distanceY <= 0.0)
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
		
		if (initial_fx != 0) {
			fx += initial_fx;
			initial_fx = 0;
		}

		if (new_y == 0) {
			fx += ff;
		}

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

		if (initial_fy != 0) {
			fy += initial_fy;
			initial_fy = 0;
		}

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
		if (new_y < edge_length)
		{
			new_y = edge_length;
			new_vy = 0.0;
		}

		//Collision

		if (checkCollission(_object) == true /*&& checkCollisionAgain == true*/)
		{
			std::cout << "Collision!" << std::endl;
			//new_vx = ((CR * _object.mass * (_object.vx - new_vx) + mass * new_vx + _object.mass * _object.vx) / (mass + _object.mass));
			//new_vy = ((CR * _object.mass * (_object.vy - new_vy) + mass * new_vy + _object.mass * _object.vy) / (mass + _object.mass));

			//checkCollisionAgain = false;
		}

		//if (distanceTo(_object) > edge_length + _object.edge_length)
			//checkCollisionAgain = true;

		//Results

		secondFrame++;
		if ((frame - 1) % (int)fps == 0)
			second++, secondFrame = 0;

		if (frame == time)
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
			std::cout << "distance to object: " << distanceTo(_object) << std::endl;
		}
		/*else system("pause");*/
	}
	
	Restart();
}

void object::NewtonsLawsMRUA()
{
	new_ax = fx / mass;

	new_vx = vx + new_ax * dt;

	new_x = x + vx * dt + (new_ax / 2.0) * dt * dt;

	new_ay = fy / mass;

	new_vy = vy + new_ay * dt;

	new_y = y + vy * dt + (new_ay / 2.0) * dt * dt;

	std::cout << "NEWTON'S RESULTS" << std::endl << std::endl;
	std::cout << "x: " << new_x << "  vx: " << new_vx << "  ax: " << new_ax << std::endl;
	std::cout << "y: " << new_y << "  vy: " << new_vy << "  ay: " << new_ay << std::endl << std::endl;

	Restart();
}

void object::Restart()
{
	int restart;
	double time;
	object obstacle;

	std::cout << std::endl;
	std::cout << "Enter '1' if you want to compare the results with Newton's laws" << std::endl;
	std::cout << "Enter '2' if you want to restart the whole process" << std::endl;
	std::cout << "Enter another number if you want to exit" << std::endl << std::endl;

	std::cin >> restart;

	if (restart == 1)
	{
		NewtonsLawsMRUA();
	}
	else if (restart == 2)
	{
		std::cout << std::endl;

		enterData();

		std::cout << "How many seconds will the simulation last? ";
		std::cin >> time;
		std::cout << std::endl;

		update(time, obstacle, 1);
	}
	else 
	{
	system("pause");
	}
}
#include "VerletIntegrator.h"
#include <iostream>

int main()
{
	//VerletIntegrator::Object object1;
	//object1.vx = 5;
	//object1.x = 5;
	Object sphere;

	sphere.x = 0.0;
	sphere.y = 4000.0;
	sphere.vx = 0.0;
	sphere.vy = 0.0;
	sphere.ax = 0.0;
	sphere.ay = gravity;
	sphere.radius = 1.0;
	sphere.area = sphere.radius * sphere.radius * 3.14159265359;
	sphere.mass = 1000.0;

	Forces sphere_forces;

	double new_x = sphere.x;
	double new_y = sphere.y;
	double new_vx = sphere.vx;
	double new_vy = sphere.vy;
	double new_ax = sphere.ax;
	double new_ay = sphere.ay;

	for (int t = 0; t < 60; t++)
	{
		//VerletIntegrator::Integrate(object1, 1);

		//Y

		sphere_forces.y = 0.5 * AIR_DENSITY * new_vy * new_vy * sphere.area * sphere.CD;

		new_ay = sphere_forces.y / sphere.mass + gravity;

		new_y = sphere.y + new_vy * t + (new_ay / 2) * t * t;
		new_vy = sphere.vy + new_ay * t;


		//X

		sphere_forces.x = 0.5 * AIR_DENSITY * new_vx * new_vx * sphere.area * sphere.CD;

		new_ax = sphere_forces.x / sphere.mass;


		new_x = sphere.x + new_vx * t + (new_ax / 2) * t * t;
		new_vx = sphere.vx + new_ax * t;

		if (new_y <= 0)
			break;

		std::cout << "x: " << new_x << "  vx: " << new_vx << "  ax: " << new_ax << std::endl;
		std::cout << "y: " << new_y << "  vy: " << new_vy << "  ay: " << new_ay << std::endl << std::endl;

	}

	system("pause");
	return 0;
}
#include "VerletIntegrator.h"
#include <iostream>

int main()
{
	//VerletIntegrator::Object object1;
	//object1.vx = 5;
	//object1.x = 5;
	float xi = 5;
	float vi = 5;
	float v = 0;
	float a = 1;
	float x = 0;

	for (int t = 0; t < 60; t++)
	{
		//VerletIntegrator::Integrate(object1, 1);
		x = xi + v*t + (a / 2)*t*t;
		v = vi + a*t;

		std::cout << "x: " << x << "  v: " << v << "  a: " << a << " t: "<< t << std::endl;
	}

	system("pause");
	return 0;
}
#include "VerletIntegrator.h"
#include <iostream>

int main()
{
	//VerletIntegrator::Object object1;
	//object1.vx = 5;
	//object1.x = 5;
	float v = 5;
	float a = 1;
	float x = 5;

	for (int t = 1, i = 0; i < 60; i++)
	{
		//VerletIntegrator::Integrate(object1, 1);
		x = x + v*t + (a / 2)*t*t;
		v = v + a*t;

		std::cout << "x: " << x << "  v: " << v << "  a: " << a << " t: "<< i << std::endl;
	}

	system("pause");
	return 0;
}
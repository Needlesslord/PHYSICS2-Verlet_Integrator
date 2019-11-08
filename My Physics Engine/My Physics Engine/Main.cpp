#include "VerletIntegrator.h"
#include <iostream>

int main()
{
	//VerletIntegrator::Object object1;
	//object1.vx = 5;
	//object1.x = 5;
	int xi = 5;
	int vi = 5;
	int v = 0;
	int a = 1;
	int x = 0;

	for (int t = 0; t < 60; t++)
	{
		//VerletIntegrator::Integrate(object1, 1);
		x = xi + v*t + (a / 2)*t*t;
		v = vi + a*t;

		std::cout << "x: " << x << "  v: " << v << "  a: " << a << std::endl;
	}

	system("pause");
	return 0;
}
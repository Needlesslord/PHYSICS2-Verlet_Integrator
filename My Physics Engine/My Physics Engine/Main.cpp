#include "VerletIntegrator.h"
#include <iostream>

int main()
{
	//VerletIntegrator::Object object1;
	//object1.vx = 5;
	//object1.x = 5;
	//float xi = 0.0;
	//float vi = 5.0;
	float v = 1.0;
	float a = 1.0;
	float x = 0.0;
	float fr = 30.0;
	float dt = 0.0;

	for (int numF = 0; numF < 60; numF++)
	{
		//calculate the dt: time between frames
		dt = 1.0f / fr;							//1 --> int, 1.0 --> float

		//VerletIntegrator::Integrate(object1, 1);


		x = x + v * dt + (a * 0.5f)*(dt*dt);		// 0.5 better than 1/2
		v = v + a * dt;
		std::cout << "x: " << x << "  v: " << v << "  a: " << a << "  frame: " << numF << std::endl;
	}

	system("pause");
	return 0;
}

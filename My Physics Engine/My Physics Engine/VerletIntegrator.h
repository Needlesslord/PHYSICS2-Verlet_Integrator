#pragma once

class VerletIntegrator
{
public:

	struct Object
	{
		int x;
		int y;
		int vx;
		int vy;
		int ax;
		int ay;
	};


	//Constructor
	VerletIntegrator();

	// Destructor
	virtual ~VerletIntegrator();

	// Integration function
	Object Integrate(Object obj, int dt);

};
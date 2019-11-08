#pragma once

class VerletIntegrator
{
	struct Object
	{
		int x;
		int y;
		int vx;
		int vy;
		int ax;
		int ay;
	};

public:

	//Constructor
	VerletIntegrator();

	// Destructor
	virtual ~VerletIntegrator();

	// Integration function
	Object Integrate(Object obj, int dt);

};
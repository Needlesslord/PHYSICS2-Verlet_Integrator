#ifndef __VERLETINTEGRATOR_H__
#define __VERLETINTEGRATOR_H__

#include "j1Module.h"

class VerletIntegrator : public j1Module
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

#endif // __VERLETINTEGRATOR_H__
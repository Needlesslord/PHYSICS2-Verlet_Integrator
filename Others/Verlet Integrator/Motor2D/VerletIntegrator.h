#ifndef __VERLETINTEGRATOR_H__
#define __VERLETINTEGRATOR_H__

#include "j1Module.h"

struct data_xvadt
{
	int x;
	int v;
	int a;
	int t;
};

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
	data_xvadt NewtonsLawsMRUA(int xo, int vo, int ao, int dt);		//to call only at the end
	data_xvadt NewtonsLawsMRUAdt(int xo, int vo, int ao, int dt, int t);	//to call frame x frame


};

#endif // __VERLETINTEGRATOR_H__
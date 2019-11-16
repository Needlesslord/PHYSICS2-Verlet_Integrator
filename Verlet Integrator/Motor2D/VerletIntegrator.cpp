#include "VerletIntegrator.h"
#include "j1App.h"

//Constructor
VerletIntegrator::VerletIntegrator() : j1Module()
{
	name.create("physics");
}

// Destructor
VerletIntegrator::~VerletIntegrator()
{
}

VerletIntegrator::Object VerletIntegrator::Integrate(Object obj, int dt)
{
	obj.x = obj.x + obj.vx*dt + (obj.ax / 2)*dt*dt;
	obj.vx = obj.vx + obj.ax*dt;
	return obj;
}


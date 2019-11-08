#include "VerletIntegrator.h"

VerletIntegrator::Object VerletIntegrator::Integrate(Object obj, int dt)
{
	obj.x = obj.x + obj.vx*dt + (obj.ax / 2)*dt*dt;
	obj.vx = obj.vx + obj.ax*dt;
	return obj;
}
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

data_xvadt VerletIntegrator::NewtonsLawsMRUA(int xo, int vo, int ao, int dt) //to call only at the end
{
	int to = 0;
	int f, m;								//not necessary
	int a = ao;		//a const
	int v, x, t = dt;
	v = a * dt + vo;
	x = 0.5*a*t*t + vo * t + xo;
	int v2 = (2 * a*(x - xo) + vo * vo);	//not necessary

	data_xvadt finaldata;

	finaldata.x = x;
	finaldata.v = v;
	finaldata.a = a;
	finaldata.t = t;

	return finaldata;
}

data_xvadt VerletIntegrator::NewtonsLawsMRUAdt(int xo, int vo, int ao, int dt, int t) //to call frame x frame
{
	int to = 0;
	int f, m;								//not necessary
	int a = ao;		//a const
	int v, x, tf = to+t;
	
	if (t < dt)
	{
		v = a * dt + vo;
		x = 0.5*a*t*t + vo * t + xo;
		int v2 = (2 * a*(x - xo) + vo * vo);	//not necessary
		t++;

		data_xvadt NewtonsLawsMRUAdt(int x, int v, int a, int dt, int t); 
	}

	data_xvadt finaldata;

	finaldata.x = x;
	finaldata.v = v;
	finaldata.a = a;
	finaldata.t = t;

	return finaldata;
}


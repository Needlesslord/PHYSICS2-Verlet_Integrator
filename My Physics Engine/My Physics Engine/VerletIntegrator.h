#pragma once

double AIR_DENSITY = 1.2;
double WATER_DENSITY = 1000;
double gravity = -9.81;

struct Object
{
	double x;
	double y;
	double vx;
	double vy;
	double ax;
	double ay;

	//Aerodynamics //SPHERE
	double radius;
	double area;
	double CD = 0.47;; //Coeficiente Aerodinámico de resistencia
	double mass;
};

struct Forces
{
	double x;
	double y;
};
/*
class VerletIntegrator
{
public:

	struct Object
	{
		float x;
		float y;
		float vx;
		float vy;
		float ax;
		float ay;

		//Aerodynamics //SPHERE
		float area;
		float CD = 0.47;; //Coeficiente Aerodinámico de resistencia
	};


	//Constructor
	VerletIntegrator();

	// Destructor
	virtual ~VerletIntegrator();

	// Integration function
	Object Integrate(Object obj, int dt);

};*/
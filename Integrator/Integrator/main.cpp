#include "object.h"



int main()
{
	double time;

	object sphere;
	object obstacle;

	//sphere2
	obstacle.setX(5.0);
	obstacle.setY(0.0);
	obstacle.setAX(0.0);
	obstacle.setAY(0.0);
	obstacle.setVX(0.0);
	obstacle.setVY(0.0);
	obstacle.setRadius(1.0);
	obstacle.setDensity(2000.0);



	sphere.enterData();

	std::cout << "How many seconds will the simulation last? ";
	std::cin >> time;
	std::cout << std::endl;

	sphere.update(time, obstacle, 1);
}
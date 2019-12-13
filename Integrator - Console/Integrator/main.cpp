#include "object.h"



int main()
{
	double time;

	object cube;
	object obstacle;

	//obstacle
	obstacle.setX(5.0);
	obstacle.setY(0.0);
	obstacle.setAX(0.0);
	obstacle.setAY(0.0);
	obstacle.setVX(0.0);
	obstacle.setVY(0.0);
	//obstacle.setRadius(1.0);
	obstacle.setDensity(HUGE_VAL);


	cube.enterData();

	std::cout << "How many seconds will the simulation last? (must be larger that 0, otherwise it will be set to 5) ";
	std::cin >> time;
	if (time <= 0)
	{
		time = 5;
	}
	std::cout << std::endl;

	cube.update(time, obstacle, 1);
}
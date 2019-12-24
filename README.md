


***



# Verlet Integrator


## by Team Vegetta: Tomás Carreras, Enric-G. Durán, Marc Garcia, Núria Lamonja, Alex Lopez, Raul Morente, Albert Robles



***

***



## Verlet Integrator: A quick summary


 - Verlet Integration is a numerical method used to integrate Newton’s equations of motion. It is frequently used to calculate trajectories of particles in molecular dynamics simulations and computer graphics. (https://en.wikipedia.org/wiki/Verlet_integration)

 - The Verlet integrator provides good numerical stability, as well as other properties that are important in physical systems such as time reversibility and preservation of the symplectic form on phase space, at no significant additional computational cost over the simple Euler method. (https://en.wikipedia.org/wiki/Verlet_integration)



***



## Goals


Our goal for this project is to have an interactable integrator that, given an initial data, in our concrete case the initial position x and y, speed vx and vy, acceleration ax and ay, a radius, a density and elapsed time, it computes their values at the end of that given time. 
Our intention is that it will also have a way to test the correct function of the integrator, which will print every frame and it will be able to pause it and a graphic representation. 
In addition, the Newton's Laws will be implemented in order to compare the results of the integrator with the final data and see the accuracy and the standard deviation. 


Our frame rate will be of 60 fps. 
Air density will be implemented, as well as gravity. 
We will have a ground and the ball will be able to collide with it. 
Frame per frame we are going to be calculating each variable to update it.



***



## Verlet Integrator: The formulas we used


To calculate the force in the x axis we will use the following formula:

**fx = 0.5 * AIR_DENSITY * new_vx * new_vx * area * CD**

	Where:
	fx - force in the x axis
	AIR_DENSITY - denstity of the air, constant
	new_vx - the velocity for this frame
	area - area of the object (sphere)
	CD - drag coefficient

From the Verlet Integrator we know the following: 

In case we didn't need the speed, the formulas we would use would be:

**new_vx = vx + new_ax * dt**
	
	Where:
	new_vx - the velocity for this frame
	vx - the velocity of the previous frame 
	new_ax - the acceleration for this frame
	dt - the delta time (elapsed time) between the previous frame and this one

**new_x = new_x * 2 - x + new_ax * dt * dt**

	Where:
	new_x - the position for this frame
	x - the position of the previous frame
	dt - the delta time (elapsed time) between the previous frame and this one
	new_ax - the acceleration for this frame

However, we are going to be using the velocity. Then, to compute the acceleration and the speed we will use MRUA, which is used to calculate the Velocity Verlet. In this case, the acceleraion would be take as constant and we would have:

**new_vx = vx + new_ax * dt**

	Where:
	new_vx - the velocity for this frame
	vx - the velocity of the previous frame 
	new_ax - the acceleration for this frame
	dt - the delta time (elapsed time) between the previous frame and this one

**new_x = new_x * 2 - x + new_ax * dt * dt**

	Where:
	new_x - the position for this frame
	x - the position of the previous frame
	dt - the delta time (elapsed time) between the previous frame and this one
	new_ax - the acceleration for this frame

Then again, we take into account that the acceleration may not be the same through all of this process and, therefore, the formulas we are finally coing to use are:

**new_ax = fx / mass**

	Where:
	new_ax - the acceleration for this frame
	fx - force in the x axis
	mass - mass of the object, given a radius and a density

**new_vx = vx + new_ax * dt**

	Where:
	new_vx - the velocity for this frame
	vx - the velocity of the previous frame 
	new_ax - the acceleration for this frame
	dt - the delta time (elapsed time) between the previous frame and this one

**new_x = x + vx * dt + (new_ax / 2.0) * dt * dt**

	Where:
	new_x - the position for this frame
	x - the position of the previous frame
	vx - the velocity of the previous frame
	dt - the delta time (elapsed time) between the previous frame and this one
	new_ax - the acceleration for this frame

We  will use Newton's Laws to compare the results of the integrator with the "reality", as stated before. To compute the acceleration, the velocity and the position we will use the MRUA formulas:

**new_ax = fx / mass**

	Where:
	new_ax - the acceleration for this frame
	fx - force in the x axis
	mass - mass of the object, given a radius and a density

**new_vx = vx + new_ax * dt**

	Where:
	new_vx - the velocity for this frame
	vx - the velocity of the previous frame 
	new_ax - the acceleration for this frame
	dt - the delta time (elapsed time) between the previous frame and this one

**new_x = x + vx * dt + (new_ax / 2.0) * dt * dt**

	Where:
	new_x - the position for this frame
	x - the position of the previous frame
	vx - the velocity of the previous frame
	dt - the delta time (elapsed time) between the previous frame and this one
	new_ax - the acceleration for this frame


To compute the forces, the acceleration, the speed and the position for the y axis, we will use the formulas stated above as well, but taking into account the gravity, as said before.


To see further information on where we took our information on what formulas to use from, please take a look at our "Data" folder in our [GitHub repository](https://github.com/Needlesslord/Physics2theory) the following web pages:

[Verlet Integration · GitBook](https://www.algorithm-archive.org/contents/verlet_integration/verlet_integration.html)

[Wikipedia: Verlet Integration](https://en.wikipedia.org/wiki/Verlet_integration)

[A Verlet based approach for 2D game physics](https://www.gamedev.net/articles/programming/math-and-physics/a-verlet-based-approach-for-2d-game-physics-r2714)



***



## Installation


Go to our GitHub repository and download the .zip. Go To the folder "Integrator - console", open the solution and Debug it.

Enjoy!



***



## Team members:


**Programmer:** Tomás Carreras Ugarte

	GitHub: tomascarreras1000

**Programmer:** Enric-G. Durán

	GitHub: EnricGDV

**Programmer:** Marc Garcia

	GitHub: EnricGDV

**Programmer:** Alex Lopez

	GitHub: AlexLA99

**Programmer:** Raul Morente

	GitHub: Akarumbra

**Programmer:** Albert Robles

	GitHub: Albertito029

**Team Leader and progammer:** Núria Lamonja

	GitHub:	 needlesslord



***



## Credits:


Design and Development: 

		Tomás Carreras
		
		Enric-G. Durán

		Marc Garcia
		
		Núria Lamonja
		
		Alex Lopez
		
		Raul Morente
		
		Albert Robles


Team Leader:

		Núria Lamonja


We would like to thank David de la Torre, who has helped with this project and given us kind advice.
This project has been done for CITM-TTC under the MIT License.



***



## Download to the latest release


Here you can go to the release page and download the different versions available. Just click on the release, unzip it once downloaded and you can play clicking the Application.
Instructions can be found in this same web page or in the readme.md file included in the zip.


[Releases](https://github.com/Needlesslord/PHYSICS2-Verlet_Integrator/releases)



***



## Usage


	CONTROLS:

	COMPUTER KEYBOARD ONLY


In each step, the user will receive instructions of what data or keys they should press. In addition, there is a tutorial at the begining explaining everything.



***



## Content


In this integrator you are shown a welcome message at first and a small tutorial. 

After that, you input the data and all the frames will be displayed on the screen afterwards.

In the final results, it will also be displayed in case you want to the results of calculating everything with the Newton's Laws.



***



## Disclosure


This is an integrator made by second year students of the Videogame Design and Development degree taught at CITM-TTC.

The integrator has been made using C++, using SDL libraries.



***



## Links


[Github](https://github.com/Needlesslord/Physics2theory): https://github.com/Needlesslord/PHYSICS2-Verlet_Integrator

[Releases of this integrator](https://github.com/Needlesslord/PHYSICS2-Verlet_Integrator/releases): https://github.com/Needlesslord/Physics2theory/releases

[Our web page](https://needlesslord.github.io/Physics2theory/): https://needlesslord.github.io/PHYSICS2-Verlet_Integrator/



***



## License


Copyright (c) [2019] [Tomás Carreras, Enric-G. Durán, Marc Garcia, Núria Lamonja, Alex Lopez, Raul Morente, Albert Robles]

Under the MIT License.

All rights reserved to the developers and publishers of the original release (Tomás Carreras, Enric-G. Durán, Marc Garcia, Núria Lamonja, Alex Lopez, Raul Morente, Albert Robles). 
The aim of this project (link to the github project can be found above) and respectively wiki is only educational. 

The content can only be used for non-commercial purposes. 

The copyright of the music and art is used for non-commercial projects and educational purposes.
In case you want to use it for other cases please do contact their rightful owners.

If you want to use this integrator or its content please do ask beforehand (email: needlesslord@gmail.com).

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

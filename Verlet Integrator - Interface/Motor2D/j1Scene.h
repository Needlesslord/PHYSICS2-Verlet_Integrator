#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include"VerletIntegrator.h"
struct SDL_Texture;

struct input 
{
	uint count = 0;
	uint lastInput[10] = {};
	uint i = 0;
	char count_string[10];
};

class j1Scene : public j1Module
{
public:

	j1Scene();
	virtual ~j1Scene();
	bool Awake();
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

	void Draw(float x, float y);

	uint step;
	uint font;
	uint currentInput = 1;

	input x0;					// currentInput = 1;
	input y0;					// currentInput = 2;
	input vx0;					// currentInput = 3;
	input vy0;					// currentInput = 4;
	input ax0;					// currentInput = 5;
	input ay0;					// currentInput = 6;
	input SideLength;			// currentInput = 7;
	input density;				// currentInput = 8;
	input fx0;					// currentInput = 9;
	input fy0;					// currentInput = 10;
	input mu;					// currentInput = 11;
	input collision;			// currentInput = 12;
	input time;					// currentInput = 13;

	int star_position [13] = {137, 168, 199, 230, 261, 292, 323, 354, 385, 416, 447, 495, 543 };
	uint num_star;
	bool first_time = true;
	bool draw = false;
	SDL_Rect quad;
	
private:
	SDL_Texture* screen_0;
	SDL_Texture* screen_1;
	SDL_Texture* screen_2;
	SDL_Texture* screen_3;
	SDL_Texture* screen_4;
	SDL_Texture* screen_5;
	SDL_Texture* screen_6;

	SDL_Texture* star;

	SDL_Texture* ball_tex;


	SDL_Texture* objTex;
	SDL_Rect objRect = { 0, 0, 406, 406 };

};

#endif // __j1SCENE_H__
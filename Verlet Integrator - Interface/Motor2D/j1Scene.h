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
	input L;					// currentInput = 7;
	input fx0;					// currentInput = 8;
	input fy0;					// currentInput = 9;
	input mu;					// currentInput = 10;
	input collision;			// currentInput = 11;
	input time;					// currentInput = 12;

	int star_position [12] = {137, 168, 199, 230, 261, 292, 323, 354, 385, 416, 464, 513};
	uint num_star;
	bool first_time = true;
	SDL_Rect quad;
	
private:
	SDL_Texture* screen_0;
	SDL_Texture* screen_1;
	SDL_Texture* screen_2;
	SDL_Texture* screen_3;
	SDL_Texture* screen_4;
	SDL_Texture* screen_5;

	SDL_Texture* star;

	SDL_Texture* ball_tex;

};

#endif // __j1SCENE_H__
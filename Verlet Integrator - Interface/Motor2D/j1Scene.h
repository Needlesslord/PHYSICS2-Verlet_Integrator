#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include"VerletIntegrator.h"
struct SDL_Texture;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	uint step;
	uint count = 0;
	uint i = 0;
	uint lastInput[10] = {};
	uint font;
	int star_position [12] = {137, 168, 199, 230, 261, 292, 323, 354, 385, 416, 464, 513};
	uint num_star;
	char count_string[10];
	
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
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
	char count_string[10];
	
private:
	SDL_Texture* img;
	SDL_Texture* ball_tex;
	int font;
};

#endif // __j1SCENE_H__
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

	int step;
	SDL_Rect ball;

private:
	SDL_Texture* img;
	SDL_Texture* ball_tex;
};

#endif // __j1SCENE_H__
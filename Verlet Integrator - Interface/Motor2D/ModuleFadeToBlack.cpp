#include <math.h>
#include "Globals.h"
#include "p2Log.h"
#include "j1App.h"
#include "ModuleFadeToBlack.h"
#include "j1Render.h"
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_timer.h"
#include "j1Scene.h"

ModuleFadeToBlack::ModuleFadeToBlack()
{
	screen = {0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE};
}

ModuleFadeToBlack::~ModuleFadeToBlack()
{}

// Load assets
bool ModuleFadeToBlack::Start()
{
	LOG("Preparing Fade Screen");
	SDL_SetRenderDrawBlendMode(App->render->renderer, SDL_BLENDMODE_BLEND);
	return true;
}

// Update: draw background
bool ModuleFadeToBlack::Update()
{
	if(current_step == fade_step::none)
		return UPDATE_CONTINUE;

	Uint32 now = SDL_GetTicks() - start_time;
	float normalized = MIN(1.0f, (float)now / (float)total_time);

	switch(current_step)
	{
		case fade_step::reboot:
		{
			if (now >= total_time)
			{
				//App->collisions->Disable();

				// ---

				total_time += total_time;
				start_time = SDL_GetTicks();
				
				current_step = fade_step::fade_from_black;
			}
		} break;

		case fade_step::fade_to_black:
		{
			if(now >= total_time)
			{
				// TODO 2: enable / disable the modules received when FadeToBlacks() gets called
				moduleoff->active = false;
				moduleon->active = true;
				// ---
				total_time += total_time;
				start_time = SDL_GetTicks();
				current_step = fade_step::fade_from_black;
			}
		} break;

		case fade_step::fade_from_black:
		{
			normalized = 1.0f - normalized;

			if(now >= total_time)
				current_step = fade_step::none;
		} break;
	}

	// Finally render the black square with alpha on the screen
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, (Uint8)(normalized * 255.0f));
	SDL_RenderFillRect(App->render->renderer, &screen);

	return UPDATE_CONTINUE;
}

// Fade to black. At mid point deactivate one module, then activate the other
bool ModuleFadeToBlack::FadeToBlack(j1Module* module_off, j1Module* module_on, float time)
{
	bool ret = false;

	if(current_step == fade_step::none)
	{

		current_step = fade_step::fade_to_black;
		start_time = SDL_GetTicks();
		total_time = (Uint32)(time * 0.5f * 1000.0f);
		moduleoff = module_off;
		moduleon = module_on;
		ret = true;
	}

	return ret;
}

bool ModuleFadeToBlack::Reboot(float time)
{
	bool ret = false;

	if (current_step == fade_step::none)
	{
		current_step = fade_step::reboot;
		start_time = SDL_GetTicks();
		total_time = (Uint32)(time * 0.5f * 1000.0f);

		ret = true;
	}
	//App->player->Enable();
	//App->player2->Enable();
	//App->collisions->Enable();
	//App->render->camera.x = -245;
	//App->render->camera.y = -10;

	//App->scene_2->reboot = true;
	return ret;
}
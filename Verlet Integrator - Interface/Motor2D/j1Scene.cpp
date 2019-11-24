#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "ModuleFonts.h"
#include "VerletIntegrator.h"

object Ball;

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;
	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	screen_0 = App->tex->Load("textures/0.png");
	screen_1 = App->tex->Load("textures/1.png");
	screen_2 = App->tex->Load("textures/2.png");
	screen_3 = App->tex->Load("textures/3.png");
	screen_4 = App->tex->Load("textures/4.png");
	screen_5 = App->tex->Load("textures/5.png");

	star = App->tex->Load("textures/star.png");

	ball_tex = App->tex->Load("textures/ball.png");
	font = App->fonts->Load("textures/Fonts_Numbers.png", "0123456789", 1);
	step = 0;
	num_star = 0;
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if (step == 0)
	{
		App->render->Blit(screen_0, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
		}
	}
	else if (step == 1)
	{
		App->render->Blit(screen_1, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
	}
	else if (step == 2)
	{
		App->render->Blit(screen_2, 0, 0);

		App->render->Blit(star, 30, star_position[num_star]);

		if (App->input->GetKeyDown(SDLK_s) && num_star < 11)
		{
			num_star++;
		}
		if (App->input->GetKeyDown(SDLK_w) && num_star > 0)
		{
			num_star--;
		}

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
			num_star = 0;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
		if (count < 100000000) 
		{
			if (App->input->GetKeyDown(SDLK_0))
			{
				lastInput[i] = 0;
				count = count * 10;
				i++;
			}
			if (App->input->GetKeyDown(SDLK_1))
			{
				lastInput[i] = 1;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_2))
			{
				lastInput[i] = 2;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_3))
			{
				lastInput[i] = 3;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_4))
			{
				lastInput[i] = 4;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_5))
			{
				lastInput[i] = 5;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_6))
			{
				lastInput[i] = 6;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_7))
			{
				lastInput[i] = 7;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_8))
			{
				lastInput[i] = 8;
				count = count * 10 + lastInput[i];
				i++;
			}
			if (App->input->GetKeyDown(SDLK_9))
			{
				lastInput[i] = 9;
				count = count * 10 + lastInput[i];
				i++;
			}
		}
		if (count != 0)
		{
			if (App->input->GetKeyDown(SDLK_BACKSPACE))
			{
				i--;
				count = count - lastInput[i];
				count = count / 10;
			}
		}
	}
	else if (step == 3)
	{
		App->render->Blit(screen_3, 0, 0);

		if (App->input->GetKeyDown(SDLK_1))
		{
			step++;
		}
		else if (App->input->GetKeyDown(SDLK_2))
		{
			step += 2;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
	}
	else if (step == 4)
	{
		App->render->Blit(screen_4, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
	}
	else if (step == 5)
	{
		App->render->Blit(screen_5, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step -= 2;
		}
	}
	if (step > 5)step = 5;
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	if (step == 2)
	{
	sprintf_s(count_string, 10, "%1d", count);
	App->fonts->BlitText(100, 100, font, count_string);
	}

	bool ret = true;
	if (App->input->GetKeyDown(SDLK_ESCAPE))
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	App->tex->UnLoad(screen_0);
	App->tex->UnLoad(ball_tex);
	App->fonts->UnLoad(font);
	return true;
}
